#include "ofApp.h"

void ofApp::setup(){
	ofBackground(255);
	ofSetSmoothLighting(true);

	gui.setup("Parameters", "settings.xml");
	gui.add(radius.set("Radius", 10, 0, 100));
	gui.add(resolution.set("Resolution", 10, 0, 10));	

	sphere.set(radius, resolution); 
}

void ofApp::update(){	
	cam.setDistance(0);
	//spotlight.setPosition(0, 0, 0);

	spinX = sin(ofGetElapsedTimef()*.5f);
	spinY = cos(ofGetElapsedTimef()*.5f);	
	tweakFaces();
}

void ofApp::draw(){
	gui.draw();

	//spotlight.enable();
	cam.begin();	

	ofFill();
	ofSetColor(0);	

	//sphere.rotate(spinX, 1.0, 0.0, 0.0);
	//sphere.rotate(spinY, 0, 1.0, 0.0);
	sphere.setPosition(0, 0, 0);
	sphere.draw();
	
	cam.end();
	//spotlight.disable();
}

void ofApp::tweakFaces() {
	sphere.setMode(OF_PRIMITIVE_TRIANGLES);
	vector<ofMeshFace> triangles = sphere.getMesh().getUniqueFaces();

	displacement = sin(ofGetElapsedTimef() * 4);
	for (size_t i = 0; i < triangles.size() - 5; i++) {
		normal = triangles[i].getFaceNormal();
		for (int j = 0; j < 3; j++) {
			triangles[i].setVertex(j, triangles[i].getVertex(j) + normal * displacement);
			ofDrawLine(triangles[i].getVertex(j).x    , triangles[i].getVertex(j).y    , triangles[i].getVertex(j).z,
				       triangles[i + 1].getVertex(j).x, triangles[i + 1].getVertex(j).y, triangles[i + 1].getVertex(j).z);
		}
	}
	sphere.getMesh().setFromTriangles(triangles);
	sphere.draw();
}

void ofApp::keyPressed(int key){
	if (key == ' ') {
		sphere.set(radius, resolution);
	}
}