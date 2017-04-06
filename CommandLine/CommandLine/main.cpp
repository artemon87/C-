//
//  main.cpp
//  CommandLine
//
//  Created by Artem Kovtunenko on 11/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
    
    
    vector<string> vect;
    
    cout<<"Number of arguments "<<argc<<endl;

    if(argc==4)
    {
        for(int i=1; i<argc; i++)
        {
            cout<<"Comman line arg "<<i<<" "<<argv[i]<<endl;
        }
    }
    //cout<<argv[0]<<" "<<endl;
    return 0;
}
