//
//  Graph.h
//  Graph
//
//  Created by Artem Kovtunenko on 1/31/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#ifndef __Graph__Graph__
#define __Graph__Graph__

#include <stdio.h>
#include <iostream>

#include "GraphData.h"

using namespace std;

class Graph
{
private:
    
    static const int MAX_VERTICES = 100;
    
    struct EdgeNode
    {
        int adjVertex;
        int weight;
        EdgeNode *nextEdge;
    };
    struct VertexNode
    {
        EdgeNode *edgeHead;		// head of the list of edges
        GraphData *data;		// store vertex data here
    };
    
    // array of VertexNodes
    VertexNode vertices[MAX_VERTICES];
    
    // table of information for Dijkstra's algorithm
    struct Table
    {
        bool visited;			// whether vertex has been visited
        int dist;				// shortest known distance from source
        int path;				// previous vertex in path of min dist
    };
    
    int size;					// number of vertices in the graph
    Table T[MAX_VERTICES][MAX_VERTICES];
    
public:
    
    Graph();
    Graph(Graph &);
    ~Graph();
    void buildGraph(ifstream &);
    void insertEdge(int, int, int);
    bool removeEdge(int, int);
    void findShortestPath();
    void displayAll();
	void displayALLHelper(EdgeNode *, VertexNode *);
    void display(int, int);
};

#endif /* defined(__Graph__Graph__) */