//
//  main.cpp
//  Recursion1
//
//  Created by Artem Kovtunenko on 10/15/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>


using namespace std;


int sumUp(int n);

int main(int argc, const char * argv[]) {
    int number;
    cout<<"Enter your number to sum up"<<endl;
    cin>>number;
    int s=sumUp(number);
    cout<<s;
    
    
    return 0;
}
int sumUp(int n)
{
    int sum;
    if(n<0)
    {
        sum=0;
    }
    else{
        sum=n+sumUp(n-1);
        //return sum;
    }
    return sum;
}