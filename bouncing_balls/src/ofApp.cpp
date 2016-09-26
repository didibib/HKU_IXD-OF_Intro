#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);

	gui.setup("Instellingen", "settings.xml");
	gui.add(show.set("Show", 1, 0, 1));
	gui.add(radius.set("Radius", 10, 1, 50));
	gui.add(speedX.set("SpeedX", 3, -10, 10));
	gui.add(speedY.set("SpeedY", 3, -10, 10));
	gui.add(color.set("Color", ofColor::white));

	//ofAddListener(arduino.EInitialized, this,)
}

void ofApp::update() {
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
		if(show == 1)balls[i].draw();

		for (int j = 0; j < balls.size(); j++) {
			if (i != j) {
				ofSetColor(color);
				if (balls[i].amountLines <= 3 && balls[j].amountLines <= 3) {
					ofDrawLine(balls[i].position.x, balls[i].position.y, balls[j].position.x, balls[j].position.y);
					balls[i].amountLines += 1;
					balls[j].amountLines += 1;
				}				
			}
		}		
	}
	gui.draw();
}

void ofApp::keyPressed(int key) {
	if (key == ' ') {
		if (balls.size() > 0) {
			balls.pop_back();
		}
	}	
}

void ofApp::mousePressed(int x, int y, int button) {
	cout << "\n" << "mousePressed    " << x << " , " << y << " , " << button;

	BouncyBall ball;
	ofVec2f pos = ofVec2f(x, y);
	ball = BouncyBall(pos, speedX, speedY, radius, color);
	balls.push_back(ball);
}

void ofApp::mouseReleased(int x, int y, int button) {
	cout << "\n" << "mouseReleased    " << x << " , " << y << " , " << button;
}