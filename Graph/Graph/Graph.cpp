//
//  Graph.cpp
//  Graph
//
//  Created by Artem Kovtunenko on 1/31/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#include "Graph.h"
#include "GraphData.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph:: Graph()
{}
Graph:: ~Graph()
{}

void Graph::buildGraph(ifstream& infile)
{
    
    infile >> size; 
	cout<<size;// data member stores array size
    if (infile.eof())
        return;
    infile.ignore();                         // throw away '\n' go to next line
    
    // get descriptions of vertices
    //vertices[size]=*new VertexNode[size-1];
	char ch[50];
    for (int v = 0; v <= size; v++) {
        infile.getline(ch, 50, '\n');      // read descriptions (use of this method is not mandatory)
		string mystring=string(ch);
		cout<<mystring<<endl;
		GraphData *info=new GraphData;
		info->setGraphName(mystring);
		VertexNode *vertex=new VertexNode;
		vertex->data = info;
		vertex->edgeHead = NULL;
		//vertices[v].data=info;
        //vertices[v].edgeHead=NULL;
		vertices[v] = *vertex;
    }
    int src = 1, dest = 1, cost = 1;
    for (;;) {
        infile >> src >> dest >> cost;
        if (src == 0 || infile.eof())
            break;
        insertEdge(src, dest, cost);
    }
	//insertEdge(2, , 1);
	insertEdge(2, 3, 6);
	insertEdge(2, 3, 2);
	removeEdge(2, 4);/////////////////////////////////////////////////////////
	insertEdge(2, 3, 1);//////////////////////////////////////////////
	int a; ////////////////////////
	cin >> a; //////////////////////
}
void Graph:: insertEdge(int src, int dest, int cost)
{
    EdgeNode *node;// = new EdgeNode;
	EdgeNode *temp;
	temp=vertices[src].edgeHead;

	while(temp && temp->nextEdge)
	{
        if(temp->nextEdge->adjVertex > dest)
        {
            node = new EdgeNode;
            node->weight = cost;
            node->nextEdge = temp->nextEdge;
            temp->nextEdge = node;
        }
		else if(temp->nextEdge->adjVertex == dest)
		{
			//cout<<temp->adjVertex<<endl;//////////////////
			temp->nextEdge->weight = cost;
			return;
		}
		temp = temp->nextEdge;
	}
	node=new EdgeNode;
	node->weight = cost;
	node->adjVertex = dest;
	node->nextEdge = NULL;

	if(temp)
	{
	    temp->nextEdge = node;
	}
	else
	{
		vertices[src].edgeHead = node;
	}

    //node->weight=cost;
    //node->adjVertex=dest;
    //node->nextEdge=vertices[src].edgeHead;
    //vertices[src].edgeHead=node;
    
}
bool Graph:: removeEdge(int src, int dest)
{
	if(vertices[src].edgeHead == NULL)
	{
		return false;
	}
	else
	{
		EdgeNode *temp, *prev;
		temp = vertices[src].edgeHead;
		if(temp->adjVertex == dest)
		{
		    vertices[src].edgeHead = temp->nextEdge;
			delete temp;
			return true;
	    }
		while(temp)
		{
			if(temp->adjVertex != dest)
			{
				prev = temp;
                temp = temp->nextEdge;
			}
		
		    else if(temp->adjVertex == dest)
		    {
				//vertices[src].edgeHead = temp->nextEdge;
				//delete temp;
				//return true;
				prev->nextEdge = temp->nextEdge;
				delete temp;
				temp = prev->nextEdge;
				return true;
			}
		}
		return false;
	}
}
void Graph:: findShortestPath()
{
	EdgeNode *temp;
	//temp = vertices[0].edgeHead;
	//T[MAX_VERTICES][MAX_VERTICES] = *new Table;

	for(int i = 0; i <= size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			T[i][j].visited = false;//temp->adjVertex;
			T[i][j].dist = numeric_limits<int>::infinity();
			T[i][j].path = -1;
		}
	}

}
void displayAll();
void Graph:: displayALLHelper(EdgeNode * node, VertexNode * vertex)
{
	//cout << *vertex->data << " : "<< node->
}
void display(int, int);