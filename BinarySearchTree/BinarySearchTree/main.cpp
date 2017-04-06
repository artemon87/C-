//
//  main.cpp
//  BinarySearchTree
//
//  Created by Artem Kovtunenko on 11/14/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "BSTree.h"
//#include "Account.h"
#include <fstream>
#include "Transaction.h"

int main(int argc, const char * argv[]) {

    Transaction a;
    BSTree tree;
    queue<Transaction> myQ;
    a.ReadFromAFile("BankTrans.txt", myQ);
    a.PopFromQueue(myQ, tree);
    cout<<endl;
    cout<<"Processing Done. Final Balances:"<<endl;
    tree.Display();
    tree.Empty();
    return 0;
}
