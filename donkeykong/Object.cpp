//
//  Object.cpp
//  SDL_Tutorial
//
//  Created by Ryan Moran on 3/20/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//

#include "Object.h"
#include <math.h>
#include <iostream>


using namespace std;

//Non-default Constructor, sets parameters and loads surface
Object::Object(int h, int w, int x, int y, double velX, double velY, double accelY, int cState, int cFrame, int mFrames, int climb, int oTime, int fRate){
    height = h;
    width = w;
    xpos = x;
    ypos = y;
    vx = velX;
    vy= velY;
    ay = accelY;
    currentState = cState;
    currentFrame = cFrame;
    maxFrames=mFrames;
    climbing=climb;
    oldTime=oTime;
    frameRate=fRate;
    marioSurface = SDL_LoadBMP("DonkeyKong.bmp");
    setAnimation();
    Transparent(marioSurface, 255, 0, 255);
    
}

//Display function takes in parameters of clipping from sprite sheet, makes rectangle, and blits the rectangle
void Object::display(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
    
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

//Display function takes in parameters of clipping from sprite sheet, makes rectangle, and blits the rectangle, only used for mario display when climbing = 1
void Object::climbingdisplay(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
    
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
void Object::updateAnimation(){
    oldTime = SDL_GetTicks();
    currentFrame++;
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
    //(*this).setAnimation();
}


SDL_Surface* Object::getMarioSurface(){
    return marioSurface;
}

int Object::getspritesheetx(){
    return spritesheetx;
}

//Function sets animation parameters according to state of mario
void Object::setAnimation(){
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

int Object::getspritesheety(){
    return spritesheety;
}

int Object::getheight(){
    return height;
}

int Object::getwidth(){
    return width;
}

int Object::getxpos(){
    return xpos;
}

int Object::getypos(){
    return ypos;
}

int Object::getcurrentframe(){
    return currentFrame;
}

int Object::getcurrentstate(){
    return currentState;
}

void Object::setcurrentstate(int state){
    currentState = state;
}

int Object::getclimbing(){
    return climbing;
}

int Object::getoldtime(){
    return oldTime;
}

int Object::getframerate(){
    return frameRate;
}

//Function makes pink background on mario surface transparent
void Object::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    
    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));
    
}

void Object::cleanUp(){
    SDL_FreeSurface( marioSurface );
}
