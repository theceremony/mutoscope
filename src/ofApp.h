#pragma once

#include "ofMain.h"
#include "ofxManyMouse.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp, public ofxManyMouse{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseScroll(int device, int axis, int value);
		void mouseDisconnect(int device);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	

	

	ofVideoPlayer           mvPlayer;
	ofFbo                   fbo;
	ofPixels                fboPixels;
	ofImage                 image;
	ofTexture				planeText;
	ofPlanePrimitive        plane1;
	ofLight					point;
	
	int						numberOfPlanes	= 10;
	float					rotationSpeed	= 1;
	int						rotationOffset	= 50;
	bool					hasResized		= false;
	int						alphaLevel		= 20;
	int						currentFrame;
	
	vector<ofPlanePrimitive> planes;

};
