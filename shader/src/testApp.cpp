#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    int mult = 2;
    ofBackground(255);
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh.addVertex(ofVec3f(50,50));
    mesh.addVertex(ofVec3f(350,50));
    mesh.addVertex(ofVec3f(350,350));
    mesh.addVertex(ofVec3f(50,350));
    
    mesh.addTexCoord(ofVec2f(0,0));
    mesh.addTexCoord(ofVec2f(300,0));
    mesh.addTexCoord(ofVec2f(300,300));
    mesh.addTexCoord(ofVec2f(0,300));
    
    shader.load("noise");
    //ofDisableArbTex();
    image.loadImage("test.jpg");

    diagram.loadImage("diagram.jpg");
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    ofTranslate(300, 180);
    shader.begin();
    shader.setUniformTexture("tex", image.getTextureReference(), 0);
    shader.setUniform1f("time", (ofGetElapsedTimeMillis()%1000)/1000.);
    mesh.draw();
    shader.end();
    ofPopMatrix();
    
    /////////////////////////////////////////////////////////
    // Some info:
    /////////////////////////////////////////////////////////
    
    string info;
    info = "ofShader.\n\n";
    info += "Instructions:\n";
    info += "You can find the shaders in the data folder of the example.\n";
    info += "A shader is a small program that runs on the graphics card (GPU).\n";
    info += "The vertex shader handles the geometry / The fragment shader handles how fragment (!=pixels) are rendered.\n";
    
    ofDrawBitmapStringHighlight(info, ofPoint(10,20));
    
    diagram.draw(ofGetWidth()-510, ofGetHeight()-115);
    
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