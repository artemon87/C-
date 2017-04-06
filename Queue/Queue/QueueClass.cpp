//
//  QueueClass.cpp
//  Queue
//
//  Created by Artem Kovtunenko on 11/17/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "QueueClass.h"

QueueClass:: QueueClass()
{
    arr.resize(8);
    front =0;
    back=int (arr.size())-1;
    count=0;
}
QueueClass:: QueueClass(int ar[])
{
    
}
int QueueClass:: size()const
{
    
}

bool QueueClass:: isEmpty()const
{
    if(count==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool QueueClass:: push(const int &value)
{
    if(count==arr.size())
    {
        doubleQueueSize();
    }
    back=(back+1)% arr.size();
    arr[back]=value;
    count++;
}
int QueueClass:: pop() throw (exception)
{
    int retVal;
    if(count>0)
    {
        retVal=arr[front];
        front=(front +1)% arr.size();
        count--;
    }
    else
    {
        throw <#expression#>("No more space");
    }
}



