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
		ofImage					catImage;
		ofTexture				planeText;
		ofPlanePrimitive        plane1;
		ofxAssimpModelLoader    planeModel;
		bool					hasResized = false;
	
	int x,y;
	int alphaLevel = 20;
	int currentFrame;

};
