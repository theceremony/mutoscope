#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofEnableDepthTest();
    // --------------------------------------
    mvPlayer.loadMovie("test_1.mov");
    mvPlayer.play();
	
    x = y = 0;
	
	catImage.loadImage("cat-hat.jpg");
    
    // --------------------------------------
    plane1.set(1024, 768);
    plane1.setPosition(1024/2, 768/2, 0);
    plane1.setResolution(2, 2);
	plane1.resizeToTexture(mvPlayer.getTextureReference(),.1);
    // --------------------------------------
	
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
    
    plane1.rotate(1, -10, 0, 0.0);
}

//--------------------------------------------------------------
void ofApp::draw(){

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
