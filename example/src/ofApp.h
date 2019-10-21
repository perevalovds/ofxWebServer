#pragma once

#include "ofMain.h"
#include "ofxWebServer.h"

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
	
	ofColor color;
	
	int port;

};


