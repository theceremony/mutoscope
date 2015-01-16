#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // --------------------------------------
    mvPlayer.loadMovie("test_1.mov");
    mvPlayer.stop();
    // --------------------------------------
    fbo.allocate(1024,768);
    // --------------------------------------
    
    x = y = 0;
    
    
    // --------------------------------------
    plane1.set(1024, 768);
    plane1.setPosition(1024/2, 768/2, 0);
    plane1.setResolution(2, 2);
    // --------------------------------------
    
    // Settings -----------------------------
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    // --------------------------------------
}

//--------------------------------------------------------------
void ofApp::update(){
    mvPlayer.update();
    currentFrame = mvPlayer.getCurrentFrame();
    if(mvPlayer.isFrameNew()){
        ofLog(OF_LOG_NOTICE, "CURRENT FRAME:" +  ofToString(mvPlayer.getCurrentFrame()));
    }
    plane1.rotate(1, -1, 0, 0.0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (mvPlayer.isFrameNew()) {
        mvPlayer.draw(x,y, 100, 100);
        mvPlayer.getTextureReference().bind();
    }
    
    plane1.draw();
    //plane1.drawWireframe();
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
