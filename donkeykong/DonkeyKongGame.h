//
//  DonkeyKongGame.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//  Highest class for game

#ifndef DONKEYKONGGAME_H
#define DONKEYKONGGAME_H

#include "Floor.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Object.h"
#include "Mario.h"
#include "Peach.h"
#include "DonkeyKong.h"
#include "Barrel.h"
#include "Hammer.h"
#include "Oil.h"
#include "Fireball.h"
#include <vector>

class DonkeyKongGame{
    
public:
    
    DonkeyKongGame();
    
    SDL_Surface* OnLoad(char*); //Function to load game background
    
    void Display(); //Renders all of the game objects and background onto the screen
    
    void Music_intro();

    void scoreAndLevel(); //keeps track of player score and prints it on screen
    

    void cleanUp(); //Cleans up all of the object in the game when it is finished
    
    void playDonkeyKong(); //Initiates gameplay and calls all other functions
    
    void applyBackground(int, int, SDL_Surface*, SDL_Surface*);
    
    void initializeFloors();
    
    int checkOnFloor(int, int, int, int);
    
    int checkForCollisions();
    
    int checkForWinner();
    
    void initializeLevel();
    
    void setBarrelSpeedBoost();
    
    void runIntroScreen();
    
    void onLoad(char);
    
    void introDisplay();

    void deathAnimation();
    
private:
    
    SDL_Surface* screen;//Screen surface
    SDL_Surface* background;//Surface for game background
    SDL_Surface *message;
    SDL_Surface* introScreen;
    SDL_Surface* floor;
    SDL_Surface* text;
    TTF_Font* font;
    
    Mario mario;//Mario object
    Peach peach; //Peach object
    DonkeyKong donkeykong; //donkeykong object
    Hammer hammer; //hammer object
    Oil oil; //oil can object
    Fireball fireball; //a fireball object
    vector<Barrel> barrels; //Barrel object
    
    int level;
	
  
    int dkSpeed;
    
    int scoreint; //integer value to keep track of score
    //char* currentScore;
};

#endif
