//
//  Mario.cpp
//  SDL_Tutorial
//
//  Created by Jacob Gavin on 3/20/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include "Mario.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Mario::Mario(){
    height = 20;
    width = 20;
    xpos = 130;
    ypos = 435;
    vy = 0;
    vx = 0;
    currentState = 1;
    currentFrame = 1;
    maxFrames = 2;
    marioSurface = SDL_LoadBMP("DonkeyKong.bmp");
    setAnimation();
    Transparent(marioSurface, 255, 0, 255);
    
}

//Display function takes in parameters of clipping from sprite sheet, makes rectangle, and blits the rectangle
void Mario::display(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
    
    SDL_Rect DestR;
    
    DestR.x = X;
    DestR.y = Y;
    
    SDL_Rect SrcR;
    
    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;
    
    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);
    
}


//Function updates animation frames
void Mario::updateAnimation(){
    currentFrame++;
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
    (*this).setAnimation();
}

void Mario::move(){
    double dt = .5;
    xpos = xpos + vx * dt;
    ypos = ypos + vy * dt;
}


SDL_Surface* Mario::getMarioSurface(){
    return marioSurface;
}

int Mario::getspritesheetx(){
    return spritesheetx;
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
        case 9: //Climbing left
            spritesheetx = 163;
            spritesheety = 20;
            currentFrame = 1;
            maxFrames = 1;
            height = 20;
            width = 19;
            break;
        case 10: //Climbing right
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
            case SDLK_UP: vy -= height / 2; break;
            case SDLK_DOWN: vy += height / 2; break;
            case SDLK_LEFT: vx -= width / 2; currentState = 3; setAnimation(); break;
            case SDLK_RIGHT: vx += width / 2; currentState = 2; setAnimation(); break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: vy += height / 2; break;
            case SDLK_DOWN: vy -= height / 2; break;
            case SDLK_LEFT: vx += width / 2; currentState = 12; setAnimation(); break;
            case SDLK_RIGHT: vx -= width / 2; currentState = 1; setAnimation(); break;
        }
    }
}

int Mario::getspritesheety(){
    return spritesheety;
}

int Mario::getheight(){
    return height;
}

int Mario::getwidth(){
    return width;
}

int Mario::getxpos(){
    return xpos;
}

int Mario::getypos(){
    return ypos;
}

int Mario::getcurrentframe(){
    return currentFrame;
}

//Function makes pink background on mario surface transparent
void Mario::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    
    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));
    
}

