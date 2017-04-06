//
//  Player.h
//  Soccer
//
//  Created by Artem Kovtunenko on 10/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __Soccer__Player__
#define __Soccer__Player__

#include <stdio.h>
#include <string>

using namespace std;

typedef string S;

//using namespace std;

class Player {
    
private:
    S fname;
    S lname;
    int number;
    
public:
    
    Player();
    Player(S fName, S  lName, int num);
    Player (S fName, S lName);
    void setPlayer(S fName, S  lName, int num);
    int getNumber() const;
    string getFirstName()const;
    void sutNumber(int num);
    void lucky();
    
};

#endif /* defined(__Soccer__Player__) */
