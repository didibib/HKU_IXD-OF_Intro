#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		static const int nGrid = 10000;
		Ball grid[nGrid];

		ofVec3f position;
		float radius = 10;
		float spacing = 50;
		int cols = ofGetWidth() / spacing;
		int rows = ofGetHeight() / spacing;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
};
