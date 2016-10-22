#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define CAM_WIDTH 420
#define CAM_HEIGHT 340

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	ofVideoPlayer video;
	ofVideoGrabber grabber;

	ofImage image;
	ofPixels workspace;
	ofVec2f index;

private:
	float vidW, vidH;
};