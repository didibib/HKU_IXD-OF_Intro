#include "Planet.h"

Planet::Planet()
{

}


Planet::~Planet()
{

}

void Planet::setup(string name) {
	planetParameterGroup.setName(name);
	planetParameterGroup.add(rotateSpeed.set("speed", 0.0, 0.0, 9.0));
	planetParameterGroup.add(distance.set("distance", 0.0, 0.0, 600));
	planetParameterGroup.add(color.set("color", ofColor::white, 0, 255));
}

void Planet::update() {
	rotation++;
}

void Planet::draw() {
	ofSetColor(color);
	ofRotate(rotation*rotateSpeed);
	ofDrawSphere(300);
}