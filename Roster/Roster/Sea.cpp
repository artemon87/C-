//
//  Sea.cpp
//  Roster
//
//  Created by Artem Kovtunenko on 10/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Sea.h"
#include <iostream>

Player:: Player (){}
Player:: Player(S fName, S  lName, int num)
         {
           cout<<"Class was created of type PLAYER with paramenters"<<endl;
           fname=fName;
           lname=lName;
           number=num;
          }
Player:: Player (S fName, S lName);{fname=fName; lname=lName;}
Player:: int getNumber() const;{return number;}
Player:: string getFirstName()const{cout<<"Full name: "<<fname<<endl; return fname;}
Player:: void sutNumber(int num){number=num;}
Player:: void lucky(){cout<<"You are lucky"<<endl;}


