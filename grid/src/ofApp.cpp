#include "ofApp.h"

void ofApp::setup(){
	ofBackground(255);
	
	int index = 0;
	for (int x = 0; x < cols; x++) {
		for (int y = 0; y < rows; y++) {
			grid[index] = Ball(x, y, spacing, radius);
			index += 1;
		}
	}
}

void ofApp::update(){

}

void ofApp::draw(){
	for (int i = 0; i < nGrid; i++) {
		grid[i].draw(); 
	}
}

void ofApp::keyPressed(int key){

}
