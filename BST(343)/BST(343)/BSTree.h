//
//  BSTree.h
//  BST(343)
//
//  Created by Artem Kovtunenko on 1/13/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#ifndef _BSTREE_H_
#define _BSTREE_H_

#include "TreeData.h"

using namespace std;


struct Node
{
    TreeData * item;
    int count;
    Node * leftChild;
    Node *rightChild;
};

class BSTree
{
private:
    
    Node *root;
    
public:
    
    BSTree();
    BSTree(const BSTree &tree);
    ~BSTree();
    
    void copyConstructor(Node *original, Node *&copy);
    bool insertHelper(Node *&node, TreeData *data);
    bool findToDelete(Node *&node, const TreeData &data);
    void deleteNode(Node *&node);
    int numberOfNodes(Node *node)const;
    void makeEmptyHelper(Node *&);
    bool compareTrees(Node *first, Node *second)const;
    void printOut(Node *node, ostream &out)const;
    
    const TreeData *retrieve(const TreeData & data) const;
    int depth(const TreeData &) const;
    int descendants(const TreeData &) const;
    bool isEmpty() const;
    
    bool insert(TreeData *);
    bool remove(const TreeData &);
    void makeEmpty();
    
    const BSTree & operator=(const BSTree &tree);
    bool operator==(const BSTree &tree)const;
    bool operator!=(const BSTree &tree)const;
    
    friend ostream& operator<<(ostream &out, const BSTree &tree);
    
    void moveLeft(Node *&n);
    
    
    
};

#endif