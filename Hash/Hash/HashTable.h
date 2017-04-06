#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdio.h>
#include <string>


using namespace std;


class HashTable
{
    
public:
    
    HashTable();
    ~HashTable();
    
    int hashIt(const string &);
    int hashIt(int);
    //void addItem(string &, const string &);
    //void makeEmty();
	//void remove(Item *);

};


#endif /* defined(__Hash__Hash__) */