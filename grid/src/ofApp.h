#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		static const int nGrid = 10000;
		Ball grid[nGrid];

		float spacing = 50;
		int cols = ofGetWidth() / spacing;
		int rows = ofGetHeight() / spacing;		
		int gridSize = cols * rows;

		float ampRadius;
		float incRadius;
		
		ofxPanel gui;
		ofParameter<float> radius;
		ofParameter<int> zValue;
		ofParameter<int> colorMultR;
		ofParameter<int> colorMultG;
		ofParameter<int> colorMultB;

		ofVec2f mousePos; 

		void setup();
		void update();
		void draw();		

		void mouseReleased(int x, int y, int button);
};