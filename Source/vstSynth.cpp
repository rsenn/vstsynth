/*
synth.cpp - JUCE Voice and Sound classes for synthesiser implementation
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

#include "vstSynth.h"

vstSynthSound::vstSynthSound()
{
}

bool vstSynthSound::appliesToNote(const int /*midiNoteNumber*/)
{
	return true;
}
bool vstSynthSound::appliesToChannel(const int /*midiChannel*/)
{
	return true;
} 

//=========================================================================

vstSynthVoice::vstSynthVoice(float* parameters)
{
	localParameters = parameters;
}

vstSynthVoice::~vstSynthVoice()
{
}

float vstSynthVoice::getParameter (int index)
{
	switch (index) 
	{
            // single oscillator
        case osc1WaveParam:          return localParameters[0];
        case osc1OctaveParam:        return localParameters[1];
        case osc1LevelParam:         return localParameters[2];
            
        case osc2WaveParam:          return localParameters[3];
        case osc2OctaveParam:        return localParameters[4];
        case osc2LevelParam:         return localParameters[5];
            
        case osc3WaveParam:          return localParameters[6];
        case osc3OctaveParam:        return localParameters[7];
        case osc3LevelParam:         return localParameters[8];
            
            // envelope
        case attackParam:           return localParameters[9];
        case decayParam:            return localParameters[10];
        case sustainParam:          return localParameters[11];
        case releaseParam:          return localParameters[12];
            
            // LFO
        case lfoDestParam:          return localParameters[13];
        case lfoWaveParam:          return localParameters[14];
        case lfoFreqParam:          return localParameters[15];
        case lfoDevParam:           return localParameters[16];
            
            // filter 
        case filterTypeParam:       return localParameters[17];
        case filterCutoffParam:     return localParameters[18];
        case filterResonanceParam:  return localParameters[19];
        case filterGainParam:       return localParameters[20];
            
            // delay
        case delayTimeParam:        return localParameters[21];
        case delayFeedbackParam:    return localParameters[22];
        case delayGainParam:        return localParameters[23];
            
            // output
        case noiseParam:            return localParameters[24];
        case driveParam:            return localParameters[25];
        case outputGainParam:       return localParameters[26];
            
        default:                    return 0.0f;
	}
}

bool vstSynthVoice::canPlaySound (SynthesiserSound* sound)
{
	return dynamic_cast <vstSynthSound*> (sound) != 0;
}

void vstSynthVoice::startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*currrentPitchWheelPosition*/)
{
	freq = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	keyLevel = velocity/127;
    
	oscillator1.noteOn(freq, getParameter(osc1OctaveParam), keyLevel * getParameter(osc1LevelParam), getParameter(osc1WaveParam));
	oscillator2.noteOn(freq, getParameter(osc2OctaveParam), keyLevel * getParameter(osc2LevelParam), getParameter(osc2WaveParam));
	oscillator3.noteOn(freq, getParameter(osc3OctaveParam), keyLevel * getParameter(osc3LevelParam), getParameter(osc3WaveParam));

	envelope.setAllTimes(getParameter(attackParam), getParameter(decayParam), getParameter(sustainParam)/10, getParameter(releaseParam));
	envelope.keyOn();
}

void vstSynthVoice::stopNote (const bool allowTailOff)
{   
	oscillator1.noteOff(0.0001);
	oscillator2.noteOff(0.0001);
	oscillator3.noteOff(0.0001);
	envelope.keyOff();
    clearCurrentNote();
}

void vstSynthVoice::pitchWheelMoved (const int /*newValue*/)
{
}

void vstSynthVoice::controllerMoved (const int index, const int newValue)
{
}

void vstSynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    envelope.setAllTimes(getParameter(attackParam), getParameter(decayParam), getParameter(sustainParam)/10, getParameter(releaseParam));
    
	oscillator1.update(getParameter(osc1OctaveParam), keyLevel * getParameter(osc1LevelParam), getParameter(osc1WaveParam));
	oscillator2.update(getParameter(osc2OctaveParam), keyLevel * getParameter(osc2LevelParam), getParameter(osc2WaveParam));
	oscillator3.update(getParameter(osc3OctaveParam), keyLevel * getParameter(osc3LevelParam), getParameter(osc3WaveParam));
    
    if ((int) getParameter(lfoDestParam) == 1)
    {
        vibratoOn = true;
    }
    else
    {
        vibratoOn = false;
    }
    
	oscillator1.fillBuffer(outputBuffer, startSample, numSamples, &envelope, getParameter(noiseParam), getParameter(lfoFreqParam), getParameter(lfoDevParam), vibratoOn);
	oscillator2.fillBuffer(outputBuffer, startSample, numSamples, &envelope, getParameter(noiseParam), getParameter(lfoFreqParam), getParameter(lfoDevParam), vibratoOn);
	oscillator3.fillBuffer(outputBuffer, startSample, numSamples, &envelope, getParameter(noiseParam), getParameter(lfoFreqParam), getParameter(lfoDevParam), vibratoOn);
}