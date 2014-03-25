//
//  Mario.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/20/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//  Class for mario object

#ifndef MARIO_H
#define MARIO_H

#include <SDL/SDL.h>
#include <string>
using namespace std;

class Mario{
    
public:
    Mario();//Constructor
    
    void display(SDL_Surface*, SDL_Surface*, int, int, int, int, int, int);//Displays mario
    void climbingdisplay(SDL_Surface*, SDL_Surface*, int, int, int, int, int, int);//Displays mario
    
    void updateAnimation();//Increments frame
    void move();
    
    //Get functions
    SDL_Surface* getMarioSurface();
    int getspritesheetx();
    int getspritesheety();
    int getheight();
    int getwidth();
    int getxpos();
    int getypos();
    int getcurrentframe();
    int getcurrentstate();
    int getclimbing();
    int getoldtime();
    int getframerate();
    
    void setAnimation();//Sets animation parameters according to animation state
    void setcurrentstate(int);
    
    void Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);//Makes pink background of mario image transparent

    void handle_input(SDL_Event);
    
private:
    int spritesheetx;
    int spritesheety;
    int height;
    int width;
    int xpos;
    int ypos;
    double vx;
    double vy;
    double ay;
    int currentState;
    int currentFrame;
    int maxFrames;
    int climbing;
    int oldTime;
    int frameRate;
    SDL_Surface* marioSurface;
    
};

#endif
