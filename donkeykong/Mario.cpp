//
//  Mario.cpp
//  SDL_Tutorial
//
//  Created by Jacob Gavin on 3/20/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include "Mario.h"

//Constructor, sets parameters and loads surface
Mario::Mario(){
    height = 20;
    width = 20;
    xpos = 130;
    ypos = 435;
    currentState = 4;
    currentFrame = 1;
    maxFrames = 2;
    marioSurface = SDL_LoadBMP("/Users/jgavin/Documents/donkeykong/donkeykong/DonkeyKong.bmp");
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
}

void Mario::move(){
    double dt = .5;
    vx = 15;
    vy = -6;
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
        case 1: //Facing left
            spritesheetx = 134;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            break;
        case 2: //Facing right
            spritesheetx = 153;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 1;
            break;
        case 3: //Running left
            spritesheetx = 92;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 2;
            break;
        case 4: //Running right
            spritesheetx = 172;
            spritesheety = 0;
            currentFrame = 1;
            maxFrames = 2;
            break;
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

