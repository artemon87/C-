#include "Store.h"
#include "RockCD.h"
#include "ClassicalCD.h"
#include "DVD.h"

void Store:: readInventory(fstream &infile)
{
	//Customer *customer;
	Inventory *inventory;
	string ch;
	int num;
	if(infile.eof())
		return;
	else
	{
		while(!infile.eof())
		{
			infile >> ch;
			

			if( ch == "C")
			{
				inventory = new ClassicalCD;
				inventory->setInitials(ch);
				infile.ignore(256, '\n');
				infile >> num;
				inventory->setCount(num);
				infile.ignore(256, '\n');

				infile.ignore(256, '\n');
				infile.ignore(256, '\n');
			}
			else if( ch == "R")
			{
				inventory->setInitials(ch);
			}
			else if( ch == "D")
			{
				inventory->setInitials(ch);
			}
			else
				infile.ignore(256, '\n');
			//infile >> 
		}
	}
}
void Store:: readCustomer(fstream &infile)
{
}
void Store:: readTransaction(fstream &infile)
{
}