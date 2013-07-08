#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255);
    ofSetVerticalSync(true);
    
    // This example shows three diferent ofFbo drawing methods:
    
    bDrawFbo = true;
    bDrawDepth = false;
    bDrawTexture = false;
    
    // We start by setting the ofFbo properties.
    
    ofFbo::Settings settings;
    settings.width = ofGetWidth();
    settings.height = ofGetHeight();
    settings.internalformat = GL_RGBA32F_ARB; // Info levels.
    settings.textureTarget = GL_TEXTURE_2D;
    settings.depthStencilInternalFormat = GL_DEPTH_COMPONENT32_ARB;
    settings.depthStencilAsTexture = true;
    settings.useDepth = true;
    settings.numSamples = 16; // Useful for border easing.
    settings.useStencil = false;
    fbo.allocate(settings);
    
    fbo.begin();
        ofClear(255,255,255,255);
    fbo.end();
    
    ofEnableNormalizedTexCoords();
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    glEnable(GL_DEPTH_TEST);
    
    //////////////////////////////////////////////////////////
    // 1. DRAW INSIDE THE FBO
    //////////////////////////////////////////////////////////
    
    // We draw inside the FBO.
    fbo.begin();
        ofClear(255);
        ofSetColor(255,0,0);
        ofSphere(mouseX,ofGetHeight()/2,mouseY,120);
    fbo.end();
    // At this point We clear the screen but the info drawed is inside ofFBO.
    ofClear(255);
    
    //////////////////////////////////////////////////////////
    // 2. DRAW THE FBO ON THE SCREEN
    //////////////////////////////////////////////////////////
    
    ofSetColor(255,255,255,255);
    
    // We draw the entire fbo.
    
    if(bDrawFbo) {
        fbo.draw(0, 0);
    }
    
    // We draw the depth map of the fbo.
    
    if(bDrawDepth) {
        fbo.getDepthTexture().draw(0,0);
    }
    
    // We apply the fbo tetxure to a sphere.
    
    if(bDrawTexture) {
        ofPushStyle();
            ofNoFill();
            fbo.getTextureReference().bind();
            ofSphere(ofGetWidth()/2,ofGetHeight()/2,220);
            fbo.getTextureReference().unbind();
        ofPopStyle();
    }
        
    glDisable(GL_DEPTH_TEST);
    
    //////////////////////////////////////////////////////////
    // Some info:
    //////////////////////////////////////////////////////////
    
    string info;
    
    info = "ofFbo Example\n";
    if(bDrawFbo) info += "Draw the FBO to the screen.\n\n";
    if(bDrawDepth) info += "Draw the depth map of the fbo.\n\n";
    if(bDrawTexture) info += "Apply the fbo as texture.\n\n";
    info += "Instructions:\n";
    info += "Press 1,2,3 to change drawing method\n";
    info += "Press 's' to save depth map as .png\n";
    
    ofDrawBitmapStringHighlight(info, ofPoint(10,20));
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    // Change drawing mode:
    
    if(key=='1') {
        bDrawFbo = true;
        bDrawDepth = false;
        bDrawTexture = false;
    }
    
    if(key=='2') {
        bDrawFbo = false;
        bDrawDepth = true;
        bDrawTexture = false;
    }
    
    if(key=='3') {
        bDrawFbo = false;
        bDrawDepth = false;
        bDrawTexture = true;
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key=='s') {
        // TODO: Saved image looks weird ¿?
        ofFloatPixels depthPixels;
        fbo.getDepthTexture().readToPixels(depthPixels);
        ofSaveImage(depthPixels,"depth.png");
    }
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