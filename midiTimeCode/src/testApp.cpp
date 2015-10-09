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
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofSetVerticalSync(true);
	ofBackground(255, 255, 255);
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	// print input ports to console
	midiIn.listPorts(); // via instance
	//ofxMidiIn::listPorts(); // via static as well
	
	// open port by number (you may need to change this)
	midiIn.openPort(0);
	//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input");	// open a virtual port
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, true, false);
	
	// add testApp as a listener
	midiIn.addListener(this);
	
	// print received messages to the console
//	midiIn.setVerbose(true);
}

//--------------------------------------------------------------
void testApp::update() {
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(0);
	
	// draw the last recieved message contents to the screen
    //	text << "Received: " << ofxMidiMessage::getStatusString(midiMessage.status);
    //	ofDrawBitmapString(text.str(), 20, 20);
    //	text.str(""); // clear
	
//    if (midiMessage.channel==15) cout << "151515" << endl;
//    if (midiMessage.channel==16) cout << "161616" << endl;
    
	text << "ch15: " << ch15;
	ofDrawBitmapString(text.str(), 40, 134);
	text.str(""); // clear

    text << "ch16: " << ch16;
	ofDrawBitmapString(text.str(), 130, 134);
	text.str(""); // clear

//	text << "channel: " << midiMessage.channel;
//	ofDrawBitmapString(text.str(), 20, 34);
//	text.str(""); // clear
//	
//	text << "pitch: " << midiMessage.pitch;
//	ofDrawBitmapString(text.str(), 20, 48);
//	text.str(""); // clear
//	ofRect(20, 58, ofMap(midiMessage.pitch, 0, 127, 0, ofGetWidth()-40), 20);
//	
//	text << "velocity: " << midiMessage.velocity;
//	ofDrawBitmapString(text.str(), 20, 96);
//	text.str(""); // clear
//	ofRect(20, 105, ofMap(midiMessage.velocity, 0, 127, 0, ofGetWidth()-40), 20);
//	
//	text << "control: " << midiMessage.control;
//	ofDrawBitmapString(text.str(), 20, 144);
//	text.str(""); // clear
//	ofRect(20, 154, ofMap(midiMessage.control, 0, 127, 0, ofGetWidth()-40), 20);
//	
//	text << "value: " << midiMessage.value;
//	ofDrawBitmapString(text.str(), 20, 192);
//	text.str(""); // clear
//	if(midiMessage.status == MIDI_PITCH_BEND) {
//		ofRect(20, 202, ofMap(midiMessage.value, 0, MIDI_MAX_BEND, 0, ofGetWidth()-40), 20);
//	}
//	else {
//		ofRect(20, 202, ofMap(midiMessage.value, 0, 127, 0, ofGetWidth()-40), 20);
//	}
//	
//	text << "delta: " << midiMessage.deltatime;
//	ofDrawBitmapString(text.str(), 20, 240);
//	text.str(""); // clear
    
    
//	text << hourView << " : " << minView << " : " << secondView << " : " << frameView;
//	ofDrawBitmapString(text.str(), 20, 20);
//	text.str(""); // clear

    text << tempoBars << " : " << tempoqNotes << " : " << num32thNotes;
    ofDrawBitmapString(text.str(), 20, 20);
    text.str(""); // clear
}

//--------------------------------------------------------------
void testApp::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}

//--------------------------------------------------------------
void testApp::newMidiMessage(ofxMidiMessage& msg) {
    
	// make a copy of the latest message
	midiMessage = msg;
    
    //    messageIndex = midiMessage.byteOne;
    //
    //    messageIndex % 4 == 0;
    
    //    midiMessage
    
//    cout << (midiMessage.status) << endl;
//    cout << (midiMessage.status >> 2) << endl;
//    cout << (midiMessage.status >> 4) << endl;
//    cout << (midiMessage.status >> 7) << endl;
//    cout << (midiMessage.status >> 16) << endl;
//    cout << ((midiMessage.bytes[0] >> 4) % 4) << endl;

//    cout << "ch   : "<< (((int)midiMessage.bytes[0])) << endl;
//    cout << "note : " << (((int)midiMessage.bytes[1])) << endl;

    
    if ((int)midiMessage.bytes[0]==192){
        //        cout << "ch   : "<< (((int)midiMessage.bytes[0])) << endl;
        cout << "ch   : "<< (((int)midiMessage.bytes[1])) << endl;
        cout << "cont : " << (((int)midiMessage.bytes[2])) << endl;
    }

    
//    if ((int)midiMessage.bytes[0]==190){
//    cout << "ch   : "<< (((int)midiMessage.bytes[1])) << endl;
//    cout << "cont : " << (((int)midiMessage.bytes[2])) << endl;
//    }
//
//    if ((int)midiMessage.bytes[0]==158){
//        ch15 = (int)midiMessage.bytes[1];
//    }
//    if ((int)midiMessage.bytes[0]==159){
//        ch16 = (int)midiMessage.bytes[1];
//    }
    
//    if (midiMessage.status == 128) {
//        ch15 = (midiMessage.bytes[0] >> 8) % 4;
//    }
//    if (midiMessage.status == 129) {
//        ch16 = midiMessage.channel;
//    }
    
//    cout << msg.status << endl;
//    if( msg.status == 250 ){
//        frameReset = false;
////        cout << "START" << endl;
//    }
//
//    if( msg.status == 252 ){
//        frameReset = true;
////        cout << "STOP" << endl;
//    }
//
//    if( msg.status == 242 ){
//        static int times[4]     = {0, 0, 0, 0};
//
//        cout << "Song Pointer" << (msg.byteOne >> 7) << endl;
//        cout << "Song Pointer" << (msg.byteTwo >> 7) << endl;
//        
//        bool btestCounter = ((msg.bytes[2] >> 4) % 4 == 0);
//        int value = msg.bytes[2] & 0xF2;     // the low nibble: value
//        if(btestCounter) times[kMTCFrames]++;
//        cout << "Song Pointer" << times[0] << endl;
//        cout << "Song Pointer" << value << endl;
//        
//    }
//    
//    if( msg.status == 248 ){
//        static int times[4]     = {0, 0, 0, 0};                 // this static buffer will hold our 4 time componens (frames, seconds, minutes, hours)
//        //////        static char *szType     = "";                           // SMPTE type as string (24fps, 25fps, 30fps drop-frame, 30fps)
//        static int numFrames    = 96;                          // number of frames per second (start off with arbitrary high number until we receive it)
//        ////
//        int messageIndex        = msg.byteOne >> 4;       // the high nibble: which quarter message is this (0...7).
//        int value               = msg.byteOne & 0x0F;     // the low nibble: value
//        int timeIndex           = messageIndex>>1;              // which time component (frames, seconds, minutes or hours) is this
//        bool bNewFrame          = messageIndex % 4 == 0;
//        
//        //        cout << messageIndex << endl;
//        //        cout << value << endl;
//        //        cout << timeIndex << endl;
//        //        cout << "bNewFrame " << bNewFrame << endl;
//        
//        if(frameReset){
//            times[0] = 0;
//        }
//        
//        if(bNewFrame) {
//            times[kMTCFrames]++;
//            if(times[kMTCFrames] >= numFrames) {
//                times[kMTCFrames] %= numFrames;
//                times[kMTCSeconds]++;
//                if(times[kMTCSeconds] >= 60) {
//                    times[kMTCSeconds] %= 60;
//                    times[kMTCMinutes]++;
//                    if(times[kMTCMinutes] >= 60) {
//                        times[kMTCMinutes] %= 60;
//                        times[kMTCHours]++;
//                    }
//                }
//            }
//            frameView = times[0];
//            secondView = times[1];
//            minView = times[2];
//            hourView = times[3];
//        }
//    }
    
    
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
            // if(num32thNotes % 2 == 0) midiOut.sendNoteOff(1, 62, 0); else  midiOut.sendNoteOn(1, 62, 127);
            num32thNotes  += 1;
        }
        
        if(tempoTicks % _ticksPerqNote == 0 ) {
            tempoqNotes += 1;
            tempoTicks = 0;
            if (tempoqNotes % (tempoNumerator + 1) == 0 ) {   /// eso est‡ bien ???
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
        
//        cout << " live Set playing ...." << endl;
        
        isPlaying = true;
    };
    
    if(msg.status == MIDI_STOP) // cout << " live Set paused " << endl;
    
    if(msg.status == MIDI_SONG_POS_POINTER  && msg.byteOne == 0 && msg.byteTwo == 0)  {
//        cout << " live Set  stopped " << endl;
        tempoTicks = 0;
        tempoqNotes = 1;
        tempoBars = 1;
        //isPlaying = false;
        num32thNotes = 0;
        ticksfor32thNote = 0;
        
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    
	switch(key) {
		case 'l':
			midiIn.listPorts();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mouseReleased() {
}
