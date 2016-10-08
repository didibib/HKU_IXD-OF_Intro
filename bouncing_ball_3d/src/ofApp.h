#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		ofxPanel gui;

		ofEasyCam cam;
		ofLight light;

		void setup();
		void update();
		void draw();

		void doos(float _a);

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
};
