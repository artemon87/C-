#ifndef _ROCKCD_H_
#define _ROCKCD_H_


//#pragma once
#include "Inventory.h"


class RockCD: public Inventory
{
    
private:
    //int count;
    string artistName;
    //string title;
    //int year;
    
public:
    
    RockCD();
	RockCD(string, int, string, string, int);
    ~RockCD();
    
    
};

#endif