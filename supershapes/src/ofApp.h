#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		ofxPanel gui;
		ofParameter<float> radius;
		ofParameter<int> resolution;

		ofSpherePrimitive sphere;

		ofEasyCam cam;
		ofLight spotlight;

		float spinX;
		float spinY;

		float displacement;
		ofVec3f normal;

		void setup();
		void update();
		void draw();
		void tweakFaces();

		void keyPressed(int key);
		
};
