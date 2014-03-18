//
//  main.m
//  donkeykong
//
//  Created by Jacob Gavin on 3/18/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include "SDL/SDL.h"
#include <iostream>
using namespace std;

SDL_Surface* OnLoad(char* File) {
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

int main(int argc, char *argv[])
{
    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;
    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    
    //Set up screen
    screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
    
    //Load image
    hello = OnLoad("/Users/jgavin/Documents/donkeykong/donkeykong/hello.bmp");
    
    //Apply image to screen
    SDL_BlitSurface( hello, NULL, screen, NULL );
    
    //Update Screen
    SDL_Flip( screen );
    
    //Pause
    SDL_Delay( 2000 );
    
    //Free the loaded image
    SDL_FreeSurface( hello );
    
    //Quit SDL
    SDL_Quit();
    
    return 0;
}
