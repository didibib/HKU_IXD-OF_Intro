#include "ofApp.h"

void ofApp::setup() {
	ofSetBackgroundColor(255);

	for (int i = 0; i < nBalls; i++) {
		balls[i] = BouncyBall();
	}
}

void ofApp::update() {
	for (int i = 0; i < nBalls; i++) {
		balls[i].updateBall();
	}


}

void ofApp::draw() {
	for (int i = 0; i < nBalls; i++) {
		balls[i].drawBall();
		balls[i].resetBall();
	}
}

void ofApp::keyPressed(int key) {

}

void ofApp::mousePressed(int x, int y, int button) {

}