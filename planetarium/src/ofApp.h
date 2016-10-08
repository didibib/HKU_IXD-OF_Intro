#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Planet.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxPanel gui;
		ofParameterGroup params;
		
		ofEasyCam cam;
		ofLight light;

		Planet planet;

		bool drawGrid;
		bool drawLight;

		void keyPressed(int key);
};