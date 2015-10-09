#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

class testApp : public ofBaseApp, public ofxMidiListener {
	public:
		void setup();
		void update();
		void draw();
    void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);
    
    void newMidiMessage(ofxMidiMessage& eventArgs);
	
	stringstream text;
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;

    int messageIndex;
    
    int frameView;
    int secondView;
    int minView;
    int hourView;
    
    bool frameReset;
    
    int testCounter;
    
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
    
    
    int midiTempoTest;
    int midiTempoCal;
    
    
    int ch16;
    int ch15;
};
