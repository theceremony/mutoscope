#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofEnableDepthTest();
    // --------------------------------------
    mvPlayer.loadMovie("test_1.mov");
    mvPlayer.stop();
	
    x = y = 0;
	
	catImage.loadImage("cat-hat.jpg");
    
    // --------------------------------------
    plane1.set(ofGetWidth(), ofGetHeight());

    plane1.setResolution(2, 2);
	plane1.resizeToTexture(mvPlayer.getTextureReference(),.5);
	plane1.setPosition(ofGetWidth()/2, ofGetHeight() - (plane1.getHeight()/2), 0);

	
    // --------------------------------------
    // Settings -----------------------------
    ofSetFrameRate(60);
    // --------------------------------------
	
}

//--------------------------------------------------------------
void ofApp::update(){
    mvPlayer.update();
    
    if(mvPlayer.isFrameNew()){
        currentFrame = mvPlayer.getCurrentFrame();
		ofLog(OF_LOG_NOTICE, "CURRENT FRAME:" +  ofToString(mvPlayer.getCurrentFrame()));
    }
    
	
	plane1.rotate(-rotationSpeed,1,0,0);
	
	plane1.rotateAround(-rotationSpeed, ofVec3f(1,0,0), ofVec3f(0,ofGetHeight(),0));
//	plane1.setPosition(ofGetWidth()/2, ofGetHeight(), 0);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(0,0);
	mvPlayer.getTextureReference().bind();
	plane1.draw();
	mvPlayer.getTextureReference();
	
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
    if(button == 0){
        mvPlayer.setFrame(currentFrame + 1);
    }else if(button == 2){
        mvPlayer.setFrame(currentFrame - 1);
    }
    ofLog(OF_LOG_NOTICE, "Mouse pressed:" + ofToString(button));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseScroll(int device, int axis, int value){
    ofLog(OF_LOG_NOTICE, "Mouse scroll:" + ofToString(axis));
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
