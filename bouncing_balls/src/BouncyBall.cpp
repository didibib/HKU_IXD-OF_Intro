#include "BouncyBall.h"

BouncyBall::BouncyBall()
{

}

BouncyBall::~BouncyBall()
{
}

void BouncyBall::setup() {
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
	speedX = ofRandom(5, 10);
	speedY = ofRandom(5, 10);
	radius = ofRandom(10, 100);
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void BouncyBall::update() {
	if (x <= 0) {
		x = 0;
		speedX *= -1;
	}
	else if (x >= ofGetWidth()) {
		x = ofGetWidth();
		speedX *= -1;
	}

	if (y <= 0) {
		y = 0;
		speedY *= -1;
	}
	else if (y >= ofGetHeight()) {
		y = ofGetHeight();
		speedY *= -1;
	}

	x += speedX;
	y += speedY;
}

void BouncyBall::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}