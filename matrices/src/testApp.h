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
    
        ofMatrix4x4 transform;
    
        ofMatrix4x4 modelView;
        ofMatrix4x4 projection;
    
        int w;
        int h;

        ofCamera camera;
        ofCamera topcamera;
    
};
