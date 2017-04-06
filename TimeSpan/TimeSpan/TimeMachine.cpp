//
//  main.cpp
//  TimeSpan
//
//  Created by Artem Kovtunenko on 10/8/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "TimeSpan.h"

using namespace std;

int main()
{
    TimeSpan time1(1.5, 0, -13), time2(1.5, 20.5, 30), time3(4), time4(16.5, 30), time5;
    cout<<time1<<time2<<time3<<time4<<time5<<endl;
    TimeSpan time11(1, 30, -13);
    if(time1!=time11)
    {
        cout<<"Time1!=Time11"<<endl;
    }
    else
    {
        cout<<"They are equal"<<endl;
    }
    TimeSpan time6(1, 1, 1);
    cout<<time6<<endl;
    TimeSpan time7(0);
    time7=time1+time2;
    cout<<time3<<endl;
    TimeSpan time8(1.5, 0, 13);
    TimeSpan time9(1, 60, 0);
    TimeSpan time10(2, -1, 60);
    if(time9==time10)
    {
        cout<<"Equal "<<endl;
    }
    TimeSpan time12;
    time12.setHours(3);
    time12.setMinutes(20);
    time12.setSeconds(15);
    cout<<time12<<endl;
    time10+=time2;
    cout<<time10<<endl;
    time10-=time2;
    cout<<time10<<endl;
    TimeSpan input;
    cout<<"Enter hours, minutes, and seconds: "<<endl;
    cin>>input;
    cout<<input;
    
    
    return 0;
}

