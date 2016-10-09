#include "ofApp.h"

void ofApp::setup(){
	ofSetBackgroundColor(255);

	gui.setup();
	gui.add(speedX.set("Speed X", 3, -10, 10));
	gui.add(speedY.set("Speed Y", 4, -10, 10));
	gui.add(speedZ.set("Speed Z", 2.5, -10, 10));
	gui.add(color.set("color", ofColor::black));

	box.set(boxSize);
	
	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor(255, 255, 255));
	light.enable();
}

void ofApp::update(){
	for (int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}	
}

void ofApp::draw(){
	ofEnableDepthTest();
	cam.begin();
	
	ofSetColor(0);
	box.drawWireframe();
	for (int i = 0; i < balls.size(); i++) {
		balls[i].draw();
	}

	cam.end();
	ofDisableDepthTest();

	gui.draw();
}

void ofApp::addBall() {
	BouncyBall ball;
	ofVec3f pos = ofVec3f(0, 0, 0);
	ofVec3f speed = ofVec3f(speedX, speedY, speedZ);
	ball = BouncyBall(pos, speed, color, boxSize);
	balls.push_back(ball);
}

void ofApp::deleteBall() {
	if (balls.size() > 0) {
		balls.pop_back();
	}
}

void ofApp::keyPressed(int key){
	if (key == 'a') {
		addBall();
	}
	else if (key == 'd') {
		deleteBall();
	}
}

void ofApp::box(float _size) {
	float w = _size / 2;
	ofDrawLine(-w, -w, w, w, -w, w);
}
