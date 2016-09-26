#pragma once

#include "ofMain.h"

class BouncyBall
{
public:
	BouncyBall();
	BouncyBall(ofVec2f _position, float _speedX, float _speedY, int _radius, ofColor _color);

	ofVec2f position;
	ofVec2f speed;
	float radius;
	ofColor color;

	void setup();
	void update();
	void draw();
	void detectBorders();	
};