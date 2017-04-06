//
//  main.cpp
//  Soccer
//
//  Created by Artem Kovtunenko on 10/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "Player.h"
#include "PlayerAgent.h"

using namespace std;

int main() {
    // insert code here...
    PlayerAgent artem("Artem", "Kovtunenko", 16);
    //artem.setAgentID();
    int id=artem.getAgentID();
    cout<<"ID : "<<id<<endl;
    artem.lucky();
    cout<<artem.getFirstName()<<endl;
    PlayerAgent max;
    max.setPlayer("Max", "Kovt", 7);
    int temp=max.getNumber();
    cout<<"Max's number: "<<temp<<endl;
    
    
    return 0;
}
