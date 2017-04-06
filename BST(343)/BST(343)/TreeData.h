//
//  TreeData.h
//  BST(343)
//
//  Created by Artem Kovtunenko on 1/13/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#ifndef _TREEDATA_H_
#define _TREEDATA_H_


#include <iostream>

using namespace std;

class TreeData
{
private:
    
    char character;
    //int count;
    
public:
    
    TreeData();
    TreeData(char ch);
    ~TreeData();
    
    //int getCount()const;
    char getCharacter()const;
    
    bool setCharacter(char ch);
    //bool setCount(int n);
    
    bool operator<(const TreeData & data)const;
    bool operator>(const TreeData & data)const;
    bool operator==(const TreeData & data)const;
    bool operator!=(const TreeData & data) const;
    
    
    friend istream& operator>>(istream &in, TreeData & data);
    friend ostream& operator<<(ostream &out, const TreeData & data);
    
};

#endif
