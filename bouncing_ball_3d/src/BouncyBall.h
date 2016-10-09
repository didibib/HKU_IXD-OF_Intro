#pragma once

#include "ofMain.h"

class BouncyBall
{
public:
	BouncyBall();
	BouncyBall(ofVec3f _position, ofVec3f _speed, ofColor _color, float _boxSize);

	ofVec3f position;
	ofVec3f speed;
	float radius;
	ofColor color;
	float border;

	ofConePrimitive cone;

	void setup();
	void update();
	void draw();
	void detectBorders();
	void setSpeed(float _speedMultX, float _speedMultY);
};

