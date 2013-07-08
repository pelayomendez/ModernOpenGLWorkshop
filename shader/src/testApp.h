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
    
        ofMesh mesh;
        ofShader shader;
        // Basically a shader is a small program that runs on the graphics card (GPU).
        // We are going to use it to modify how pixels of an image are rendered.
        // The shader program it«s applied at the same time to all the pixels of the image - no like a for{}
        // We can also pass parameters to it.
    
        ofImage image;
        ofImage diagram;
		
};
