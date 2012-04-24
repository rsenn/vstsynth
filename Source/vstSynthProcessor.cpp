/*
PluginProcessor.cpp - synth implementation using:
		- STK (https://ccrma.stanford.edu/software/stk/)
			for "oscillators" and envelope generators
		- JUCE (http://rawmaterialsoftware.com)
			for connection to VST/AU, MIDI and GUI
		- high order parametric filters (http://www.ece.rutgers.edu/~orfanidi/hpeq/)
		- circular delay buffer

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
==============================================================================

This file was auto-generated!

It contains the basic startup code for a Juce application.

==============================================================================
*/

#include "vstSynthProcessor.h"
#include "vstSynthEditor.h"

//==============================================================================
vstSynthAudioProcessor::vstSynthAudioProcessor()
	: delayBuffer(1,1)

{
	setParameter(osc1WaveParam, 0);
	setParameter(osc2WaveParam, 0);
	setParameter(osc3WaveParam, 0);

	setParameter(osc1OctaveParam, 0);
	setParameter(osc2OctaveParam, 0);
	setParameter(osc3OctaveParam, 0);

	setParameter(osc1LevelParam, 0); //log
	setParameter(osc2LevelParam, 0); //log
	setParameter(osc3LevelParam, 0); //log

	setParameter(noiseParam, 0);

	setParameter(attackParam, 0);
	setParameter(decayParam, 0);
	setParameter(sustainParam, 0);
	setParameter(releaseParam, 0);

	setParameter(lfoDestParam, 0);
	setParameter(lfoWaveParam, 0);
	setParameter(lfoFreqParam, 0);
	setParameter(lfoDevParam, 0);

	setParameter(filterTypeParam, 1);
	setParameter(filterCutoffParam, .25);
	setParameter(filterResonanceParam, 1);
	setParameter(filterGainParam, 1);

	setParameter(delayTimeParam, 0);
	setParameter(delayFeedbackParam, 0); //log
	setParameter(delayGainParam, 0); //log

	setParameter(driveParam, 1);
	setParameter(outputGainParam, 0); //log

	// Initialise the synth...
	for (int i = 1; --i >= 0;)
	{
		vstSynth.addVoice (new vstSynthVoice(parameters));
	}
	vstSynth.addSound(new vstSynthSound());
}

vstSynthAudioProcessor::~vstSynthAudioProcessor()
{
}

//==============================================================================
const String vstSynthAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

int vstSynthAudioProcessor::getNumParameters()
{
	return totalNumParams;
}

float vstSynthAudioProcessor::getParameter (int index)
{
	switch (index) 
	{
		// single oscillator
	case osc1WaveParam:          return parameters[0];
	case osc1OctaveParam:        return parameters[1];
	case osc1LevelParam:         return parameters[2];

	case osc2WaveParam:          return parameters[3];
	case osc2OctaveParam:        return parameters[4];
	case osc2LevelParam:         return parameters[5];

	case osc3WaveParam:          return parameters[6];
	case osc3OctaveParam:        return parameters[7];
	case osc3LevelParam:         return parameters[8];

		// envelope
	case attackParam:           return parameters[9];
	case decayParam:            return parameters[10];
	case sustainParam:          return parameters[11];
	case releaseParam:          return parameters[12];

		// LFO
	case lfoDestParam:          return parameters[13];
	case lfoWaveParam:          return parameters[14];
	case lfoFreqParam:          return parameters[15];
	case lfoDevParam:           return parameters[16];

		// filter 
	case filterTypeParam:       return parameters[17];
	case filterCutoffParam:     return parameters[18];
	case filterResonanceParam:  return parameters[19];
	case filterGainParam:       return parameters[20];

		// delay
	case delayTimeParam:        return parameters[21];
	case delayFeedbackParam:    return parameters[22];
	case delayGainParam:        return parameters[23];

		// output
	case noiseParam:            return parameters[24];
	case driveParam:            return parameters[25];
	case outputGainParam:       return parameters[26];

	default:                    return 0.0f;
	}
}

void vstSynthAudioProcessor::setParameter (int index, float newValue)
{
	switch (index) 
	{
		// single oscillator
	case osc1WaveParam:          parameters[0] = newValue; break;
	case osc1OctaveParam:        parameters[1] = newValue+1; break;
	case osc1LevelParam:         parameters[2] = newValue; break;

	case osc2WaveParam:          parameters[3] = newValue; break;
	case osc2OctaveParam:        parameters[4] = newValue+1; break;
	case osc2LevelParam:         parameters[5] = newValue; break;

	case osc3WaveParam:          parameters[6] = newValue; break;
	case osc3OctaveParam:        parameters[7] = newValue+1; break;
	case osc3LevelParam:         parameters[8] = newValue; break;

		// envelope
	case attackParam:           parameters[9] = newValue; break;
	case decayParam:            parameters[10] = newValue; break;
	case sustainParam:          parameters[11] = newValue; break;
	case releaseParam:          parameters[12] = newValue; break;

		// LFO
	case lfoDestParam:          parameters[13] = newValue; break;
	case lfoWaveParam:          parameters[14] = newValue; break;
	case lfoFreqParam:          parameters[15] = newValue; break;
	case lfoDevParam:           parameters[16] = newValue; break;

		// filter 
	case filterTypeParam:       parameters[17] = newValue; break;
	case filterCutoffParam:     parameters[18] = newValue; break;
	case filterResonanceParam:  parameters[19] = newValue; break;
	case filterGainParam:       parameters[20] = newValue; break;

		// delay
	case delayTimeParam:        parameters[21] = newValue; break;
	case delayFeedbackParam:    parameters[22] = newValue; break;
	case delayGainParam:        parameters[23] = newValue; break;

		// output
	case noiseParam:            parameters[24] = newValue; break;
	case driveParam:            parameters[25] = newValue; break;
	case outputGainParam:       parameters[26] = newValue; break;

	default:                    break;
	}
}

const String vstSynthAudioProcessor::getParameterName (int index)
{
	switch (index) 
	{
		// single oscillator
	case osc1WaveParam:          return "osc1Wave";
	case osc1OctaveParam:        return "osc1Octave";
	case osc1LevelParam:         return "osc1Level";

	case osc2WaveParam:          return "osc2Wave";
	case osc2OctaveParam:        return "osc2Octave";
	case osc2LevelParam:         return "osc2Level";

	case osc3WaveParam:          return "osc3Wave";
	case osc3OctaveParam:        return "osc3Octave";
	case osc3LevelParam:         return "osc3Level";

		// envelope
	case attackParam:           return "attack";
	case decayParam:            return "decay";
	case sustainParam:          return "sustain";
	case releaseParam:          return "release";

		// LFO
	case lfoDestParam:          return "lfoDest";
	case lfoWaveParam:          return "lfoWave";
	case lfoFreqParam:          return "lfoFreq";
	case lfoDevParam:           return "lfoDev";

		// filter 
	case filterTypeParam:       return "filterType";
	case filterCutoffParam:     return "filterCutoff";
	case filterResonanceParam:  return "filterResonance";
	case filterGainParam:       return "filterGain";

		// delay
	case delayTimeParam:        return "delayTime";
	case delayFeedbackParam:     return "delayFeedback";
	case delayGainParam:        return "delayGain";

		// output
	case noiseParam:            return "noiseGain";
	case driveParam:            return "drive";
	case outputGainParam:       return "outputGain";

	default:                    break;
	}
	return String::empty;
}

const String vstSynthAudioProcessor::getParameterText (int index)
{
	return String (getParameter (index), 2);
}

const String vstSynthAudioProcessor::getInputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

const String vstSynthAudioProcessor::getOutputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

bool vstSynthAudioProcessor::isInputChannelStereoPair (int index) const
{
	return true;
}

bool vstSynthAudioProcessor::isOutputChannelStereoPair (int index) const
{
	return true;
}

bool vstSynthAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool vstSynthAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

int vstSynthAudioProcessor::getNumPrograms()
{
	return 0;
}

int vstSynthAudioProcessor::getCurrentProgram()
{
	return 0;
}

void vstSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String vstSynthAudioProcessor::getProgramName (int index)
{
	return String::empty;
}

void vstSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void vstSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	// Use this method as the place to do any pre-playback
	// initialisation that you need..
	vstSynth.setCurrentPlaybackSampleRate(sampleRate);
	Stk::setSampleRate(sampleRate);
	keyboardState.reset();
	hpeqFilter.setCoefficients(getParameter(filterTypeParam), getParameter(filterGainParam), getParameter(filterCutoffParam), getParameter(filterResonanceParam));
}

void vstSynthAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
	keyboardState.reset();
}

void vstSynthAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	// This is the place where you'd normally do the guts of your plugin's
	// audio processing...

	const int numSamples = buffer.getNumSamples();

	if (delayBuffer.getNumSamples() != getParameter(delayTimeParam) + numSamples)
	{
		delayBuffer.setSize(1, getParameter(delayTimeParam) + numSamples);
		delayBuffer.clear();
		delayWritePtr =  delayBuffer.getSampleData(0) + (int) getParameter(delayTimeParam);
		delayReadPtr = delayBuffer.getSampleData(0);
		hpeqFilter.reset();
	}

	keyboardState.processNextMidiBuffer(midiMessages, 0, numSamples, true);
	vstSynth.renderNextBlock(buffer, midiMessages, 0, numSamples);

	float* bufferPtr = buffer.getSampleData(0, 0);

	for (int currentSample = 0; currentSample < numSamples; currentSample++)
	{
		if (getParameter(lfoDestParam) == 2)
		{
			tremolo.setVibratoRate(getParameter(lfoFreqParam));
			tremolo.setVibratoGain(getParameter(lfoDevParam)/10);
			*bufferPtr *= (float) (1+tremolo.tick());
		}

		*bufferPtr = tanhf(getParameter(driveParam) * *bufferPtr);

		if (getParameter(delayTimeParam) > 0)
		{
			*bufferPtr += getParameter(delayFeedbackParam) * *delayReadPtr;
			*delayWritePtr = *bufferPtr;
			delayWritePtr++;
			delayReadPtr++;

			if (delayReadPtr > delayBuffer.getSampleData(0) + delayBuffer.getNumSamples())
			{
				delayReadPtr = delayBuffer.getSampleData(0);
			}

			if (delayWritePtr > delayBuffer.getSampleData(0) + delayBuffer.getNumSamples())
			{
				delayWritePtr = delayBuffer.getSampleData(0);
			}
		}


		bufferPtr++;
	}

	hpeqFilter.processSamples(buffer.getSampleData(0, 0), numSamples);

	//	buffer.addFrom(0, 0, delayBuffer, 0, 0, numSamples, getParameter(delayFeedbackParam));
	//	delayBuffer = buffer;

	buffer.addFrom(1, 0, buffer, 0, 0, numSamples);

	buffer.applyGain(0, numSamples, getParameter(outputGainParam));

	// In case we have more outputs than inputs, we'll clear any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
	{
		buffer.clear (i, 0, buffer.getNumSamples());
	}
}

//==============================================================================
bool vstSynthAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* vstSynthAudioProcessor::createEditor()
{
	return new vstSynthAudioProcessorEditor (this);
}

//==============================================================================
void vstSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.
}

void vstSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new vstSynthAudioProcessor();
}