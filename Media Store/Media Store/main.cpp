//
//  main.cpp
//  Media Store
//
//  Created by Artem Kovtunenko on 2/27/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string a = "inventory.txt";
    fstream stream(a);
    string temp;
    int integer;
    if (stream.eof()) return 0;
        
    getline (stream, temp, ',');
     //stream >> temp;
      //getline(stream, temp, ',');
      cout<<temp<<endl;
    stream.get();
    getline (stream, temp, ',');
    cout<<temp<<endl;
    
    return 0;
}
