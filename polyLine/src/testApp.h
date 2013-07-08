#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
	
        void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
    private:
    
    
        ofCamera polylineCamera;
        ofPolyline polyline;
        // ofPolyline is slower than ofPath when we draw but it's better for calculations.
        
        ofPoint prevLookAt;
        int positionInPoly;
    
        ofEasyCam camera;
        // This is like a pre-made camera that we use for quick prototyping.
        // It can be interacted with the mouse.
    
};
