#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Ball.h"

class ofApp : public ofBaseApp {

public:
	static const int nGrid = 10000;
	Ball grid[nGrid];

	ofxPanel gui;
	ofParameter<float> spacing;
	float oldSpacing;
	ofParameter<float> radius;
	ofParameter<int> zValue;
	ofParameter<int> colorMultR;
	ofParameter<int> colorMultG;
	ofParameter<int> colorMultB;

	int cols, rows;
	int gridSize;

	float ampRadius;
	float incRadius;

	ofVec2f mousePos;

	void setup();
	void update();
	void draw();

	void mouseReleased(int x, int y, int button);
};