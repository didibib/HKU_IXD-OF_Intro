#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxPanel gui;
		ofParameter<float> rotateSpeedX;
		ofParameter<float> rotateSpeedY;
		ofParameter<float> rotateSpeedZ;

};
