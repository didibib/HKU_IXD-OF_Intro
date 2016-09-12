#include "ofApp.h"
#include "BouncyBall.h"

static const int nBalls = 10;
BouncyBall balls[nBalls];

//--------------------------------------------------------------
void ofApp::setup() {
	for (int i = 0; i < nBalls; i++) {
		balls[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < nBalls; i++) {
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < nBalls; i++) {
		balls[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}