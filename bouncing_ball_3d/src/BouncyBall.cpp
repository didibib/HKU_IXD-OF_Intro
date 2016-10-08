#include "BouncyBall.h"

BouncyBall::BouncyBall()
{
}

BouncyBall::BouncyBall(ofVec3f _position, float _speedX, float _speedY, float _speedZ, ofColor _color) {
	position = _position;
	speed.x = _speedX;
	speed.y = _speedY; 
	speed.z = _speedZ;
	color = _color;
}

void BouncyBall::setup() {

}

void BouncyBall::update() {
	position += speed;
	detectBorders();
}

void BouncyBall::draw() {
	
}

void BouncyBall::detectBorders() {

}

void BouncyBall::setSpeed(float _speedMultX, float _speedMultY) {

}
