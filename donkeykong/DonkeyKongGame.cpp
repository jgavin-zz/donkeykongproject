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
#include "SDL_image/SDL_image.h"
include "SDL_ttf/SDL_ttf.h"
#include <string>
#include "DonkeyKongGame.h"
#include "Object.h"
#include "Mario.h"
#include "Peach.h"
#include "DonkeyKong.h"
#include "SDL/SDL_mixer.h"

using namespace std;


SDL_Event event;
//The music that will be played
Mix_Music *music = NULL;

//Constructor for DonkeyKongGame, initializes SDL, creates screen, and loads background
DonkeyKongGame::DonkeyKongGame(){
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Color textColor = { 255, 255, 255 }; // it's white for now, color of text
    screen = SDL_SetVideoMode( 550, 471, 32, SDL_SWSURFACE );
    background = SDL_LoadBMP("DonkeyKongBackground.bmp");
   
    TTF_Font *font;
    font = TTF_OpenFont( "kongtext.ttf", 36 ); //size 12 font
    message = TTF_RenderText_Solid( font, "Current Score:", textColor );
    initializeFloors();
}


void DonkeyKongGame::Music() {
   
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    music = Mix_LoadMUS( "intro.wav" );
    Mix_PlayMusic(music, -1);
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
    SDL_FreeSurface( message );
    mario.cleanUp();
    Mix_FreeMusic( music );
    
    //Quit SDL Mixer
    Mix_CloseAudio();
    //Quit SDL
    SDL_Quit();
}

//Function to create gameplay
void DonkeyKongGame::playDonkeyKong(){
    bool quit = false;
    int counter = 0;
    Display();
    Music();

    while( quit == false )
    {
        //cout << "onFloor = " << mario.onFloor << endl;
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
            checkOnFloor(mario.getxpos(), mario.getypos(), mario.getwidth(), mario.getheight());
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
        checkOnFloor(mario.getxpos(), mario.getypos(), mario.getwidth(), mario.getheight());
        Display();
    }
    SDL_Quit();
}

//Function to initialize floors
void DonkeyKongGame::initializeFloors(){
    floors[0].setslope(-.009107);
    floors[0].setyint(455);
    floors[0].setxmin(0);
    floors[0].setxmax(550);
    floors[0].setymin(400);
    floors[0].setymax(455);
    
    floors[1].setslope(.03777);
    floors[1].setyint(388);
    floors[1].setxmin(0);
    floors[1].setxmax(503);
    floors[1].setymin(345);
    floors[1].setymax(410);
    
    floors[2].setslope(-.04297);
    floors[2].setyint(352);
    floors[2].setxmin(38);
    floors[2].setxmax(550);
    floors[2].setymin(292);
    floors[2].setymax(354);
    
    floors[3].setslope(.04118);
    floors[3].setyint(277);
    floors[3].setxmin(0);
    floors[3].setxmax(510);
    floors[3].setymin(236);
    floors[3].setymax(298);
    
    floors[4].setslope(-.0435);
    floors[4].setyint(245);
    floors[4].setxmin(38);
    floors[4].setxmax(550);
    floors[4].setymin(192);
    floors[4].setymax(241);
    
    floors[5].setslope(.01569);
    floors[5].setyint(180);
    floors[5].setxmin(0);
    floors[5].setxmax(510);
    floors[5].setymin(0);
    floors[5].setymax(188);
    
    floors[6].setslope(0);
    floors[6].setyint(123);
    floors[6].setxmin(235);
    floors[6].setxmax(353);
    floors[6].setymin(0);
    floors[6].setymax(123);
}

int DonkeyKongGame::checkOnFloor(int xpos, int ypos, int width, int height){
    int yfloor;
    
    if(( ypos + height < floors[6].getymax() )&&( ypos + height > floors[6].getymin() )){
        if(( xpos < floors[6].getxmax() )&&( xpos + width > floors[6].getxmin() )){
            
            yfloor =  floors[6].getslope() * mario.xpos + floors[6].getyint();
            cout << "yfloor = " << yfloor << endl;
            
            if( ypos + height >= yfloor ){
                mario.ypos = (yfloor) - height;
                mario.vy = 0;
                mario.onFloor = 1;
                mario.floorNumber = 7;
                return 1;
            }
        }
    }
    if(( ypos + height < floors[5].getymax() )&&( ypos + height > floors[5].getymin() )){
        if(( xpos < floors[5].getxmax() )&&( xpos + width > floors[5].getxmin() )){
            
            yfloor =  floors[5].getslope() * mario.xpos + floors[5].getyint();
            cout << "yfloor = " << yfloor << endl;
            
            if( ypos + height >= yfloor ){
                mario.ypos = (yfloor) - height;
                mario.vy = 0;
                mario.onFloor = 1;
                mario.floorNumber = 6;
                return 1;
            }
        }
    }
    if(( ypos + height < floors[4].getymax() )&&( ypos + height > floors[4].getymin() )){
        if(( xpos < floors[4].getxmax() )&&( xpos + width > floors[4].getxmin() )){
            
            yfloor =  floors[4].getslope() * mario.xpos + floors[4].getyint();
            cout << "yfloor = " << yfloor << endl;
            
            if( ypos + height >= yfloor ){
                mario.ypos = (yfloor) - height;
                mario.vy = 0;
                mario.onFloor = 1;
                mario.floorNumber = 5;
                return 1;
            }
        }
    }
    if(( ypos + height < floors[3].getymax() )&&( ypos + height > floors[3].getymin() )){
        if(( xpos < floors[3].getxmax() )&&( xpos + width > floors[3].getxmin() )){
            
            yfloor =  floors[3].getslope() * mario.xpos + floors[3].getyint();
            cout << "yfloor = " << yfloor << endl;
            
            if( ypos + height >= yfloor ){
                mario.ypos = (yfloor) - height;
                mario.vy = 0;
                mario.onFloor = 1;
                mario.floorNumber = 4;
                return 1;
            }
        }
    }
    if(( ypos + height < floors[2].getymax() )&&( ypos + height > floors[2].getymin() )){
        if(( xpos < floors[2].getxmax() )&&( xpos + width > floors[2].getxmin() )){
            
            yfloor =  floors[2].getslope() * mario.xpos + floors[2].getyint();
            
            if( ypos + height >= yfloor ){
                mario.ypos = (yfloor) - height;
                mario.vy = 0;
                mario.onFloor = 1;
                mario.floorNumber = 3;
                return 1;
            }
        }
    }
    
    if(( ypos + height < floors[1].getymax() )&&( ypos + height > floors[1].getymin() )){
        if(( xpos < floors[1].getxmax() )&&( xpos + width > floors[1].getxmin() )){
            
            yfloor =  floors[1].getslope() * mario.xpos + floors[1].getyint();
            
            if( ypos + height >= yfloor ){
                mario.ypos = (yfloor) - height;
                mario.vy = 0;
                mario.onFloor = 1;
                mario.floorNumber = 2;
                return 1;
            }
        }
    }
    if( ypos + height > floors[0].getymin() ){
        
        yfloor =  floors[0].getslope() * mario.xpos + floors[0].getyint();
        
        if( ypos + height >= yfloor ){
            mario.ypos = (yfloor) - height;
            mario.onFloor = 1;
            mario.vy = 0;
            mario.floorNumber = 1;
            return 1;
        }
    }
    return 0;
}
