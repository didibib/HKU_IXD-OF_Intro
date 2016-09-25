#include "ofApp.h"

void ofApp::setup() {
	ofSetBackgroundColor(255);

	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 40, 10, 100));


	for (int i = 0; i < nBalls; i++) {
		ofVec3f rPosition = ofVec3f(ofRandom(ofGetWidth(), ofGetHeight()));
		ofVec3f rSpeed = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
		balls[i] = BouncyBall(rPosition, rSpeed, radius);
	}
}

void ofApp::update() {
	for (int i = 0; i < nBalls; i++) {
		balls[i].updateBall();	
		
		if (balls[i].radius != radius) {
			balls[i].radius = radius;
		}
	}
}

void ofApp::draw() {
	gui.draw();

	for (int i = 0; i < nBalls; i++) {
		balls[i].drawBall();
	}
}

void ofApp::keyPressed(int key) {

}

void ofApp::mousePressed(int x, int y, int button) {

}