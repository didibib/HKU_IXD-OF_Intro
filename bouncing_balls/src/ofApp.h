#pragma once

#include "ofMain.h"

#include "BouncyBall.h"
#include "Pyramid.h"

class ofApp : public ofBaseApp {

	public:
		static const int nBalls = 50;

		BouncyBall balls[nBalls];

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
};