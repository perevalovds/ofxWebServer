#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Server");
	ofSetWindowShape(300, 200);
	port = 8910;
	server.start("httpdocs", port);
	server.addHandler(this, "actions/*");
	color.r = 255;
	color.g = 255;
	color.b = 255;
}


void ofApp::httpGet(string url) {
	string colorString = getRequestParameter("color");
	if(colorString=="red") {
		color.r = 255;
		color.g = 0;
		color.b = 0;
	} else if(colorString=="green") {
		color.r = 0;
		color.g = 255;
		color.b = 0;
	} else if(colorString=="blue") {
		color.r = 0;
		color.g = 0;
		color.b = 255;
	}
	httpResponse("Color value: " 
					+ ofToString(color.r) 
					+ " " + ofToString(color.g) 
					+ " " + ofToString(color.b));
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(color.r, color.g, color.b);
	ofFill();
	ofRect(0,0,ofGetWidth(), ofGetHeight());

	ofDrawBitmapStringHighlight("open in browser localhost:" + ofToString(port), 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

