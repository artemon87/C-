//
//  GraphData.h
//  Graph
//
//  Created by Artem Kovtunenko on 1/31/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#ifndef __Graph__GraphData__
#define __Graph__GraphData__

#include <stdio.h>
#include <string>
#include <iostream>


using namespace std;


class GraphData
{
    
private:
    
    string name;
    
public:
    
    GraphData();
    ~GraphData();
    string getGraphData()const;
    void setGraphName(string);
    
    friend ostream& operator<<(ostream &, const GraphData &);
    friend istream& operator>>(istream &, GraphData &);

    
};

#endif /* defined(__Graph__GraphData__) */