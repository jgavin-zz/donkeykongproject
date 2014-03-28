//
//  Mario.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/20/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//  Class for mario object

#ifndef MARIO_H
#define MARIO_H

#include "Object.h"
#include <SDL/SDL.h>
#include <string>
using namespace std;

class Mario : public Object{
    
public:
    Mario();//Default Constructor
    
    void move();
    
    
    virtual void setAnimation();//Sets animation parameters according to animation state
    
    void handle_input(SDL_Event);
    int onFloor;
    
private:
    
    int direction;
    
};

#endif
