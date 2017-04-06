#ifndef _DVD_H_
#define _DVD_H_


//#pragma once
#include "Inventory.h"


class DVD: public Inventory
{
    
private:
    
    //int count;
    //string title;
    string director;
    //int year;
public:
    
    DVD();
	DVD(string, int, string, string, int);
    ~DVD();
};

#endif

