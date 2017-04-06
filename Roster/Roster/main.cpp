//
//  main.cpp
//  Roster
//
//  Created by Artem Kovtunenko on 10/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "Sea.h"

using namespace std;


#define out cout
typedef string S;


const int TEAM_SIZE=50;

/*class Player {
    
private:
    S fname;
    S lname;
    int number;
    
public:
    
    Player(){};
    Player(S fName, S  lName, int num)
    {
        out<<"Class was created of type PLAYER with paramenters"<<endl;
        fname=fName;
        lname=lName;
        number=num;
    }
    void setPlayer(S fName, S  lName, int num){fname=fName; lname=lName; number=num;}
    int getNumber() const{return number;}
    string getFullName()const{return fname;}
    void sutNumber(int num){number=num;}
    
};*/

class Roster
{
private:
    Player player[TEAM_SIZE];
    
public:
    Roster()
    {
        
    }
    Roster(S team){out<<team<<" team was created"<<endl;}
    
    void AddPlayer(const Player &player)
    {
        out<<"You just added a player"<<endl;
    }
    Player getPlayer;
    void RemovePlayer(const Player &player);
    void PrintRoster();
    
    Player getPlayerByNumber(int num)const;
    Player getlayerByName(S fname, S lname)const;
    bool IsOnTeam(const Player &player);
};


int main() {
    
    S a;
    out<<"wellcome"<<endl;
    Roster seahawks("Seahawks");
    Player p1("Russel", "Wilson", 3);
    Player p2("Spiro", "Agnew", 7);
    Player p3("Tony", "Blair", 14);
    //p1.setPlayer("Russel", "Wilson", 3);
    seahawks.AddPlayer(p1);
    
    
    
    // Players player (playerLName, playerFName, number);
    return 0;
}


