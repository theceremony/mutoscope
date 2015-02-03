//
//  animatedOfPlanePrimative.cpp
//  muto_scroll_app
//
//  Created by Jeramy Morrill on 1/22/15.
//
//

#include "animatedOfPlanePrimative.h"

AnimatedOfPlanePrimative::AnimatedOfPlanePrimative(void){}
AnimatedOfPlanePrimative::AnimatedOfPlanePrimative(ofTexture tex){
	setup(tex,0);
}
AnimatedOfPlanePrimative::AnimatedOfPlanePrimative(ofTexture tex,int startStep){
	setup(tex,startStep);
}
void AnimatedOfPlanePrimative::setup(ofTexture tex,int startStep){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofxKeyframeAnimRegisterEvents(this);
	_step = startStep;
	setResolution(2, 2);
	set(ofGetWidth(), ofGetHeight());
	resizeToTexture(tex,.5);
}
void AnimatedOfPlanePrimative::draw(){
	ofPlanePrimitive::draw();
}
void AnimatedOfPlanePrimative::drawFaces(){
	ofPlanePrimitive::drawFaces();
}

void AnimatedOfPlanePrimative::update(){
	
	if(_isAnimating){
		_step += 1;
		if(_step == _steps) _step = 0;
		_r = ofxEasingExt::easeInOutS(_ease, _step,0 , -360, _steps);
		float diff = _r - getCurrentRotation();
		rotate(diff);
	}
}

void AnimatedOfPlanePrimative::rotate(float deg){
	ofPlanePrimitive::rotate(deg,1,0,0);
	ofPlanePrimitive::rotateAround(deg, ofVec3f(1,0,0), ofVec3f(0,ofGetHeight(),0));
}

void AnimatedOfPlanePrimative::setInitialRotation(float rot){
	_initialRotation = rot;
	ofPlanePrimitive::setOrientation(ofVec3f(rot,0,0));
}

float AnimatedOfPlanePrimative::getCurrentRotation(){
	return getOrientationEuler().x;
}

void AnimatedOfPlanePrimative::onKeyframe(ofxPlaylistEventArgs& args){
	ofLog(OF_LOG_VERBOSE) << "Keyframe Event received for (" << args.pSender << "): " << args.message << ": " << ofGetFrameNum();
}

void AnimatedOfPlanePrimative::gotMessage(ofMessage msg){
	
}