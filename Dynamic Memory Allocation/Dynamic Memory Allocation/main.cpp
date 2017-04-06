//
//  main.cpp
//  Dynamic Memory Allocation
//
//  Created by Artem Kovtunenko on 10/29/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int *p1=new int;
    *p1=1;
    double *p2=new double;
    *p2=2;
    cout<<*p1<<endl;
    cout<<*p2<<endl;
    
    delete p1;
    *p1=NULL;
    
    
    p1=new int;
    *p1=11;
    
    
    cout<<*p1<<endl;
    cout<<*p2<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
