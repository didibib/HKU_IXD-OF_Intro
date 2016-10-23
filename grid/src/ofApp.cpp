#include "ofApp.h"

void ofApp::setup() {
	//ofToggleFullscreen();
	ofBackground(255);
	ofEnableDepthTest();

	gui.setup("Settings", "settings.xml");
	gui.add(spacing.set("Spacing", 50, 10, 50));
	gui.add(radius.set("Radius", 50, 1, 50));
	gui.add(zMult.set("Z Value", 3, 1, 20));
	//gui.add(colorMultR.set("R multiplier", 1, 1, 5));
	//gui.add(colorMultG.set("G multiplier", 1, 1, 5));
	//gui.add(colorMultB.set("B multiplier", 1, 1, 5));
	gui.add(waveX.set("Wave", 17, 0, 20));

	light.setDirectional();
	light.setPosition(ofGetWidth() / 2, ofGetHeight() / 4, -30);
	light.lookAt(ofVec3f(ofGetWidth() / 2, ofGetHeight() / 2, 0));
	light.setDiffuseColor(ofColor(255, 255, 255));
	light.enable();

	vidGrabber.setVerbose(true);
	vidGrabber.setup(CAM_WIDTH, CAM_HEIGHT);

	colorImg.allocate(CAM_WIDTH, CAM_HEIGHT);
	grayImage.allocate(CAM_WIDTH, CAM_HEIGHT);
	grayBg.allocate(CAM_WIDTH, CAM_HEIGHT);
	grayDiff.allocate(CAM_WIDTH, CAM_HEIGHT);

	bLearnBakground = true;
	threshold = 80;

	oldSpacing = spacing;
	drawGrid();

	isPressed = false;
}

void ofApp::update() {
	ofBackground(150, 150, 150);

	bool bNewFrame = false;

	vidGrabber.update();
	bNewFrame = vidGrabber.isFrameNew();

	if (bNewFrame) {
		colorImg.setFromPixels(vidGrabber.getPixels());

		grayImage = colorImg;
		if (bLearnBakground == true) {
			grayBg = grayImage;
			bLearnBakground = false;
		}

		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		contourFinder.findContours(grayDiff, 20, (340 * 240) / 3, 10, true);
	}
	//mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());

	if (oldSpacing != spacing) {
		oldSpacing = spacing;

		drawGrid();
	}

	if (isPressed) {
		for (int i = 0; i < gridSize; i++) {
			ofVec2f ballPos = ofVec2f(grid[i].position.x, grid[i].position.y);
			float distance = ballPos.distance(position);
			float waveRadius = ofMap(distance, 0, ofGetWidth(), radius, 0);
			//float distancePosZ = ofMap(distance, 0, ofGetWidth(), ofGetWidth() / zMult, 0);
			//float eye = ofMap(distance, 0, ofGetWidth(), 2, -10);
			float wavePos = ofMap(distance, 0, ofGetWidth(), waveX, 0);
			float zPos = pointsym(wavePos);

			grid[i].setRadius(waveRadius);
			grid[i].setPosZ(zPos);
		}
	}
	else {
		for (int i = 0; i < gridSize; i++) {
			grid[i].setRadius(radius);
			grid[i].setPosZ(0);
		}
	}
}

void ofApp::draw() {
	ofEnableDepthTest();

	for (int i = 0; i < gridSize; i++) {
		ofVec2f ballPos = ofVec2f(grid[i].position.x, grid[i].position.y);
		float distance = ofMap(ballPos.distance(position), 0, ofGetWidth(), 255, 0);

		ofColor color = ofColor(distance, distance, distance);
		grid[i].setColor(color);

		grid[i].draw();
	}

	ofDisableDepthTest();

	ofSetHexColor(0xffffff);
	//colorImg.draw(20, 20);
	//grayImage.draw(360, 20);
	grayBg.draw(0, ofGetHeight() - CAM_HEIGHT);
	grayDiff.draw(CAM_WIDTH, ofGetHeight() - CAM_HEIGHT);

	ofFill();
	ofSetHexColor(0x333333);
	float xPos = CAM_WIDTH * 2;
	float yPos = ofGetHeight() - CAM_HEIGHT;
	ofDrawRectangle(xPos, yPos, CAM_WIDTH, CAM_HEIGHT);
	ofSetHexColor(0xffffff);

	contourFinder.draw(xPos, yPos);

	for (int i = 0; i < contourFinder.nBlobs; i++) {
		contourFinder.blobs[i].draw(xPos, yPos);

		if (contourFinder.blobs[i].hole == false) {
			position.x = contourFinder.blobs[i].boundingRect.getCenter().x + xPos;
			position.y = contourFinder.blobs[i].boundingRect.getTop() + yPos;
		}

		//ofSetColor(255);
		//if (contourFinder.blobs[i].hole) {
		//	ofDrawBitmapString("hole",
		//		contourFinder.blobs[i].boundingRect.getCenter().x + xPos,
		//		contourFinder.blobs[i].boundingRect.getCenter().y + yPos);
		//}
	}

	gui.draw();
}

void ofApp::drawGrid() {
	cols = ofGetWidth() / spacing;
	rows = ofGetHeight() / spacing;
	gridSize = cols * rows;

	int index = 0;
	for (int x = 0; x < cols; x++) {
		for (int y = 0; y < rows; y++) {
			grid[index] = Ball(x, y, spacing, radius);
			index += 1;
		}
	}
}

float ofApp::powpow(float _var) {
	float product;

	product = pow(_var, (0.25 * pow(_var, 0.5))) / 100; // 100 is de asymptoot, dus de max

	return product;
}

float ofApp::pointsym(float _var) {
	float product;

	product = pow((_var - 3), 3) - 6 * pow((_var + 3), 2); // 20 is de asymptoo, dus de max && deze functie creert een bol vorm

	return product;
}

void ofApp::mousePressed(int x, int y, int button) {
	if (button == 0 && isPressed == true) {
		isPressed = false;
	}
	else if (button == 0 && isPressed == false) {
		isPressed = true;
	}
}

void ofApp::keyPressed(int key) {

	switch (key) {
	case ' ':
		bLearnBakground = true;
		break;
	case '+':
		threshold++;
		if (threshold > 255) threshold = 255;
		break;
	case '-':
		threshold--;
		if (threshold < 0) threshold = 0;
		break;
	}
}