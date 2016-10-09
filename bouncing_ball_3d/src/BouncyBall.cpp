#include "BouncyBall.h"

BouncyBall::BouncyBall()
{
}

BouncyBall::BouncyBall(ofVec3f _position, ofVec3f _speed, ofColor _color, float _boxSize) {
	position = _position;
	speed = _speed;
	color = _color;
	border = _boxSize/2;

	cone.set(20, 20, 4, 1);
}

void BouncyBall::setup() {

}

void BouncyBall::update() {
	cone.setPosition(position);

	position.x += speed.x;
	position.y += speed.y;
	position.z += speed.z;

	cout << "\n" << position;
	detectBorders();
}

void BouncyBall::draw() {
	ofSetColor(color);
	cone.draw();
}

void BouncyBall::detectBorders() {
	if (position.x <= -border) {
		position.x = -border;
		speed.x *= -1;
	}
	else if (position.x >= border) {
		position.x = border;
		speed.x *= -1;
	}

	if (position.y <= -border) {
		position.y = -border;
		speed.y *= -1;
	}
	else if (position.y >= border) {
		position.y = border;
		speed.y *= -1;
	}

	if (position.z <= -border) {
		position.z = -border;
		speed.z *= -1;
	}
	else if (position.z >= border) {
		position.z = border;
		speed.z *= -1;
	}
}

void BouncyBall::setSpeed(float _speedMultX, float _speedMultY) {

}
