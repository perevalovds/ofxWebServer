#pragma once

#include "ofMain.h"
#include "ofxWebServer.h"

//This example demonstrates sending oF screen to webpage and also sending mouse clicks from web.
//It uses ofxKu addon for base64 encoding (only ofxKuUtilsBase64.h,.cpp files are required).

class ofApp : public ofBaseApp, public ofxWSRequestHandler {

public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	ofxWebServer server;
	void httpGet(string url);
	
	
	int port;

	ofMutex mutex;

	//mouse coords received from web, used for drawing circle
	float x_, y_;

};


