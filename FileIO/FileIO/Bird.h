//
//  Bird.h
//  FileIO
//
//  Created by Artem Kovtunenko on 10/24/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __FileIO__Bird__
#define __FileIO__Bird__

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Bird
{
    friend istream& operator >>(istream & in, Bird &);
    friend ostream& operator<<(ostream & out, const Bird &);
public:
    Bird();
    Bird(string name);
    string getName()const;
    //~Bird();
private:
    string name;
    int id;
    
};

#endif /* defined(__FileIO__Bird__) */
