//
//  Employee.h
//  Employee
//
//  Created by Artem Kovtunenko on 10/10/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __Employee__Employee__
#define __Employee__Employee__

#include <stdio.h>
#include <string>

using namespace std;


class Employee
{
public:
    Employee();
    Employee(string name);
    Employee(string name, int number);
    string getName()const;

    
private:
    int number;
    string name;
    
    
};

#endif /* defined(__Employee__Employee__) */
