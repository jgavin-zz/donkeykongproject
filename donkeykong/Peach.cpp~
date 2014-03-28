//
//  Peach.cpp
//  donkeykong
//
//  Created by Jacob Gavin on 3/27/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

//
//  Peach.cpp
//  SDL_Tutorial
//
//  Created by Jacob Gavin on 3/25/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//

#include "Object.h"
#include "Peach.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Peach::Peach() : Object(21, 20, 250, 100, 0, 0, 0, 1, 1, 2, 0, 0, 100){
    setAnimation();
}

void Peach::updateAnimation(){
    oldTime = SDL_GetTicks();
    currentFrame++;
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
    //(*this).setAnimation();
}


//Function sets animation parameters according to state of mario
void Peach::setAnimation(){
    switch(currentState){
        case 1: //running left
            spritesheetx = 102;
            spritesheety = 124;
            currentFrame = 1;
            maxFrames = 2;
            height = 21;
            width = 22;
            break;
        case 2: //running right
            spritesheetx = 154;
            spritesheety = 124;
            currentFrame = 1;
            maxFrames = 2;
            height = 21;
            width = 22;
            break;
    }
}
