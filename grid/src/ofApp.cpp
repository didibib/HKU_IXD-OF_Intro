#include "ofApp.h"

void ofApp::setup() {
	ofBackground(255);
	gui.setup("Settings", "settings.xml");
	gui.add(color.set("Color", ofColor::white));
	gui.add(radius.set("Radius", 10, 1, 50));
	//gui.add(increaseInc.set("Increment", 1, 1, 10));
	//gui.add(multrN.set("Noise Multiplyer", 50, 1, 200));

	cout << "\n" << "cols: " << cols << "  rows: " << rows;

	int index = 0;
	for (int x = 0; x < cols; x++) {
		for (int y = 0; y < rows; y++) {
			grid[index] = Ball(x, y, spacing, radius);
			index += 1;
		}
	}
}

void ofApp::update() {
	mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());

	for (int i = 0; i < gridSize; i++) {
		ofVec2f ballPos = ofVec2f(grid[i].position.x, grid[i].position.y);
		distance = ofMap(ballPos.distance(mousePos), 0, ofGetWidth(), radius, 0);
		grid[i].setRadius(distance);		
	}
}

void ofApp::draw() {
	for (int i = 0; i < gridSize; i++) {
		float tmpc_f = ofMap(distance, radius, 0, 0, 255);
		ofColor tmpc = ofColor(tmpc_f);
		grid[i].setColor(tmpc);
		grid[i].draw();
		//ofDrawLine(grid[i].posX, grid[i].posY, mousePos.x, mousePos.y);		
	}	

	gui.draw();
}

void ofApp::keyPressed(int key) {

}

// ------------------------------------------

void ofApp::v1_update() {
	a += 0.001;
	disNoise = ofNoise(a) * multrN;
	displacement = (int)disNoise;
}

void ofApp::v1_draw() {
	ofSetColor(0);
	increment = 0;
	for (int i = 0; i < gridSize + 1; i++) {
		//grid[i].draw();

		if (displacement > 0) {
			if (i%displacement == 3) ofDrawLine(grid[i].posX, grid[i].posY, mousePos.x, mousePos.y);
			if (i%displacement == 0) grid[i].draw();
			if (i%displacement == 4) ofDrawLine(grid[i].posX, grid[i].posY, grid[i+1].posX, grid[i+1].posY);

			increment += increaseInc;
		}
	}
}