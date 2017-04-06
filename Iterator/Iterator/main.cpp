//
//  main.cpp
//  Iterator
//
//  Created by Artem Kovtunenko on 10/24/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <list>


using namespace std;


int main()
{
    string s1("Was Andurson"), dir2("Wong Kr Wai"), dir3("Akira Kurosava");
    string dir4("Woody Allen");
    list<string> str;
    list<string>:: iterator iter;
    
    str.push_front(s1);
    str.push_front(dir2);
    str.push_front(dir3);
    
    
    //str.push_back("Artem");
    //str.push_back("Oleg");
    //str.push_back("Anton");
    //str.push_back("Sashok");
    
    for(iter=str.begin(); iter != str.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    cout<<endl;
    iter--;
    iter--;
    str.insert(iter, dir4);
   
    for(iter=str.begin(); iter != str.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    
    
    return 0;
}
