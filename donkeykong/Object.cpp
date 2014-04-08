//
//  Object.cpp
//  SDL_Tutorial
//
//  Created by Ryan Moran on 3/20/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//

#include "Object.h"
#include "math.h"
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
    marioSurface = SDL_LoadBMP("/Users/jgavin/Documents/donkeykong/donkeykong/DonkeyKong.bmp");
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

//Function to initialize floors
void Object::initializeFloors(){
    floors[0].setslope(-.009107);
    floors[0].setyint(455);
    floors[0].setxmin(0);
    floors[0].setxmax(550);
    floors[0].setymin(420);
    floors[0].setymax(455);
    
    floors[1].setslope(.03777);
    floors[1].setyint(388);
    floors[1].setxmin(0);
    floors[1].setxmax(503);
    floors[1].setymin(378);
    floors[1].setymax(415);
    
    floors[2].setslope(-.04297);
    floors[2].setyint(352);
    floors[2].setxmin(38);
    floors[2].setxmax(550);
    floors[2].setymin(322);
    floors[2].setymax(361);
    
    floors[3].setslope(.04118);
    floors[3].setyint(277);
    floors[3].setxmin(0);
    floors[3].setxmax(510);
    floors[3].setymin(265);
    floors[3].setymax(303);
    
    floors[4].setslope(-.0435);
    floors[4].setyint(245);
    floors[4].setxmin(38);
    floors[4].setxmax(550);
    floors[4].setymin(201);
    floors[4].setymax(250);
    
    floors[5].setslope(.01569);
    floors[5].setyint(180);
    floors[5].setxmin(0);
    floors[5].setxmax(510);
    floors[5].setymin(140);
    floors[5].setymax(195);
    
    floors[6].setslope(0);
    floors[6].setyint(123);
    floors[6].setxmin(235);
    floors[6].setxmax(353);
    floors[6].setymin(0);
    floors[6].setymax(130);
}

int Object::checkOnFloor(int print){
    
    int yfloor[7];
    yfloor[0] =  floors[0].getslope() * xpos + floors[0].getyint();
    yfloor[1] =  floors[1].getslope() * xpos + floors[1].getyint();
    yfloor[2] =  floors[2].getslope() * xpos + floors[2].getyint();
    yfloor[3] =  floors[3].getslope() * xpos + floors[3].getyint();
    yfloor[4] =  floors[4].getslope() * xpos + floors[4].getyint();
    yfloor[5] =  floors[5].getslope() * xpos + floors[5].getyint();
    yfloor[6] =  floors[6].getslope() * xpos + floors[6].getyint();
    
    
    if((climbing == 0) || ((climbing == 1) && (direction == 0) && (yfloor[floorNumber-1]-(ypos+height) < 20))|| ((climbing == 1) && (direction == 1) && ((ypos+height)-yfloor[floorNumber-1] < 20))){
        if(( ypos + height < floors[6].getymax() )&&( ypos + height > floors[6].getymin() )){
            
            if(( xpos < floors[6].getxmax() )&&( xpos + width > floors[6].getxmin() )){
                
                if((climbing == 1) && (direction == 0) && (ypos + height >= yfloor[6])) return 0;
                
                if( ((ypos + height) - yfloor[6] <= 10 )&&((ypos + height) - yfloor[6] >= 0 )){
                    if(alive == 0){
                        currentState = 15;
                        vx = 0;
                        setAnimation();
                    }
                    ypos = (yfloor[6]) - height;
                    vy = 0;
                    onFloor = 1;
                    floorNumber = 7;
                    previousFloor = 7;
                    return yfloor[6];
                }
            }
        }
        if(( ypos + height < floors[5].getymax() )&&( ypos + height > floors[5].getymin() )){
            if(( xpos < floors[5].getxmax() )&&( xpos + width > floors[5].getxmin() )){
                
                if( ((ypos + height) - yfloor[5] <= 10 )&&((ypos + height) - yfloor[5] >= 0 )){
                    if(alive == 0){
                        currentState = 15;
                        vx = 0;
                        setAnimation();
                    }
                    ypos = (yfloor[5]) - height;
                    vy = 0;
                    onFloor = 1;
                    floorNumber = 6;
                    previousFloor = 6;
                    return yfloor[5];
                }
            }
        }
        if(( ypos + height < floors[4].getymax() )&&( ypos + height > floors[4].getymin() )){
            if(( xpos < floors[4].getxmax() )&&( xpos + width > floors[4].getxmin() )){
                
                if( ((ypos + height) - yfloor[4] <= 10 )&&((ypos + height) - yfloor[4] >= 0 )){
                    if(alive == 0){
                        currentState = 15;
                        vx = 0;
                        setAnimation();
                    }
                    ypos = (yfloor[4]) - height;
                    vy = 0;
                    onFloor = 1;
                    floorNumber = 5;
                    previousFloor = 5;
                    return yfloor[4];
                }
            }
        }
        if(( ypos + height < floors[3].getymax() )&&( ypos + height > floors[3].getymin() )){
            if(( xpos < floors[3].getxmax() )&&( xpos + width > floors[3].getxmin() )){
                
                if( ((ypos + height) - yfloor[3] <= 10 )&&((ypos + height) - yfloor[3] >= 0 )){
                    if(alive == 0){
                        currentState = 15;
                        vx = 0;
                        setAnimation();
                    }
                    ypos = (yfloor[3]) - height;
                    vy = 0;
                    onFloor = 1;
                    floorNumber = 4;
                    previousFloor = 4;
                    return yfloor[3];
                }
            }
        }
        if(( ypos + height < floors[2].getymax() )&&( ypos + height > floors[2].getymin() )){
            if(( xpos < floors[2].getxmax() )&&( xpos + width > floors[2].getxmin() )){
                
                
                if( ((ypos + height) - yfloor[2] <= 10 )&&((ypos + height) - yfloor[2] >= 0 )){
                    if(alive == 0){
                        currentState = 15;
                        vx = 0;
                        setAnimation();
                    }
                    ypos = (yfloor[2]) - height;
                    vy = 0;
                    onFloor = 1;
                    floorNumber = 3;
                    previousFloor = 3;
                    return yfloor[2];
                }
            }
        }
        
        if(( ypos + height < floors[1].getymax() )&&( ypos + height > floors[1].getymin() )){
            if(( xpos < floors[1].getxmax() )&&( xpos + width > floors[1].getxmin() )){
                
                if( ((ypos + height) - yfloor[1] <= 10 )&&((ypos + height) - yfloor[1] >= 0 )){
                    if(alive == 0){
                        currentState = 15;
                        vx = 0;
                        setAnimation();
                    }
                    ypos = (yfloor[1]) - height;
                    vy = 0;
                    onFloor = 1;
                    floorNumber = 2;
                    previousFloor = 2;
                    return yfloor[1];
                }
            }
        }
        if( ypos + height > floors[0].getymin() ){
            
            if( ((ypos + height) - yfloor[0] <= 10 )&&((ypos + height) - yfloor[0] >= 0 )){
                if(alive == 0){
                    currentState = 15;
                    setAnimation();
                    vx = 0;
                }
                ypos = (yfloor[0]) - height;
                onFloor = 1;
                vy = 0;
                floorNumber = 1;
                previousFloor = 1;
                return yfloor[0];
            }
        }
    }
    return 0;
}

int Object::checkOnLadder(int direction){
    if((previousFloor == 1)&&( direction == 1))
    {
        if ((xpos + width/2 >= 200 && xpos + width/2 <= 220)||(xpos + width/2 >= 430 && xpos + width/2 <= 450))
        {
            if((xpos + width/2 >= 200 && xpos + width/2 <= 220)&&(ypos <= 436)){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(((previousFloor == 1)||(previousFloor == 2))&&((floorNumber == 1) || (floorNumber == 2)) && (onFloor == 0)){
        if ((xpos + width/2 >= 200 && xpos + width/2 <= 220)||(xpos + width/2 >= 430 && xpos + width/2 <= 450))
        {
            if((previousFloor == 1)&&(direction == 1)&&(xpos + width/2 >= 200 && xpos + width/2 <= 220)&&(ypos <= 436)){
                return 2;
            }
            else if((previousFloor == 2)&&(direction == 0)&&(xpos + width/2 >= 200 && xpos + width/2 <= 220)&&(ypos + height >= 420)){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if((previousFloor == 2)&&( direction == 1))
    {
        if ((xpos + width/2 >= 80 && xpos + width/2 <= 100)||(xpos + width/2 >= 236 && xpos + width/2 <= 256))
        {
            return 1;
        }
    }
    if((previousFloor == 2)&&( direction == 0))
    {
        if ((xpos + width/2 >= 200 && xpos + width/2 <= 220)||(xpos + width/2 >= 430 && xpos + width/2 <= 450))
        {
            if((xpos + width/2 >= 200 && xpos + width/2 <= 220)&&(ypos + height >= 420)){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(((previousFloor == 2)||(previousFloor == 3))&&((floorNumber == 2) || (floorNumber == 3)) && (onFloor == 0)){
        if ((xpos + width/2 >= 80 && xpos + width/2 <= 100)||(xpos + width/2 >= 236 && xpos + width/2 <= 256))
        {
            return 1;
        }
    }
    if((previousFloor == 3)&&( direction == 1))
    {
        if ((xpos + width/2 >= 155 && xpos + width/2 <= 175)||(xpos + width/2 >= 275 && xpos + width/2 <= 295)||(xpos + width/2 >= 432 && xpos + width/2 <= 452))
        {
            if((xpos + width/2 >= 155 && xpos + width/2 <= 175)&&(ypos <= 318)){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if((previousFloor == 3)&&( direction == 0))
    {
        if ((xpos + width/2 >= 80 && xpos + width/2 <= 100)||(xpos + width/2 >= 236 && xpos + width/2 <= 256))
        {
            return 1;
        }
    }
    if(((previousFloor == 3)||(previousFloor == 4))&&((floorNumber == 3) || (floorNumber == 4)) && (onFloor == 0)){
        if ((xpos + width/2 >= 155 && xpos + width/2 <= 175)||(xpos + width/2 >= 275 && xpos + width/2 <= 295)||(xpos + width/2 >= 432 && xpos + width/2 <= 452))
        {
            if(xpos + width/2 >= 155 && xpos + width/2 <= 175 && direction == 0 && ypos + height >= 308 && ypos + height <= 318){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if((previousFloor == 4)&&(direction == 1))
    {
        if ((xpos + width/2 >= 79 && xpos + width/2 <= 99)||(xpos + width/2 >= 196 && xpos + width/2 <= 216)||(xpos + width/2 >= 393 && xpos + width/2 <= 413))
        {
            if(xpos + width/2 >= 393 && xpos + width/2 <= 413 && ypos <= 273 && ypos >= 255){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if((previousFloor == 4)&&( direction == 0))
    {
        if ((xpos + width/2 >= 155 && xpos + width/2 <= 175)||(xpos + width/2 >= 275 && xpos + width/2 <= 295)||(xpos + width/2 >= 432 && xpos + width/2 <= 452))
        {
            if(xpos + width/2 >= 155 && xpos + width/2 <= 175 && ypos + height >= 308){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(((previousFloor == 4)||(previousFloor == 5))&&((floorNumber == 4) || (floorNumber == 5)) && (onFloor == 0)){
        if ((xpos + width/2 >= 79 && xpos + width/2 <= 99)||(xpos + width/2 >= 196 && xpos + width/2 <= 216)||(xpos + width/2 >= 393 && xpos + width/2 <= 413))
        {
            if(xpos + width/2 >= 393 && xpos + width/2 <= 413 && ypos <= 273 && ypos >= 255 && direction == 1){
                return 2;
            }
            else if(xpos + width/2 >= 393 && xpos + width/2 <= 413 && ypos + height >= 251 && ypos + height <= 271 && direction == 0){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if((previousFloor == 5)&&(direction == 1))
    {
        if ((xpos + width/2 >= 235 && xpos + width/2 <= 255)||(xpos + width/2 >= 431 && xpos + width/2 <= 451))
        {
            if(xpos + width/2 >= 235 && xpos + width/2 <= 255 && ypos <= 221 && ypos >= 201){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if((previousFloor == 5)&&(direction == 0))
    {
        if ((xpos + width/2 >= 79 && xpos + width/2 <= 99)||(xpos + width/2 >= 196 && xpos + width/2 <= 216)||(xpos + width/2 >= 393 && xpos + width/2 <= 413))
        {
            if(xpos + width/2 >= 393 && xpos + width/2 <= 413 && ypos + height >= 251 && ypos + height <= 271){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(((previousFloor == 5)||(previousFloor == 6))&&((floorNumber == 5) || (floorNumber == 6)) && (onFloor == 0)){
        if ((xpos + width/2 >= 235 && xpos + width/2 <= 255)||(xpos + width/2 >= 431 && xpos + width/2 <= 451))
        {
            if(xpos + width/2 >= 235 && xpos + width/2 <= 255 && ypos <= 221 && ypos >= 241 && direction == 1){
                return 2;
            }
            else if(xpos + width/2 >= 235 && xpos + width/2 <= 255 && ypos + height >= 205 && ypos + height <= 225 && direction == 0){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if((previousFloor == 6)&&(direction == 1))
    {
        if ((xpos + width/2 >= 191 && xpos + width/2 <= 211)||(xpos + width/2 >= 216 && xpos + width/2 <= 236)||(xpos + width/2 >= 334 && xpos + width/2 <= 354))
        {
            return 1;
        }
    }
    if((previousFloor == 6)&&(direction == 0))
    {
        if ((xpos + width/2 >= 235 && xpos + width/2 <= 255)||(xpos + width/2 >= 431 && xpos + width/2 <= 451))
        {
            if(xpos + width/2 >= 235 && xpos + width/2 <= 255 && ypos + height >= 205 && ypos + height <= 225){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(((previousFloor == 6)||(previousFloor == 7))&&((floorNumber == 6) || (floorNumber == 7)) && (onFloor == 0)){
        if ((xpos + width/2 >= 191 && xpos + width/2 <= 211)||(xpos + width/2 >= 216 && xpos + width/2 <= 236)||(xpos + width/2 >= 334 && xpos + width/2 <= 354))
        {
            return 1;
        }
    }
    if((previousFloor == 7)&&(direction == 0))
    {
        if ((xpos + width/2 >= 191 && xpos + width/2 <= 211)||(xpos + width/2 >= 216 && xpos + width/2 <= 236)||(xpos + width/2 >= 334 && xpos + width/2 <= 354))
        {
            return 1;
        }
    }
    return 0;
}