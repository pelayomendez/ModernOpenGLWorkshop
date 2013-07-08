#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetVerticalSync(true);
    
    // Mesh Mode:
    //mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    // Add vertex to the mesh:
    
    mesh.addVertex(ofVec3f(0,0));
    mesh.addVertex(ofVec3f(300,0));
    mesh.addVertex(ofVec3f(300,300));
    mesh.addVertex(ofVec3f(0,300));
    
    // Add index to the mesh:
    
    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(2);
    
    mesh.addIndex(2);
    mesh.addIndex(3);
    mesh.addIndex(0);
    
    // Add colors to the mesh:
    
    mesh.addColor(ofColor(125,125,125));
    mesh.addColor(ofColor(125,125,125));
    mesh.addColor(ofColor(0,0,0));
    mesh.addColor(ofColor(0,0,0));

    image.loadImage("texture.png");
    // Makes ofImage not to allocate texture if not needed:
    //image.setUseTexture(false);
    
    // How Texture is resized:
    //image.getTextureReference().setTextureMinMagFilter(GL_NEAREST,GL_NEAREST);
    image.getTextureReference().setTextureMinMagFilter(GL_LINEAR,GL_LINEAR);
    
    // Texture coordinates:

    mesh.addTexCoord(ofVec2f(0,0));
    mesh.addTexCoord(ofVec2f(image.width,0));
    mesh.addTexCoord(ofVec2f(image.width,image.height));
    mesh.addTexCoord(ofVec2f(0,image.height));
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    
        // Draw mesh:
    
        ofTranslate(40,240);
        mesh.draw();
        //mesh.drawWireframe();
    
        // Original image:
    
        ofTranslate(320,0);
        image.draw(0,0,300,300);
    
        // Add texture to the mesh:
    
        ofTranslate(320,0);
        image.getTextureReference().bind();
        mesh.draw();
        image.getTextureReference().unbind();
    
    ofPopMatrix();
    
    /////////////////////////////////////////////////////////
    // Some info:
    /////////////////////////////////////////////////////////
    
    string info;
    info = "ofMesh\n\n";
    info += "vertex -> triangles\n";
    info += "texture coordinates -> for every vertex [0..1] or [0..texture size]\n";
    info += "vertex color -> for every vertex\n\n";
    info += "ofVboMesh\n\n";
    info += "VboMesh saves one copy on RAM and another in the graphics card.\n";
    info += "Graphics card copy only is modified when the RAM copy changes.";
    
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