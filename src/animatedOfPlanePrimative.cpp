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
	setup(tex);
}
void AnimatedOfPlanePrimative::setup(ofTexture tex){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofxKeyframeAnimRegisterEvents(this);
	
	setResolution(2, 2);
	set(ofGetWidth(), ofGetHeight());
	resizeToTexture(tex,.5);
	
	plist.addKeyFrame( Playlist::Action::event(this,"START"))
		.addKeyFrame( Playlist::Action::tween(1000.f,2000.f,&animRot,-360,Playlist::TWEEN_EXPO) )
		.addKeyFrame( Playlist::Action::event(this,"END"));

}
void AnimatedOfPlanePrimative::draw(){
	ofPlanePrimitive::draw();
}
void AnimatedOfPlanePrimative::drawFaces(){
	ofPlanePrimitive::drawFaces();
}

void AnimatedOfPlanePrimative::update(){
	plist.update();
	float diff = animRot - getCurrentRotation();
//	ofLog(OF_LOG_NOTICE, "CURRENT FRAME:" +  ofToString(ofGetFrameNum()));
//	ofLog(OF_LOG_NOTICE, "duration:" +  ofToString(plist.duration));
//	ofLog(OF_LOG_NOTICE, "diff:" +  ofToString(diff));
	rotate(diff);
}

void AnimatedOfPlanePrimative::rotate(float deg){
	ofPlanePrimitive::rotate(deg,1,0,0);
	ofPlanePrimitive::rotateAround(deg, ofVec3f(1,0,0), ofVec3f(0,ofGetHeight(),0));
}

void AnimatedOfPlanePrimative::setInitialRotation(float rot){
	initialRotation = rot;
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