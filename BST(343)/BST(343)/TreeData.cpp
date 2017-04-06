//
//  TreeData.cpp
//  BST(343)
//
//  Created by Artem Kovtunenko on 1/13/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//
#include "TreeData.h"
#include <iostream>

using namespace std;

TreeData:: TreeData()
{
    //char=" ";
    //count=0;
}
TreeData:: TreeData(char ch)
{
    character=ch;
    //count=0;
}
TreeData:: ~TreeData()
{}
char TreeData:: getCharacter()const
{
    return character;
}

bool TreeData:: setCharacter(char ch)
{
    character=ch;
    return true;
}

bool TreeData:: operator<(const TreeData & data)const
{
    return (character < data.character);
}
bool TreeData:: operator>(const TreeData & data)const
{
    return (character > data.character);
}
bool TreeData:: operator==(const TreeData & data)const
{
    return (character == data.character);
}
bool TreeData:: operator!=(const TreeData & data) const
{
    return (character != data.character);
}
ostream& operator<<(ostream &out, const TreeData & data)
{
    out << data.character;
    return out;
}
istream& operator>>(istream &in, TreeData &data)
{
    in >> data.character;
    return in;
}
