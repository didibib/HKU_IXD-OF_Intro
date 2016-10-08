#include "ofApp.h"

void ofApp::setup(){
	ofSetBackgroundColor(255);

	gui.setup();

	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor(255, 255, 255));
	light.enable();
}

void ofApp::update(){

}

void ofApp::draw(){
	gui.draw();

	ofEnableDepthTest();
	cam.begin();
	
	doos(500.0);

	cam.end();
	ofDisableDepthTest();
}

void doos(float _a) {
	float r = _a / 2;
	ofSetColor(0);
	ofDrawLine(-r, -r, r, r, -r, r);
	ofDrawLine(r, -r, r, r, r, r);
	ofDrawLine(r, r, r, -r, r, r);
	ofDrawLine(-r, r, r, -r, -r, r);
}

void ofApp::keyPressed(int key){

}

void ofApp::mousePressed(int x, int y, int button){

}
