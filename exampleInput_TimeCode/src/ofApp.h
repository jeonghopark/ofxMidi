/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */

// Midi Sync for Mac
// Copyright (c) 2015 JeongHo Park <jeonghopark@jeonghopark.de>



#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

class ofApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
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
