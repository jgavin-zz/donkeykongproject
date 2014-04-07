//
//  DonkeyKongGame.cpp
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include <SDL/SDL.h>
#include <iostream>
#include "SDL/SDL.h"
#include <string>
#include "DonkeyKongGame.h"
#include "Object.h"
#include "Mario.h"
#include "Peach.h"
#include "DonkeyKong.h"
#include "Barrel.h"
#include "math.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

//#include "SDL/SDL_mixer.h"
//#include "SDL_image/SDL_image.h"
//include "SDL_ttf/SDL_ttf.h"

using namespace std;


SDL_Event event;
//The music that will be played
//Mix_Music *music = NULL;

//Constructor for DonkeyKongGame, initializes SDL, creates screen, and loads background
DonkeyKongGame::DonkeyKongGame ()
{
    SDL_Init (SDL_INIT_EVERYTHING);
    // SDL_Color textColor = { 255, 255, 255 }; // it's white for now, color of text
    screen = SDL_SetVideoMode (550, 471, 32, SDL_SWSURFACE);
    background = SDL_LoadBMP ("DonkeyKongBackground.bmp");
    
    // TTF_Font *font;
    // font = TTF_OpenFont( "kongtext.ttf", 36 ); //size 12 font
    // message = TTF_RenderText_Solid( font, "Current Score:", textColor );
    mario.initializeFloors ();
    //Barrel barrel;
    barrels.push_back(Barrel());
}


void DonkeyKongGame::Music ()
{
    
    // Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    //  music = Mix_LoadMUS( "intro.wav" );
    //  Mix_PlayMusic(music, -1);
}

//Display function which puts background and all objects on screen
void DonkeyKongGame::Display ()
{
    int i;
    
    SDL_FillRect (screen, &screen->clip_rect,
                  SDL_MapRGB (screen->format, 0xFF, 0xFF, 0xFF));
    
    //Apply image to screen
    SDL_BlitSurface (background, NULL, screen, NULL);
    
    if (mario.getclimbing () == 0)
    {
        mario.display (screen, mario.getMarioSurface (), mario.getxpos (),
                       mario.getypos (),
                       mario.getspritesheetx () +
                       mario.getcurrentframe () * mario.getwidth (),
                       mario.getspritesheety (), mario.getwidth (),
                       mario.getheight ());
    }
    if (mario.getclimbing () == 1)
    {
        mario.climbingdisplay (screen, mario.getMarioSurface (),
                               mario.getxpos (), mario.getypos (),
                               mario.getspritesheetx () +
                               mario.getcurrentframe () * mario.getwidth () * 2,
                               mario.getspritesheety (), mario.getwidth (),
                               mario.getheight ());
    }
    
    peach.display (screen, peach.getMarioSurface (), peach.getxpos (),
                   peach.getypos (),
                   peach.getspritesheetx () +
                   peach.getcurrentframe () * peach.getwidth (),
                   peach.getspritesheety (), peach.getwidth (),
                   peach.getheight ());
    
    donkeykong.display (screen, donkeykong.getMarioSurface (),
                        donkeykong.getxpos (), donkeykong.getypos (),
                        donkeykong.getspritesheetx () +
                        donkeykong.getcurrentframe () * donkeykong.getwidth (),
                        donkeykong.getspritesheety (), donkeykong.getwidth (),
                        donkeykong.getheight ());
    
    for(i = 0; i < barrels.size(); i++){
    barrels[i].display(screen, barrels[i].getMarioSurface(), barrels[i].getxpos(), barrels[i].getypos(), barrels[i].getspritesheetx() + barrels[i].getcurrentframe()*barrels[i].getwidth(), barrels[i].getspritesheety(), barrels[i].getwidth(), barrels[i].getheight());
    }
    
    
    SDL_Flip (screen);
    
}

//Function to clean up game when over
void DonkeyKongGame::cleanUp ()
{
    
    //Free the loaded image
    //SDL_FreeSurface( screen );
    SDL_FreeSurface (background);
    SDL_FreeSurface (message);
    mario.cleanUp ();
    // Mix_FreeMusic( music );
    
    //Quit SDL Mixer
    //  Mix_CloseAudio();
    //Quit SDL
    SDL_Quit ();
}

//Function to create gameplay
void DonkeyKongGame::playDonkeyKong ()
{
    bool quit = false;
    int counter = 0;
    int i;
    Display ();
    Music ();
    srand (time(NULL));
    while (quit == false)
    {
        //cout << "onFloor = " << mario.onFloor << endl;
        if (mario.getoldtime () + mario.getframerate () < SDL_GetTicks ())
        {
            mario.updateAnimation ();
        }
        if ((peach.getoldtime () + peach.getframerate () < SDL_GetTicks ())
            && (counter % 5) == 0)
        {
            peach.updateAnimation ();
            if (counter % 30 == 0 && peach.currentState == 1)
            {
                peach.currentState = 2;
                peach.setAnimation ();
            }
            else if (counter % 30 == 0 && peach.currentState == 2)
            {
                peach.currentState = 1;
                peach.setAnimation ();
            }
        }
        if ((donkeykong.currentState == 3 && donkeykong.currentFrame == 2) || (donkeykong.currentState == 2 && donkeykong.currentFrame == 0))
        {
            if (rand() % 10 + 1 >= 3 && donkeykong.currentState != 3 && counter % 100 == 0)
            {
                donkeykong.currentState = 3;
                donkeykong.setAnimation();
            }
            else if (donkeykong.currentState != 2 && counter % 100 == 0)
            {
                donkeykong.currentState = 2;
                donkeykong.setAnimation();
            }
        }
        if (counter % 100 == 0 && donkeykong.currentState == 2)
        {
            if (donkeykong.currentFrame == 0)
            {
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
            }
            else
            {
                donkeykong.updateAnimation ();
            }
            
        }
        if (counter % 100 == 0 && donkeykong.currentState == 3)
        {
            if (donkeykong.currentFrame == 2)
            {
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
            }
            else if (donkeykong.currentFrame == 0)
            {
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
            }
            else if (donkeykong.currentFrame == 3)
            {
                Barrel barrel;
                barrels.push_back(barrel);
                for(i = 0; i < barrels.size(); i++){
                    barrels[i].currentState = 1;
                    barrels[i].currentFrame = 2;
                    barrels[i].updateAnimation();
                    barrels[i].updateAnimation();
                }
                
                if (rand() % 10 + 1 >= 4 || mario.getypos() <= 250)
                {
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                }
                else
                {
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                }
            }
            else
            {
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
            }
        }
        while (SDL_PollEvent (&event))
        {
            mario.checkOnFloor (0);
            if (mario.getoldtime () + mario.getframerate () < SDL_GetTicks ())
            {
                mario.updateAnimation ();
            }
            //Handle events for Mario
            mario.handle_input (event);
            //If the user has Xed out the window
            if (event.type == SDL_QUIT)
            {
                //Quit the program
                quit = true;
            }
            mario.updateAnimation ();
        }
        counter += 1;
        for(i = 0; i < barrels.size(); i++){
           barrels[i].roll();
        }
        mario.move ();
        mario.checkOnFloor (0);
        for(i = 0; i < barrels.size(); i++){
            barrels[i].checkOnFloor(1);
        }
        if(mario.checkOnLadder(mario.direction) == 1){
            mario.onLadder = 1;
        }
        else if(mario.checkOnLadder(mario.direction) == 2){
            mario.onLadder = 2;
            mario.vy = 0;
        }
        else{
            mario.onLadder = 0;
        }
        if(checkForCollisions()){
            cout << "Died" << endl;
            mario.alive = 0;
            if(mario.rdirection == 0) mario.vx = 2;
            if(mario.rdirection == 1) mario.vx = -2;
            mario.vy = -4;
            mario.currentState = 14;
            mario.setAnimation();
        }
        Display ();
    }
    SDL_Quit ();
}

int DonkeyKongGame::checkForCollisions(){
    int i;
    int barrelxcenter;
    int barrelycenter;
    int marioxcenter = mario.xpos + mario.width/2;
    int marioycenter = mario.ypos + mario.height/2;
    int barrelradius = 6;
    int marioradius = 8;
    int mindistance;
    double distance;
    
    for(i = 0; i < barrels.size(); i++){
        barrelxcenter = barrels[i].xpos + barrels[i].width/2;
        barrelycenter = barrels[i].ypos + barrels[i].height/2;
        mindistance = marioradius + barrelradius;
        distance = sqrt(pow(marioxcenter-barrelxcenter,2)+pow(marioycenter-barrelycenter,2));
        //cout << "Barrel " << i << " distance = " << distance << endl;
        if(distance < mindistance) return 1;
    }
    return 0;
}
