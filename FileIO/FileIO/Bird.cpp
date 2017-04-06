//
//  Bird.cpp
//  FileIO
//
//  Created by Artem Kovtunenko on 10/24/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Bird.h"
Bird:: Bird()
{
    name=" ";
    id=0;
}
Bird:: Bird(string name)
{
    name=name;
    id=0;
}
string Bird:: getName()const
{
    return name;
}
istream& operator >>(istream & in, Bird & bird) //no const here for the bird
{
    in>>bird.name;
    in>>bird.id;
    return in;
}
ostream& operator<<(ostream & out, const Bird & bird)
{
    out<<bird.name<<" "<<bird.id<<endl;
    return out;
}