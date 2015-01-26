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
		AnimatedOfPlanePrimative(void);
		AnimatedOfPlanePrimative(ofTexture tex);
		void setup(ofTexture tex);
		void update();
		void drawFaces();
		void draw();
		void rotate(float deg);
		void setInitialRotation(float rot);
		void gotMessage(ofMessage msg);
		void onKeyframe(ofxPlaylistEventArgs& args);
		float getCurrentRotation();
	private:
		float		initialRotation;
		float		animRot = 0;
		bool		isAnimating;
		ofxPlaylist	plist;
};

#endif
