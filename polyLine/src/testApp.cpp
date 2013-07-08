#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetVerticalSync(true);
    ofSetCircleResolution(4);
    
    // We define a polyLine that will hold camera's path:
    
    int mult = 4;
    
    polyline.curveTo(0,0,0);
    polyline.curveTo(0,0,-10*mult);
    polyline.curveTo(0,-5,-20*mult);
    polyline.curveTo(10,-15,-30*mult);
    polyline.curveTo(0,-15,-40*mult);
    polyline.curveTo(-10,-5,-50*mult);
    polyline.curveTo(-5,5,-60*mult);
    polyline.curveTo(0,0,-70*mult);
    polyline.curveTo(5,-5,-80*mult);
    polyline.curveTo(10,-10,-90*mult);
    polyline.curveTo(15,-15,-100*mult);
    
    // Obtain intermediate steps in the polyline:
    
    polyline = polyline.getResampledBySpacing(1);
    
    positionInPoly = 0;
    prevLookAt = polyline[1];
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Update main camera position:
    
    polylineCamera.setPosition(polyline[positionInPoly]);
    
    // Grab next point data with some easing and update camera lookAt vector:
    
    prevLookAt = prevLookAt*.9 + polyline[positionInPoly+1]*.5;
    polylineCamera.lookAt(prevLookAt,ofVec3f(0,-1,0));
    
    // We loop through the points of the line_
    
    positionInPoly += 1;
    positionInPoly %= polyline.size()-1;

}

//--------------------------------------------------------------
void testApp::draw(){
  
    // Refrence camera:
    
    camera.setPosition(0, 0, -50);
    
    camera.begin(ofRectangle(ofGetWidth()-340,ofGetHeight()-260,320,240));
        ofPushStyle();
            ofSetColor(0);
            ofNoFill();
            polyline.draw();
            polylineCamera.draw();
        ofPopStyle();
    camera.end();
    
    // Main camera:
    
    polylineCamera.begin();
    polyline.draw();
    ofPushStyle();
    ofSetColor(80);
    ofNoFill();
    for(int i =0;i<polyline.size();i++) {
        ofCircle(polyline[i], 1.5);
    }
    ofFill();
    polylineCamera.end();
    
    /////////////////////////////////////////////////////////
    // Some info:
    /////////////////////////////////////////////////////////
    
    string info;
    info = "ofCamera folllows of Polyline.\n";
    info+= "ofPolyline is slower than ofPath for drawing but it's better for calculations";
    
    ofDrawBitmapStringHighlight(info, ofPoint(10,20));
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
   
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
   
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}