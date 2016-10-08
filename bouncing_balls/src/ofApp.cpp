#include "ofApp.h"

#define PIN_ADD 11
#define PIN_DELETE 12
#define PIN_POTMETER 1
#define PIN_LDR 0

void ofApp::setup() {
	ofBackground(0);

	gui.setup("Instellingen", "settings.xml");
	gui.add(show.set("Show", 1, 0, 1));
	gui.add(radius.set("Radius", 10, 1, 50));
	gui.add(speedX.set("SpeedX", 3, -10, 10));
	gui.add(speedY.set("SpeedY", 3, -10, 10));
	gui.add(speedZ.set("SpeedZ", 3, -10, 10));
	gui.add(color.set("Color", ofColor::white));

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	arduino.connect("COM4");
	arduino.sendFirmwareVersionRequest();
}

void ofApp::update() {
	arduino.update();

	for (int i = 0; i < balls.size(); i++) {
		balls[i].update();

		if (balls[i].radius != radius) {
			balls[i].radius = radius;
		}
		if (balls[i].speed.x != speedX) {
			balls[i].speed.x != speedX;
		}
		if (balls[i].speed.y != speedY) {
			balls[i].speed.y != speedY;
		}

		for (int j = 0; j < balls.size(); j++) {
			if (i != j) {
				if (balls[i].position.distance(balls[j].position) <= radius) {
					balls[i].speed *= -1;
					balls[j].speed *= -1;
				}
			}
		}

		ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
		if (balls[i].position.distance(mousePos) < radius / 2) {
			balls[i].position = mousePos;
		}
	}
}

void ofApp::draw() {
	for (unsigned int i = 0; i < balls.size(); i++) {
		if (show == 1)balls[i].draw();

		for (int j = 0; j < balls.size(); j++) {
			if (i != j) {
				ofSetColor(color);
				float distance = balls[i].position.distance(balls[j].position);
				if (distance <= 300) {
					ofDrawLine(balls[i].position.x, balls[i].position.y, balls[j].position.x, balls[j].position.y);
				}
			}
		}
	}
	gui.draw();
}
void ofApp::addBall() {
	BouncyBall ball;
	ofVec3f pos = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	ball = BouncyBall(pos, speedX, speedY, radius, color);
	balls.push_back(ball);
}

void ofApp::deleteBall() {
	if (balls.size() > 0) {
		balls.pop_back();
	}
}

void ofApp::keyPressed(int key) {
	if (key == ' ') {
		deleteBall();
	}
}

void ofApp::mousePressed(int x, int y, int button) {

}


void ofApp::mouseReleased(int x, int y, int button) {
	BouncyBall ball;
	ofVec2f pos = ofVec2f(x, y);
	ball = BouncyBall(pos, speedX, speedY, radius, color);
	balls.push_back(ball);
}

void ofApp::setupArduino(const int& version) {
	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_ADD, ARD_INPUT);
	arduino.sendDigitalPinMode(PIN_DELETE, ARD_INPUT);
	arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);
	arduino.sendAnalogPinReporting(PIN_LDR, ARD_ANALOG);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pin) {
	int value = arduino.getDigital(pin);
	ofLogNotice() << "Digital pin" << pin << " changed to " << value << endl;

	if (pin == PIN_ADD && value == 1) {
		addBall();
	}
	else if (pin == PIN_DELETE && value == 1) {
		deleteBall();
	}
}

void ofApp::analogPinChanged(const int& pin) {
	int value = arduino.getAnalog(pin);
	ofLogNotice() << "Analog pin" << pin << " changed to " << value << endl;

	if (pin == PIN_POTMETER) {
		radius = ofMap(value, 0, 1024, radius.getMin(), radius.getMax());
	}
	else if (pin == PIN_LDR) {
		float colorHue = ofMap(value, 0, 1024, 0, 255);
		ofColor newColor = ofColor(color.get());
		newColor.setHue(colorHue);
		color = newColor;
	}
}