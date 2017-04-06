//
//  QueueClass.h
//  Queue
//
//  Created by Artem Kovtunenko on 11/17/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __Queue__QueueClass__
#define __Queue__QueueClass__

#include <stdio.h>
#include <vector>

using namespace std;

const int ARRAY_SIZE=10;

class QueueClass
{
public:
    QueueClass();
    QueueClass(int ar[]);
    int size()const;
    bool isEmpty()const;
    bool push(const int &);
    int pop() throw (exception);
    
    
    
    ~QueueClass();
    
private:
    //int array[ARRAY_SIZE];
    struct Node
    {
        int val;
        Node *next=NULL;
    };
    vector<int> arr;
    Node *back;
    Node *front;
    int count;
    
};

#endif /* defined(__Queue__QueueClass__) */
