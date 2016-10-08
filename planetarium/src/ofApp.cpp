#include "ofApp.h"

void ofApp::setup(){
	ofSetBackgroundColor(0);

	planet.setup("mals");
	params.add(planet.planetParameterGroup);

	gui.setup(params);

	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor::white);
	light.enable();
}

void ofApp::update(){
	planet.update();
}

void ofApp::draw(){
	gui.draw();

	cam.begin();

	if (drawLight) light.draw();
	if (drawGrid) ofDrawGrid(200);

	planet.draw();

	cam.end();

	
}

void ofApp::keyPressed(int key) {
	if (key == 'g') {
		drawGrid = !drawGrid;
	}
	else if (key == 'l') {
		drawLight = !drawLight;
	}
	else if (key == 'k') {
	
	}
}