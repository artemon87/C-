//
//  PlayerAgent.cpp
//  Soccer
//
//  Created by Artem Kovtunenko on 10/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "PlayerAgent.h"
#include <iostream>

using namespace std;


PlayerAgent::PlayerAgent(){}
PlayerAgent:: PlayerAgent(string Fname, string Lname, int ID): Player(Fname, Lname)
              {agentID=ID; cout<<"Your new ID: "<<agentID<<endl;}
    //PlayerAgent(S Name){name=Name;}
    //void setAgent(S name){name=name;}
void PlayerAgent:: setAgentID()
                   {agentID=rand()& 100+1;}
int PlayerAgent:: getAgentID()
                  {return agentID;}
