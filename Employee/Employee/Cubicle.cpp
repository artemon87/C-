//
//  Cubicle.cpp
//  Employee
//
//  Created by Artem Kovtunenko on 10/10/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Cubicle.h"
#include "Employee.h"
#include <string>
#include <iostream>


using namespace std;

Cubicle::Cubicle ()
{
    cout<<"Default constructor for Cubicle"<<endl;
}
Cubicle:: Cubicle(int a, int b)
{
    width=a;
    length=b;
}
Cubicle:: Cubicle(int a, int b, Employee name)
{
    width=a;
    length=b;
    name=name;
}
string Cubicle::getEmployee()
{
    return Employee.getName();
}