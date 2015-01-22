#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // --------------------------------------
    mvPlayer.loadMovie("test_1_720.mov");
    mvPlayer.stop();
	mvPlayer.setSpeed(1);
	ofEnableDepthTest();
	ofEnableLighting();
	ofEnableAntiAliasing();
	
	point.setDiffuseColor(ofColor(255.0, 255.0, 255.0));
	point.setPointLight();
	point.setPosition(0, -200, 200);
	point.enable();
	
    // --------------------------------------
	
	for(int i=0; i < numberOfPlanes; i++){
		AnimatedOfPlanePrimative pl;
		pl.setup(mvPlayer.getTextureReference());
		pl.setPosition(ofGetWidth()/2, ofGetHeight() - (pl.getHeight()/2), 0);
		pl.rotate(-((360 /numberOfPlanes) * i));
		planes.push_back(pl);
	}
	
    // Settings -----------------------------
    ofSetFrameRate(30);
    // --------------------------------------
	
}

//--------------------------------------------------------------
void ofApp::update(){
    mvPlayer.update();
    
    if(mvPlayer.isFrameNew()){
        currentFrame = mvPlayer.getCurrentFrame();
		ofLog(OF_LOG_NOTICE, "CURRENT FRAME:" +  ofToString(mvPlayer.getCurrentFrame()));
    }
	
	for(int i=0; i < planes.size(); i++){
		planes[i].rotate(-rotationSpeed);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
//	ofClear(255,255);
	for(int i=0; i < planes.size(); i++){
		mvPlayer.getTextureReference().bind();
		planes[i].drawFaces();
		mvPlayer.getTextureReference();
	}
	point.draw();
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
