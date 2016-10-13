#include "ofApp.h"

void ofApp::setup() {
	for (int i = 0; i < VOICES; i++) {
		voicePlayer[i].load("voice" + ofToString(i + 1) + ".wav");
		voicePlayer[i].setLoop(true);
		voicePlayer[i].setPaused(true);
		voicePlayer[i].play();
	}

	ofSoundSetVolume(0.2);
}

void ofApp::update() {
	ofSoundUpdate();
}

void ofApp::draw() {

}

void ofApp::keyPressed(int key) {
	if (key == '1') {
		//voicePlayer.setPaused(voicePlayer.isPlaying());
	}
	if (key == 'q') {
		voicePlayer[0].setPaused(voicePlayer[0].isPlaying());
	}
	else if (key == 'w') {
		voicePlayer[1].setPaused(voicePlayer[1].isPlaying());
	}
	else if (key == 'e') {
		voicePlayer[2].setPaused(voicePlayer[2].isPlaying());
	}
	else if (key == 'a') {
		voicePlayer[3].setPaused(voicePlayer[3].isPlaying());
	}
	else if (key == 's') {
		voicePlayer[4].setPaused(voicePlayer[4].isPlaying());
	}
	else if (key == 'd') {
		voicePlayer[5].setPaused(voicePlayer[5].isPlaying());
	}
}
