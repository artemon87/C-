//
//  Cubicle.h
//  Employee
//
//  Created by Artem Kovtunenko on 10/10/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __Employee__Cubicle__
#define __Employee__Cubicle__

#include <stdio.h>
#include <string>
#include "Employee.h"

using namespace std;

class Cubicle:public Employee
{
    Cubicle ();
    Cubicle(int a, int b);
    Cubicle(int a, int b, Employee name);
    string getEmployee();
private:
    int width, length;
    Employee name;
};


#endif /* defined(__Employee__Cubicle__) */
