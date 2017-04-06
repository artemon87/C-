#ifndef _CLASSICAL_H_
#define _CLASSICAL_H_


//#pragma once
#include "inventory.h"


class ClassicalCD: public Inventory
{
    
private:
    //int count;
    string composer;
    string artistName;
    //string title;
    //int year;
    
public:
    
    ClassicalCD();
	ClassicalCD(string, int, string, string, int, string);
    ~ClassicalCD();
    
};

#endif
