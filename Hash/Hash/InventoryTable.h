//
//  Hash.h
//  Hash
//
//  Created by Artem Kovtunenko on 2/14/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#ifndef __INVENTORYTABLE_H__
#define __INVENTORYTABLE_H__

#include <stdio.h>
#include <string>
#include "Inventory.h"
#include "HashTable.h"

using namespace std;


class InventoryTable//: public HashTable
{
    
private:
    
    
    static const int SIZE = 10;
    int count;
    
    struct Item
    {
        Inventory *item;
        Item *next;
    };
    Item *Table[SIZE];
    
public:
    
    InventoryTable();
    ~InventoryTable();
    
    int getSizeTable()const;
    int hashIt(const string &);
    int hashIt(int);
    void addItem(Inventory *, const string &);
	void removeItem(Inventory *, const string &);
    void makeEmpty();
    void remove(Item *);
    
    
    
    
    
    
};

#endif