/*
PluginProcessor.h - header file for PluginProcessor.cpp
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

#ifndef __PLUGINPROCESSOR_H_AEB64BCF__
#define __PLUGINPROCESSOR_H_AEB64BCF__

#include "vstSynth.h"
#include "vstSynthFilter.h"


//==============================================================================
/**
*/
class vstSynthAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    vstSynthAudioProcessor();
    ~vstSynthAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    
    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
    
    //==============================================================================

    /* 
     oscWave: oscillator output waveform. 0 = SineWave, 1 = BlitSquare, 2 = BlitSaw
     oscOctave: osciallator octave (1-4). output frequency = Midi key frequency * 2^oscOctave
     oscLevel: gain applied to individual oscillator.
     */

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

	float parameters[27];
        
    //==============================================================================
    Synthesiser vstSynth;
	MidiKeyboardState keyboardState;
    AudioSampleBuffer delayBuffer;
	vstSynthFilter hpeqFilter;
	Modulate tremolo;
    
    float* delayWritePtr;
    float* delayReadPtr;

	float gain;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (vstSynthAudioProcessor);
};

#endif  // __PLUGINPROCESSOR_H_AEB64BCF__
