//
//  PlayerAgent.h
//  Soccer
//
//  Created by Artem Kovtunenko on 10/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __Soccer__PlayerAgent__
#define __Soccer__PlayerAgent__

#include "Player.h"
#include <stdio.h>
#include <string>

using namespace std;

class PlayerAgent : public Player
{
private:
    string name;
    int agentID;
public:
    PlayerAgent();
    PlayerAgent(string Fname, string Lname, int ID);//: Player(Fname, Lname); //no need to declare a help from a Player class in .h file (only in cpp)
    void setAgentID();
    int getAgentID();
};


#endif /* defined(__Soccer__PlayerAgent__) */
