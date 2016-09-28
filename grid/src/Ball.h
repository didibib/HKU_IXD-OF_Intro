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
	float posX, posY;
	ofColor color;

	void setup();
	void update();
	void draw();

	void setRadius(float _distanceMult);
	void setColor(ofColor _color);
	void setPosZ(float _zPos);
};