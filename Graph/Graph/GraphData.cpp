//
//  GraphData.cpp
//  Graph
//
//  Created by Artem Kovtunenko on 1/31/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#include "GraphData.h"

GraphData:: GraphData()
{}

GraphData:: ~GraphData()
{}

string GraphData:: getGraphData()const
{
    return name;
}
void GraphData:: setGraphName(string info)
{
    name=info;
}

ostream& operator<<(ostream &out, const GraphData &data)
{
    out<<data.name;
    return out;
}

istream& operator>>(istream &in, GraphData &data)
{
    in>>data.name;
    return in;
}