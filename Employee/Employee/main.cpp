//
//  main.cpp
//  Employee
//
//  Created by Artem Kovtunenko on 10/10/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "Employee.h"
#include "Cubicle.h"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    Employee ark ("Gorge");
    ark.getName();
    cout<<ark.getName()<<endl;
    Cubicle(2, 4, ark);
    
    return 0;
}
