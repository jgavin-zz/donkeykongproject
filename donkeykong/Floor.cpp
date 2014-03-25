//
//  Floor.cpp
//  donkeykong
//
//  Created by Jacob Gavin on 3/25/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include "DonkeyKongGame.h"
#include "Floor.h"
#include <SDL/SDL.h>



Floor::Floor(){
    
}

double Floor::getslope(){
    return slope;
}

double Floor::getyint(){
    return yint;
}

void Floor::setslope(int value){
    slope = value;
}

void Floor::setyint(int value){
    yint = value;
}







