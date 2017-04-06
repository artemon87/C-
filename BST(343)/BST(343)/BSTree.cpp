//
//  BSTree.cpp
//  BST(343)
//
//  Created by Artem Kovtunenko on 1/13/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//
#include "BSTree.h"
#include <iostream>

using namespace std;

BSTree:: BSTree()
{
    root=NULL;
    //root->count=0;
}
BSTree:: BSTree(const BSTree &tree)
{
    copyConstructor(tree.root, root);
}

void BSTree:: copyConstructor(Node *original, Node *&copy)
{
    if(original==NULL)
    {
        copy=NULL;
    }
    else
    {
        copy=new Node;
        copy->item=original->item;
        copy->count=original->count;
        copyConstructor(original->leftChild, copy->leftChild);
        copyConstructor(original->rightChild, copy->rightChild);
    }
}
BSTree:: ~BSTree()
{
    makeEmpty();
}

const TreeData* BSTree:: retrieve(const TreeData &data)const
{
    Node *searchNode=root;
    if(root == NULL)
    {
        return NULL;
    }
    while(searchNode)
    {
        if(*searchNode->item == data)
        {
            return &data;
        }
        else if(*searchNode->item < data)
        {
            searchNode=searchNode->rightChild;
        }
        else if(*searchNode->item > data)
        {
            searchNode=searchNode->leftChild;
        }
    }
    return NULL;
}
int BSTree:: depth(const TreeData &data) const
{
    int occurances=0;
    Node *searchNode=root;
    if(root == NULL)
    {
        return -1;
    }
    while(searchNode)
    {
        if(*searchNode->item == data)
        {
            return occurances;
        }
        else if(*searchNode->item < data)
        {
            searchNode=searchNode->rightChild;
            occurances++;
        }
        else if(*searchNode->item > data)
        {
            searchNode=searchNode->leftChild;
            occurances++;
        }
    }
    return -1;
}
int BSTree:: descendants(const TreeData &data) const
{
    Node *searchNode=root;
    while(searchNode)
    {
        if(*searchNode->item == data)
        {
            return numberOfNodes(searchNode);
        }
        else if(*searchNode->item < data)
        {
            searchNode=searchNode->rightChild;
        }
        else if(*searchNode->item > data)
        {
            searchNode=searchNode->leftChild;
        }
    }
    return -1;
}
bool BSTree:: isEmpty() const
{
    return root == NULL;
}


bool BSTree:: insert(TreeData *data)
{
    return insertHelper(root, data);
    
}
bool BSTree:: insertHelper(Node *&node, TreeData *data)
{
    
    if(node==NULL)
    {
        node=new Node;
        node->item=data;
        node->leftChild=NULL;
        node->rightChild=NULL;
        node->count+=1;
        return true;
    }
    else if(*node->item==*data)
    {
        node->count+=1; /////////////////////////
        return false;
    }
    else if(*node->item < *data)
    {
        return insertHelper(node->rightChild, data);
    }
    else
    {
        return insertHelper(node->leftChild, data);
    }
}
bool BSTree:: remove(const TreeData &data)
{
    if(root==NULL)
    {
        return false;
    }
    else
    {
        return findToDelete(root, data);
    }
}

bool BSTree:: findToDelete(Node *&node, const TreeData &data)
{
    if(node == NULL)
    {
        return false;
    }
    else if(*node->item < data)
    {
        return findToDelete(node->rightChild, data);
    }
    else if(*node->item > data)
    {
        return findToDelete(node->leftChild, data);
    }
    else
    {
        deleteNode(node);
        return true;
    }
}
void BSTree:: deleteNode(Node *&node)
{
    Node *helper;
    if(node->leftChild == NULL && node->rightChild == NULL)
    {
        if(node->count > 1)
        {
            node->count-=1;
        }
        else if(node->count == 1)
        {
            delete node->item;
            delete node;
            node = NULL;
        }
    }
    else if(node->rightChild==NULL)
    {
        if(node->count > 1)
        {
            node->count-=1;
        }
        else if(node->count == 1)
        {
            helper=node;
            node=node->leftChild;
            delete helper->item;
            delete helper;
        }
    }
    else if(node->leftChild==NULL)
    {
        if(node->count > 1)
        {
            node->count-=1;
        }
        else if(node->count == 1)
        {
            helper=node;
            node=node->rightChild;
            delete helper->item;
            delete helper;
        }
    }
    else
    {
        if(node->count == 1)
        {
            helper=node->rightChild;
            while(helper->leftChild)
            {
               helper=helper->leftChild;
            }
            helper->leftChild=node->leftChild;
            helper=node;
            node=node->rightChild;
            delete helper->item;
            delete helper;
        }
        else
        {
            node->count-=1;
        }
    }
}
int BSTree:: numberOfNodes(Node *node)const
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return (numberOfNodes(node->rightChild) + 1 + numberOfNodes(node->leftChild));
    }
}
void BSTree:: makeEmpty()
{
    makeEmptyHelper(root);
}
void BSTree:: makeEmptyHelper(Node *&node)
{
    if(node != NULL)
    {
        makeEmptyHelper(node->leftChild);
        makeEmptyHelper(node->rightChild);
        //delete node->item;
        delete node;
        node=NULL;
    }
}

const BSTree& BSTree:: operator=(const BSTree &tree)
{
    if(*this != tree)
    {
      this->makeEmpty();
    }
    copyConstructor(tree.root, root);
    return *this;
}
bool BSTree:: operator==(const BSTree &tree)const
{
    return compareTrees(this->root, tree.root);
}
bool BSTree:: compareTrees(Node *first, Node *second)const
{
    if(first == NULL && second == NULL)
    {
        return true;
    }
    else if(first != NULL || second != NULL)
    {
        return false;
    }
    else if(first->item != second->item)
    {
        return false;
    }
    else
    {
        return (compareTrees(first->leftChild, second->leftChild) && compareTrees(first->rightChild, second->rightChild));
    }
}
bool BSTree:: operator!=(const BSTree &tree)const
{
    bool equal=compareTrees(this->root, tree.root);
    if(equal == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}
ostream& operator<<(ostream &out, const BSTree &tree)
{
    tree.printOut(tree.root, out);
    return out;
}
void BSTree:: printOut(Node *node, ostream &out)const
{
    if(node == NULL)return;
    else
    {
        printOut(node->leftChild, out);
        out << *node->item << " " << node->count << endl;
        //moveLeft(node->rightChild);
        printOut(node->rightChild, out);
    }
}


void BSTree:: moveLeft(Node *&n)
{
    Node *temp = n->rightChild;
    n->rightChild = temp->leftChild;
    temp->leftChild= n;
    
    
}





























