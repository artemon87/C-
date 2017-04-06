//
//  Anna.h
//  class
//
//  Created by Artem Kovtunenko on 10/7/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __class__Anna__
#define __class__Anna__



class Anna
{
public:
    Anna();
    //Anna(int h, int m, int s);
    //void setAge(int y, int m, int d);
    void duration(int h, int m, int s);
    const int getHours()const;
    const int getMinutes()const;
    const int getSoconds()const;
    void setHours(int);
    void setMinutes(int);
    void setSoconds(int);
    Anna operator+(Anna annaB);
    
    //virtual ~Anna();
private:
    //int year;
    //int month;
    //int day;
    int hours, minutes, seconds;
    
};

#endif // ANNA_H