//
//  Anna.cpp
//  class
//
//  Created by Artem Kovtunenko on 10/7/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

//#include "Anna.h"
#include <iostream>
#include "Anna.h"

using namespace std;

Anna:: Anna()
{
    cout<<"You just created an Anna object"<<endl;
}
/*Anna:: Anna(int y, int m, int d)
 {
 year=y;
 month=m;
 day=d;
 }*/
void Anna:: duration(int h, int m, int s)
{
    Anna anna;
    anna.hours=h;
    anna.minutes=m;
    anna.seconds=s;
    
    while(anna.minutes>59)
    {
        anna.hours++;
        anna.minutes-=60;
        if(anna.seconds<0)
        {
            anna.minutes--;
            anna.seconds+=60;
        }
        else if(anna.seconds>59)
        {
            anna.minutes++;
            anna.seconds-=60;
        }
    }
    while(anna.minutes<0 && anna.hours>0)
    {
        anna.hours--;
        anna.minutes+=60;
    }
    cout<<anna.hours<<" "<<anna.minutes<<" "<<anna.seconds<<endl;;//return Anna;
}

//Anna::~Anna()
//{
    //dtor
//}
Anna Anna::operator+(Anna annaB)
{
    Anna annaA;
    annaA.hours=hours+annaB.hours;
    annaA.minutes=minutes+annaB.minutes;
    annaA.seconds=seconds+annaB.seconds;
    cout<<"Hours "<<annaA.hours<<"Minutes "<<annaA.minutes<<"Seconds "<<annaA.seconds<<endl;
    return annaA;    
}
const int Anna:: getHours()const
{
    return hours;
}
const int Anna:: getMinutes()const
{
    return minutes;
}
const int Anna:: getSoconds()const
{
    return seconds;
}
void Anna:: setHours(int h)
{
    hours=h;
}
void Anna:: setMinutes(int m)
{
    minutes=m;
}
void Anna:: setSoconds(int s)
{
    seconds=s;
}
