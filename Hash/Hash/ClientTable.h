//
//  Hash.h
//  Hash
//
//  Created by Artem Kovtunenko on 2/14/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#ifndef __CLIENTTABLE_H__
#define __CLIENTTABLE_H__

#include <stdio.h>
#include <string>
#include "HashTable.h"
#include "Transaction.h"
#include "Customer.h"


using namespace std;

class ClientTable: public HashTable
{
private:

	static const int SIZE = 503;
	struct History
	{
		Customer *client;
		//Transaction *trans;
		Inventory *inv;
		History *next;
	};
	History *Table[SIZE];

public:
	ClientTable();
	~ClientTable();


	int getSizeTable()const;
    int hashIt(const string &);
    int hashIt(int);
    void addItem(Inventory *, const int);
	void addCustomer(Customer *);
	void removeItem(Inventory *, const int);
    void makeEmpty();
    void remove(History *);
};

#endif /* defined(__Hash__Hash__) */