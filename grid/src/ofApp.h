#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"

#include "Ball.h"
#include <cmath>

#define CAM_WIDTH 320
#define CAM_HEIGHT 240

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
	
	//ofVec2f mousePos;
	ofVec2f position;
	bool isPressed;

	ofLight light;

	ofVideoGrabber 		vidGrabber;

	ofxCvColorImage			colorImg;

	ofxCvGrayscaleImage 	grayImage;
	ofxCvGrayscaleImage 	grayBg;
	ofxCvGrayscaleImage 	grayDiff;

	ofxCvContourFinder 	contourFinder;

	int 				threshold;
	bool				bLearnBakground;

	void drawGrid();
	float powpow(float _var);
	float pointsym(float _var);

	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);	
};