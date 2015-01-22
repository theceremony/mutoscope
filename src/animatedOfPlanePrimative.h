//
//  animatedOfPlanePrimative.h
//  muto_scroll_app
//
//  Created by Jeramy Morrill on 1/22/15.
//
//

#ifndef __muto_scroll_app__animatedOfPlanePrimative__
#define __muto_scroll_app__animatedOfPlanePrimative__

#include "ofMain.h"
#include "ofxPlaylist.h"

class AnimatedOfPlanePrimative : public ofPlanePrimitive{
	
	public:
		void setup(ofTexture tex);
		void update();
		void drawFaces();
		void draw();
		void rotate(float deg);
		void setInitialRotation(float rot);
		float getCurrentRotation();
		ofxPlaylist	plist;
	private:
		float		initialRotation;
		bool		isAnimating;

};

#endif
