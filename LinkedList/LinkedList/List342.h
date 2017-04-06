//
//  List342.h
//  LinkedList
//
//  Created by Artem Kovtunenko on 10/16/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef _LIST342_H_
#define _LIST342_H_


class List342
{
  public:
    List342()
    {
        headP=nullptr;
        itemNumber=0;
    }
    //copy constructor
    List342(const List342<ItemType> &copyList)
    {
        itemNumber=copyList->itemNumber;
        Node<ItemType> * oiginalPtr=copyList->headP;
    }
    list342()
    virtual ~List342();
    
private:
    Node<ItemType> *headP;
    int itemNumber;
};
template <class ItemType>
class Node
{
private:
    Node *next;
    ItemType item;
public:
    Node()
    {
        next=nullptr;
        item=0;
    }
    Node(ItemType &id)
    {
        next=nullptr;
        item=id;
    }
    Node(ItemType &id, Node<ItemType> *nextNodeP)
    {
        item=id;
        next=nextNodeP;
    }
    void setItem(const ItemType &id)
    {
        item=id;
    }
    void setNext(Node<ItemType> *nextNodeP)
    {
        next=nextNodeP;
    }
    ItemType getItem()const
    {
        return item;
    }
    Node<ItemType>* getNext()const
    {
        return next;
    }
};

#endif // LIST342_H

