//
//  Mario.cpp
//  SDL_Tutorial
//
//  Created by Jacob Gavin on 3/20/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include "Object.h"
#include "Mario.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Mario::Mario() : Object(20, 20, 130, 435, 0, 0, 0, 1, 1, 2, 0, 0, 100){
    direction = 1;
    onFloor = 1;
    ay = 0;
    vy = 0;
    floorNumber = 1;
}


void Mario::move(){
    double dt = .5;
    ay = 2;
    if( climbing == 0) vy = vy + ay * dt;
    xpos = xpos + vx * dt;
    ypos = ypos + vy * dt;

    if (xpos <= 0) {
	xpos = 2;
	vx = 0;
    }

    if (xpos >= 531) {
	xpos = 529;
	vx = 0;
    }


    //cout << "xpos: " << xpos << endl;
    //cout << "ypos: " << ypos << endl;
}


//Function sets animation parameters according to state of mario
void Mario::setAnimation(){
    switch(currentState){
        case 1: //Facing right
            spritesheetx = 134;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 20;
            break;
        case 2: //Running right
            spritesheetx = 153;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 20;
            break;
        case 3: //Running left
            spritesheetx = 92;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 2;
            height = 20;
            width = 20;
            break;
        case 4: //Running left2
            spritesheetx = 172;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 2;
            height = 20;
            width = 20;
            break;
        case 5: //Running left with hammer
            spritesheetx = 69;
            spritesheety = 40;
            currentFrame = 1;
            maxFrames = 2;
            height = 31;
            width = 27;
            break;
        case 6: //Running right with hammer
            spritesheetx = 183;
            spritesheety = 40;
            currentFrame = 1;
            maxFrames = 2;
            height = 31;
            width = 27;
            break;
        case 7: //Facing left with hammer
            spritesheetx = 97;
            spritesheety = 40;
            currentFrame = 1;
            maxFrames = 2;
            height = 31;
            width = 27;
            break;
        case 8: //Facing left with hammer
            spritesheetx = 156;
            spritesheety = 40;
            currentFrame = 1;
            maxFrames = 2;
            height = 31;
            width = 27;
            break;
        case 9: //Climbing
            spritesheetx = 123;
            spritesheety = 20;
            currentFrame = 1;
            maxFrames = 2;
            height = 20;
            width = 19;
            break;
        case 10: //Stopped on ladder
            spritesheetx = 123;
            spritesheety = 20;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 19;
            break;
        case 11: //Facing ladder
            spritesheetx = 142;
            spritesheety = 20;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 19;
            break;
        case 12: //Running left
            spritesheetx = 92;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 20;
            break;
        case 13: //Jumpng right
            spritesheetx = 194;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 20;
            break;
            
            
    }
}

void Mario::handle_input(SDL_Event event)
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: if(checkOnLadder(0)) {vy = -2; climbing = 1; currentState = 9; setAnimation();} break;
            case SDLK_DOWN: if(checkOnLadder(1)) {vy = 2; climbing = 1; currentState = 9; setAnimation();} break;
            case SDLK_LEFT: vx = -4; currentState = 3; climbing = 0; direction = 0; setAnimation(); break;
            case SDLK_RIGHT: vx = 4; currentState = 4; climbing = 0; setAnimation(); direction = 1; break;
            case SDLK_SPACE:
                if(onFloor){
                    onFloor = 0;
                    vy = -10; climbing = 0; ypos--;
                    if(direction == 1) currentState = 13;
                    setAnimation();
                    break;
                    if(direction == 0) currentState = 12;
                    setAnimation();
                    break;
                    
                }
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: if (!onFloor) {vy = 0; currentState = 10; climbing = 0; setAnimation();} else {vx = 0; currentState = 2; climbing = 0; setAnimation();}  break;
            case SDLK_DOWN: if (!onFloor) {vy = 0; currentState = 10; climbing = 0; setAnimation();} else {vx = 0; currentState = 2; climbing = 0; setAnimation();}  break;
            case SDLK_LEFT: vx = 0; currentState = 1; climbing = 0; setAnimation(); break;
            case SDLK_RIGHT: vx = 0; currentState = 2; climbing = 0; setAnimation(); break;
            case SDLK_SPACE: climbing = 0; 
        }
    }
}

int Mario::checkOnLadder(int direction){
    cout << floorNumber << endl;
    if(floorNumber == 1)
    {
        if ((xpos + width/2 >= 200 && xpos + width/2 <= 220)||(xpos + width/2 >= 430 && xpos + width/2 <= 450))
        {
            if (direction == 0)
            {
                return 1;
            }
        }
    }
    if(floorNumber == 2)
    {
        if ((xpos + width/2 >= 80 && xpos + width/2 <= 100)||(xpos + width/2 >= 236 && xpos + width/2 <= 256))
        {
            if (direction == 0)
            {
                return 1;
            }
        }
    }
    if(floorNumber == 3)
    {
        if ((xpos + width/2 >= 155 && xpos + width/2 <= 175)||(xpos + width/2 >= 275 && xpos + width/2 <= 295)||(xpos + width/2 >= 432 && xpos + width/2 <= 452))
        {
            if (direction == 0)
            {
                return 1;
            }
        }
    }
    if(floorNumber == 4)
    {
        if ((xpos + width/2 >= 79 && xpos + width/2 <= 99)||(xpos + width/2 >= 196 && xpos + width/2 <= 216)||(xpos + width/2 >= 393 && xpos + width/2 <= 413))
        {
            if (direction == 0)
            {
                return 1;
            }
        }
    }
    if(floorNumber == 5)
    {
        if ((xpos + width/2 >= 235 && xpos + width/2 <= 255)||(xpos + width/2 >= 431 && xpos + width/2 <= 451))
        {
            if (direction == 0)
            {
                return 1;
            }
        }
    }
    if(floorNumber == 6)
    {
        if ((xpos + width/2 >= 191 && xpos + width/2 <= 211)||(xpos + width/2 >= 216 && xpos + width/2 <= 236)||(xpos + width/2 >= 334 && xpos + width/2 <= 354))
        {
            cout << "Ladder found" << endl;
            if (direction == 0)
            {
                return 1;
            }
        }
    }
    if(floorNumber == 7)
    {
        cout << "Ladder not found" << endl;
        if ((xpos + width/2 >= 191 && xpos + width/2 <= 211)||(xpos + width/2 >= 216 && xpos + width/2 <= 236)||(xpos + width/2 >= 334 && xpos + width/2 <= 354))
        {
            cout << "Ladder found" << endl;
            if (direction == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
