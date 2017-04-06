#include "CustomerList.h"
#include <iostream>

using namespace std;

CustomerList:: CustomerList()
{
	for (int i = 0; i < size; i++)
	{
		vertices[i].data = NULL;
		vertices[i].edgeHead = NULL;
	}
}


CustomerList:: ~CustomerList()
{

}


void CustomerList:: addTrans(Inventory *inv, Customer *cust)
{
	Trans *temp;
	Trans *newTrans = new Trans;

	temp = vertices[cust->getID()].edgeHead;
	while(temp && temp->next)
	{
		if(temp->info == inv)
		{
			temp->info->addItem(inv->inventoryLeft());
			return;
		}
		temp = temp->next;
	}
	newTrans->info = inv;
	newTrans->next = NULL;
	if(temp)
	{
		temp->next = newTrans;
	}
	else
	{
		vertices[cust->getID()].edgeHead = newTrans;
	}
	CustomerIDs.push_back(cust->getID());

}
void CustomerList:: addCustomer(Customer *cust)
{
	if(vertices[cust->getID()].data == NULL)
	{
		vertices[cust->getID()].data = cust;
		vertices[cust->getID()].edgeHead = NULL;
	}
	else
	{
		cout << "Customer with this ID already exists" << endl;
	}
}