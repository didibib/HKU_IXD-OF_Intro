#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		float phase;

		void setup();
		void update();
		void draw();
		void audioOut(float* output, int bufferSize, int nChannels);

		void keyPressed(int key);		

		ofSoundStream soundStream;
};
