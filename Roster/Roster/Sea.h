//
//  Sea.h
//  Roster
//
//  Created by Artem Kovtunenko on 10/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __SEA_H
#define __SEA_H

#include <string>
//#include <iostream>

using namespace std;
//#define out cout

typedef string S;


class Player {
    
private:
    S fname;
    S lname;
    int number;
    
public:
    
    Player(){};
    Player(S fName, S  lName, int num)
    {
    }
    Player (S fName, S lName);//{fname=fName; lname=lName;}
    void setPlayer(S fName, S  lName, int num){fname=fName; lname=lName; number=num;}
    int getNumber() const;//{return number;}
    string getFirstName()const//{cout<<"Full name: "<<fname<<endl; return fname;}
    void sutNumber(int num){number=num;}
    void lucky(){cout<<"You are lucky"<<endl;}
    
};

#endif /* defined(__Player__) */
