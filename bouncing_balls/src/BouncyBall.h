#pragma once
#include "C:\Users\Tariq Bakhtali\Desktop\OF\libs\openFrameworks\app\ofBaseApp.h"

#include "ofMain.h"

class BouncyBall : public ofBaseApp {

public:
	BouncyBall();
	~BouncyBall();

	void setup();
	void update();
	void draw();

private:
	float x, y;
	float speedX, speedY;
	float radius;
	ofColor color;
};
