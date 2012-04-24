//
//  additiveSynth.cpp
//  additiveSynth
//
//  Created by Gabriel Olochwoszcz on 3/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "additiveSynth.h"

int additiveSynthVoice::osc1Wave;
int additiveSynthVoice::osc1Octave;
float additiveSynthVoice::osc1Level;

int additiveSynthVoice::osc2Wave;
int additiveSynthVoice::osc2Octave;
float additiveSynthVoice::osc2Level;

int additiveSynthVoice::osc3Wave;
int additiveSynthVoice::osc3Octave;
float additiveSynthVoice::osc3Level;

int additiveSynthVoice::lfoDest;
int additiveSynthVoice::lfoWave;
float additiveSynthVoice::lfoFreq;
float additiveSynthVoice::lfoDev;

float additiveSynthVoice::attack;
float additiveSynthVoice::decay;
float additiveSynthVoice::sustain;
float additiveSynthVoice::release;

int additiveSynthVoice::filterType;
float additiveSynthVoice::filterCutoff;
float additiveSynthVoice::filterResonance;
float additiveSynthVoice::filterGain;

int additiveSynthVoice::delayTime;
float additiveSynthVoice::delayFeedback;
float additiveSynthVoice::delayGain;

float additiveSynthVoice::noiseGain;
float additiveSynthVoice::drive;
float additiveSynthVoice::outputGain;

unsigned int numOscillators = 3;

additiveSynthSound::additiveSynthSound()
{
}

bool additiveSynthSound::appliesToNote(const int /*midiNoteNumber*/)
{
	return true;
}
bool additiveSynthSound::appliesToChannel(const int /*midiChannel*/)
{
	return true;
} 

//=========================================================================

additiveSynthVoice::additiveSynthVoice()
{
}

additiveSynthVoice::~additiveSynthVoice()
{
}

bool additiveSynthVoice::canPlaySound (SynthesiserSound* sound)
{
	return dynamic_cast <additiveSynthSound*> (sound) != 0;
}

void additiveSynthVoice::startNote (const int midiNoteNumber, const float velocity, SynthesiserSound* /*sound*/, const int /*currrentPitchWheelPosition*/)
{
	freq = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	keyLevel = velocity/127;

	oscillator1.noteOn(freq, osc1Octave, osc1Level, osc1Wave);
	oscillator2.noteOn(freq, osc2Octave, osc2Level, osc2Wave);
	oscillator3.noteOn(freq, osc3Octave, osc3Level, osc3Wave);

	envelope.setAllTimes(attack, decay, sustain/10, release);
	envelope.keyOn();
}

void additiveSynthVoice::stopNote (const bool allowTailOff)
{
	envelope.keyOff();
	clearCurrentNote();
}

void additiveSynthVoice::pitchWheelMoved (const int /*newValue*/)
{
}

void additiveSynthVoice::controllerMoved (const int /*controllerNumber*/, const int /*newValue*/)
{
}

void additiveSynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	//float* totalOutput = new float[numSamples];

	envelope.setAllTimes(attack, decay, sustain/10, release);
    LFO.setVibratoRate(lfoFreq);

	//for (int currentSample = 0; currentSample < numSamples; currentSample++)
	//{
		oscillator1.update(osc1Octave, osc1Wave, osc1Level);
		oscillator2.update(osc2Octave, osc2Wave, osc2Level);
		oscillator3.update(osc3Octave, osc3Wave, osc3Level);

   //    switch (lfoDest) {
    //        case 0:
    //        {
    //                LFO.setVibratoGain(lfoDev);
				//	oscOutput = (float) (envelope.tick() * (oscillator1.tick() + oscillator2.tick() + oscillator3.tick() + noiseGain * noise.tick()));
    //            break;
    //        }
    //        case 1:
    //        {
				//oscillator1.setFrequency(freq+LFO.tick());
				//oscillator2.setFrequency(freq+LFO.tick());
				//oscillator3.setFrequency(freq+LFO.tick());
				//oscOutput = (float) (envelope.tick() * (oscillator1.tick() + oscillator2.tick() + oscillator3.tick() + noiseGain * noise.tick()));
				//break;
    //        }
    //        case 2:
    //        {
				//LFO.setVibratoGain(1);
				//oscOutput = (float) (LFO.tick() * envelope.tick() * (oscillator1.tick() + oscillator2.tick() + oscillator3.tick() + noiseGain * noise.tick()));
    //        }
   
    //    }
        

		
	//	totalOutput[currentSample] = oscOutput;
	//}

//	for (int currentChannel = outputBuffer.getNumChannels(); --currentChannel >= 0;)
//	{
//		outputBuffer.addFrom(0, startSample, totalOutput, numSamples, outputGain);
//	}

	//delete [] totalOutput;
}