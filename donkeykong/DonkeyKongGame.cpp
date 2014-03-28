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
//#include "SDL/SDL_image.h"
//#include "SDL/SDL_ttf.h"
#include <string>
#include "DonkeyKongGame.h"
#include "Object.h"
#include "Mario.h"
#include "Peach.h"
#include "DonkeyKong.h"

using namespace std;



SDL_Event event;

//The font that's going to be used
//TTF_Font *font = NULL;
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
    
    peach.display(screen, peach.getMarioSurface(), peach.getxpos(), peach.getypos(), peach.getspritesheetx() + peach.getcurrentframe()*peach.getwidth(), peach.getspritesheety(), peach.getwidth(), peach.getheight());
    
    donkeykong.display(screen, donkeykong.getMarioSurface(), donkeykong.getxpos(), donkeykong.getypos(), donkeykong.getspritesheetx() + donkeykong.getcurrentframe()*donkeykong.getwidth(), donkeykong.getspritesheety(), donkeykong.getwidth(), donkeykong.getheight());
    
    
    SDL_Flip(screen);
    
}

//Function to clean up game when over
void DonkeyKongGame::cleanUp(){
    
    //Free the loaded image
    //SDL_FreeSurface( screen );
    SDL_FreeSurface( background );
    mario.cleanUp();
    
    
    //Quit SDL
    SDL_Quit();
}

//Function to create gameplay
void DonkeyKongGame::playDonkeyKong(){
    bool quit = false;
    int counter = 0;
    Display();
    while( quit == false )
    {
        if(checkOnFloor(mario.getxpos(), mario.getypos(), mario.getwidth(), mario.getheight())){
            mario.vy = 0;
            mario.ay = 0;
            mario.onFloor = 0;
        }
        if(mario.getoldtime() + mario.getframerate() < SDL_GetTicks()) {
            mario.updateAnimation();
        }
        if((peach.getoldtime() + peach.getframerate() < SDL_GetTicks()) && (counter%5)==0) {
            peach.updateAnimation();
            if(counter%30==0 && peach.currentState==1){
                peach.currentState=2;
                peach.setAnimation();
            }
            else if(counter%30==0 && peach.currentState==2){
                peach.currentState=1;
                peach.setAnimation();
            }
            
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
        counter+=1;
        mario.move();
        Display();
    }
    SDL_Quit();
}

//Function to initialize floors
void DonkeyKongGame::initializeFloors(){
    floors[0].setslope(-.009107);
    floors[0].setyint(455);
    floors[0].setxmin(0);
    floors[0].setxmax(549);
    floors[0].setymin(400);
    floors[0].setymax(455);
}

int DonkeyKongGame::checkOnFloor(int xpos, int ypos, int width, int height){
    int yfloor;
    if(( ypos + height > floors[0].getymax() )&&( ypos + height < floors[0].getymin() )){
        
        yfloor =  floors[0].getslope() * mario.xpos + floors[0].getyint();
        
        if( ypos + height == yfloor ){
            mario.ypos = (yfloor - 2) - height;
            return 1;
        }
    }
    return 0;
}
