//
//  main.cpp
//  332Lab
//
//  Created by Artem Kovtunenko on 10/3/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include <stdlib.h> //for random


using namespace std;


#define out cout
typedef string S;


const int TEAM_SIZE=50;

class Player {
    
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
    Player (S fName, S lName){fname=fName; lname=lName;}
    void setPlayer(S fName, S  lName, int num){fname=fName; lname=lName; number=num;}
    int getNumber() const{return number;}
    string getFirstName()const{out<<"Full name: "<<fname<<endl; return fname;}
    void sutNumber(int num){number=num;}
    void lucky(){out<<"You are lucky"<<endl;}
    
};
class PlayerAgent : public Player
{
  private:
    S name;
    int agentID;
  public:
    PlayerAgent(){}
    PlayerAgent(S Fname, S Lname, int ID): Player(Fname, Lname){agentID=ID; out<<"Your new ID: "<<agentID<<endl;}
    //PlayerAgent(S Name){name=Name;}
    //void setAgent(S name){name=name;}
    void setAgentID(){agentID=rand()& 100+1;}
    int getAgentID(){return agentID;}
};

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
    
    //S a;
    //out<<"wellcome"<<endl;
    //Roster seahawks("Seahawks");
    //Player p1("Russel", "Wilson", 3);
    //Player p2("Spiro", "Agnew", 7);
    //Player p3("Tony", "Blair", 14);
    PlayerAgent agent("Artem", "Kovtunenko", 3);
    agent.setAgentID();
    int id=agent.getAgentID();
    out<<"ID : "<<id<<endl;
    agent.lucky();
    out<<agent.getFirstName()<<endl;
    //out<<"Agent's name: "<<agent.getFullName()<<endl;
    //p1.setPlayer("Russel", "Wilson", 3);
    //seahawks.AddPlayer(p1);
    
    
    
    // Players player (playerLName, playerFName, number);
    return 0;
}
  

