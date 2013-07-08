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
        // vertex -> triangles
        // texture coordinates -> for every vertex [0..1] or [0..texture size]
        // vertex color -> for every vertex
    
        ofVboMesh vbomesh;
        // Saves one copy on RAM and another in the graphics card.
        // Graphics card copy only is modified when the RAM copy changes.
    
        ofImage image;

};
