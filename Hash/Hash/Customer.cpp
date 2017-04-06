#include "Customer.h"


Customer::Customer()
{
}


Customer::~Customer()
{
}

void Customer:: setLastN(string last)
{
	lastN = last;
}

void Customer:: setFirstN(string first)
{
	firstN = first;
}

void Customer:: setID(int IDnum)
{
	ID = IDnum;
}

string Customer:: getLastN()const
{
	return lastN;
}

string Customer:: getFirstN()const
{
	return firstN;
}

int Customer:: getID()const
{
	return ID;
}