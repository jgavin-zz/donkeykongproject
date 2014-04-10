//  Created by Ryan Moran on 4/10/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.

////NOTE: BOUNCE FUNCTION BELOW NOT FINISHED YET. FUNCTION BELOW FROM BARREL CLASS FOR COMPARISON
#include "Object.h"
#include "Fireball.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Fireball::Fireball() : Object(17, 17, 25, 430, 0, 0, 0, 1, 0, 2, 0, 0, 100){
    setAnimation();
    floorNumber = 1;
    climbing = 0;
    initializeFloors();
    alive = 1;
}

void Fireball::move(){
    double dt = .5; ay = 2;
    if( climbing == 0){
        vx += (ax * dt);
        vy += (ay * dt);
        xpos += (vx * dt);
        ypos += (vy * dt);
    }
    
    if (xpos <= 0) {
        xpos = 2;
        vx = 0;
    }
    
    if (xpos >= 531) {
        xpos = 529;
        vx = 0;
    }
    
    if ( ypos <= 49) {
        ypos = 50;
        vy = 0;
    }
}

void Fireball::bounce(){ //Haven't changed this from the roll function used in barrel yet
	//cout<<floorNumber<<endl;
	if(floorNumber == 6){
        ax = 0;
        vx = 1.5;
        //ax = .05;
        move();
		//xpos += .5;
		/*if(xpos >= 350){
         ypos+=.025;
         }*/
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
        
		/*if (xpos >= 507){
         floorNumber -=1;
         ypos = 215;
         }*/
        /*if(checkOnFloor()){
         ypos = checkOnFloor() - height;
         vy = 0;
         onFloor = 1;
         floorNumber = 7;
         previousFloor = 7;
         }*/
	}
	else if (floorNumber == 5){
        vx = -1.5;
        //ax = -.05;
        move();
		/*xpos -= .5;
		ypos+=.02;*/
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
        
		/*if (xpos <= 23){
			floorNumber -=1;
			ypos = 265;
		}*/
	}
	else if (floorNumber == 4){
        vx = 1.5;
        //ax = .05;
        move();
		/*xpos += .5;
		ypos+=.025;*/
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
        
		/*if (xpos >= 507){
			floorNumber -=1;
			ypos = 320;
		}*/
	}
	else if (floorNumber == 3){
        vx = -1.5;
        //ax = .05;
        move();
		/*xpos -= .5;
		ypos+=.025;*/
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
        
		/*if (xpos <= 23){
			floorNumber -=1;
			ypos = 376;
		}*/
	}
	else if (floorNumber == 2){
        vx = 1.5;
        //ax = .05;
        move();
		/*xpos += .5;
		ypos+=.025;*/
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
        
		/*if (xpos >= 507){
			floorNumber -=1;
			ypos = 432;
		}*/
	}
	else if (floorNumber == 1){
        vx = -1.5;
        //ax = .05;
        move();
		//xpos -= .5;
		if(xpos>267){
		ypos+=.025;
		}
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
        
		if (xpos <= 23){
			currentState = 1;
			setAnimation();
		}
	}
}



void Fireball::updateAnimation(){
    oldTime = SDL_GetTicks();
    currentFrame++;
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
    //(*this).setAnimation();
}


//Function sets animation parameters according to state of mario
void Fireball::setAnimation(){
    switch(currentState){
        case 1: //moving left
            spritesheetx = 111;
            spritesheety = 220;
            currentFrame = 1;
            maxFrames = 2;
            height = 17;
            width = 17;
            break;
        case 2: //moving right
            spritesheetx = 155;
            spritesheety = 220;
            currentFrame = 1;
            maxFrames = 2;
            height = 17;
            width = 17;
            break;
       
    }
}
