//
//  Player.cpp
//  Soccer
//
//  Created by Artem Kovtunenko on 10/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Player.h"
#include <iostream>
using namespace std;

typedef string S;


    
Player:: Player(){};
Player:: Player(S fName, S  lName, int num)
         {
           cout<<"Class was created of type PLAYER with paramenters"<<endl;
           fname=fName;
           lname=lName;
           number=num;
         }
Player:: Player (S fName, S lName){fname=fName; lname=lName;}
void Player:: setPlayer(S fName, S  lName, int num){fname=fName; lname=lName; number=num;}
int Player:: getNumber() const{return number;}
string Player:: getFirstName()const{cout<<"Full name: "<<fname<<endl; return fname;}
void Player:: sutNumber(int num){number=num;}
void Player:: lucky(){cout<<"You are lucky"<<endl;}
    

