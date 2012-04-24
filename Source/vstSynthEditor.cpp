/*
PluginEditor.cpp - synth interface generated from JUCE
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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "vstSynthProcessor.h"
#include "vstSynthEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]


//==============================================================================
vstSynthAudioProcessorEditor::vstSynthAudioProcessorEditor (vstSynthAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter),
      filterGroup (0),
      filterGainSlider (0),
      lfoGroup (0),
      lfoDevSlider (0),
      oscGroup (0),
      label21 (0),
      envelopeGroup (0),
      sustainSlider (0),
      osc1lvlSlider (0),
      delayGroup (0),
      delayFBSlider (0),
      delayGainSlider (0),
      outputGroup (0),
      label8 (0),
      decaySlider (0),
      attackSlider (0),
      delayTimeSlider (0),
      label (0),
      label2 (0),
      label3 (0),
      label4 (0),
      label5 (0),
      label6 (0),
      label7 (0),
      noiseSlider (0),
      driveSlider (0),
      outputGainSlider (0),
      label11 (0),
      label12 (0),
      label13 (0),
      releaseSlider (0),
      osc3WaveBox (0),
      osc3OctaveBox (0),
      label23 (0),
      label24 (0),
      label25 (0),
      label27 (0),
      label29 (0),
      filterFreqSlider (0),
      label31 (0),
      label32 (0),
      label33 (0),
      lfoFreqSlider (0),
      lfoWaveBox (0),
      lfoDestBox (0),
      label9 (0),
      osc3lvlSlider (0),
      filterResSlider (0),
      filterTypeBox (0),
      label10 (0),
      label26 (0),
      osc2WaveBox (0),
      osc2OctaveBox (0),
      label14 (0),
      label15 (0),
      label16 (0),
      osc2lvlSlider (0),
      label17 (0),
      osc1WaveBox (0),
      osc1OctaveBox (0),
      label18 (0),
      label19 (0),
      label20 (0)
{
    addAndMakeVisible (filterGroup = new GroupComponent (L"new group",
                                                         L"Filter"));
    filterGroup->setColour (GroupComponent::outlineColourId, Colour (0x88c6159a));
    filterGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (filterGainSlider = new Slider (L"new slider"));
    filterGainSlider->setRange (0.0001, 10, 0.001);
    filterGainSlider->setSliderStyle (Slider::Rotary);
    filterGainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    filterGainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc6159a));
    filterGainSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    filterGainSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    filterGainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    filterGainSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x1111ee));
    filterGainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    filterGainSlider->addListener (this);

    addAndMakeVisible (lfoGroup = new GroupComponent (L"new group",
                                                      L"LFO"));
    lfoGroup->setTextLabelPosition (Justification::centredLeft);
    lfoGroup->setColour (GroupComponent::outlineColourId, Colour (0x8874c615));
    lfoGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (lfoDevSlider = new Slider (L"new slider"));
    lfoDevSlider->setRange (0, 10, 0.1);
    lfoDevSlider->setSliderStyle (Slider::Rotary);
    lfoDevSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    lfoDevSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff74c615));
    lfoDevSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    lfoDevSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    lfoDevSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    lfoDevSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    lfoDevSlider->addListener (this);

    addAndMakeVisible (oscGroup = new GroupComponent (L"new group",
                                                      L"Oscillators"));
    oscGroup->setColour (GroupComponent::outlineColourId, Colour (0x88c67e15));
    oscGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (label21 = new Label (L"new label",
                                            L"Oscillator 1"));
    label21->setFont (Font (15.0000f, Font::bold));
    label21->setJustificationType (Justification::centred);
    label21->setEditable (false, false, false);
    label21->setColour (Label::textColourId, Colours::white);
    label21->setColour (TextEditor::textColourId, Colours::black);
    label21->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (envelopeGroup = new GroupComponent (L"new group",
                                                           L"Envelope"));
    envelopeGroup->setColour (GroupComponent::outlineColourId, Colour (0x88158ec6));
    envelopeGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (sustainSlider = new Slider (L"new slider"));
    sustainSlider->setRange (0, 10, 0.1);
    sustainSlider->setSliderStyle (Slider::Rotary);
    sustainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    sustainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    sustainSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    sustainSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    sustainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    sustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    sustainSlider->addListener (this);

    addAndMakeVisible (osc1lvlSlider = new Slider (L"new slider"));
    osc1lvlSlider->setRange (1, 10, 0.1);
    osc1lvlSlider->setSliderStyle (Slider::Rotary);
    osc1lvlSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    osc1lvlSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc67e15));
    osc1lvlSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    osc1lvlSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    osc1lvlSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    osc1lvlSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    osc1lvlSlider->addListener (this);

    addAndMakeVisible (delayGroup = new GroupComponent (L"new group",
                                                        L"Delay"));
    delayGroup->setColour (GroupComponent::outlineColourId, Colour (0x88c1b115));
    delayGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (delayFBSlider = new Slider (L"new slider"));
    delayFBSlider->setRange (1, 10, 0.1);
    delayFBSlider->setSliderStyle (Slider::Rotary);
    delayFBSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    delayFBSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc1b115));
    delayFBSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    delayFBSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    delayFBSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfaf7f7));
    delayFBSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    delayFBSlider->addListener (this);

    addAndMakeVisible (delayGainSlider = new Slider (L"new slider"));
    delayGainSlider->setRange (1, 10, 0.1);
    delayGainSlider->setSliderStyle (Slider::Rotary);
    delayGainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    delayGainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc1b115));
    delayGainSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    delayGainSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    delayGainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    delayGainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    delayGainSlider->addListener (this);

    addAndMakeVisible (outputGroup = new GroupComponent (L"new group",
                                                         L"Output"));
    outputGroup->setColour (GroupComponent::outlineColourId, Colour (0x88c61515));
    outputGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (label8 = new Label (L"new label",
                                           L"Destination"));
    label8->setFont (Font (15.0000f, Font::plain));
    label8->setJustificationType (Justification::centredRight);
    label8->setEditable (false, false, false);
    label8->setColour (Label::backgroundColourId, Colour (0xb70101));
    label8->setColour (Label::textColourId, Colours::white);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (decaySlider = new Slider (L"new slider"));
    decaySlider->setRange (0, 10, 0.1);
    decaySlider->setSliderStyle (Slider::Rotary);
    decaySlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    decaySlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    decaySlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    decaySlider->setColour (Slider::textBoxTextColourId, Colours::white);
    decaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    decaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    decaySlider->addListener (this);

    addAndMakeVisible (attackSlider = new Slider (L"new slider"));
    attackSlider->setRange (0, 10, 0.1);
    attackSlider->setSliderStyle (Slider::Rotary);
    attackSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    attackSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    attackSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    attackSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    attackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    attackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    attackSlider->addListener (this);

    addAndMakeVisible (delayTimeSlider = new Slider (L"new slider"));
    delayTimeSlider->setRange (0, 44100, 1);
    delayTimeSlider->setSliderStyle (Slider::Rotary);
    delayTimeSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    delayTimeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc1b115));
    delayTimeSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    delayTimeSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    delayTimeSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    delayTimeSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    delayTimeSlider->addListener (this);

    addAndMakeVisible (label = new Label (L"new label",
                                          L"Attack"));
    label->setFont (Font (15.0000f, Font::bold));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (L"new label",
                                           L"Sustain"));
    label2->setFont (Font (15.0000f, Font::bold));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label3 = new Label (L"new label",
                                           L"Decay"));
    label3->setFont (Font (15.0000f, Font::bold));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::white);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label4 = new Label (L"new label",
                                           L"Release"));
    label4->setFont (Font (15.0000f, Font::bold));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colours::white);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label5 = new Label (L"new label",
                                           L"Feedback"));
    label5->setFont (Font (15.0000f, Font::bold));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colours::white);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label6 = new Label (L"new label",
                                           L"Gain"));
    label6->setFont (Font (15.0000f, Font::bold));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colours::white);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label7 = new Label (L"new label",
                                           L"Time"));
    label7->setFont (Font (15.0000f, Font::bold));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colours::white);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (noiseSlider = new Slider (L"new slider"));
    noiseSlider->setRange (1, 10, 0.1);
    noiseSlider->setSliderStyle (Slider::Rotary);
    noiseSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    noiseSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc61515));
    noiseSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    noiseSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    noiseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    noiseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    noiseSlider->addListener (this);

    addAndMakeVisible (driveSlider = new Slider (L"new slider"));
    driveSlider->setRange (1, 5, 0.05);
    driveSlider->setSliderStyle (Slider::Rotary);
    driveSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    driveSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc61515));
    driveSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    driveSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    driveSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xc61515));
    driveSlider->setColour (Slider::textBoxOutlineColourId, Colour (0xc61515));
    driveSlider->addListener (this);

    addAndMakeVisible (outputGainSlider = new Slider (L"new slider"));
    outputGainSlider->setRange (1, 10, 0.1);
    outputGainSlider->setSliderStyle (Slider::Rotary);
    outputGainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    outputGainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc61515));
    outputGainSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    outputGainSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    outputGainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    outputGainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    outputGainSlider->addListener (this);

    addAndMakeVisible (label11 = new Label (L"new label",
                                            L"Gain"));
    label11->setFont (Font (15.0000f, Font::bold));
    label11->setJustificationType (Justification::centred);
    label11->setEditable (false, false, false);
    label11->setColour (Label::textColourId, Colours::white);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label12 = new Label (L"new label",
                                            L"Drive"));
    label12->setFont (Font (15.0000f, Font::bold));
    label12->setJustificationType (Justification::centred);
    label12->setEditable (false, false, false);
    label12->setColour (Label::textColourId, Colours::white);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label13 = new Label (L"new label",
                                            L"Noise"));
    label13->setFont (Font (15.0000f, Font::bold));
    label13->setJustificationType (Justification::centred);
    label13->setEditable (false, false, false);
    label13->setColour (Label::textColourId, Colours::white);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (releaseSlider = new Slider (L"new slider"));
    releaseSlider->setRange (0, 10, 0.1);
    releaseSlider->setSliderStyle (Slider::Rotary);
    releaseSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    releaseSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    releaseSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    releaseSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    releaseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    releaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    releaseSlider->addListener (this);

    addAndMakeVisible (osc3WaveBox = new ComboBox (L"new combo box"));
    osc3WaveBox->setEditableText (false);
    osc3WaveBox->setJustificationType (Justification::centredLeft);
    osc3WaveBox->setTextWhenNothingSelected (String::empty);
    osc3WaveBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    osc3WaveBox->addItem (L"Sine", 1);
    osc3WaveBox->addItem (L"Saw", 2);
    osc3WaveBox->addItem (L"Square", 3);
    osc3WaveBox->addListener (this);

    addAndMakeVisible (osc3OctaveBox = new ComboBox (L"new combo box"));
    osc3OctaveBox->setEditableText (false);
    osc3OctaveBox->setJustificationType (Justification::centredLeft);
    osc3OctaveBox->setTextWhenNothingSelected (String::empty);
    osc3OctaveBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    osc3OctaveBox->addItem (L"1", 1);
    osc3OctaveBox->addItem (L"2", 2);
    osc3OctaveBox->addItem (L"3", 3);
    osc3OctaveBox->addItem (L"4", 4);
    osc3OctaveBox->addListener (this);

    addAndMakeVisible (label23 = new Label (L"new label",
                                            L"Octave"));
    label23->setFont (Font (15.0000f, Font::plain));
    label23->setJustificationType (Justification::centredRight);
    label23->setEditable (false, false, false);
    label23->setColour (Label::textColourId, Colours::white);
    label23->setColour (TextEditor::textColourId, Colours::black);
    label23->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label24 = new Label (L"new label",
                                            L"Waveform"));
    label24->setFont (Font (15.0000f, Font::plain));
    label24->setJustificationType (Justification::centredRight);
    label24->setEditable (false, false, false);
    label24->setColour (Label::textColourId, Colours::white);
    label24->setColour (TextEditor::textColourId, Colours::black);
    label24->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label25 = new Label (L"new label",
                                            L"Level"));
    label25->setFont (Font (15.0000f, Font::bold));
    label25->setJustificationType (Justification::centred);
    label25->setEditable (false, false, false);
    label25->setColour (Label::textColourId, Colours::white);
    label25->setColour (TextEditor::textColourId, Colours::black);
    label25->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label27 = new Label (L"new label",
                                            L"Frequency"));
    label27->setFont (Font (15.0000f, Font::bold));
    label27->setJustificationType (Justification::centred);
    label27->setEditable (false, false, false);
    label27->setColour (Label::textColourId, Colours::white);
    label27->setColour (TextEditor::textColourId, Colours::black);
    label27->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label29 = new Label (L"new label",
                                            L"Deviation"));
    label29->setFont (Font (15.0000f, Font::bold));
    label29->setJustificationType (Justification::centred);
    label29->setEditable (false, false, false);
    label29->setColour (Label::textColourId, Colours::white);
    label29->setColour (TextEditor::textColourId, Colours::black);
    label29->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (filterFreqSlider = new Slider (L"new slider"));
    filterFreqSlider->setRange (0.00, 0.50, 0.00001);
    filterFreqSlider->setSliderStyle (Slider::Rotary);
    filterFreqSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    filterFreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc6159a));
    filterFreqSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    filterFreqSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    filterFreqSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    filterFreqSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    filterFreqSlider->addListener (this);

    addAndMakeVisible (label31 = new Label (L"new label",
                                            L"Resonance"));
    label31->setFont (Font (15.0000f, Font::bold));
    label31->setJustificationType (Justification::centred);
    label31->setEditable (false, false, false);
    label31->setColour (Label::textColourId, Colours::white);
    label31->setColour (TextEditor::textColourId, Colours::black);
    label31->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label32 = new Label (L"new label",
                                            L"Frequency"));
    label32->setFont (Font (15.0000f, Font::bold));
    label32->setJustificationType (Justification::centred);
    label32->setEditable (false, false, false);
    label32->setColour (Label::textColourId, Colours::white);
    label32->setColour (TextEditor::textColourId, Colours::black);
    label32->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label33 = new Label (L"new label",
                                            L"Gain"));
    label33->setFont (Font (15.0000f, Font::bold));
    label33->setJustificationType (Justification::centred);
    label33->setEditable (false, false, false);
    label33->setColour (Label::textColourId, Colours::white);
    label33->setColour (TextEditor::textColourId, Colours::black);
    label33->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (lfoFreqSlider = new Slider (L"new slider"));
    lfoFreqSlider->setRange (0, 10, 0.1);
    lfoFreqSlider->setSliderStyle (Slider::Rotary);
    lfoFreqSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    lfoFreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff74c615));
    lfoFreqSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    lfoFreqSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    lfoFreqSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    lfoFreqSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    lfoFreqSlider->addListener (this);

    addAndMakeVisible (lfoWaveBox = new ComboBox (L"new combo box"));
    lfoWaveBox->setEditableText (false);
    lfoWaveBox->setJustificationType (Justification::centredLeft);
    lfoWaveBox->setTextWhenNothingSelected (String::empty);
    lfoWaveBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    lfoWaveBox->addItem (L"Sine", 1);
    lfoWaveBox->addItem (L"Saw", 2);
    lfoWaveBox->addItem (L"Square", 3);
    lfoWaveBox->addListener (this);

    addAndMakeVisible (lfoDestBox = new ComboBox (L"new combo box"));
    lfoDestBox->setEditableText (false);
    lfoDestBox->setJustificationType (Justification::centredLeft);
    lfoDestBox->setTextWhenNothingSelected (String::empty);
    lfoDestBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    lfoDestBox->addItem (L"Off", 1);
    lfoDestBox->addItem (L"Vibrato", 2);
    lfoDestBox->addItem (L"Tremolo", 3);
    lfoDestBox->addItem (L"Envelope", 4);
    lfoDestBox->addListener (this);

    addAndMakeVisible (label9 = new Label (L"new label",
                                           L"Waveform"));
    label9->setFont (Font (15.0000f, Font::plain));
    label9->setJustificationType (Justification::centredRight);
    label9->setEditable (false, false, false);
    label9->setColour (Label::textColourId, Colours::white);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (osc3lvlSlider = new Slider (L"new slider"));
    osc3lvlSlider->setRange (1, 10, 0.1);
    osc3lvlSlider->setSliderStyle (Slider::Rotary);
    osc3lvlSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    osc3lvlSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc67e15));
    osc3lvlSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    osc3lvlSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    osc3lvlSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    osc3lvlSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808000));
    osc3lvlSlider->addListener (this);

    addAndMakeVisible (filterResSlider = new Slider (L"new slider"));
    filterResSlider->setRange (1, 100, 0.1);
    filterResSlider->setSliderStyle (Slider::Rotary);
    filterResSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    filterResSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc6159a));
    filterResSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    filterResSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    filterResSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    filterResSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    filterResSlider->addListener (this);

    addAndMakeVisible (filterTypeBox = new ComboBox (L"new combo box"));
    filterTypeBox->setEditableText (false);
    filterTypeBox->setJustificationType (Justification::centredLeft);
    filterTypeBox->setTextWhenNothingSelected (String::empty);
    filterTypeBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    filterTypeBox->addItem (L"Low Pass", 1);
    filterTypeBox->addItem (L"Band Pass", 2);
    filterTypeBox->addItem (L"High Pass", 3);
    filterTypeBox->addListener (this);

    addAndMakeVisible (label10 = new Label (L"new label",
                                            L"Type"));
    label10->setFont (Font (15.0000f, Font::plain));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (Label::textColourId, Colours::white);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label26 = new Label (L"new label",
                                            L"Oscillator 3"));
    label26->setFont (Font (15.0000f, Font::bold));
    label26->setJustificationType (Justification::centred);
    label26->setEditable (false, false, false);
    label26->setColour (Label::textColourId, Colours::white);
    label26->setColour (TextEditor::textColourId, Colours::black);
    label26->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (osc2WaveBox = new ComboBox (L"new combo box"));
    osc2WaveBox->setEditableText (false);
    osc2WaveBox->setJustificationType (Justification::centredLeft);
    osc2WaveBox->setTextWhenNothingSelected (String::empty);
    osc2WaveBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    osc2WaveBox->addItem (L"Sine", 1);
    osc2WaveBox->addItem (L"Saw", 2);
    osc2WaveBox->addItem (L"Square", 3);
    osc2WaveBox->addListener (this);

    addAndMakeVisible (osc2OctaveBox = new ComboBox (L"new combo box"));
    osc2OctaveBox->setEditableText (false);
    osc2OctaveBox->setJustificationType (Justification::centredLeft);
    osc2OctaveBox->setTextWhenNothingSelected (String::empty);
    osc2OctaveBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    osc2OctaveBox->addItem (L"1", 1);
    osc2OctaveBox->addItem (L"2", 2);
    osc2OctaveBox->addItem (L"3", 3);
    osc2OctaveBox->addItem (L"4", 4);
    osc2OctaveBox->addListener (this);

    addAndMakeVisible (label14 = new Label (L"new label",
                                            L"Octave"));
    label14->setFont (Font (15.0000f, Font::plain));
    label14->setJustificationType (Justification::centredRight);
    label14->setEditable (false, false, false);
    label14->setColour (Label::textColourId, Colours::white);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label15 = new Label (L"new label",
                                            L"Waveform"));
    label15->setFont (Font (15.0000f, Font::plain));
    label15->setJustificationType (Justification::centredRight);
    label15->setEditable (false, false, false);
    label15->setColour (Label::textColourId, Colours::white);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label16 = new Label (L"new label",
                                            L"Level"));
    label16->setFont (Font (15.0000f, Font::bold));
    label16->setJustificationType (Justification::centred);
    label16->setEditable (false, false, false);
    label16->setColour (Label::textColourId, Colours::white);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (osc2lvlSlider = new Slider (L"new slider"));
    osc2lvlSlider->setRange (1, 10, 0.1);
    osc2lvlSlider->setSliderStyle (Slider::Rotary);
    osc2lvlSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 20);
    osc2lvlSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc67e15));
    osc2lvlSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::grey);
    osc2lvlSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    osc2lvlSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    osc2lvlSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    osc2lvlSlider->addListener (this);

    addAndMakeVisible (label17 = new Label (L"new label",
                                            L"Oscillator 2"));
    label17->setFont (Font (15.0000f, Font::bold));
    label17->setJustificationType (Justification::centred);
    label17->setEditable (false, false, false);
    label17->setColour (Label::textColourId, Colours::white);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (osc1WaveBox = new ComboBox (L"new combo box"));
    osc1WaveBox->setEditableText (false);
    osc1WaveBox->setJustificationType (Justification::centredLeft);
    osc1WaveBox->setTextWhenNothingSelected (String::empty);
    osc1WaveBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    osc1WaveBox->addItem (L"Sine", 1);
    osc1WaveBox->addItem (L"Saw", 2);
    osc1WaveBox->addItem (L"Square", 3);
    osc1WaveBox->addListener (this);

    addAndMakeVisible (osc1OctaveBox = new ComboBox (L"new combo box"));
    osc1OctaveBox->setEditableText (false);
    osc1OctaveBox->setJustificationType (Justification::centredLeft);
    osc1OctaveBox->setTextWhenNothingSelected (String::empty);
    osc1OctaveBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    osc1OctaveBox->addItem (L"1", 1);
    osc1OctaveBox->addItem (L"2", 2);
    osc1OctaveBox->addItem (L"3", 3);
    osc1OctaveBox->addItem (L"4", 4);
    osc1OctaveBox->addListener (this);

    addAndMakeVisible (label18 = new Label (L"new label",
                                            L"Octave"));
    label18->setFont (Font (15.0000f, Font::plain));
    label18->setJustificationType (Justification::centredRight);
    label18->setEditable (false, false, false);
    label18->setColour (Label::textColourId, Colours::white);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label19 = new Label (L"new label",
                                            L"Waveform"));
    label19->setFont (Font (15.0000f, Font::plain));
    label19->setJustificationType (Justification::centredRight);
    label19->setEditable (false, false, false);
    label19->setColour (Label::textColourId, Colours::white);
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label20 = new Label (L"new label",
                                            L"Level"));
    label20->setFont (Font (15.0000f, Font::bold));
    label20->setJustificationType (Justification::centred);
    label20->setEditable (false, false, false);
    label20->setColour (Label::textColourId, Colours::white);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x0));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 328);


    //[Constructor] You can add your own custom stuff here..
//	startTimer(50);

	vstSynthAudioProcessor* ourProcessor = getProcessor();

	osc1WaveBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::osc1WaveParam), false);
	osc2WaveBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::osc2WaveParam), false);
	osc3WaveBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::osc3WaveParam), false);

	osc1OctaveBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::osc1OctaveParam), false);
	osc2OctaveBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::osc2OctaveParam), false);
	osc3OctaveBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::osc3OctaveParam), false);
    
	osc1lvlSlider->setValue(pow(10, ourProcessor->getParameter(vstSynthAudioProcessor::osc1LevelParam)), false); //log
	osc2lvlSlider->setValue(pow(10, ourProcessor->getParameter(vstSynthAudioProcessor::osc2LevelParam)), false); //log
	osc3lvlSlider->setValue(pow(10, ourProcessor->getParameter(vstSynthAudioProcessor::osc3LevelParam)), false); //log
    
	noiseSlider->setValue(pow(10, ourProcessor->getParameter(vstSynthAudioProcessor::noiseParam)), false); //log

    attackSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::attackParam), false);
	decaySlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::decayParam), false);
	sustainSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::sustainParam), false);
	releaseSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::releaseParam), false);

	lfoDestBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::lfoDestParam), false);
	lfoWaveBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::lfoWaveParam), false);
	lfoFreqSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::lfoFreqParam), false);
	lfoDevSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::lfoDevParam), false);
    
	filterTypeBox->setSelectedItemIndex (ourProcessor->getParameter(vstSynthAudioProcessor::filterTypeParam), false);
	filterFreqSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::filterCutoffParam), false);
	filterResSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::filterResonanceParam), false);
	filterGainSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::filterGainParam), false);
    
	delayTimeSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::delayTimeParam), false);
	delayFBSlider->setValue(pow(10, ourProcessor->getParameter(vstSynthAudioProcessor::delayFeedbackParam)), false); //log
	delayGainSlider->setValue(pow(10, ourProcessor->getParameter(vstSynthAudioProcessor::delayGainParam)), false); //log
    
	driveSlider->setValue(ourProcessor->getParameter(vstSynthAudioProcessor::driveParam), false);
	outputGainSlider->setValue(pow(10, ourProcessor->getParameter(vstSynthAudioProcessor::outputGainParam)), false); //log

    //[/Constructor]
}

vstSynthAudioProcessorEditor::~vstSynthAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (filterGroup);
    deleteAndZero (filterGainSlider);
    deleteAndZero (lfoGroup);
    deleteAndZero (lfoDevSlider);
    deleteAndZero (oscGroup);
    deleteAndZero (label21);
    deleteAndZero (envelopeGroup);
    deleteAndZero (sustainSlider);
    deleteAndZero (osc1lvlSlider);
    deleteAndZero (delayGroup);
    deleteAndZero (delayFBSlider);
    deleteAndZero (delayGainSlider);
    deleteAndZero (outputGroup);
    deleteAndZero (label8);
    deleteAndZero (decaySlider);
    deleteAndZero (attackSlider);
    deleteAndZero (delayTimeSlider);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (label3);
    deleteAndZero (label4);
    deleteAndZero (label5);
    deleteAndZero (label6);
    deleteAndZero (label7);
    deleteAndZero (noiseSlider);
    deleteAndZero (driveSlider);
    deleteAndZero (outputGainSlider);
    deleteAndZero (label11);
    deleteAndZero (label12);
    deleteAndZero (label13);
    deleteAndZero (releaseSlider);
    deleteAndZero (osc3WaveBox);
    deleteAndZero (osc3OctaveBox);
    deleteAndZero (label23);
    deleteAndZero (label24);
    deleteAndZero (label25);
    deleteAndZero (label27);
    deleteAndZero (label29);
    deleteAndZero (filterFreqSlider);
    deleteAndZero (label31);
    deleteAndZero (label32);
    deleteAndZero (label33);
    deleteAndZero (lfoFreqSlider);
    deleteAndZero (lfoWaveBox);
    deleteAndZero (lfoDestBox);
    deleteAndZero (label9);
    deleteAndZero (osc3lvlSlider);
    deleteAndZero (filterResSlider);
    deleteAndZero (filterTypeBox);
    deleteAndZero (label10);
    deleteAndZero (label26);
    deleteAndZero (osc2WaveBox);
    deleteAndZero (osc2OctaveBox);
    deleteAndZero (label14);
    deleteAndZero (label15);
    deleteAndZero (label16);
    deleteAndZero (osc2lvlSlider);
    deleteAndZero (label17);
    deleteAndZero (osc1WaveBox);
    deleteAndZero (osc1OctaveBox);
    deleteAndZero (label18);
    deleteAndZero (label19);
    deleteAndZero (label20);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void vstSynthAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff131a26));

    g.setColour (Colour (0x22c1b115));
    g.fillRoundedRectangle (624.0f, 18.0f, 72.0f, 98.0f, 10.0000f);

    g.setColour (Colour (0x22c67e15));
    g.fillRoundedRectangle (14.0f, 18.0f, 238.0f, 98.0f, 10.0000f);

    g.setColour (Colour (0x22c67e15));
    g.fillRoundedRectangle (14.0f, 118.0f, 238.0f, 98.0f, 10.0000f);

    g.setColour (Colour (0x22c67e15));
    g.fillRoundedRectangle (14.0f, 218.0f, 238.0f, 98.0f, 10.0000f);

    g.setColour (Colour (0x22158ec6));
    g.fillRoundedRectangle (270.0f, 18.0f, 336.0f, 84.0f, 10.0000f);

    g.setColour (Colour (0x2274c615));
    g.fillRoundedRectangle (270.0f, 124.0f, 336.0f, 85.0f, 10.0000f);

    g.setColour (Colour (0x22c6159a));
    g.fillRoundedRectangle (270.0f, 230.0f, 336.0f, 85.0f, 10.0000f);

    g.setColour (Colour (0x22c61515));
    g.fillRoundedRectangle (714.0f, 18.0f, 72.0f, 98.0f, 10.0000f);

    g.setColour (Colour (0x22c61515));
    g.fillRoundedRectangle (714.0f, 118.0f, 72.0f, 98.0f, 10.0000f);

    g.setColour (Colour (0x22c61515));
    g.fillRoundedRectangle (714.0f, 218.0f, 72.0f, 98.0f, 10.0000f);

    g.setColour (Colour (0x22c1b115));
    g.fillRoundedRectangle (624.0f, 218.0f, 72.0f, 98.0f, 10.0000f);

    g.setColour (Colour (0x22c1b115));
    g.fillRoundedRectangle (624.0f, 118.0f, 72.0f, 98.0f, 10.0000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void vstSynthAudioProcessorEditor::resized()
{
    filterGroup->setBounds (262, 215, 352, 109);
    filterGainSlider->setBounds (540, 240, 60, 80);
    lfoGroup->setBounds (262, 109, 352, 108);
    lfoDevSlider->setBounds (540, 134, 60, 80);
    oscGroup->setBounds (6, 2, 254, 322);
    label21->setBounds (15, 20, 235, 20);
    envelopeGroup->setBounds (262, 2, 352, 108);
    sustainSlider->setBounds (460, 28, 60, 80);
    osc1lvlSlider->setBounds (190, 35, 60, 80);
    delayGroup->setBounds (616, 2, 88, 322);
    delayFBSlider->setBounds (632, 235, 60, 80);
    delayGainSlider->setBounds (632, 135, 60, 80);
    outputGroup->setBounds (706, 2, 88, 322);
    label8->setBounds (268, 144, 80, 20);
    decaySlider->setBounds (380, 28, 60, 80);
    attackSlider->setBounds (300, 28, 60, 80);
    delayTimeSlider->setBounds (630, 35, 60, 80);
    label->setBounds (286, 14, 88, 20);
    label2->setBounds (446, 14, 88, 20);
    label3->setBounds (366, 14, 88, 20);
    label4->setBounds (526, 14, 88, 20);
    label5->setBounds (616, 220, 88, 20);
    label6->setBounds (616, 120, 88, 20);
    label7->setBounds (616, 20, 88, 20);
    noiseSlider->setBounds (720, 35, 60, 80);
    driveSlider->setBounds (720, 135, 60, 80);
    outputGainSlider->setBounds (720, 235, 60, 80);
    label11->setBounds (706, 220, 88, 20);
    label12->setBounds (706, 120, 88, 20);
    label13->setBounds (706, 20, 88, 20);
    releaseSlider->setBounds (540, 28, 60, 80);
    osc3WaveBox->setBounds (90, 245, 90, 20);
    osc3OctaveBox->setBounds (90, 280, 90, 20);
    label23->setBounds (10, 280, 80, 20);
    label24->setBounds (10, 245, 80, 20);
    label25->setBounds (190, 220, 60, 20);
    label27->setBounds (446, 120, 88, 20);
    label29->setBounds (526, 120, 88, 20);
    filterFreqSlider->setBounds (380, 240, 60, 80);
    label31->setBounds (446, 226, 88, 20);
    label32->setBounds (366, 226, 88, 20);
    label33->setBounds (526, 226, 88, 20);
    lfoFreqSlider->setBounds (460, 134, 60, 80);
    lfoWaveBox->setBounds (350, 179, 90, 20);
    lfoDestBox->setBounds (350, 144, 90, 20);
    label9->setBounds (268, 179, 80, 20);
    osc3lvlSlider->setBounds (190, 235, 60, 80);
    filterResSlider->setBounds (460, 240, 60, 80);
    filterTypeBox->setBounds (278, 270, 90, 20);
    label10->setBounds (278, 245, 88, 24);
    label26->setBounds (15, 220, 235, 20);
    osc2WaveBox->setBounds (90, 145, 90, 20);
    osc2OctaveBox->setBounds (90, 180, 90, 20);
    label14->setBounds (10, 180, 80, 20);
    label15->setBounds (10, 145, 80, 20);
    label16->setBounds (190, 120, 60, 20);
    osc2lvlSlider->setBounds (190, 135, 60, 80);
    label17->setBounds (15, 120, 235, 20);
    osc1WaveBox->setBounds (90, 45, 90, 20);
    osc1OctaveBox->setBounds (90, 80, 90, 20);
    label18->setBounds (10, 80, 80, 20);
    label19->setBounds (10, 45, 80, 20);
    label20->setBounds (190, 20, 60, 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

//void vstSynthAudioProcessorEditor::timerCallback()
//{
//	vstSynthAudioProcessor* ourProcessor = getProcessor();
//
//	osc1WaveBox->setSelectedItemIndex (ourProcessor->osc1Wave, false);
//	osc2WaveBox->setSelectedItemIndex (ourProcessor->osc2Wave, false);
//	osc3WaveBox->setSelectedItemIndex (ourProcessor->osc3Wave, false);
//
//	osc1OctaveBox->setSelectedItemIndex (ourProcessor->osc1Octave, false);
//	osc2OctaveBox->setSelectedItemIndex (ourProcessor->osc2Octave, false);
//	osc3OctaveBox->setSelectedItemIndex (ourProcessor->osc3Octave, false);
//
//	osc1lvlSlider->setValue (ourProcessor->osc1Level, false);
//	osc2lvlSlider->setValue (ourProcessor->osc2Level, false);
//	osc3lvlSlider->setValue (ourProcessor->osc3Level, false);
//}

void vstSynthAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]
    
	// Oscillators =========================
    if (sliderThatWasMoved == osc1lvlSlider)
    {
        //[UserSliderCode_osc1lvlSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::osc1LevelParam, (float) log10(osc1lvlSlider->getValue()));
        //[/UserSliderCode_osc1lvlSlider]
    }
    else if (sliderThatWasMoved == osc2lvlSlider)
    {
        //[UserSliderCode_osc2lvlSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::osc2LevelParam, (float) log10(osc2lvlSlider->getValue()));
        //[/UserSliderCode_osc2lvlSlider]
    }
    else if (sliderThatWasMoved == osc3lvlSlider)
    {
        //[UserSliderCode_osc3lvlSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::osc3LevelParam, (float) log10(osc3lvlSlider->getValue()));
        //[/UserSliderCode_osc3lvlSlider]
    }
    
	// LFO =====================================
    else if (sliderThatWasMoved == lfoDevSlider)
    {
        //[UserSliderCode_lfoDevSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::lfoDevParam, (float) lfoDevSlider->getValue());
        //[/UserSliderCode_lfoDevSlider]
    }
    else if (sliderThatWasMoved == lfoFreqSlider)
    {
        //[UserSliderCode_lfoFreqSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::lfoFreqParam, (float) lfoFreqSlider->getValue());
        //[/UserSliderCode_lfoFreqSlider]
    }
    
	// Noise ==================================
    else if (sliderThatWasMoved == noiseSlider) 
    {
        //[UserSliderCode_noiseSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::noiseParam, 0.001 * log10((float) noiseSlider->getValue()));
        //[/UserSliderCode_noiseSlider]
    }
    
	// Envelope =================================
    else if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::attackParam, (float) attackSlider->getValue());
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == sustainSlider)
    {
        //[UserSliderCode_sustainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::sustainParam, (float) sustainSlider->getValue());
        //[/UserSliderCode_sustainSlider]
    }
    else if (sliderThatWasMoved == decaySlider)
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::decayParam, (float) decaySlider->getValue());
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == releaseSlider)
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::releaseParam, (float) releaseSlider->getValue());
        //[/UserSliderCode_releaseSlider]
    }
    
	// Filter ======================================
    else if (sliderThatWasMoved == filterGainSlider)
    {
        //[UserSliderCode_filterGainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::filterGainParam, (float) filterGainSlider->getValue());
		getProcessor()->hpeqFilter.setGain(getProcessor()->getParameter(vstSynthAudioProcessor::filterGainParam));
        //[/UserSliderCode_filterGainSlider]
    }
    else if (sliderThatWasMoved == filterFreqSlider)
    {
        //[UserSliderCode_filterFreqSlider] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::filterCutoffParam, (float) filterFreqSlider->getValue());
		getProcessor()->hpeqFilter.setFrequency(getProcessor()->getParameter(vstSynthAudioProcessor::filterCutoffParam));
        //[/UserSliderCode_filterFreqSlider]
    }
    else if (sliderThatWasMoved == filterResSlider)
    {
        //[UserSliderCode_filterResSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::filterResonanceParam, (float) filterResSlider->getValue());
        getProcessor()->hpeqFilter.setResonance(getProcessor()->getParameter(vstSynthAudioProcessor::filterResonanceParam));
        //[/UserSliderCode_filterResSlider]
    }
    
	// Delay ======================================
    else if (sliderThatWasMoved == delayFBSlider)
    {
        //[UserSliderCode_delayFBSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::delayFeedbackParam, (float) log10(delayFBSlider->getValue()));
        //[/UserSliderCode_delayFBSlider]
    }
    else if (sliderThatWasMoved == delayGainSlider)
    {
        //[UserSliderCode_delayGainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::delayGainParam, (float) log10(delayGainSlider->getValue()));
        //[/UserSliderCode_delayGainSlider]
    }
    
	else if (sliderThatWasMoved == delayTimeSlider)
    {
        //[UserSliderCode_delayTimeSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::delayTimeParam, (float) delayTimeSlider->getValue());
        //[/UserSliderCode_delayTimeSlider]
    }
    
	// Output =====================================
    else if (sliderThatWasMoved == driveSlider)
    {
        //[UserSliderCode_driveSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::driveParam, (float) driveSlider->getValue());
        //[/UserSliderCode_driveSlider]
    }
    else if (sliderThatWasMoved == outputGainSlider)
    {
        //[UserSliderCode_outputGainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (vstSynthAudioProcessor::outputGainParam, log10((float) outputGainSlider->getValue()));
        //[/UserSliderCode_outputGainSlider]
    }
    
    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void vstSynthAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]
    
    // Oscillator 1 ===================
	if (comboBoxThatHasChanged == osc1WaveBox)
    {
        //[UserComboBoxCode_osc1WaveBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::osc1WaveParam, (float) osc1WaveBox->getSelectedItemIndex());

        //[/UserComboBoxCode_osc1WaveBox]
    }
    else if (comboBoxThatHasChanged == osc1OctaveBox)
    {
        //[UserComboBoxCode_osc1OctaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::osc1OctaveParam, (float) osc1OctaveBox->getSelectedItemIndex());

        //[/UserComboBoxCode_osc1OctaveBox]
    }    
    
    // Oscillator 2 ===================
    else if (comboBoxThatHasChanged == osc2WaveBox)
    {
        //[UserComboBoxCode_osc2WaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::osc2WaveParam, (float) osc2WaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc2WaveBox]
    }
    else if (comboBoxThatHasChanged == osc2OctaveBox)
    {
        //[UserComboBoxCode_osc2OctaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::osc2OctaveParam, (float) osc2OctaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc2OctaveBox]
    }
    
    // Oscillator 3 ===================
	else if (comboBoxThatHasChanged == osc3WaveBox)
    {
        //[UserComboBoxCode_osc3WaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::osc3WaveParam, (float) osc3WaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc3WaveBox]
    }
    else if (comboBoxThatHasChanged == osc3OctaveBox)
    {
        //[UserComboBoxCode_osc3OctaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::osc3OctaveParam, (float) osc3OctaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc3OctaveBox]
    }
	
	// LFO ==============================
    else if (comboBoxThatHasChanged == lfoWaveBox)
    {
        //[UserComboBoxCode_lfoWaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::lfoWaveParam, (float) lfoWaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_lfoWaveBox]
    }
    else if (comboBoxThatHasChanged == lfoDestBox)
    {
        //[UserComboBoxCode_lfoDestBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::lfoDestParam, (float) lfoDestBox->getSelectedItemIndex());
        //[/UserComboBoxCode_lfoDestBox]
    }
    
	// Filter Type
    else if (comboBoxThatHasChanged == filterTypeBox)
    {
        //[UserComboBoxCode_filterTypeBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(vstSynthAudioProcessor::filterTypeParam, (float) filterTypeBox->getSelectedItemIndex());
		getProcessor()->hpeqFilter.setType((int) getProcessor()->getParameter(vstSynthAudioProcessor::filterTypeParam));

        //[/UserComboBoxCode_filterTypeBox]
    }
    
    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="vstSynthAudioProcessorEditor"
                 componentName="" parentClasses="public Component" constructorParams="vstSynthAudioProcessor* ownerFilter"
                 variableInitialisers="AudioProcessorEditor (ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330000013" fixedSize="1"
                 initialWidth="800" initialHeight="328">
  <BACKGROUND backgroundColour="ff131a26">
    <ROUNDRECT pos="624 18 72 98" cornerSize="10" fill="solid: 22c1b115" hasStroke="0"/>
    <ROUNDRECT pos="14 18 238 98" cornerSize="10" fill="solid: 22c67e15" hasStroke="0"/>
    <ROUNDRECT pos="14 118 238 98" cornerSize="10" fill="solid: 22c67e15" hasStroke="0"/>
    <ROUNDRECT pos="14 218 238 98" cornerSize="10" fill="solid: 22c67e15" hasStroke="0"/>
    <ROUNDRECT pos="270 18 336 84" cornerSize="10" fill="solid: 22158ec6" hasStroke="0"/>
    <ROUNDRECT pos="270 124 336 85" cornerSize="10" fill="solid: 2274c615" hasStroke="0"/>
    <ROUNDRECT pos="270 230 336 85" cornerSize="10" fill="solid: 22c6159a" hasStroke="0"/>
    <ROUNDRECT pos="714 18 72 98" cornerSize="10" fill="solid: 22c61515" hasStroke="0"/>
    <ROUNDRECT pos="714 118 72 98" cornerSize="10" fill="solid: 22c61515" hasStroke="0"/>
    <ROUNDRECT pos="714 218 72 98" cornerSize="10" fill="solid: 22c61515" hasStroke="0"/>
    <ROUNDRECT pos="624 218 72 98" cornerSize="10" fill="solid: 22c1b115" hasStroke="0"/>
    <ROUNDRECT pos="624 118 72 98" cornerSize="10" fill="solid: 22c1b115" hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="ea3069c632e89929" memberName="filterGroup"
                  virtualName="" explicitFocusOrder="0" pos="262 215 352 109" outlinecol="88c6159a"
                  textcol="ffffffff" title="Filter"/>
  <SLIDER name="new slider" id="ec58c63b4ccff8af" memberName="filterGainSlider"
          virtualName="" explicitFocusOrder="0" pos="540 240 60 80" rotarysliderfill="ffc6159a"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxhighlight="1111ee" textboxoutline="808080" min="0" max="10"
          int="0.1" style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="new group" id="9a03f50615df1c9f" memberName="lfoGroup"
                  virtualName="" explicitFocusOrder="0" pos="262 109 352 108" outlinecol="8874c615"
                  textcol="ffffffff" title="LFO" textpos="33"/>
  <SLIDER name="new slider" id="9b2e1431fcd2f805" memberName="lfoDevSlider"
          virtualName="" explicitFocusOrder="0" pos="540 134 60 80" rotarysliderfill="ff74c615"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="100" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="new group" id="65a0feb597479c50" memberName="oscGroup"
                  virtualName="" explicitFocusOrder="0" pos="6 2 254 322" outlinecol="88c67e15"
                  textcol="ffffffff" title="Oscillators"/>
  <LABEL name="new label" id="55fd3e4f75cff325" memberName="label21" virtualName=""
         explicitFocusOrder="0" pos="15 20 235 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Oscillator 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <GROUPCOMPONENT name="new group" id="7ace822ca98bda71" memberName="envelopeGroup"
                  virtualName="" explicitFocusOrder="0" pos="262 2 352 108" outlinecol="88158ec6"
                  textcol="ffffffff" title="Envelope"/>
  <SLIDER name="new slider" id="8f89739b8fee464b" memberName="sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="460 28 60 80" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="fd2273ee05f26609" memberName="osc1lvlSlider"
          virtualName="" explicitFocusOrder="0" pos="190 35 60 80" rotarysliderfill="ffc67e15"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="new group" id="1ff1c17feeb8ec2a" memberName="delayGroup"
                  virtualName="" explicitFocusOrder="0" pos="616 2 88 322" outlinecol="88c1b115"
                  textcol="ffffffff" title="Delay"/>
  <SLIDER name="new slider" id="a75d50ad64e53127" memberName="delayFBSlider"
          virtualName="" explicitFocusOrder="0" pos="632 235 60 80" rotarysliderfill="ffc1b115"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="faf7f7"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="2b67fbd26d4a51e1" memberName="delayGainSlider"
          virtualName="" explicitFocusOrder="0" pos="632 135 60 80" rotarysliderfill="ffc1b115"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="new group" id="32ee0e26eb09be5a" memberName="outputGroup"
                  virtualName="" explicitFocusOrder="0" pos="706 2 88 322" outlinecol="88c61515"
                  textcol="ffffffff" title="Output"/>
  <LABEL name="new label" id="ee0c7e762e5270f5" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="268 144 80 20" bkgCol="b70101" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Destination" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="f5aabb99a95e5062" memberName="decaySlider"
          virtualName="" explicitFocusOrder="0" pos="380 28 60 80" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="95bb1bdea3cb3d24" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="300 28 60 80" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="d31354e1003f6da9" memberName="delayTimeSlider"
          virtualName="" explicitFocusOrder="0" pos="630 35 60 80" rotarysliderfill="ffc1b115"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="501a157c94ed15a8" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="286 14 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Attack" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="220b9859b66f7f8d" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="446 14 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Sustain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="dfcf9cca27e240f5" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="366 14 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Decay" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="bb0184db111ca28" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="526 14 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Release" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="c5b8dd30e3f72c57" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="616 220 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Feedback" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="33f990a20ca36ef7" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="616 120 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="efd42dad964489a3" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="616 20 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Time" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <SLIDER name="new slider" id="50603b8782394472" memberName="noiseSlider"
          virtualName="" explicitFocusOrder="0" pos="720 35 60 80" rotarysliderfill="ffc61515"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="bad6de7cc47b0108" memberName="driveSlider"
          virtualName="" explicitFocusOrder="0" pos="720 135 60 80" rotarysliderfill="ffc61515"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="c61515"
          textboxoutline="c61515" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="74d03ea84f25ef02" memberName="outputGainSlider"
          virtualName="" explicitFocusOrder="0" pos="720 235 60 80" rotarysliderfill="ffc61515"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="6f104a8e37375aa0" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="706 220 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="49c1ace250c4f8ee" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="706 120 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Drive" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="6b139137b8b0fd39" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="706 20 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Noise" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <SLIDER name="new slider" id="9dabcece093dca00" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="540 28 60 80" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="c37948d0c3bd9c5b" memberName="osc3WaveBox"
            virtualName="" explicitFocusOrder="0" pos="90 245 90 20" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="4ae71ef44644cda7" memberName="osc3OctaveBox"
            virtualName="" explicitFocusOrder="0" pos="90 280 90 20" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="912baf86a1a0ad06" memberName="label23" virtualName=""
         explicitFocusOrder="0" pos="10 280 80 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Octave" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="332fa9d8aa556539" memberName="label24" virtualName=""
         explicitFocusOrder="0" pos="10 245 80 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Waveform" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="9824114c301fcea0" memberName="label25" virtualName=""
         explicitFocusOrder="0" pos="190 220 60 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Level" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="43d19f5393ba8ba0" memberName="label27" virtualName=""
         explicitFocusOrder="0" pos="446 120 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Frequency" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="200d41631cc9ffa5" memberName="label29" virtualName=""
         explicitFocusOrder="0" pos="526 120 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Deviation" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <SLIDER name="new slider" id="c6e3b536dabbe181" memberName="filterFreqSlider"
          virtualName="" explicitFocusOrder="0" pos="380 240 60 80" rotarysliderfill="ffc6159a"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="dfbe4933e3b8ec07" memberName="label31" virtualName=""
         explicitFocusOrder="0" pos="446 226 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Resonance" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="ac6f6b11384ff2b" memberName="label32" virtualName=""
         explicitFocusOrder="0" pos="366 226 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Frequency" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="a0b29c1bc98035a1" memberName="label33" virtualName=""
         explicitFocusOrder="0" pos="526 226 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <SLIDER name="new slider" id="c40e18508b0c7437" memberName="lfoFreqSlider"
          virtualName="" explicitFocusOrder="0" pos="460 134 60 80" rotarysliderfill="ff74c615"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="9ef0d8a2b2849ba7" memberName="lfoWaveBox"
            virtualName="" explicitFocusOrder="0" pos="350 179 90 20" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="8eb3a72193ed6930" memberName="lfoDestBox"
            virtualName="" explicitFocusOrder="0" pos="350 144 90 20" editable="0"
            layout="33" items="Off&#10;Vibrato&#10;Tremolo&#10;Envelope"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="4995cb78101163ca" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="268 179 80 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Waveform" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="4c6a01a02cb62be7" memberName="osc3lvlSlider"
          virtualName="" explicitFocusOrder="0" pos="190 235 60 80" rotarysliderfill="ffc67e15"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808000" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="5809b2c616366c36" memberName="filterResSlider"
          virtualName="" explicitFocusOrder="0" pos="460 240 60 80" rotarysliderfill="ffc6159a"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="a6246f5792d2062f" memberName="filterTypeBox"
            virtualName="" explicitFocusOrder="0" pos="278 270 90 20" editable="0"
            layout="33" items="Low Pass&#10;Band Pass&#10;High Pass" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="3c636708a43de103" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="278 245 88 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Type" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8eb30b7b5e9d77bd" memberName="label26" virtualName=""
         explicitFocusOrder="0" pos="15 220 235 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Oscillator 3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="new combo box" id="5c54f1a8a395239b" memberName="osc2WaveBox"
            virtualName="" explicitFocusOrder="0" pos="90 145 90 20" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="2fc2e28ae0fde6a3" memberName="osc2OctaveBox"
            virtualName="" explicitFocusOrder="0" pos="90 180 90 20" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="b5a440e9f025ebd2" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="10 180 80 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Octave" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="35e567332bb5c0d5" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="10 145 80 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Waveform" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="f452e44f60e3b2ec" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="190 120 60 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Level" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <SLIDER name="new slider" id="e7671b1dcd8ad512" memberName="osc2lvlSlider"
          virtualName="" explicitFocusOrder="0" pos="190 135 60 80" rotarysliderfill="ffc67e15"
          rotaryslideroutline="ff808080" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="1b877b32ef164692" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="15 120 235 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Oscillator 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="new combo box" id="f77e2df6e32fe9bb" memberName="osc1WaveBox"
            virtualName="" explicitFocusOrder="0" pos="90 45 90 20" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="8160e144bbe9cd9c" memberName="osc1OctaveBox"
            virtualName="" explicitFocusOrder="0" pos="90 80 90 20" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="356b6b7cf57e370a" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="10 80 80 20" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Octave" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="532eb7a22ea08ac9" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="10 45 80 20" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Waveform" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="99c889db831c4574" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="190 20 60 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Level" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
