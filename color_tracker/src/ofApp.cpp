#include "ofApp.h"

void ofApp::setup(){
	grabber.setup(CAM_WIDTH, CAM_HEIGHT, true);

	rgbImage.allocate(CAM_WIDTH, CAM_HEIGHT);
	hsvImage.allocate(CAM_WIDTH, CAM_HEIGHT);
	
	hue.allocate(CAM_WIDTH, CAM_HEIGHT);
	saturation.allocate(CAM_WIDTH, CAM_HEIGHT);
	value.allocate(CAM_WIDTH, CAM_HEIGHT);

	filtered.allocate(CAM_WIDTH, CAM_HEIGHT);

	mouseClicked = 0;
}

void ofApp::update(){
	grabber.update();

	if (grabber.isFrameNew()) {
		rgbImage.setFromPixels(grabber.getPixels().getData(), CAM_WIDTH, CAM_HEIGHT);
		rgbImage.mirror(false, true);

		hsvImage = rgbImage;
		hsvImage.convertRgbToHsv();
		hsvImage.convertToGrayscalePlanarImages(hue, saturation, value);
		// VRAAG: WAT GEBEURT HIER OOK ALWEER ?

		for (int i = 0; i < CAM_WIDTH * CAM_HEIGHT; i++) {
			for(int j = 0; j < SELECTED; j++)
			// VRAAG: WAAROM PAKKEN WE DE HUE ?
			if (ofInRange(hue.getPixels()[i], selectedHue[j] - MARGIN, selectedHue[j] + MARGIN)) {
				filtered.getPixels()[i] = 255;
			}
			else {
				filtered.getPixels()[i] = 0;
			}
		}
	}
	filtered.flagImageChanged();
}

void ofApp::draw(){
	rgbImage.draw(0, 0);
	hsvImage.draw(CAM_WIDTH, 0);
	filtered.draw(CAM_WIDTH * 2, 0);

	hue.draw(0, CAM_HEIGHT);
	saturation.draw(CAM_WIDTH, CAM_HEIGHT);
	value.draw(CAM_WIDTH * 2, CAM_HEIGHT);
}

void ofApp::keyPressed(int key){

}

void ofApp::mousePressed(int x, int y, int button) {
	selectedHue[mouseClicked] = hue.getPixels()[x + y * CAM_WIDTH];
	cout << "selectedHue: " << selectedHue << endl;

	mouseClicked++;
	if (mouseClicked >= 2) mouseClicked = 0;
}