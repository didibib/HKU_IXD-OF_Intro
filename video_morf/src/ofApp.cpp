#include "ofApp.h"

void ofApp::setup(){
	ofBackground(255);

	video.load("ferrofluid.webm");
	video.play();
	video.setLoopState(OF_LOOP_PALINDROME);

	vidW = video.getWidth();
	vidH = video.getHeight();

	grabber.listDevices();
	grabber.setDeviceID(0);
	grabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);
	grabber.setDesiredFrameRate(30);

	workspace.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);
	index = ofVec2f(0, 0);
}

void ofApp::update(){
	//video.update();
	grabber.update();

	if (grabber.isFrameNew()) {
		ofPixels pixels = grabber.getPixels();

		for (int y = 0; y < pixels.getHeight(); y++) {
			for (int x = 0; x < pixels.getWidth(); x++) {

				ofColor colCompare = pixels.getColor(x, y);
				ofColor colNext = pixels.getColor(x + 1, y + 1);

				if (colCompare != colNext) {
					ofSetColor(0);
				}

				//col.r = 255 - col.r;
				//col.g = 255 - col.g;
				//col.b = 255 - col.b;
				
				//workspace.setColor(x, y, col);
			}
		}

		image.setFromPixels(workspace);
	}
}

void ofApp::draw(){
	//video.draw(ofGetWidth()/2 - vidW/2, ofGetHeight()/2 - vidH/2);
	//grabber.draw(ofGetWidth() / 2 - CAM_WIDTH / 2, ofGetHeight() / 2 - CAM_HEIGHT / 2);
	image.draw(ofGetWidth() / 2 - CAM_WIDTH / 2, ofGetHeight() / 2 - CAM_HEIGHT / 2);
}

void ofApp::keyPressed(int key){

}