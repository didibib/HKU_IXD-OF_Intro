#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"

#include "Ball.h"
#include <cmath>

class ofApp : public ofBaseApp {

public:
	static const int nGrid = 10000;
	Ball grid[nGrid];

	ofxPanel gui;
	ofParameter<float> spacing;
	float oldSpacing;
	ofParameter<float> radius;
	ofParameter<int> zMult;
	ofParameter<int> colorMultR;
	ofParameter<int> colorMultG;
	ofParameter<int> colorMultB;
	ofParameter<int> waveX;

	int cols, rows;
	int gridSize;
	
	ofVec2f mousePos;
	bool isPressed;

	ofLight light;

	void setup();
	void update();
	void draw();
	void drawGrid();
	float powpow(float _var);
	float pointsym(float _var);

	void mousePressed(int x, int y, int button);
};