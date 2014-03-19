//
//  DonkeyKongGame.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include <SDL/SDL.h>

class DonkeyKongGame{
    
public:
    
    DonkeyKongGame();
    
    SDL_Surface* OnLoad(char*);
    
    void Display(); //Renders all of the game objects and background onto the screen
    
    void cleanUp(); //Cleans up all of the object in the game when it is finished
    
    void playDonkeyKong(); //Initiates gameplay and calls all other functions
    
private:
    
    SDL_Surface* screen;
    SDL_Surface* background;
    
};
