//
//  Barrel.h
//
//  Created by Ryan Moran on 4/1/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//  Class for barrel object

#ifndef BARREL_H
#define BARREL_H

#include "Object.h"
#include <SDL/SDL.h>
#include <string>
using namespace std;

class Barrel : public Object{
    
public:
    Barrel();//Default Constructor
    
    void roll(); //handles rolling a barrel down the floors
    
    virtual void setAnimation();//Sets animation parameters according to animation state
    virtual void updateAnimation(); //Peach specific version of update animation
    virtual void move();

    int hitOil;
    double speedBoost;
    int type;
    
private:
    
    
};

#endif
