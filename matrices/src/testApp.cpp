#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetVerticalSync(true);
    
    // We put screen dimensions into a variable:
    
    w = ofGetWidth();
    h = ofGetHeight();
    
    
    // Identity Matrix Transform:
    
    transform.makeIdentityMatrix();
    transform.rotate(45, 0, 0, 1);
    transform.translate(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    // Model / Projection Matrix:
    // TODO: This is not working properly.
    // modelView.makeIdentityMatrix();
    // projection.makePerspectiveMatrix(1, w/h, 0, 100);
    
    // Setup cameras:
    
    camera.setFov(60);
    camera.setPosition(0, 0, 0);
    camera.lookAt(ofVec3f(0,0,1),ofVec3f(0,-1,0));
    
    topcamera.setFov(60);
    topcamera.setPosition(0, 60, 5);
    topcamera.lookAt(ofVec3f(0,0,10),ofVec3f(0,0,1));
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Reference lines:
    
    ofSetColor(220);
    ofLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    ofLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
    
    // Identity Matrix Transform:
    
    ofPushMatrix();
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofMultMatrix(transform);
        ofRect(0,0,w/2,w/2);
        ofSetRectMode(OF_RECTMODE_CORNER);
    ofPopMatrix();
    
    // Model / Projection Matrix:
    // TODO: This is not working properly.
    /*
    ofSetMatrixMode(OF_MATRIX_MODELVIEW);
    ofLoadMatrix(modelView);
    ofSetMatrixMode(OF_MATRIX_PROJECTION);
    ofLoadMatrix(projection);
    */
     
    // Draw Cameras:
    
    ofNoFill();
    ofSetColor(80);
    topcamera.begin(ofRectangle(w-340,h-260,320,240));
        camera.begin(ofRectangle(0,0,w,h));
        ofSphere(0, 0, 10, 2);
        camera.end();
        ofSphere(0, 0, 10, 2);
        camera.draw();
    topcamera.end();
    
     /////////////////////////////////////////////////////////
    // Some info:
    /////////////////////////////////////////////////////////
    
    string info;
    info = "Cameras & Matrix Transformations.\n\n";
    info += "Instructions:\n";
    info += "Use cursors to move the camera.\n";
    
    ofDrawBitmapStringHighlight(info, ofPoint(10,20));
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if(key == OF_KEY_UP) {
        camera.move(0, 0, 1);
        camera.lookAt(camera.getPosition()+ofVec3f(0,0,1),ofVec3f(0,-1,0));
    }
    
    if(key == OF_KEY_DOWN) {
        camera.move(0, 0, -1);
        camera.lookAt(camera.getPosition()+ofVec3f(0,0,1),ofVec3f(0,-1,0));
    }
    
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