#include "ofApp.h"

//This example demonstrates sending oF screen to webpage.
//It uses ofxKu addon for base64 encoding (only ofxKuUtilsBase64.h,.cpp files are required)

#include "ofxKuUtilsBase64.h"

ofImage img;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Server");
	ofSetWindowShape(300, 200);
	port = 8910;
	server.start("httpdocs", port);
	server.addHandler(this, "actions/*");

	int w = 256;
	int h = 128;
	img.allocate(w, h, OF_IMAGE_COLOR);
	img.setColor(ofColor(128));
}


void ofApp::httpGet(string url) {
	//Sending screen image
	
	//We need to use mutex, because httpGet is callback, which can appear at any time
	//(even during JPEG conversion)
	
	mutex.lock();

	//https://stackoverflow.com/questions/5363957/retrieve-an-image-from-the-server-store-it-in-localstorage-and-display-it
	//https://stackoverflow.com/questions/20877813/auto-refresh-images-in-html
	//string colorString = getRequestParameter("color");

	//Encode to JPEG base64
	//Note: you can use ofxTurboJpeg for faster conversion; 
	//but note that it uses different quality settings (from 0 to 100)
	ofBuffer buffer;
	ofImageQualityType jpeg_quality = OF_IMAGE_QUALITY_MEDIUM;
	ofSaveImage(img, buffer, OF_IMAGE_FORMAT_JPEG, jpeg_quality);
	
	string base64 = ofxKuUtilsBase64::encode((unsigned char*)buffer.getBinaryBuffer(), buffer.size());
	
	//Send response
	httpResponse("Content-Type: image/jpeg", base64);

	mutex.unlock();

}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(64);
	ofSetColor(255);
	float time = ofGetElapsedTimef();
	float rad = ofMap(sin(time), -1, 1, 20, 50);
	ofFill();
	ofCircle(ofGetWidth() / 2, ofGetHeight() / 2, rad);


	ofDrawBitmapStringHighlight("open in browser localhost:" + ofToString(port), 20, 20);

	//capture screen
	mutex.lock();
	img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	mutex.unlock();
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

