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
		AnimatedOfPlanePrimative(ofTexture &tex);
		AnimatedOfPlanePrimative(ofTexture &tex,int startStep);
		void setup(ofTexture &tex,int startStep);
		void update();
		void drawFaces();
		void draw();
		void rotate(float deg);
		void setInitialRotation(float rot);
		void gotMessage(ofMessage msg);
		void onKeyframe(ofxPlaylistEventArgs& args);
		float getCurrentRotation();

	private:
		ofTexture		_texture;
		float			_initialRotation;
		float			_animRot		= 0;
		float			_r				= 0;
		int				_step			= 0;
		int				_steps			= 360; // decrese number of steps to speed up timing of animation;
		bool			_isAnimating	= true;
		ofxEasingExpo*	_ease			= new ofxEasingExpo;
};

#endif
