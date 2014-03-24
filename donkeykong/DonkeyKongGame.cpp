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
#include "Mario.h"

using namespace std;


//Constructor for DonkeyKongGame, initializes SDL, creates screen, and loads background
DonkeyKongGame::DonkeyKongGame(){
    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode( 550, 471, 32, SDL_SWSURFACE );
    background = OnLoad("/Users/jgavin/Documents/donkeykong/donkeykong/DonkeyKongBackground.bmp");
}


//Surface load function
SDL_Surface* DonkeyKongGame::OnLoad(char* File) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
    
    if((Surf_Temp = SDL_LoadBMP(File)) == NULL) {
        cout << "Returned Null" << endl;
        return NULL;
    }
    
    Surf_Return = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
    
    return Surf_Return;
}


//Display function which puts background and all objects on screen
void DonkeyKongGame::Display(){
    
    mario.display(background, mario.getMarioSurface(), mario.getxpos(), mario.getypos(),mario.getspritesheetx() + mario.getcurrentframe()*mario.getwidth(), mario.getspritesheety(), mario.getwidth(), mario.getheight());
   
    //Apply image to screen
    SDL_BlitSurface( background, NULL, screen, NULL );
    
    
    //Update Screen
    SDL_Flip( screen );
    
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
    int count = 1;
    while(count < 100){
        Display();
        SDL_Delay(150);
        mario.updateAnimation();
        mario.move();
        count++;
    }
    SDL_Quit();
}
