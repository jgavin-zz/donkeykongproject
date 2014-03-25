//
//  DonkeyKongGame.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//  Highest class for game

#ifndef DONKEYKONGGAME_H
#define DONKEYKONGGAME_H

#include <SDL/SDL.h>
#include "Object.h"
#include "Mario.h"

class DonkeyKongGame{
    
public:
    
    DonkeyKongGame();
    
    SDL_Surface* OnLoad(char*); //Function to load game background
    
    void Display(); //Renders all of the game objects and background onto the screen
    
    void cleanUp(); //Cleans up all of the object in the game when it is finished
    
    void playDonkeyKong(); //Initiates gameplay and calls all other functions
    
    void applyBackground(int, int, SDL_Surface*, SDL_Surface*);
private:
    
    SDL_Surface* screen;//Screen surface
    SDL_Surface* background;//Surface for game background
    Mario mario;//Mario object
    
};

#endif
