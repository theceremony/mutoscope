#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // --------------------------------------
    mvPlayer.loadMovie("test_1.mov");
    mvPlayer.stop();
	ofEnableDepthTest();
	ofEnableLighting();
	ofEnableAntiAliasing();

	
	point.setDiffuseColor(ofColor(255.0, 255.0, 255.0));
	point.setPointLight();
	point.setPosition(0, -200, 300);
	point.setSpotConcentration(10);
	point.enable();
	
    // --------------------------------------
	
	for(int i=0; i < numberOfPlanes; i++){
		ofPlanePrimitive pl;
		pl.set(ofGetWidth(), ofGetHeight());
		pl.setResolution(2, 2);
		pl.resizeToTexture(mvPlayer.getTextureReference(),.6);
		pl.setPosition(ofGetWidth()/2, ofGetHeight() - (pl.getHeight()/2), 0);
		pl.rotate(-((360 /numberOfPlanes) * i),1,0,0);
		pl.rotateAround(-((360 /numberOfPlanes) * i), ofVec3f(1,0,0), ofVec3f(0,ofGetHeight(),0));
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
		planes[i].rotate(-rotationSpeed,1,0,0);
		planes[i].rotateAround(-rotationSpeed, ofVec3f(1,0,0), ofVec3f(0,ofGetHeight(),0));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(0,0);
	for(int i=0; i < planes.size(); i++){
		mvPlayer.getTextureReference().bind();
		planes[i].draw();
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
