#pragma once

#include "ofMain.h"

class BouncyBall
{
public:
	BouncyBall();
	BouncyBall(ofVec2f _position, float _speedX, float _speedY, int _radius, ofColor _color);

	ofVec3f position;
	ofVec3f speed;
	ofVec3f speedInit;
	float radius;
	ofColor color;

	void setup();
	void update();
	void draw();
	void detectBorders();	
	void setSpeed(float _speedMultX, float _speedMultY );
};