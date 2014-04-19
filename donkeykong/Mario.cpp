
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
    previousFloor = 1;
    onLadder = 0;
    alive = 1;
    hasHammer = 0;
    hadHammer = 0;
    hammerStartTime = 0;
    jumping = 0;
}


void Mario::move(){
    double dt = .12; ay = 1.5;//student machine ay = 1.5 and jake's comp ay = 8
    if( climbing == 0){
        vy += (ay * dt);
        xpos += (vx * dt);
        ypos += (vy * dt);
    }
    else{
        xpos += (vx * dt);
        ypos += (vy * dt);
    }
    
    if (xpos <= 0) {
        xpos = 2;
        vx = 0;
    }
    
    if (xpos >= 531) {
        xpos = 529;
        vx = 0;
    }
    
    if ( ypos <= 49) {
        ypos = 50;
        vy = 0;
    }
}


//Function sets animation parameters according to state of mario
void Mario::setAnimation(){
    switch(currentState){
        case 1: //Facing left
            spritesheetx = 134;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 20;
            break;
        case 2: //Facing right
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
        case 4: //Running right
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
        case 12: //Jumping left
            spritesheetx = 92;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 20;
            break;
        case 13: //Jumping right
            spritesheetx = 194;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 20;
            break;
        case 14: //Dying through air
            spritesheetx = 71;
            spritesheety = 105;
            currentFrame = 1;
            maxFrames = 4;
            height = 20;
            width = 20;
            break;
        case 15: //Dead left
            spritesheetx = 40;
            spritesheety = 85;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 20;
            break;
        case 16: //Dead right
            spritesheetx = 206;
            spritesheety = 85;
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
                //student machine vy = -2
            case SDLK_UP: if( checkOnLadder(1) == 1 && alive && !hasHammer)
            {
                if((floorNumber < 7)&&(floorNumber == previousFloor)) floorNumber++;
                vy = -2; direction = 1; climbing = 1; onLadder = 1;
                onFloor = 0;
            }
            else if ( checkOnLadder(1) == 2){
                if((floorNumber < 7)&&(floorNumber == previousFloor)) floorNumber++;
                vy = 0; direction = 1; climbing = 1; onLadder = 2;
                onFloor = 0;
            }
            break;
            case SDLK_DOWN: if(checkOnLadder(0) == 1 && alive && !hasHammer)
            {
                //student machine vy = 2
                if((floorNumber < 7)&&(floorNumber == previousFloor)) floorNumber--;
                vy = 2; direction = 0; climbing = 1; onLadder = 1;
                onFloor = 0;
            }
            else if ( checkOnLadder(0) == 2 && alive){
                if((floorNumber < 7)&&(floorNumber == previousFloor)) floorNumber--;
                vy = 0; direction = 0; climbing = 1; onLadder = 2;
                onFloor = 0;
            }
                break;
                //student machine vx = 4
            case SDLK_LEFT: if(alive){ vx = -4;  climbing = 0; rdirection = 0;} break;
            case SDLK_RIGHT: if(alive){ vx = 4; climbing = 0; rdirection = 1;} break;
                //student machine vy = -10
            case SDLK_SPACE:
                if(onFloor && alive && !hasHammer){
                    onFloor = 0; jumping = 1;
                    vy = -10; climbing = 0; ypos--;
                }
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: if(climbing && alive && !hasHammer) { vy = 0; climbing = 1; } break;
            case SDLK_DOWN: if( climbing && alive && !hasHammer) {vy = 0; climbing = 1; } break;
            case SDLK_LEFT: if(alive) { if(vx<0) vx = 0; if(onFloor) climbing = 0;} break;
            case SDLK_RIGHT: if(alive){ if(vx>0) vx = 0; if(onFloor) climbing = 0; setAnimation();} break;
            case SDLK_SPACE: if(alive && !hasHammer){climbing = 0;} break;
                
        }
    }
}

int Mario::checkForHammer(){
    int hammerXmin = 35;
    int hammerXmax = 65;
    int hammerYmin = 315;
    int hammerYmax = 333;

    if(((xpos + width/2 >= hammerXmin)&&(xpos + width/2 <= hammerXmax))&&((ypos + height/2 >= hammerYmin)&&(ypos + height/2 <= hammerYmax))&&(hadHammer == 0)){
        hadHammer = 1;
        return 1;
    }
    else{
        return 0;
    }

}

void Mario::determineAnimation(){
    //Facing right
    if(onFloor && !jumping && !hasHammer && rdirection && !vx && !vy  && !climbing){
        currentState = 2;
    }
    //Facing left
    if(onFloor && !jumping && !hasHammer && !rdirection && !vx && !vy  && !climbing){
        currentState = 1;
    }
    //Running left
    if(onFloor && !jumping && !hasHammer && !rdirection && vx < 0 && !vy  && !onLadder && !climbing){
        currentState = 3;
    }
    //Running right
    if(onFloor && !jumping && !hasHammer && rdirection && vx > 0 && !vy  && !onLadder && !climbing){
        currentState = 4;
    }
    //Running left with hammer
    if(onFloor && !jumping && hasHammer && !rdirection && vx < 0 && !vy  && !onLadder && !climbing){
        currentState = 5;
    }
    //Running right with hammer
    if(onFloor && !jumping && hasHammer && rdirection && vx > 0 && !vy  && !onLadder && !climbing){
        currentState = 6;
    }
    //Facing left with hammer
    if(onFloor && !jumping && hasHammer && !rdirection && !vx && !vy  && !onLadder && !climbing){
        currentState = 7;
    }
    //Facing right with hammer
    if(onFloor && !jumping && hasHammer && rdirection && !vx && !vy  && !onLadder && !climbing){
        currentState = 8;
    }
    //Climbing
    if(!vx && vy  && onLadder && climbing){
        currentState = 9;
    }
    //Not Climbing
    if(!vx && !vy  && onLadder && climbing){
        currentState = 10;
    }
    //Jumping left
    if(!onFloor && jumping && !hasHammer && !rdirection && vx < 0 && !onLadder && !climbing){
        currentState = 12;
    }
    //Jumping right
    if(!onFloor && jumping && !hasHammer && rdirection && vx > 0 && !onLadder && !climbing){
        currentState = 13;
    }
    //Dying through air
    if(jumping && !alive){
        currentState = 14;
    }
    //Dead on ground
    if(!jumping && !alive){
        currentState = 15;
    }

    
    
    
}
