#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		static const int nGrid = 10000;
		Ball grid[nGrid];

		float radius = 10;
		float spacing = 50;
		int cols = ofGetWidth() / spacing;
		int rows = ofGetHeight() / spacing;
		int gridSize = cols * rows;
		
		ofxPanel gui;		

		void setup();
		void update();
		void draw();
		

		void keyPressed(int key);	

		// ----------------------------------
		int displacement;
		int disEql;
		int increment;
		float disNoise;
		ofParameter<int>increaseInc;
		ofParameter<int>multrN;

		float a = 0;
		void v1_update();
		void v1_draw();
};