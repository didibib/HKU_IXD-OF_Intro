#pragma once

#include "ofMain.h"

class BouncyBall
{
public:
	BouncyBall();
	BouncyBall(ofVec3f _position, float _speedX, float _speedY, float _speedZ, ofColor _color);

	ofVec3f position;
	ofVec3f speed;
	float radius;
	ofColor color;

	void setup();
	void update();
	void draw();
	void detectBorders();
	void setSpeed(float _speedMultX, float _speedMultY);
};

