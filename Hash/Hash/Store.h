#ifndef _STORE_H_
#define _STORE_H_

#include "Customer.h"
#include "Inventory.h"
#include "CustomerList.h"
#include "InventoryTable.h"
#include <iostream>
#include <fstream>


class Store
{
public:

	void readInventory(fstream &);
	void readCustomer(fstream &);
	void readTransaction(fstream &);

};

#endif