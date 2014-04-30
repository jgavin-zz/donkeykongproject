//  Created by Ryan Moran on 4/1/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.

////NOTE THAT FOR NOW USES PINK SPRITESHEET: this ended up being much simpler than trying to use two sheets

#include "Object.h"
#include "Hammer.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Hammer::Hammer() : Object(18, 10, 45, 315, 0, 0, 0, 1, 1, 1, 0, 0, 100){
    setAnimation();
}



//Function sets animation parameters according to state of mario
void Hammer::setAnimation(){
    switch(currentState){
        case 1:
           spritesheetx = 195;
           spritesheety = 263;
           currentFrame = 0;
           maxFrames = 1;
           height = 18;
           width = 10;
           break;
    }
}

