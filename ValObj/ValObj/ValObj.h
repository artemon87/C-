//
//  ValObj.h
//  ValObj
//
//  Created by Artem Kovtunenko on 11/10/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __ValObj__ValObj__
#define __ValObj__ValObj__

#include <stdio.h>
class ValObj
{
public:
    ValObj();
    ValObj Func1(ValObj par);
    ValObj Func2(ValObj param);
    ValObj& Func3(ValObj param)
    {
        return param; //param value will be lost as soon as the function ends, yet we are passing it by reference later
    }                 // param only lives until function ends
    ValObj& Func4(ValObj param);
    
    
};

#endif /* defined(__ValObj__ValObj__) */
