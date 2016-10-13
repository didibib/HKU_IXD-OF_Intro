#include "Ball.h"

Ball::Ball() {

}

Ball::Ball(int _x, int _y, float _spacing, float _radius) {
	posX = _x;
	posY = _y;
	radius = _radius;
	spacing = _spacing;
	position.x = posX * spacing;
	position.y = posY * spacing;
}

void Ball::setup() {

}

void Ball::update() {

}

void Ball::draw() {
	ofSetColor(color);
	ofDrawCircle(position.x, position.y, position.z, radius);
}

void Ball::setSpacing(float _newSpacing) {
	position.x = 0;
	position.y = 0;
	position.x = posX * _newSpacing;
	position.y = posY * _newSpacing;
}

void Ball::setRadius(float _distanceMult) {
	radius = _distanceMult;
}

void Ball::setColor(ofColor _color) {
	color = _color;
}

void Ball::setPosZ(float _zPos) {
	position.z = _zPos;
}