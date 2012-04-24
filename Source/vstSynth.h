/*
vstSynth.h - header for vstSynth.cpp
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



#include "StkIncludes.h"
#include "vstSynthOscillator.h"

class vstSynthSound : public SynthesiserSound
{
public:
    vstSynthSound();
    
    bool appliesToNote(const int /*midiNoteNumber*/);
    bool appliesToChannel(const int /*midiChannel*/);
}; 

class vstSynthVoice : public SynthesiserVoice
{
public:
    vstSynthVoice(float* parameters);
    ~vstSynthVoice();
    float getParameter(int index);
  
    bool canPlaySound (SynthesiserSound* sound);
    
    void startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*currrentPitchWheelPosition*/);
    
    void stopNote (const bool allowTailOff);
    
    void pitchWheelMoved (const int /*newValue*/);
    
    void controllerMoved (const int /*controllerNumber*/, const int /*newValue*/);

	void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);

private:
    enum Parameters
    {
        // single oscillator
        osc1WaveParam,
        osc1OctaveParam,
        osc1LevelParam,
        
        osc2WaveParam,
        osc2OctaveParam,
        osc2LevelParam,
		
        osc3WaveParam,
        osc3OctaveParam,
        osc3LevelParam,
        
		// envelope
        attackParam,
        decayParam,
        sustainParam,
        releaseParam,
        
        // LFO
        lfoDestParam,
        lfoWaveParam,
        lfoFreqParam,
        lfoDevParam,
        
        // filter 
        filterTypeParam,
        filterCutoffParam,
        filterResonanceParam,
        filterGainParam,
        
        // delay
        delayTimeParam,
        delayFeedbackParam,
        delayGainParam,
        
        // output
        noiseParam,
        driveParam,
        outputGainParam,
        
        totalNumParams
    };

    float* localParameters;

	vstSynthOscillator oscillator1;
	vstSynthOscillator oscillator2;
	vstSynthOscillator oscillator3;
    
	stk::ADSR envelope;
    bool vibratoOn;
    
    float oscOutput;
    
    double freq;
	double keyLevel;
};