#ifndef _ROSTER
#define _ROSTER
#include <iostream>
using namespace std;

typedef string City;

class Sea : public Roster
{
  private:
    City seattle;
    
  public:
    Sea(){ cout<<"You have just created Sea class"<<endl;}
};

#include "332(Roster).cpp"
#endif