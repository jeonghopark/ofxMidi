//
//  MidiInput.hpp
//  exampleInput_MIDIClass
//
//  Created by jeonghopark on 27/09/15.
//
//

#ifndef MidiInput_hpp
#define MidiInput_hpp

#pragma once

#include "ofMain.h"

#include "ofxMidi.h"

class MidiInput : public ofxMidiListener {

public:
    
    void setup();
    void update();
    void draw();
    void exit();

    
    void newMidiMessage(ofxMidiMessage& eventArgs);
    
    stringstream text;
    
    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;
    
    int barIndex;
    
    int tempoDenominator;
    float ticksPerBar;
    int tempoNumerator;
    int ticksPerqNote;
    int ticks32thNotePerBar;
    int ticksPer32thNote;
    int tempoTicks;
    int ticksfor32thNote;
    int num32thNotes;
    int tempoqNotes;
    int tempoBars;
    bool isPlaying;
    
    
    
};

#endif /* MidiInput_hpp */
