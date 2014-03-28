//
//  Object.h
//  donkeykong
//
//  Created by Ryan Moran on 3/20/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//  Class for mario object

#ifndef OBJECT_H
#define OBJECT_H

#include <SDL/SDL.h>
#include <string>
using namespace std;

class Object{
    
public:

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

    Object(int h, int w, int x, int y, double velX, double velY, double accelY, int cState, int cFrame, int mFrames, int climb, int oTime, int fRate); //non default constructor
    
    void display(SDL_Surface*, SDL_Surface*, int, int, int, int, int, int);//Displays object
    void climbingdisplay(SDL_Surface*, SDL_Surface*, int, int, int, int, int, int);//Displays object
    
    void updateAnimation();//Increments frame
    
    //Get functions
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
    
    virtual void setAnimation();//Sets animation parameters according to animation state
    void setcurrentstate(int);
    
    void Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);//Makes pink background of mario image transparent

    void handle_input(SDL_Event);

    SDL_Surface* getMarioSurface();
    
    void cleanUp();
    
private:
    
};

#endif
