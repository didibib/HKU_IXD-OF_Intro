#include "ofApp.h"

void ofApp::setup(){
	ofBackground(255);
	
	int index = 0;
	for (int x = 0; x < cols + 1; x++) {
		for (int y = 0; y < rows + 1; y++) {
			grid[index] = Ball(x, y, spacing, radius);
			index += 1;
		}
	}
}

void ofApp::update(){
	
}

void ofApp::draw(){
	ofVec3f mousePos = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0);

	for (int i = 0; i < gridSize + 1; i++) {
		grid[i].draw(); 

		ofVec3f objPos = ofVec3f(grid[i].position.x, grid[i].position.y, grid[i].position.z);
		ofDrawLine(grid[i].position.x, grid[i].position.y, mousePos.x, mousePos.y);
		//float distance = objPos.distance(mousePos);
	}
}

void ofApp::keyPressed(int key){
	
}