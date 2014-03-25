//
//  Floor.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/25/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//
#ifndef FLOOR_H
#define FLOOR_H

class Floor{
    
public:
    
    Floor();
    double getslope();
    double getyint();
    
    void setslope(int);
    void setyint(int);
    
private:
    
    double slope;
    double yint;
    
};

#endif
