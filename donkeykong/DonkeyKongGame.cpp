//
//  DonkeyKongGame.cpp
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include <SDL/SDL.h>
#include <iostream>
#include "DonkeyKongGame.h"
#include "Object.h"
#include "Mario.h"

using namespace std;

SDL_Event event;
//Constructor for DonkeyKongGame, initializes SDL, creates screen, and loads background
DonkeyKongGame::DonkeyKongGame(){
    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode( 550, 471, 32, SDL_SWSURFACE );
    background = SDL_LoadBMP("/Users/jgavin/Documents/donkeykong/donkeykong/DonkeyKongBackground.bmp");
    initializeFloors();
}


//Display function which puts background and all objects on screen
void DonkeyKongGame::Display(){
 
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );  

    //Apply image to screen
    SDL_BlitSurface( background, NULL, screen, NULL );
    
    if(mario.getclimbing() == 0){
    mario.display(screen, mario.getMarioSurface(), mario.getxpos(), mario.getypos(), mario.getspritesheetx() + mario.getcurrentframe()*mario.getwidth(), mario.getspritesheety(), mario.getwidth(), mario.getheight());
    }
    if(mario.getclimbing() == 1){
        mario.climbingdisplay(screen, mario.getMarioSurface(), mario.getxpos(), mario.getypos(),mario.getspritesheetx() + mario.getcurrentframe()*mario.getwidth()*2, mario.getspritesheety(), mario.getwidth(), mario.getheight());
    }


   SDL_Flip(screen);
    
}

//Function to clean up game when over
void DonkeyKongGame::cleanUp(){
    
    //Free the loaded image
    SDL_FreeSurface( background );
    
    //Quit SDL
    SDL_Quit();
}

//Function to create gameplay
void DonkeyKongGame::playDonkeyKong(){
    bool quit = false;
    Display();
    while( quit == false )
    {
        if(mario.getoldtime() + mario.getframerate() < SDL_GetTicks()) {
            mario.updateAnimation();
        }
        while( SDL_PollEvent( &event ) )
        {
            if(mario.getoldtime() + mario.getframerate() < SDL_GetTicks()) {
                mario.updateAnimation();
            }
            //Handle events for Mario
            mario.handle_input(event);
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
            mario.updateAnimation();
        }
        mario.move();
        Display();
    }
    SDL_Quit();
}

//Function to initialize floors
void DonkeyKongGame::initializeFloors(){
    floors[0].setslope(.4);
}
