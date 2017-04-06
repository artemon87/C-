//
//  main.cpp
//  FileIO
//
//  Created by Artem Kovtunenko on 10/24/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Bird.h"


using namespace std;

template <class ItemType>
vector<ItemType> ReadFileIn(string fName);


int main() {
    
    vector<Bird> theBirds;
    string fname;
    vector<string> ourInput;
    cout<<"Input name of the file:"<<endl;
    cin>>fname;
    
    theBirds=ReadFileIn<Bird>(fname);
    
    for(int i=0; i<theBirds.size(); i++)
    {
        cout<<theBirds.at(i);
    }
    
    
    return 0;
}

template <class ItemType>
vector<ItemType> ReadFileIn(string fName)
{
    //ItemType line;
    vector<ItemType> vec;
    ItemType line;
    //vector<string> vec;
    ifstream InFile;
    
    InFile.open(fName);
    
    //while(InFile.getline(file, line))
    while(!InFile.eof())
          {
              InFile>>line;
              vec.push_back(line);
          }
    InFile.close();
    return vec;
    
    
    
}