//
//  celestialBody.h
//  solarsystem
//
//  Created by Pelayo M. on 26/04/13.
//
//

#pragma once
#include "ofMain.h"

#ifndef __solarsystem__celestialBody__
#define __solarsystem__celestialBody__

class celestialBody : public ofNode {
  
    public:
    
        void setup(float _size, float _orbitRadius, float _speed, string _name);
        void update();
        void customDraw();
    
    private:
    
        float size;
        string name;
    
        float speed;
        float orbitRadius;
    
        float latitude;
        float longitude;
    
        celestialBody * parent;
    
};

#endif /* defined(__solarsystem__celestialBody__) */
