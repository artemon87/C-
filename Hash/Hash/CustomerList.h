#ifndef _CUSTOMERLIST_H_
#define _CUSTOMERLIST_H_

#include "Customer.h"
#include "Transactions.h"
#include <vector>

using namespace std;

class CustomerList
{
private:

	static const int MAX_CUSTOMERS = 503;
    
    struct Trans              
    {
		Transactions *data;
        Trans *next;     
    };
    struct Client
    {
        Trans *edgeHead;		
        Customer *info;
    };
    

    Client vertices[MAX_CUSTOMERS];
	int size;

public:

	CustomerList();
	~CustomerList();
	void addTrans(Transactions *, Customer *);
	void addCustomer(Customer *);

};

#endif