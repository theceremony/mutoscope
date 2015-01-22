#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // --------------------------------------
    mvPlayer.loadMovie("test_1_720.mov");
    mvPlayer.stop();
	mvPlayer.setSpeed(1);
	ofEnableDepthTest();
	ofEnableLighting();
//	ofEnableAntiAliasing();

	
	point.setDiffuseColor(ofColor(255.0, 255.0, 255.0));
	point.setPointLight();
	point.setPosition(0, -200, 200);
	point.enable();
	
    // --------------------------------------
	
	for(int i=0; i < numberOfPlanes; i++){
		ofPlanePrimitive pl;
		pl.set(ofGetWidth(), ofGetHeight());
		pl.setResolution(2, 2);
		pl.resizeToTexture(mvPlayer.getTextureReference(),.5);
		pl.setPosition(ofGetWidth()/2, ofGetHeight() - (pl.getHeight()/2), 0);
		pl.rotate(-((360 /numberOfPlanes) * i),1,0,0);
		pl.rotateAround(-((360 /numberOfPlanes) * i), ofVec3f(1,0,0), ofVec3f(0,ofGetHeight() + rotationOffset,0));
		planes.push_back(pl);
		pRot.push_back(0);
		delay.push_back(0);
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
		pRot[i] = floor(planes[i].getOrientationEuler().x);
		float up = delay[i] * rotationSpeed;
		planes[i].rotate(-rotationSpeed - up,1,0,0);
		planes[i].rotateAround(-rotationSpeed - up, ofVec3f(1,0,0), ofVec3f(0,ofGetHeight()+ rotationOffset,0));
		delay[i] = 0;
		ofLog(OF_LOG_NOTICE, "plane rotation: " +  ofToString(pRot[i]));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(255,255);
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
