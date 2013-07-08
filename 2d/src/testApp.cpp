#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255);
    ofSetVerticalSync(true);
    
    // This example shows three diferent 2d drawing methods:
    
    bDrawVertex = true;
    bDrawPath = false;
    bDrawMesh = false;
    
    // We setup path properties.
    
    path.setStrokeWidth(1);
    path.setStrokeColor(ofColor::red);
    path.setFillColor(180);
    path.setCurveResolution(2);
    //path.setPolyWindingMode(OF_POLY_WINDING_POSITIVE);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(180);
    
    // ofPath drawed from mouse moves:
    
    if(bDrawPath) {
        path.draw();
    }

    // ofMesh can be draw in diferent ways. The tesselation obtained from the path
    // can be seen if we draw the wireframe of the mesh:
    
    if(bDrawMesh) {
        //mesh.drawFaces();
        mesh.drawWireframe();
        //mesh.drawVertices();
    }
    
    // ofPath avoids uploading info every frame like drawing with ofVertex:
    
    if(bDrawVertex) {
        
        ofPushStyle(); // All style changes will only apply to objects drawn until next ofPopStyle.
        
            ofSetColor(180);
            ofNoFill();
        
            // We can cicle through ofPath points and draw it one by one with ofVertex on each draw.
        
            vector<ofPolyline> vPoly = path.getOutline();
            for(int i = 0; i < vPoly.size(); i++) {
                ofBeginShape();
                    vector<ofPoint> vPoints = vPoly[i].getVertices();
                    for(int t = 0; t < vPoints.size(); t++) {
                        ofVertex(vPoints[t].x,vPoints[t].y);
                        ofSetColor(255,0,0);
                        ofCircle(vPoints[t].x,vPoints[t].y,3);
                        ofSetColor(180);
                    }
                ofEndShape(true); // Auto finish the path.
            }
        
        ofPopStyle();
    
    }
    
    // Some info:
    
    string info;
    
    info = "Drawing with: ";
    if(bDrawVertex) info += "ofVertex + ofPolyline\n\n";
    if(bDrawPath) info += "ofPath\n\n";
    if(bDrawMesh) info += "ofMesh\n\n";
    info += "Instructions:\n";
    info += "Press 1,2,3 to change drawing method\n";
    info += "Drag the mouse to add points";
    
    ofDrawBitmapStringHighlight(info, ofPoint(10,20));
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    // Change drawing mode:
    
    if(key=='1') {
        bDrawVertex = true;
        bDrawPath = false;
        bDrawMesh = false;
    }
    
    if(key=='2') {
        bDrawVertex = false;
        bDrawPath = true;
        bDrawMesh = false;
    }
    
    if(key=='3') {
        bDrawVertex = false;
        bDrawPath = false;
        bDrawMesh = true;
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
    
    // Move the mouse to add points to ofPath and generate ofMesh form the path.
    
    path.curveTo(x,y);
    mesh = path.getTessellation();

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
     
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    // Close the path on mouse release.
    
    path.close();

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