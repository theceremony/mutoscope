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

void AnimatedOfPlanePrimative::update(){}

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