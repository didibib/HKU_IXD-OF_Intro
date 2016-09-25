#include "BouncyBall.h"

BouncyBall::BouncyBall() {
	position = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0);
	speed = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
	radius = ofRandom(10, 50);
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

BouncyBall::BouncyBall(ofVec3f _position, ofVec3f _speed, float _radius) {
	position = _position;
	speed = _speed;
	radius = _radius;
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void BouncyBall::setupBall() {
	
}

void BouncyBall::updateBall() {
	position.x += speed.x;
	position.y += speed.y;
	radius += 1;

	detectBorders();		
}

void BouncyBall::drawBall() {
	ofFill();
	ofSetColor(color);
	ofDrawCircle(position.x, position.y, position.z, radius);
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

void BouncyBall::resetBall() {
	if (radius >= 100) {
		position = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0);
		radius = ofRandom(10, 40);
	}
}

