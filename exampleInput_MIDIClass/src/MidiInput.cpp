//
//  MidiInput.cpp
//  exampleInput_MIDIClass
//
//  Created by jeonghopark on 27/09/15.
//
//

#include "MidiInput.hpp"


//--------------------------------------------------------------
void MidiInput::setup() {
    
    // print input ports to console
    midiIn.listPorts(); // via instance
    //ofxMidiIn::listPorts(); // via static as well
    
    // open port by number (you may need to change this)
    //	midiIn.openPort(1);
    midiIn.openPort("IAC Driver Bus 1");	// by name
    //midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
    
    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, false, false);
    
    // add ofApp as a listener
    midiIn.addListener(this);
    
    // print received messages to the console
    midiIn.setVerbose(true);

}


//--------------------------------------------------------------
void MidiInput::update(){
    
    
}


//--------------------------------------------------------------
void MidiInput::draw(){
    
    ofSetColor(0);
    
    // draw the last recieved message contents to the screen
    text << "Received: " << ofxMidiMessage::getStatusString(midiMessage.status);
    ofDrawBitmapString(text.str(), 20, 20);
    text.str(""); // clear
    
    text << "channel: " << midiMessage.channel;
    ofDrawBitmapString(text.str(), 20, 34);
    text.str(""); // clear
    
    text << "pitch: " << midiMessage.pitch;
    ofDrawBitmapString(text.str(), 20, 48);
    text.str(""); // clear
    ofDrawRectangle(20, 58, ofMap(midiMessage.pitch, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "velocity: " << midiMessage.velocity;
    ofDrawBitmapString(text.str(), 20, 96);
    text.str(""); // clear
    ofDrawRectangle(20, 105, ofMap(midiMessage.velocity, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "control: " << midiMessage.control;
    ofDrawBitmapString(text.str(), 20, 144);
    text.str(""); // clear
    ofDrawRectangle(20, 154, ofMap(midiMessage.control, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "value: " << midiMessage.value;
    ofDrawBitmapString(text.str(), 20, 192);
    text.str(""); // clear
    if(midiMessage.status == MIDI_PITCH_BEND) {
        ofDrawRectangle(20, 202, ofMap(midiMessage.value, 0, MIDI_MAX_BEND, 0, ofGetWidth()-40), 20);
    }
    else {
        ofDrawRectangle(20, 202, ofMap(midiMessage.value, 0, 127, 0, ofGetWidth()-40), 20);
    }
    
    
    // bar Index
    ofDrawBitmapString(num32thNotes % 4 + 1, 20, 260);

}


//--------------------------------------------------------------
void MidiInput::exit() {
    
    // clean up
    midiIn.closePort();
    midiIn.removeListener(this);
}

//--------------------------------------------------------------
void MidiInput::newMidiMessage(ofxMidiMessage& msg) {
    
    // make a copy of the latest message
    midiMessage = msg;
    
    int tempoDenominator = 4;
    int tempoNumerator = 4;
    int ticksPerqNote = 48;
    
    int _ticksPerqNote = (int) 24.0 * 4.0/tempoDenominator;
    ticksPerBar = tempoNumerator * ticksPerqNote;
    ticks32thNotePerBar = (int) ticksPerBar/8.0;
    ticksPer32thNote = (int) ticksPerqNote/8.0;
    
    
    if(msg.status == 248){
        
        tempoTicks += 1;
        ticksfor32thNote +=1;
        
        if(ticksfor32thNote % ticksPer32thNote == 0 ) {
            // if(num32thNotes % 2 == 0) midiOut.sendNoteOff(1, 62, 0);
            // else  midiOut.sendNoteOn(1, 62, 127);
            num32thNotes  += 1;
        }
        
        if(tempoTicks % _ticksPerqNote == 0 ) {
            tempoqNotes += 1;
            tempoTicks = 0;
            if (tempoqNotes % (tempoNumerator + 1) == 0 ) {
                tempoBars += 1;
                tempoqNotes = 1;
                num32thNotes = 0;
                ticksfor32thNote = 0;
            }
        }
        
    }
    
    if(msg.status == MIDI_START) {
        
        //ticks = 0;
        //qNotes = 0;
        //bars = 0;
        tempoTicks = 0;
        tempoqNotes = 1;
        tempoBars = 1;
        isPlaying = false;
        num32thNotes = 0;
        ticksfor32thNote = 0;
        
        isPlaying = true;
        
    };
    
    
    
    
}