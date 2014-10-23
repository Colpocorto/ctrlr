/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "stdafx.h"
//[/Headers]

#include "CtrlrLuaMethodDebuggerPrompt.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include "CtrlrLuaMethodEditor.h"
//[/MiscUserDefs]

//==============================================================================
CtrlrLuaMethodDebuggerPrompt::CtrlrLuaMethodDebuggerPrompt (CtrlrLuaMethodEditor &_owner)
    : owner(_owner)
{
    addAndMakeVisible (debuggerOutput = new TextEditor ("Debugger output"));
    debuggerOutput->setMultiLine (true);
    debuggerOutput->setReturnKeyStartsNewLine (false);
    debuggerOutput->setReadOnly (true);
    debuggerOutput->setScrollbarsShown (true);
    debuggerOutput->setCaretVisible (false);
    debuggerOutput->setPopupMenuEnabled (true);
    debuggerOutput->setColour (TextEditor::textColourId, Colour (0xff5c5c5c));
    debuggerOutput->setColour (TextEditor::outlineColourId, Colour (0x00000000));
    debuggerOutput->setColour (TextEditor::shadowColourId, Colour (0x00000000));
    debuggerOutput->setText (String::empty);

    addAndMakeVisible (debuggerInput = new TextEditor ("Debugger input"));
    debuggerInput->setMultiLine (false);
    debuggerInput->setReturnKeyStartsNewLine (false);
    debuggerInput->setReadOnly (false);
    debuggerInput->setScrollbarsShown (false);
    debuggerInput->setCaretVisible (true);
    debuggerInput->setPopupMenuEnabled (true);
    debuggerInput->setColour (TextEditor::highlightColourId, Colour (0x5b247c8d));
    debuggerInput->setColour (TextEditor::outlineColourId, Colour (0x8a000000));
    debuggerInput->setColour (TextEditor::shadowColourId, Colour (0x00000000));
    debuggerInput->setText (String::empty);

    addAndMakeVisible (debugContinue = new ImageButton ("Continue"));
    debugContinue->setTooltip (TRANS("Continue"));
    debugContinue->addListener (this);

    debugContinue->setImages (false, true, true,
                              Image(), 0.550f, Colour (0x00000000),
                              Image(), 0.750f, Colour (0x00000000),
                              Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (debugStepOver = new ImageButton ("Step Over"));
    debugStepOver->setTooltip (TRANS("Step Over"));
    debugStepOver->addListener (this);

    debugStepOver->setImages (false, true, true,
                              Image(), 0.550f, Colour (0x00000000),
                              Image(), 0.750f, Colour (0x00000000),
                              Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (debugStepInto = new ImageButton ("Step Into"));
    debugStepInto->setTooltip (TRANS("Step Into"));
    debugStepInto->addListener (this);

    debugStepInto->setImages (false, true, true,
                              Image(), 0.550f, Colour (0x00000000),
                              Image(), 0.750f, Colour (0x00000000),
                              Image(), 1.000f, Colour (0x00000000));

    //[UserPreSize]
    debuggerOutput->setFont (Font (Font::getDefaultMonospacedFontName(), 14.0f, Font::plain));
    debuggerInput->setFont (Font (Font::getDefaultMonospacedFontName(), 14.0f, Font::plain));
    debuggerInput->addListener (this);

    debugContinue->setImages (false, true, true,
                              IMAGE(appbar_control_play_png), 0.550f, Colour (0x00000000),
                              IMAGE(appbar_control_play_png), 0.850f, Colour (0x00000000),
                              IMAGE(appbar_control_play_png), 1.000f, Colour (0x00000000));
    debugContinue->setMouseCursor (MouseCursor::PointingHandCursor);

    debugStepInto->setImages (false, true, true,
                              IMAGE(appbar_debug_step_into_png), 0.550f, Colour (0x00000000),
                              IMAGE(appbar_debug_step_into_png), 0.850f, Colour (0x00000000),
                              IMAGE(appbar_debug_step_into_png), 1.000f, Colour (0x00000000));
    debugStepInto->setMouseCursor (MouseCursor::PointingHandCursor);

    debugStepOver->setImages (false, true, true,
                              IMAGE(appbar_debug_step_over_png), 0.550f, Colour (0x00000000),
                              IMAGE(appbar_debug_step_over_png), 0.850f, Colour (0x00000000),
                              IMAGE(appbar_debug_step_over_png), 1.000f, Colour (0x00000000));
    debugStepOver->setMouseCursor (MouseCursor::PointingHandCursor);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

CtrlrLuaMethodDebuggerPrompt::~CtrlrLuaMethodDebuggerPrompt()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    debuggerOutput = nullptr;
    debuggerInput = nullptr;
    debugContinue = nullptr;
    debugStepOver = nullptr;
    debugStepInto = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CtrlrLuaMethodDebuggerPrompt::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void CtrlrLuaMethodDebuggerPrompt::resized()
{
    debuggerOutput->setBounds (0, 32, getWidth() - 0, getHeight() - 50);
    debuggerInput->setBounds (0, getHeight() - 18, getWidth() - 0, 18);
    debugContinue->setBounds (0, 0, 32, 32);
    debugStepOver->setBounds (40, 0, 32, 32);
    debugStepInto->setBounds (80, 0, 32, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void CtrlrLuaMethodDebuggerPrompt::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == debugContinue)
    {
        //[UserButtonCode_debugContinue] -- add your button handler code here..
        //[/UserButtonCode_debugContinue]
    }
    else if (buttonThatWasClicked == debugStepOver)
    {
        //[UserButtonCode_debugStepOver] -- add your button handler code here..
        //[/UserButtonCode_debugStepOver]
    }
    else if (buttonThatWasClicked == debugStepInto)
    {
        //[UserButtonCode_debugStepInto] -- add your button handler code here..
        //[/UserButtonCode_debugStepInto]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void CtrlrLuaMethodDebuggerPrompt::insertRawDebuggerOutput(const String &output)
{
    debuggerOutput->insertTextAtCaret (output);
}

void CtrlrLuaMethodDebuggerPrompt::setRawDebuggerOutput(const String &debuggerOutput)
{
    _DBG("CtrlrLuaMethodDebuggerPrompt::setRawDebuggerOutput " + debuggerOutput);
}

void CtrlrLuaMethodDebuggerPrompt::sendCommand (const String &command)
{
    commandQueue.add (command);

    debuggerOutput->insertTextAtCaret (command.trim() + "\n");

    if (owner.getParentComponent()->isCurrentlyModal())
    {
        owner.getParentComponent()->exitModalState(1);
    }
}

void CtrlrLuaMethodDebuggerPrompt::textEditorReturnKeyPressed (TextEditor &editor)
{
    if (&editor == debuggerInput)
    {
        sendCommand (debuggerInput->getText());
        debuggerInput->clear();
    }
}

StringArray &CtrlrLuaMethodDebuggerPrompt::getCommandQueue()
{
    return (commandQueue);
}

const String CtrlrLuaMethodDebuggerPrompt::getCurrentDebuggerCommand(const bool clearTheReturnedCommand)
{
    if (commandQueue.size() <= 0)
        return (String::empty);

    const String ret = commandQueue[commandQueue.size() - 1];
    commandQueue.remove (commandQueue.size() - 1);
    return (ret);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CtrlrLuaMethodDebuggerPrompt"
                 componentName="" parentClasses="public Component, public TextEditor::Listener"
                 constructorParams="CtrlrLuaMethodEditor &amp;_owner" variableInitialisers="owner(_owner)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <TEXTEDITOR name="Debugger output" id="2220af475a8f6614" memberName="debuggerOutput"
              virtualName="" explicitFocusOrder="0" pos="0 32 0M 50M" textcol="ff5c5c5c"
              outlinecol="0" shadowcol="0" initialText="" multiline="1" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <TEXTEDITOR name="Debugger input" id="b2b8220d7f2d2565" memberName="debuggerInput"
              virtualName="" explicitFocusOrder="0" pos="0 18R 0M 18" hilitecol="5b247c8d"
              outlinecol="8a000000" shadowcol="0" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <IMAGEBUTTON name="Continue" id="2ccb9131528ecffc" memberName="debugContinue"
               virtualName="" explicitFocusOrder="0" pos="0 0 32 32" tooltip="Continue"
               buttonText="Continue" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="" opacityNormal="0.55000001192092895508"
               colourNormal="0" resourceOver="" opacityOver="0.85000002384185791016"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="Step Over" id="2f8e190ee1a2d9c6" memberName="debugStepOver"
               virtualName="" explicitFocusOrder="0" pos="40 0 32 32" tooltip="Step Over"
               buttonText="Step Over" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="" opacityNormal="0.55000001192092895508"
               colourNormal="0" resourceOver="" opacityOver="0.85000002384185791016"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="Step Into" id="216fcc9599371746" memberName="debugStepInto"
               virtualName="" explicitFocusOrder="0" pos="80 0 32 32" tooltip="Step Into"
               buttonText="Step Into" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="" opacityNormal="0.55000001192092895508"
               colourNormal="0" resourceOver="" opacityOver="0.85000002384185791016"
               colourOver="0" resourceDown="" opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]