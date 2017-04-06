//
//  TimeSpan.h
//  TimeSpan
//
//  Created by Artem Kovtunenko on 10/8/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __TIMESPAN_H__
#define __TIMESPAN_H__

//#include <stdio.h>
#include <iostream>
using namespace std;

class TimeSpan
{
    
private:
    
    double hours;
    double minutes;
    double seconds;
    
public:
    
    TimeSpan();
    TimeSpan(double);
    TimeSpan(double, double);
    TimeSpan(double, double, double);
    
    int getHours()const;
    int getMinutes()const;
    int getSeconds()const;
    void setHours(int);
    void setMinutes(int);
    void setSeconds(int);
    
    void normalize(double &, double &, double &)const;
    void convert(double &, double &, double &);
    
    TimeSpan operator+(const TimeSpan &)const;
    TimeSpan operator-(const TimeSpan &)const;
    TimeSpan operator+=(const TimeSpan &);
    TimeSpan operator-=(const TimeSpan &);
    bool operator==(const TimeSpan &)const;
    bool operator!=(const TimeSpan &) const;
    
    friend istream& operator>>(istream&, TimeSpan&);
    friend ostream& operator<<(ostream&, const TimeSpan&);

};


#endif /* defined(__TimeSpan__TimeSpan__) */


