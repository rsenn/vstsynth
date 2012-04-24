/*
oscillator.h - header file for oscillator.cpp
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



#include "StkIncludes.h"
#include "../JuceLibraryCode/JuceHeader.h"

using namespace stk;

class vstSynthOscillator
{
public:
    vstSynthOscillator();
    ~vstSynthOscillator();
    
    void setFrequency(StkFloat newFrequency);
	float getFrequency();
	
	void setOctave(int newOctave);
    int getOctave();
	
	void setGain(float newGain);
	float getGain();
	
	void setWaveform(int newWaveform);
	int getWaveform();
    
	void noteOn(float newFrequency, int newOctave, float newGain, int newWaveform);
	void update(int newOctave, float newGain, int newWaveform);
    void noteOff(float newAmplitude);
	
    StkFloat tick();
	void fillBuffer(AudioSampleBuffer& buffer, int startSample, int numSamples, ADSR* envelope, float noiseGain, float lfoFreq, float lfoDev, bool vibratoOn);

private:
    float currentSample;

	float frequency;
	int octave;
	int waveform;
	StkFloat gain;
	StkFloat phase;
	float output;

	SineWave sineOut;
	BlitSaw sawOut;
	BlitSquare squareOut;
	Noise noise;

	float vibratoDepth;
	float vibratoSpeed;
    Modulate vibrato;
};
