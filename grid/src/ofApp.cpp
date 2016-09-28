#include "ofApp.h"

void ofApp::setup() {
	ofBackground(255);
	gui.setup("Settings", "settings.xml");
	gui.add(radius.set("Radius", 20, 1, 50));
	gui.add(zValue.set("Z Value", 3, 1, 10));
	gui.add(colorMultR.set("R multiplier", 2, 1, 5));
	gui.add(colorMultG.set("G multiplier", 1, 1, 5));
	gui.add(colorMultB.set("B multiplier", 1, 1, 5));
	
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
		float distance = ballPos.distance(mousePos);
		float distanceRadius = ofMap(distance, 0, ofGetWidth(), radius, 0);
		float distancePosZ = ofMap(distance, 0, ofGetWidth(), ofGetWidth()/zValue, 0);

		grid[i].setRadius(distanceRadius);
		grid[i].setPosZ(distancePosZ);
	}
}

void ofApp::draw() {
	for (int i = 0; i < gridSize; i++) {
		ofVec2f ballPos = ofVec2f(grid[i].position.x, grid[i].position.y);
		float distance = ofMap(ballPos.distance(mousePos), 0, ofGetWidth(), 0, 255);

		ofColor color = ofColor(distance * colorMultR, distance * colorMultG, distance * colorMultB);
		grid[i].setColor(color);

		grid[i].draw();
		//ofDrawLine(grid[i].posX, grid[i].posY, mousePos.x, mousePos.y);		
	}	

	gui.draw();
}