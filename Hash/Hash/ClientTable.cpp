#include "ClientTable.h"


ClientTable:: ClientTable()
{
    for (int i = 0; i < SIZE; i++)
	{
		Table[i]->client = NULL;
		Table[i]->next = NULL;
		Table[i]->trans = NULL;
		Table[i]->inv = NULL;
	}
}
ClientTable:: ~ClientTable()
{
	delete this;
}
void ClientTable:: addCustomer(Customer *cust)
{
	int index = hashIt(cust->getID());
	if(Table[index]->client == NULL)
	{
		Table[index]->client = cust;
	}
	else if(Table[index]->client != cust)
	{
		int i = 1;
		while(Table[index + i]->client != NULL || Table[index + i]->client != cust)
		{
			i++;
			i *= i;
		}
		if(Table[index + i]->client == NULL)
		{
			Table[index]->client = cust;
		}
		else
			return;
	}
}
int ClientTable:: getSizeTable()const
{
    return SIZE;
}
int ClientTable::  hashIt(const string &key)
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
int ClientTable::  hashIt(int key)
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
	if (hashValue < 0)
    {
        hashValue += SIZE;
    }
	return hashValue;
}
void ClientTable::  makeEmpty()
{
    for (int i = 0; i < SIZE; i++)
	{
		History *temp = Table[i];
		remove(temp);
	}
}
void ClientTable:: remove(History *node)
{
	while (node)
	{
		remove(node->next);
		delete node->trans;
		delete node->client;
		delete node;
	}    
}
void ClientTable:: addItem(Inventory *inv, const int s)
{
	int index = hashIt(s);
	History *temp = Table[index];
	History *prev;
	if(temp->trans == NULL)
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
void ClientTable:: removeItem(Inventory *inv, const string &s)
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
