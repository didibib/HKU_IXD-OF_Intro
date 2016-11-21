#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

#define MARGIN 5

static const int CAM_WIDTH = 320;
static const int CAM_HEIGHT = 240;
static const int SELECTED = 2;

class ofApp : public ofBaseApp{

	public:
		ofVideoGrabber grabber;

		ofxCvColorImage rgbImage;
		ofxCvColorImage hsvImage;

		ofxCvGrayscaleImage hue;
		ofxCvGrayscaleImage saturation;
		ofxCvGrayscaleImage value;

		ofxCvGrayscaleImage filtered;
		ofxCvContourFinder finder;

		int selectedHue[SELECTED];
		int mouseClicked;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);		
};