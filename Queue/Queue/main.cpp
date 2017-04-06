//
//  main.cpp
//  Queue
//
//  Created by Artem Kovtunenko on 11/17/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
 
    
    queue<int, vector<int>> theQ; //vector int is a container
    for(int i=0; i<5; i++)
    {
        theQ.push(i);
    }
    cout <<"Size "<<theQ.size()<<endl;
    cout<<"Front "<<theQ.front()<<endl;
    cout<<"Back "<<theQ.back()<<endl;
    //theQ.pop();
    cout<<"Front after POP "<<theQ.front()<<endl;
    cout<<"Back after POP "<<theQ.back()<<endl;
    
    
    
    return 0;
}
