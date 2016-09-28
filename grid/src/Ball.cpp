#include "Ball.h"

Ball::Ball() {

}

Ball::Ball(int _x, int _y, float _spacing, float _radius) {
	posX = _x;
	posY = _y;
	radius = _radius;
	spacing = _spacing;
	position.x = posX * spacing + spacing / 4;
	position.y = posY * spacing + spacing / 4;
}

void Ball::setup() {
	
}

void Ball::update() {

}

void Ball::draw() {
	ofSetColor(color);
	ofDrawCircle(position.x, position.y, radius);
}

void Ball::setRadius(float _distanceMult) {
	radius = _distanceMult;
}

void Ball::setColor(ofColor _color) {
	color = _color;
}