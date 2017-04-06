//
//  Employee.cpp
//  Employee
//
//  Created by Artem Kovtunenko on 10/10/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Employee.h"
#include <iostream>
#include <string>


using namespace std;


Employee:: Employee()
{
    cout<<"You just created an employee object"<<endl;
}
Employee:: Employee(string n)
{
    name=n;
}
Employee:: Employee(string n, int num)
{
    name=n;
    number=num;
}
string Employee:: getName()const
{
    return name;
}