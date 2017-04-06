#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;


class Customer
{
private:

	string lastN;
	string firstN;
	int ID;
    vector<Transaction *> *history;
    

public:

	Customer();
	~Customer();
	void setLastN(string);
	void setFirstN(string);
	void setID(int);

	string getLastN()const;
	string getFirstN()const;
	int getID()const;
    void displayHistory();

};

#endif