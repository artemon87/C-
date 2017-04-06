//
//  BSTree.h
//  BST
//
//  Created by Artem Kovtunenko on 12/9/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __BST__BSTree__
#define __BST__BSTree__


#include <stdio.h>
#include "Account.h"
//#include "Transaction.h"

using namespace std;

struct Node
{
    Node *left;
    Node *right;
    Account *pAccnt;
};

class BSTree
{
    
public:
    
    BSTree();
    ~BSTree();
    bool Insert(Account *source);
    bool Retrive(const Account &given, Account *&output)const;
    void Display()const;
    void Empty();
    bool isEmpty();
    
private:
    
    Node *root;
    bool Insert(Node *node);
    void Display(Node *node)const;
    void Empty(Node *node);
};

#endif /* defined(__BST__BSTree__) */
