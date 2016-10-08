#include "ofApp.h"

void ofApp::setup(){
	gui.setup("Settings", "settings.xml");
	gui.add(rotateSpeedX.set("X", 0, 0, 9.0));
	gui.add(rotateSpeedY.set("Y", 0, 0, 9.0));
	gui.add(rotateSpeedZ.set("Z", 0, 0, 9.0));
}

void ofApp::update(){

}

void ofApp::draw(){

}