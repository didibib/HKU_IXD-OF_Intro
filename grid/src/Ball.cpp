#include "Ball.h"

Ball::Ball(int _x, int _y, float _spacing, float _radius) {
	position.x = _x;
	position.y = _y;
	spacing = _spacing;
	radius = _radius;
}

void Ball::setup() {

}

void Ball::update() {

}

void Ball::draw() {
	ofSetColor(0);
	ofDrawCircle(position.x, position.y, position.z, radius);
}