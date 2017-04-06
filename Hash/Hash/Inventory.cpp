#include "Inventory.h"


Inventory:: Inventory()
{
}
Inventory:: ~Inventory()
{
}
void Inventory:: setInitials(string key)
{
	initials = key;
}
void Inventory:: setCount(int key)
{
	count = key;
}
void Inventory:: setTitle(string key)
{
	title = key;
}
void Inventory:: setYear(int key)
{
	year = key;
}
int Inventory:: inventoryLeft()const
{
	return count;
}
void Inventory:: addItem(int n)
{
	count += n;
}
void Inventory:: releaseItem()
{
	count -= 1;
}
void Inventory:: releaseAmount(int n)
{
	count -= n;
}