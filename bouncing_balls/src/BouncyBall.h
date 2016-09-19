#pragma once

#include "ofMain.h"

class BouncyBall
{
public:
	BouncyBall();

	ofVec3f position;
	float speedX, speedY;
	float radius;
	ofColor color;

	void setupBall();
	void updateBall();
	void drawBall();
	void detectBorders();
	void resetBall();
	
};