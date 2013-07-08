//
//  celestialBody.cpp
//  solarsystem
//
//  Created by Pelayo M. on 26/04/13.
//
//

#include "celestialBody.h"

void celestialBody::setup(float _size, float _orbitRadius, float _speed, string _name) {

    size = _size;
    name = _name;
    
    orbitRadius = _orbitRadius;
    speed = _speed;
    
    longitude = 0;
    parent = NULL;
    
}

void celestialBody::update() {

    orbit(longitude,0,orbitRadius,ofVec3f(0,0,0));
    //rotate(longitude*3,0,1,0);

    longitude += speed*ofGetLastFrameTime();
    if(longitude>360) longitude -= 360;

}

void celestialBody::customDraw() {
    ofSphere(0,0,0,size);
}