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

#include "vstSynthOscillator.h"

vstSynthOscillator::vstSynthOscillator()
{
	frequency = 220;
	octave = 1;
	waveform = 0;
	gain = 0;
	phase = 0;
	output = 0;
}

vstSynthOscillator::~vstSynthOscillator()
{
    
}

void vstSynthOscillator::setFrequency(StkFloat newFrequency)
{
    frequency = newFrequency;
}

float vstSynthOscillator::getFrequency()
{
	return this->frequency;
}

void vstSynthOscillator::setOctave(int newOctave)
{
	this->octave = 1<<newOctave;
}

int vstSynthOscillator::getOctave()
{
	return this->octave;
}

void vstSynthOscillator::setGain(float newGain)
{
	this->gain = newGain;
}

float vstSynthOscillator::getGain()
{
	return this->gain;
}

void vstSynthOscillator::setWaveform(int newWaveform)
{
	this->waveform = newWaveform;
}

int vstSynthOscillator::getWaveform()
{
	return this->waveform;
}

void vstSynthOscillator::noteOn(float newFrequency, int newOctave, float newGain, int newWaveform)
{
	this->setWaveform(newWaveform);
	this->setOctave(newOctave);
	this->setFrequency(newFrequency);
	this->setGain(newGain);
}

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

void vstSynthOscillator::noteOff(float newGain)
{
	this->setGain(newGain);
}

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

void vstSynthOscillator::fillBuffer(AudioSampleBuffer& buffer, int startSample, int numSamples, ADSR* envelope, float noiseGain, float lfoFreq, float lfoDev, bool vibratoOn)
{
	float* bufferPtr = buffer.getSampleData(0, startSample);
    
	if (vibratoOn)
    {
        if (vibratoSpeed != lfoFreq)
        {
            vibratoSpeed = lfoFreq;
            vibrato.setVibratoRate(vibratoSpeed);
        }
        
        if (vibratoDepth != lfoDev)
        {
            vibratoDepth = lfoDev;
            vibrato.setVibratoGain(vibratoDepth);
        }    
    }
    else
    {
        vibratoSpeed = 0;
        vibratoDepth = 0;
    }
    
    for (int currentSample = 0; currentSample < numSamples; currentSample++)
	{

        switch (waveform)
		{
            case 0: 
			{
                this->sineOut.setFrequency(octave * (frequency + vibrato.tick()));
				bufferPtr[currentSample] += (float) (envelope->tick() * (noiseGain * noise.tick() + this->getGain() * this->sineOut.tick()));
				break;
			}
            case 1:
			{
                this->sawOut.setFrequency(octave * (frequency + vibrato.tick()));
				bufferPtr[currentSample] += (float) (envelope->tick() * (noiseGain * noise.tick() + this->getGain() * this->sawOut.tick()));
				break;
			}
            case 2:
			{
                this->squareOut.setFrequency(octave * (frequency + vibrato.tick()));
				bufferPtr[currentSample] += (float) (envelope->tick() * (noiseGain * noise.tick() + this->getGain() * this->squareOut.tick()));
				break;
			}
            default:
			{
				break;
			}
		}
	}
}
