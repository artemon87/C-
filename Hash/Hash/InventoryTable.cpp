//
//  Hash.cpp
//  Hash
//
//  Created by Artem Kovtunenko on 2/14/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#include "InventoryTable.h"
#include <iostream>
using namespace std;

InventoryTable:: InventoryTable()
{
    for (int i = 0; i < SIZE; i++)
	{
		Table[i]->item = NULL;
		Table[i]->next = NULL;
	}
}
InventoryTable:: ~InventoryTable()
{
	delete this;
}

int InventoryTable:: getSizeTable()const
{
    return SIZE;
}
int InventoryTable::  hashIt(const string &key)
{
    int hashValue = 0;
   // for (int i = 0; i < key.length(); i++)
   // {
    hashValue = 37 * hashValue + key[0];
    //}
    hashValue %= SIZE;
    
    if (hashValue < 0)
    {
        hashValue += SIZE;
    }
    return hashValue;
}
int InventoryTable::  hashIt(int key)
{
    int hashValue = 0;
	hashValue = key % SIZE;
	int sum = 0;
	while (key > 0)
	{
		sum = sum + key % SIZE;
		key = key / 10;
	}
	hashValue += sum;
	return hashValue;
}
void InventoryTable::  makeEmpty()
{
    for (int i = 0; i < SIZE; i++)
	{
		Item *temp = Table[i];
		remove(temp);
	}
}
void InventoryTable:: remove(Item *node)
{
	while (node)
	{
		remove(node->next);
		delete node->item;
		delete node;
	}    
}
void InventoryTable:: addItem(Inventory *inv, const string &s)
{
	int index = hashIt(s);
	Item *temp = Table[index];
	Item *prev;
	if(temp->item == NULL)
	{
		Table[index] = new Item;
		Table[index]->item = inv;
		Table[index]->next = NULL;
	}
	else if (temp->item > inv)
	{
		Table[index] = new Item;
		Table[index]->item = inv;
		Table[index]->next = temp;
	}
	else
	{
		while (temp)
		{
			if(temp->item == inv)
			{
				temp->item->addItem(inv->inventoryLeft());
			}
			else if (temp->item > inv)
			{
				Item *newItem = new Item;
				newItem->item = inv;
				prev->next = newItem;
				newItem->next = temp;
			}
			else
			{
				prev = temp;
				temp = temp->next;
			}
		}
		if (temp == NULL)
		{
			Item *newItem = new Item;
			newItem->item = inv;
			newItem->next = NULL;
			temp = newItem;
		}
	}
}
void InventoryTable:: removeItem(Inventory *inv, const string &s)
{
	int index = hashIt(s);
	if(Table[index]->item == NULL)
		return;
	else
	{
		Item *temp = Table[index];
		Item *prev;
		while(temp->item != inv || temp)
		{
			prev = temp;
			temp = temp->next;
		}
		if(temp->item == NULL)
		{
			cout << "No such item exists in Inventory" << endl;
		}
		else if (inv->inventoryLeft() > temp->item->inventoryLeft())
		{
			cout << "Request denied. You cant take more than " 
				 << temp->item->inventoryLeft() << " copies of this item" <<endl;
		}
		else if (inv->inventoryLeft() == temp->item->inventoryLeft())
		{
			prev->next = temp;
			delete prev->item;
			delete prev;
		}
		else
			temp->item->releaseItem();

	}
}