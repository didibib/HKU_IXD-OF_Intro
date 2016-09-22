#pragma once

#include "ofMain.h"

class Ball
{
public:
	Ball();
	Ball(int _x, int _y, float _spacing, float _radius);

	ofVec3f position;
	float spacing;
	float radius;
	float distRadius;
	ofVec3f mousePos;

	void setup();
	void update();
	void draw();
	float distance();
};
