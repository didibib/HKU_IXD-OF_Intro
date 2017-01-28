#include "ofApp.h"

void ofApp::setup() {
	//ofToggleFullscreen();
	ofBackground(255);
	ofEnableDepthTest();

	// GUI settings
	gui.setup("Settings", "settings.xml");
	gui.add(spacing.set("Spacing", 50, 10, 50));
	gui.add(radius.set("Radius", 50, 1, 50));
	gui.add(zMult.set("Z Value", 3, 1, 20));
	gui.add(waveX.set("Wave", 17, 0, 20));

	// light setting
	light.setDirectional();
	light.setPosition(ofGetWidth() / 2, ofGetHeight() / 4, -30);
	light.lookAt(ofVec3f(ofGetWidth() / 2, ofGetHeight() / 2, 0));
	light.setDiffuseColor(ofColor(255, 255, 255));
	light.enable();

	// video opname settings
	vidGrabber.setVerbose(true);
	vidGrabber.setup(CAM_WIDTH, CAM_HEIGHT);

	// ruimte vrij maken in het geheugen 
	colorImg.allocate(CAM_WIDTH, CAM_HEIGHT);
	grayImage.allocate(CAM_WIDTH, CAM_HEIGHT);
	grayBg.allocate(CAM_WIDTH, CAM_HEIGHT);
	grayDiff.allocate(CAM_WIDTH, CAM_HEIGHT);
 
	bLearnBakground = true;
	threshold = 80; // threshold gebruiken we om de grote van de blobs mee te beïnvloeden 

	oldSpacing = spacing;
	drawGrid();

	isPressed = false;
}

void ofApp::update() {
	ofBackground(150, 150, 150);

	bool bNewFrame = false;

	vidGrabber.update();
	bNewFrame = vidGrabber.isFrameNew();

	if (bNewFrame) { // als dit een nieuwe frame is
		colorImg.setFromPixels(vidGrabber.getPixels()); // pak de pixels van de camera

		grayImage = colorImg; // zet de pixels in een grayImage
		if (bLearnBakground == true) { // als we de achtergrond in willen stellen dan slaan we deze pixels op in grayBg
			grayBg = grayImage;
			bLearnBakground = false;
		}

		// door het verschil met de background en wat de camera ziet te vergelijken weet oF welke objecten hij moet volgen
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);
		contourFinder.findContours(grayDiff, 20, (340 * 240) / 3, 10, true);
	}
	//mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());

	if (oldSpacing != spacing) { //  wanneer we in GUI de afstand tussen elementen aanpassen updaten we dat hier
		oldSpacing = spacing;
		drawGrid();
	}

	if (isPressed) { // wanneer de muisknop ingedrukt wordt .. 
		// .. dan gaan we elk element in het grid volgens de functie pointsym() een z-positie geven
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
	else { // wanneer de muisknop nog een keer ingedrukt wordt dan zetten we als terug in het grid
		for (int i = 0; i < gridSize; i++) {
			grid[i].setRadius(radius);
			grid[i].setPosZ(0);
		}
	}
}

void ofApp::draw() {
	ofEnableDepthTest(); // we tekenen op basis van de z-positie

	// de kleur van de elementen passen we aan afhankelijk van de afstand 
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

	// hier gaan blobs om de elementen tekenen
	for (int i = 0; i < contourFinder.nBlobs; i++) {
		contourFinder.blobs[i].draw(xPos, yPos);

		if (contourFinder.blobs[i].hole == false) { // teken geen blobs als het gaten zijn
			position.x = contourFinder.blobs[i].boundingRect.getCenter().x + xPos;
			position.y = contourFinder.blobs[i].boundingRect.getTop() + yPos;
		}
	}

	gui.draw();
}

void ofApp::drawGrid() { // een nested loop om een grid te maken
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

// ik had twee functie bedacht om het verschil in de z-positie van de elementen extremer te maken
// pointsym() gaf het gewenste effect

float ofApp::powpow(float _var) { // een machtsfunctie, deze gebruiken we voor de z-positie van de elementen
	float product;

	product = pow(_var, (0.25 * pow(_var, 0.5))) / 100; // 100 is de asymptoot, dus de max

	return product;
}

float ofApp::pointsym(float _var) { // een puntsymmetrische functie, deze gebruiken we voor de z-positie van de elementen
	float product;

	product = pow((_var - 3), 3) - 6 * pow((_var + 3), 2); // 20 is de asymptoo, dus de max

	return product;
}

void ofApp::mousePressed(int x, int y, int button) {
	if (button == 0) {
		isPressed = !isPressed;
	}
}

void ofApp::keyPressed(int key) {

	switch (key) {
	case ' ': // maak een foto van de achtergrond
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