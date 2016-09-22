#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "BouncyBall.h"

class ofApp : public ofBaseApp {

	public:
		static const int nBalls = 50;
		BouncyBall balls[nBalls];

		ofxPanel gui;
		ofParameter<ofVec3f> position;
		ofParameter<ofVec3f> speed;
		ofParameter<float> radius;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
};