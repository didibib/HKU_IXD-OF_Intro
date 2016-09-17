#include "ofApp.h"


void ofApp::setup() {
	ofSetBackgroundColor(255);
	cam.setDistance(160);

	for (int i = 0; i < nBalls; i++) {
		balls[i] = BouncyBall();
	}
	
	//ofSetColor(0);
	pyramid.set(radius, height, radiusSegments, heightSegments);
}

void ofApp::update() {
	for (int i = 0; i < nBalls; i++) {
		balls[i].updateBall();
	}
}

void ofApp::draw() {
	cam.begin();
	pointlight.enable();
	//pointlight.setPointLight();
	//for (int i = 0; i < nBalls; i++) {
	//	balls[i].drawBall();
	//}

	pyramid.setPosition(0, 0, 0);
	pyramid.draw();

	tweakTriangles();
	pointlight.disable();
	cam.end();
}

void ofApp::tweakTriangles() {
	pyramid.setMode(OF_PRIMITIVE_TRIANGLES);
	vector<ofMeshFace> triangles = pyramid.getMesh().getUniqueFaces();

	float displacement = sin(ofGetElapsedTimef() * 4);
	cout << "\n" << displacement;
	for (size_t i = 0; i < triangles.size() - 2; i++) {
		ofVec3f normal = triangles[i].getFaceNormal();
		for (int j = 0; j < 3; j++) {
			triangles[i].setVertex(j, triangles[i].getVertex(j) + normal * displacement);
			ofDrawLine(triangles[i].getVertex(j).x    , triangles[i].getVertex(j).y    , triangles[i].getVertex(j).z,
				       triangles[i + 2].getVertex(j).x, triangles[i + 2].getVertex(j).y, triangles[i + 2].getVertex(j).z);
		}
	}
	pyramid.getMesh().setFromTriangles(triangles);
	
	pyramid.drawWireframe();
}

void ofApp::keyPressed(int key) {

}

void ofApp::mousePressed(int x, int y, int button) {

}