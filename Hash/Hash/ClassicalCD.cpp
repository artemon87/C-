#include "ClassicalCD.h"


ClassicalCD::ClassicalCD()
{
}

ClassicalCD:: ClassicalCD(string str, int amount, string comp, string title, int year, string art)
{
	this->setInitials(str);
	this->setCount(amount);
	artistName = art;
	this->setTitle(title);
	this->setYear(year);
	composer = comp;
}
ClassicalCD::~ClassicalCD()
{
}
