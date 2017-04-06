#include "DVD.h"


DVD::DVD(void)
{
}

DVD:: DVD(string initial, int amount, string dir, string title, int year)
{
	this->setInitials(initial);
	this->setCount(amount);
	director = dir;
	this->setTitle(title);
	this->setYear(year);
}

DVD::~DVD(void)
{
	delete this;
}
