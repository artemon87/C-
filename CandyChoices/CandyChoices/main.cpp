//
//  main.cpp
//  CandyChoices
//
//  Created by Artem Kovtunenko on 10/15/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
using namespace std;

int candys(int n, int k);
int factorial(int fact);
int power(int num, int n);

int main(int argc, const char * argv[]) {
    
    //while(true)
    //{
        //int n, k, fact;
    int num, fact, n;
        //cout<<"Input an n and a k "<<endl;
        //cin>>n>>k;
        cout<<"Choose your number "<<endl;
        cin>>fact;
        cout<<"You have that many choices "<<endl;
   // }
    cout<<"Factorial of "<<factorial(fact)<<endl;
    cout<<"Choose power n "<<endl;
    cout<<"Power= "<<power(num, n)<<endl;
    
    return 0;
}
int candys(int n, int k)
{
    if(n==1)
    {
        return 1;
    }
    else if(k==1)
    {
        return n;
    }
    else
    {
        return candys(n-1, k-1)+candys(n-1, k);
    }
}
int factorial(int fact)
{
    if(fact==0)
    {
        return 1;
    }
    else
    {
        return fact*factorial(fact-1);
    }
}
int power(int num, int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return num*power(num, n-1);
    }
}