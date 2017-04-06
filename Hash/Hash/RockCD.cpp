#include "RockCD.h"


RockCD::RockCD()
{
}

RockCD:: RockCD(string initial, int amount, string art, string title, int year)
{
	this->setInitials(initial);
	this->setCount(amount);
	artistName = art;
	this->setTitle(title);
	this->setYear(year);
}
RockCD::~RockCD()
{
	delete this;
}
