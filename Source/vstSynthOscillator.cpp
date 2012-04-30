/*
oscillator.cpp - generates waveforms for synth from STK classes
Copyright (C) 2012 Gabriel Olochwoszcz

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
STK LICENSE:

STK WWW site: http://ccrma.stanford.edu/software/stk/

The Synthesis ToolKit in C++ (STK)
Copyright (c) 1995-2011 Perry R. Cook and Gary P. Scavone

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

Any person wishing to distribute modifications to the Software is
asked to send the modifications to the original developer so that they
can be incorporated into the canonical version.  This is, however, not
a binding provision of this license.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
 This class is used to generate the raw waveforms used by the synth. 
 Waveforms are generated using the STK SineWave, BlitSquare and BlitSaw
 classes.
*/


#include "vstSynthOscillator.h"

vstSynthOscillator::vstSynthOscillator()
{
	// Initial parameters
    frequency = 220;
	octave = 1;
	waveform = 0;
	gain = 0;
    noiseLevel = 0;
}

vstSynthOscillator::~vstSynthOscillator()
{
    
}

void vstSynthOscillator::setFrequency(StkFloat newFrequency)
{
    frequency = newFrequency; // Controlled by MIDI key number
}

float vstSynthOscillator::getFrequency()
{
	return this->frequency;
}

void vstSynthOscillator::setOctave(int newOctave)
{
	this->octave = 1<<newOctave; // Controlled by vstSynthEditor::oscXOctaveSlider
}

int vstSynthOscillator::getOctave()
{
	return this->octave;
}

void vstSynthOscillator::setGain(float newGain)
{
    this->gain = newGain; // Controlled by vstSynthEditor::oscXLevelSlider
}

float vstSynthOscillator::getGain()
{
	return this->gain;
}

void vstSynthOscillator::setWaveform(int newWaveform)
{
	this->waveform = newWaveform; // Controlled by vstSynthEditor::oscXWaveComboBox
}

int vstSynthOscillator::getWaveform()
{
	return this->waveform;
}

// Allows for setting of all parameters in one command. Called on by vstSynth on MIDI note on
void vstSynthOscillator::noteOn(float newFrequency, int newOctave, float newGain, int newWaveform)
{
	this->setWaveform(newWaveform);
	this->setOctave(newOctave);
	this->setFrequency(newFrequency);
	this->setGain(newGain);
}

// Checks current settings against any potential changes and updates as necessary
void vstSynthOscillator::update(int newOctave, float newGain, int newWaveform)
{
    if (newOctave != this->getOctave())
	{
		this->setOctave(newOctave);
	}
	if (newWaveform != this->getWaveform())
	{
		this->setWaveform(newWaveform);
	}
	if (newGain != this->getGain())
	{
		this->setGain(newGain);
	}
}

// Silences output after MIDI key release signal received
void vstSynthOscillator::noteOff(float newGain)
{
	this->setGain(newGain);
}

// Generate a single output of the appropriate waveform.
StkFloat vstSynthOscillator::tick()
{
	switch (waveform) 
	{
        case 0: 
		{
			return this->getGain() * this->sineOut.tick();
		}
        case 1:
		{
			return this->getGain() * this->sawOut.tick();
		}
        case 2:
		{
			return this->getGain() * this->squareOut.tick();
		}
        default:
		{
			return 0;
		}
	}
}

// Fills an AudioSampleBuffer with the oscillators output and applies vibrato effect if enabled.
void vstSynthOscillator::fillBuffer(AudioSampleBuffer& buffer, int startSample, int numSamples, ADSR* envelope, float noiseGain, float lfoFreq, float lfoDev, bool vibratoOn)
/*
 buffer
 startSample
 numSamples
 envelope - reference to ADSR envelope generator from calling vstSynthVoice
 noiseGain - level of noise generator
 lfoFreq - used to set vibratoSpeed
 lfoDev - used to set vibratoDepth
 vibratoOn - boolean set by caller to enable/disable vibrato
 */

{
    // Pointer to buffer
    float* bufferPtr = buffer.getSampleData(0, startSample);
    
    // Updates vibrato parameters if enabled
	if (vibratoOn)
    {
        if (vibratoSpeed != lfoFreq) // Controlled by vstSynthEditor::lfoFreqSlider
        {
            vibratoSpeed = lfoFreq;
            vibrato.setVibratoRate(vibratoSpeed);
        }
        
        if (vibratoDepth != lfoDev) // Controlled by vstSynthEditor::lfoDevSlider
        {
            vibratoDepth = lfoDev;
            vibrato.setVibratoGain(vibratoDepth);
        }    
    }
    // Reset parameters to 0 when disabled
    else
    {
        vibratoSpeed = 0;
        vibratoDepth = 0;
    }
    
    if (noiseGain <= 0.01)
    {
        noiseLevel = 0;
    }
    else
    {
        noiseLevel = 0.01 * noiseGain;
    }
    
    /*
     Fills buffer with output from generators with appropriate envelope applied. 
     Noise is also added to each oscillator to allow for proper enveloping with each key press/release.
     */
    for (int currentSample = 0; currentSample < numSamples; currentSample++)
	{
        switch (waveform)
		{
            case 0: //Sine
			{
                sineOut.setFrequency(octave * (frequency + vibrato.tick()));
				bufferPtr[currentSample] += (float) (envelope->tick() * (noiseLevel * noise.tick() + gain * sineOut.tick()));
				break;
			}
            case 1: //Saw
			{
                sawOut.setFrequency(octave * (frequency + vibrato.tick()));
				bufferPtr[currentSample] += (float) (envelope->tick() * (noiseLevel * noise.tick() + gain * sawOut.tick()));
				break;
			}
            case 2: //Square
			{
                squareOut.setFrequency(octave * (frequency + vibrato.tick()));
				bufferPtr[currentSample] += (float) (envelope->tick() * (noiseLevel * noise.tick() + gain * squareOut.tick()));
				break;
			}
            default:
			{
				break;
			}
		}
	}
}
