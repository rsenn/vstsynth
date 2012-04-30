/*
PluginEditor.h - header file for PluginEditor.cpp
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

  This is an automatically generated file created by the Jucer!

  Creation date:  26 Mar 2012 12:35:47am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_vstSynthAUDIOPROCESSOREDITOR_PLUGINEDITOR_11520947__
#define __JUCER_HEADER_vstSynthAUDIOPROCESSOREDITOR_PLUGINEDITOR_11520947__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "vstSynthProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class vstSynthAudioProcessorEditor  : public AudioProcessorEditor,
                                           public SliderListener,
                                           public ComboBoxListener//,
//										   public Timer
{
public:
    //==============================================================================
    vstSynthAudioProcessorEditor (vstSynthAudioProcessor* ownerFilter);
    ~vstSynthAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]
    
//    void timerCallback();
    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    GroupComponent* filterGroup;
    Slider* filterGainSlider;
    GroupComponent* lfoGroup;
    Slider* lfoDevSlider;
    GroupComponent* oscGroup;
    Label* label21;
    GroupComponent* envelopeGroup;
    Slider* sustainSlider;
    Slider* osc1lvlSlider;
    GroupComponent* delayGroup;
    Slider* delayFBSlider;
    Slider* delayGainSlider;
    GroupComponent* outputGroup;
    Label* label8;
    Slider* decaySlider;
    Slider* attackSlider;
    Slider* delayTimeSlider;
    Label* label;
    Label* label2;
    Label* label3;
    Label* label4;
    Label* label5;
    Label* label6;
    Label* label7;
    Slider* noiseSlider;
    Slider* driveSlider;
    Slider* outputGainSlider;
    Label* label11;
    Label* label12;
    Label* label13;
    Slider* releaseSlider;
    ComboBox* osc3WaveBox;
    ComboBox* osc3OctaveBox;
    Label* label23;
    Label* label24;
    Label* label25;
    Label* label27;
    Label* label29;
    Slider* filterFreqSlider;
    Label* label31;
    Label* label32;
    Label* label33;
    Slider* lfoFreqSlider;
    ComboBox* lfoWaveBox;
    ComboBox* lfoDestBox;
    Label* label9;
    Slider* osc3lvlSlider;
    Slider* filterResSlider;
    ComboBox* filterTypeBox;
    Label* label10;
    Label* label26;
    ComboBox* osc2WaveBox;
    ComboBox* osc2OctaveBox;
    Label* label14;
    Label* label15;
    Label* label16;
    Slider* osc2lvlSlider;
    Label* label17;
    ComboBox* osc1WaveBox;
    ComboBox* osc1OctaveBox;
    Label* label18;
    Label* label19;
    Label* label20;
    
    vstSynthAudioProcessor* getProcessor() const
    {
        return static_cast <vstSynthAudioProcessor*> (getAudioProcessor());
    }


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    vstSynthAudioProcessorEditor (const vstSynthAudioProcessorEditor&);
    const vstSynthAudioProcessorEditor& operator= (const vstSynthAudioProcessorEditor&);
};


#endif   // __JUCER_HEADER_vstSynthAUDIOPROCESSOREDITOR_PLUGINEDITOR_11520947__
