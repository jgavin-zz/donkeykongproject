//  Created by Ryan Moran on 4/10/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.

////NOTE: BOUNCE FUNCTION BELOW NOT FINISHED YET. FUNCTION BELOW FROM BARREL CLASS FOR COMPARISON
#include "Object.h"
#include "Fireball.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Fireball::Fireball() : Object(17, 17, 25, 437, 0, 0, 0, 2, 0, 2, 0, 0, 100){
    setAnimation();
    floorNumber = 1; //fireball always begins on floor one
    climbing = 0;
    initializeFloors();
    alive = 0; //fireball doesn't become alive (alive=1) until the first live barrel hits the oil can
}

//Fireball specific move function that governs physical movement of the fireball on screen
void Fireball::move(){
    //Set a dt variable and variable for gravity
    double dt = .12; ay = 1.5;
    
        vx += (ax * dt);
        vy += (ay * dt);
        xpos += (vx * dt);
        ypos += (vy * dt);
    xpos = xpos+vx*dt;
}

void Fireball::bounce(){
	if(floorNumber== 7){
		move();
	}
	else if(floorNumber == 6){
	move();
		updateAnimation();
		if (currentState == 1 && currentFrame == 1){
			updateAnimation();
		}
		if (currentFrame == 2 && currentState == 1){
			currentState = 2;
			setAnimation();
			updateAnimation();
			updateAnimation();
		}
		if (currentState == 2 && currentFrame == 2){
			updateAnimation();
			updateAnimation();
		}
		if(currentState == 2 && currentFrame == 1){
			currentState = 1;
			setAnimation();
			updateAnimation();
		}
	}
	else if (floorNumber == 5){
        move();
		updateAnimation();
		if (currentState == 1 && currentFrame == 1){
			updateAnimation();
		}
		if (currentFrame == 2 && currentState == 1){
			currentState = 2;
			setAnimation();
			updateAnimation();
			updateAnimation();
		}
		if (currentState == 2 && currentFrame == 2){
			updateAnimation();
			updateAnimation();
		}
		if(currentState == 2 && currentFrame == 1){
			currentState = 1;
			setAnimation();
			updateAnimation();
		}
	}
	else if (floorNumber == 4){
        move();
		updateAnimation();
		if (currentState == 1 && currentFrame == 1){
			updateAnimation();
		}
		if (currentFrame == 2 && currentState == 1){
			currentState = 2;
			setAnimation();
			updateAnimation();
			updateAnimation();
		}
		if (currentState == 2 && currentFrame == 2){
			updateAnimation();
			updateAnimation();
		}
		if(currentState == 2 && currentFrame == 1){
			currentState = 1;
			setAnimation();
			updateAnimation();
		}
	}
	else if (floorNumber == 3){
        move();
		updateAnimation();
		if (currentState == 1 && currentFrame == 1){
			updateAnimation();
		}
		if (currentFrame == 2 && currentState == 1){
			currentState = 2;
			setAnimation();
			updateAnimation();
			updateAnimation();
		}
		if (currentState == 2 && currentFrame == 2){
			updateAnimation();
			updateAnimation();
		}
		if(currentState == 2 && currentFrame == 1){
			currentState = 1;
			setAnimation();
			updateAnimation();
		}
	}
	else if (floorNumber == 2){
        move();
		updateAnimation();
		if (currentState == 1 && currentFrame == 1){
			updateAnimation();
		}
		if (currentFrame == 2 && currentState == 1){
			currentState = 2;
			setAnimation();
			updateAnimation();
			updateAnimation();
		}
		if (currentState == 2 && currentFrame == 2){
			updateAnimation();
			updateAnimation();
		}
		if(currentState == 2 && currentFrame == 1){
			currentState = 1;
			setAnimation();
			updateAnimation();
		}
	}
	else if (floorNumber == 1){
	if(xpos==1){
	}
	else if(xpos==490){
	}
        move();
		if(xpos>267){
		ypos+=.025;
		}
	}
}

//Function that flips through frames of spritesheet to animate fireball
void Fireball::updateAnimation(){
    oldTime = SDL_GetTicks();
    currentFrame++;
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
}


//Function sets animation parameters according to state of fireball
void Fireball::setAnimation(){
    switch(currentState){
        case 1: //moving left
            spritesheetx = 111; //x location on sprite sheet
            spritesheety = 220; //y location on sprite sheet
            currentFrame = 1; //always begins at frame 1
            maxFrames = 2; //two total frames to flip between
            height = 17;
            width = 17;
            break;
        case 2: //moving right
            spritesheetx = 155;
            spritesheety = 220;
            currentFrame = 1;
            maxFrames = 2;
            height = 17;
            width = 20;
            break;
       
    }
}

//function to make sure fireball guy stays on screen
void Fireball::ensureOnScreen(){
	if(xpos>495){
		vx = -1;
	}
	else if(xpos<5){
		vx = 1;
	}
}
