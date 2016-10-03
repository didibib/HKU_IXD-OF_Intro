#include "BouncyBall.h"

BouncyBall::BouncyBall() {
}

BouncyBall::BouncyBall(ofVec2f _position, float _speedX, float _speedY, int _radius, ofColor _color) {
	position = _position;
	speed.x = _speedX;
	speed.y = _speedY;
	speedInit.x = _speedX;
	speedInit.y = _speedY;
	radius = _radius;
	color = _color;
}

void BouncyBall::setup() {
	
}

void BouncyBall::update() {
	position.x += speed.x;
	position.y += speed.y;

	detectBorders();		
}

void BouncyBall::draw() {
	ofFill();
	ofSetColor(color);
	ofDrawCircle(position.x, position.y, radius);
}

void BouncyBall::detectBorders() {
	if (position.x <= 0) {
		position.x = 0;
		speed.x *= -1;
	}

	else if (position.x >= ofGetWidth()) {
		position.x = ofGetWidth();
		speed.x *= -1;
	}

	if (position.y <= 0) {
		position.y = 0;
		speed.y *= -1;
	}

	else if (position.y >= ofGetHeight()) {
		position.y = ofGetHeight();
		speed.y *= -1;
	}
}

void BouncyBall::setSpeed(float _speedMultX, float _speedMultY) {
	speed.x = speedInit.x * _speedMultX;
	speed.y = speedInit.y * _speedMultX;
}