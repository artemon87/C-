//
//  main.cpp
//  LeakInMemory
//
//  Created by Artem Kovtunenko on 10/17/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>

using namespace std;


int main()
{
    int size;
    string bName;
    Bird *birdF;
    cout<<"Enter a flock"<<endl;
    cin>>bName;
    cout<<"Enter the size"<<endl;
    cin>>size;
    while(true)
    {
        birdF=createF(size, name);
        delete[] birdF;
    }
    
    return 0;
}
Bird* createF(int num, string name)
{
    Bird *pBird;
    pBird=new Bird[num]; //created an array of Birds
    for(int i=0; i<num; i++)
    {
        pBird[i].setName(name);
        pBird[i].setId=i;
    }
}