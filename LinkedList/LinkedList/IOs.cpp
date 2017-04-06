//
//  IOs.cpp
//  LinkedList
//
//  Created by Artem Kovtunenko on 10/17/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
    vector<string> v;
    string lname, fname;
    ifstream file;
    file.open("name.txt");
    while (getline(file, lname))
    {
        v.push_back(lname);
    }
    
    cout<<v[0];
    file.close();
    
    return 0;
}

