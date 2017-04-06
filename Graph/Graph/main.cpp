//
//  main.cpp
//  Graph
//
//  Created by Artem Kovtunenko on 1/31/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "Graph.h"
#include "GraphData.h"
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
	char cha[10]="char";
	cout<<cha;
    string mystring=string(cha);
	cout<<mystring<<endl;

	ifstream in("graph.txt");
    Graph a;
    a.buildGraph(in);
    
    std::cout << "Hello, World!\n";
    return 0;
}