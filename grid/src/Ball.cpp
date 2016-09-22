#include "Ball.h"

Ball::Ball() {

}

Ball::Ball(int _x, int _y, float _spacing, float _radius) {
	position.x = _x;
	position.y = _y;
	radius = _radius;
	spacing = _spacing;
}

void Ball::setup() {
	posX = position.x * spacing + spacing / 4;
	posY = position.y * spacing + spacing / 4;
}

void Ball::update() {
}

void Ball::draw() {
	ofSetColor(0);
	ofDrawCircle(posX, posY, position.z, radius);
}

float Ball::distance() {
}