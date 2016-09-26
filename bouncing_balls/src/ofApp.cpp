#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);

	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 40, 10, 100));
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
				ofSetColor(ofColor::white);
				ofDrawLine(balls[i].position.x, balls[i].position.y, balls[j].position.x, balls[j].position.y);
				if (balls[i].position.distance(balls[j].position) <= radius) {
					balls[i].speed *= -1;
					balls[j].speed *= -1;
				}
			}			
		}
	}
}

void ofApp::draw() {
	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].draw();
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