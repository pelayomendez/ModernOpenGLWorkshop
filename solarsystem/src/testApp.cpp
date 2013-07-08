#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);

    // We setup diferent bodies wich extend ofNode:
    
    sun.setup(100,0,0,"sun");
    moon.setup(10, 50, 2, "moon");
    earth.setup(30, 200, 1, "earth");
    
    // We setup parent/child relation between ofNodes
    
    earth.setParent(sun);
    moon.setParent(earth);
    
    camera.setTarget(sun);
    ofNoFill();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    earth.update();
    moon.update();
    sun.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushStyle();
    ofSetColor(0);
    camera.begin();
        sun.draw();
        earth.draw();
        moon.draw();
    camera.end();
    ofPopStyle();
    
    /////////////////////////////////////////////////////////
    // Some info:
    /////////////////////////////////////////////////////////
    
    string info;
    info = "ofNode.\n\n";
    info += "A generic 3d object in space with transformation.\n";
    info += "With API to move around in global or local space";
    info += "and virtual draw method\n\n";
    info += "Instructions:\n";
    info += "Use the mouse to interact with the camera.\n";
    
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