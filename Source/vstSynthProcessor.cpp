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
    // Initialize all parameters
	setParameterNotifyingHost(osc1WaveParam, 1);
	setParameterNotifyingHost(osc2WaveParam, 1);
	setParameterNotifyingHost(osc3WaveParam, 1);

	setParameterNotifyingHost(osc1OctaveParam, 0);
	setParameterNotifyingHost(osc2OctaveParam, 0);
	setParameterNotifyingHost(osc3OctaveParam, 0);

	setParameterNotifyingHost(osc1LevelParam, 1);
	setParameterNotifyingHost(osc2LevelParam, 1);
	setParameterNotifyingHost(osc3LevelParam, 1);

	setParameterNotifyingHost(noiseParam, 0.0001);

	setParameterNotifyingHost(attackParam, 0);
	setParameterNotifyingHost(decayParam, 0);
	setParameterNotifyingHost(sustainParam, 5);
	setParameterNotifyingHost(releaseParam, 0);

	setParameterNotifyingHost(lfoDestParam, 0);
	setParameterNotifyingHost(lfoWaveParam, 0);
	setParameterNotifyingHost(lfoFreqParam, 0);
	setParameterNotifyingHost(lfoDevParam, 0);

	setParameterNotifyingHost(filterTypeParam, 0);
	setParameterNotifyingHost(filterCutoffParam, 0.25 * PI);
	setParameterNotifyingHost(filterResonanceParam, 1);
	setParameterNotifyingHost(filterGainParam, 1);

	setParameterNotifyingHost(delayTimeParam, 0);
	setParameterNotifyingHost(delayFeedbackParam, 0.0001);
	setParameterNotifyingHost(delayGainParam, 0.0001);

	setParameterNotifyingHost(driveParam, 1);
	setParameterNotifyingHost(outputGainParam, 1); //log

	// Initialise the synth. 
	for (int numVoices = 1; --numVoices >= 0;)
	{
		// A reference to global parameters is passed to each
        // voice so that it can reference them locally. 
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
	case osc1OctaveParam:        parameters[1] = newValue; break;
	case osc1LevelParam:         parameters[2] = newValue; break;

	case osc2WaveParam:          parameters[3] = newValue; break;
	case osc2OctaveParam:        parameters[4] = newValue; break;
	case osc2LevelParam:         parameters[5] = newValue; break;

	case osc3WaveParam:          parameters[6] = newValue; break;
	case osc3OctaveParam:        parameters[7] = newValue; break;
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
    // Set sample rate for both JUCE and STK
    vstSynth.setCurrentPlaybackSampleRate(sampleRate);
	Stk::setSampleRate(sampleRate);
	
	delayBuffer.clear();
	keyboardState.reset();
	
    // Initialize filter with starting parameters
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
    // number of samples in current buffer
	const int numSamples = buffer.getNumSamples();

	
    /* 
     Checks to see if delay size has changed since the last block. If it has,
     the delay buffer is resized and cleared (to prevent garbage in the output)
     The read and write pointers are also reset to their starting positions and
     the saved filter states are removed to reduce transients.
     */
    
    // delayTimeParam controlled by vstSynthEditor::delayTimeSlider
    if (delayBuffer.getNumSamples() != getParameter(delayTimeParam) + numSamples)
	{
		delayBuffer.setSize(1, getParameter(delayTimeParam) + numSamples);
		delayBuffer.clear();
		delayWritePtr =  delayBuffer.getSampleData(0) + (int) getParameter(delayTimeParam);
		delayReadPtr = delayBuffer.getSampleData(0);
		//hpeqFilter.reset();
	}

	// Receives MIDI data from host
    keyboardState.processNextMidiBuffer(midiMessages, 0, numSamples, true);
	
    // Call to vstSynthVoice::renderNextBlock where buffer is filled with raw oscillator data
    vstSynth.renderNextBlock(buffer, midiMessages, 0, numSamples);

    // Pointer to beginning of buffer
	float* bufferPtr = buffer.getSampleData(0, 0);

    // Performs tremolo (AM) if enabled, overdrive and delay operation
	for (int currentSample = 0; currentSample < numSamples; currentSample++)
	{
		// Apply tremolo if enabled
        if (getParameter(lfoDestParam) == 2) // Controlled by vstSynthEditor::lfoDestComboBox
		{
			tremolo.setVibratoRate(getParameter(lfoFreqParam)); // Controlled by vstSynthEditor::lfoFreqSlider
			tremolo.setVibratoGain(getParameter(lfoDevParam)/10); // Controlled by vstSynthEditor::lfoDevSlider
			*bufferPtr *= (float) (1+tremolo.tick()); // Modulate amplitude with tremolo output
		}

        // Push signal through tahn to introduce nonlinear distortion
		*bufferPtr = tanhf(getParameter(driveParam) * *bufferPtr); // Controlled by vstSynthEditor::driveSlider

        // Process delay if enabled
		if (getParameter(delayTimeParam) > 0) // Controlled by vstSynthEditor::delayTimeSlider
		{
            // Add existing delay data into buffer
			*bufferPtr += getParameter(delayFeedbackParam) * *delayReadPtr; // Controlled by vstSynthEditor::delayFBSlider

            // Save current output data into delay buffer
			*delayWritePtr = *bufferPtr;
			
            // Increment pointers
            delayWritePtr++;
			delayReadPtr++;

            // Circular buffer implementation: reset pointers to beginning of buffers when end is reached
			if (delayReadPtr > delayBuffer.getSampleData(0) + delayBuffer.getNumSamples())
			{
				delayReadPtr = delayBuffer.getSampleData(0);
			}

			if (delayWritePtr > delayBuffer.getSampleData(0) + delayBuffer.getNumSamples())
			{
				delayWritePtr = delayBuffer.getSampleData(0);
			}
		}
        
        // Increment pointer
		bufferPtr++;
	}
    
    // Send buffer to vstSynthFilter where it is replaced with filtered data
	hpeqFilter.processSamples(buffer.getSampleData(0, 0), numSamples);

    // All processing happens in only one channel for speed; the other channel is filled here.
	buffer.addFrom(1, 0, buffer, 0, 0, numSamples);

    // Apply overall output gain to buffer before playback
	buffer.applyGain(0, numSamples, 10 * getParameter(outputGainParam)); // Controlled by vstSynthEditor::outputGainSlider

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
