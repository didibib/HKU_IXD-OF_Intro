#include "ofApp.h"

void ofApp::setup() {
	ofBackground(255);
	gui.setup("Instellingen", "settings.xml");
	gui.add(increaseInc.set("Increment", 1, 1, 10));
	gui.add(multrN.set("Noise Multiplyer", 50, 1, 200));

	int index = 0;
	for (int x = 0; x < cols + 1; x++) {
		for (int y = 0; y < rows + 1; y++) {
			grid[index] = Ball(x, y, spacing, radius);
			index += 1;
		}
	}
}

void ofApp::update() {
	v1_update();
}

void ofApp::draw() {

	v1_draw();

	gui.draw();
}

void ofApp::keyPressed(int key) {

}

void ofApp::v1_update() {
	a += 0.001;
	disNoise = ofNoise(a) * multrN;
	displacement = (int)disNoise;
}

void ofApp::v1_draw() {
	ofVec3f mousePos = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0);
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