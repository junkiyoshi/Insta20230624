#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255);

	ofSetLineWidth(1.5);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	float base_radius = 230;
	float radius = 50;
	for (int base_deg = 0; base_deg < 360; base_deg += 6) {
		
		ofPushMatrix();
		ofRotateY(base_deg);

		int deg_start = base_deg * 3 + ofGetFrameNum() * 6;
		for (int deg = deg_start; deg < deg_start + 120; deg += 1) {

			ofSetColor(255, ofMap(deg, deg_start, deg_start + 120, 0, 255));
			auto location = glm::vec3(0, radius * sin(deg * DEG_TO_RAD), base_radius + radius * cos(deg * DEG_TO_RAD));
			auto next = glm::vec3(0, radius * sin((deg + 1) * DEG_TO_RAD), base_radius + radius * cos((deg + 1) * DEG_TO_RAD));

			ofDrawLine(location, next);
		}

		ofDrawSphere(glm::vec3(0, radius * sin((deg_start + 120) * DEG_TO_RAD), base_radius + radius * cos((deg_start + 120) * DEG_TO_RAD)), 2);

		ofPopMatrix();
	}

	this->cam.end();
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}