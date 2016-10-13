#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "BouncyBall.h"

class ofApp : public ofBaseApp{

	public:
		ofxPanel gui;
		ofParameter<float> speedX;
		ofParameter<float> speedY;
		ofParameter<float> speedZ;
		ofParameter<ofColor> color;

		vector<BouncyBall> balls;

		ofBoxPrimitive cube;
		float boxSize = 500;

		ofEasyCam cam;
		ofLight light;

		void setup();
		void update();
		void draw();

		void box(float _size);

		void addBall();
		void deleteBall();
		
		void keyPressed(int key);
};
