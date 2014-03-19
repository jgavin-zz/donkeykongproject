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

using namespace std;

DonkeyKongGame::DonkeyKongGame(){
    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode( 550, 471, 32, SDL_SWSURFACE );
    background = OnLoad("/Users/jgavin/Documents/donkeykong/donkeykong/DonkeyKongBackground.bmp");
}

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

void DonkeyKongGame::Display(){
    
    //Apply image to screen
    SDL_BlitSurface( background, NULL, screen, NULL );
    
    //Update Screen
    SDL_Flip( screen );
    
}

void DonkeyKongGame::cleanUp(){
    
    //Free the loaded image
    SDL_FreeSurface( background );
    
    //Quit SDL
    SDL_Quit();
}

void DonkeyKongGame::playDonkeyKong(){
    Display();
    SDL_Delay(3000);
    SDL_Quit();
    
}
