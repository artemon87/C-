//
//  main.cpp
//  BST
//
//  Created by Artem Kovtunenko on 12/9/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "BSTree.h"
#include "Transaction.h"
#include <fstream>
    
    using namespace std;
    
    int main(int argc, const char * argv[]) {
        
        Transaction a;
        BSTree tree;
        queue<Transaction> myQ;
        a.ReadFromAFile("BankTrans.txt", myQ);
        a.PopFromQueue(myQ, tree);
        tree.Display();
        //std::cout << "Hello, World!\n";
        //Account a;
        //BSTree tree;
        //tree.Insert(&a);
        return 0;
}
