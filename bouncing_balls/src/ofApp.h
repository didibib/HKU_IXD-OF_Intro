#pragma once

#include "ofMain.h"

#include "BouncyBall.h"
#include "Pyramid.h"

class ofApp : public ofBaseApp {

	public:
		static const int nBalls = 10;
		BouncyBall balls[nBalls];
		ofConePrimitive pyramid;
		ofEasyCam cam;
		vector<ofMeshFace> triangles;
		ofLight pointlight;

		float radius = 100;
		float height = 100;
		float radiusSegments = 4;
		float heightSegments = 1;
		float capsSegments = 1;

		void setup();
		void update();
		void draw();
		void tweakTriangles();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
};