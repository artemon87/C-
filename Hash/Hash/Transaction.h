#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include "Customer.h"
#include "Inventory.h"

class Transaction
{

private: 

	Customer *customerInfo;
	Inventory *inventoryInfo;

public:
	Transaction();
	~Transaction(void);
    void purchase(Inventory *);
    void tradeIn(Inventory *);
    void display()const;
    void history(Customer *)const;
    void historyAll()const;
};


#endif
