#pragma once

#include "ofMain.h"

class BouncyBall
{
public:
	BouncyBall();
	~BouncyBall();

	void setupBall();
	void updateBall();
	void drawBall();

	float x, y;
	float speedX, speedY;
	float radius;
	ofColor color;
};