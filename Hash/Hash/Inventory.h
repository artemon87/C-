//
//  Inventory.h
//  Hash
//
//  Created by Artem Kovtunenko on 2/14/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <stdio.h>
#include <string>

using namespace std;

class Inventory
{
    
private:
    
	string initials;
    int count;
    string title;
    string year;
    
public:
    
    Inventory();
    virtual ~Inventory();

	void setInitials(string);
	void setCount(int);
	void setTitle(string);
	void setYear(int);

    int inventoryLeft()const;
	void addItem(int);
    void releaseItem();
	void releaseAmount(int);
    
};

#endif