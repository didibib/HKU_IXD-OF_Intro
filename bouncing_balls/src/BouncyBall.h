#pragma once

#include "ofMain.h"

class BouncyBall
{
public:
	BouncyBall();
	BouncyBall(ofVec3f _position, ofVec3f _speed, float _radius);

	ofVec3f position;
	ofVec3f speed;
	float radius;
	ofColor color;

	void setupBall();
	void updateBall();
	void drawBall();
	void detectBorders();
	void resetBall();
	
};