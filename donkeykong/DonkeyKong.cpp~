//Random change
//  Created by Jacob Gavin on 3/27/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.

#include "Object.h"
#include "DonkeyKong.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
DonkeyKong::DonkeyKong() : Object(33, 43, 94, 150, 0, 0, 0, 3, 0, 2, 0, 0, 100){
    setAnimation();
}

void DonkeyKong::updateAnimation(){
    oldTime = SDL_GetTicks();
    currentFrame++;
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
    
}


//Function sets animation parameters according to state of mario
void DonkeyKong::setAnimation(){
    switch(currentState){
        case 1: //standing still
            spritesheetx = 58;
            spritesheety = 150;
            currentFrame = 1;
            maxFrames = 1;
            height = 33;
            width = 47;
            break;
        case 2: //pound chest
            spritesheetx = 57;
            spritesheety = 149;
            currentFrame = 0;
            maxFrames = 4;
            height = 33;
            width = 47;
            break;
        case 3: //throw barrel
            spritesheetx = 8;
            spritesheety = 149;
            currentFrame = 2;
            maxFrames = 6;
            height = 33;
            width = 48;
    }
}
