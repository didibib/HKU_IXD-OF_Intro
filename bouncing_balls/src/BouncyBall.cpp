#include "BouncyBall.h"

BouncyBall::BouncyBall() {
	position = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0);
	speedX = ofRandom(-2, 2);
	speedY = ofRandom(-2, 2);
	radius = ofRandom(10, 50);
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));	
}

void BouncyBall::setupBall() {
	
}

void BouncyBall::updateBall() {
	position.x += speedX;
	position.y += speedY;
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
		speedX *= -1;
	}
	else if (position.x >= ofGetWidth()) {
		position.x = ofGetWidth();
		speedX *= -1;
	}

	if (position.y <= 0) {
		position.y = 0;
		speedY *= -1;
	}
	else if (position.y >= ofGetHeight()) {
		position.y = ofGetHeight();
		speedY *= -1;
	}
}

void BouncyBall::resetBall() {
	if (radius >= 100) {
		position = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0);
		radius = ofRandom(10, 50);
	}
}

