//
//  main.cpp
//  Binary
//
//  Created by Artem Kovtunenko on 1/5/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "Binary.h"

using namespace std;

    int main()
    {
        Binary q(2);
        Binary w(10000000);
        q=w;
        cout<<"q= "<<q<<endl;
        /*Binary c(5);
        Binary a;
        Binary b(10);
        Binary d(4);
        //Binary c(3);
        //Binary c2(15);
        cout<<c<<endl;
        a=b-2;
        a.setBit(-1);
        cout<<"Before: "<<a<<endl;
        a-=c;
        cout<<"After: "<<a<<endl;
        //cout<<c<<endl;
        cout<<d<<endl;
        Binary n;
        cout<<"Enter number"<<endl;
        cin>>n;
        if(a==n)
        {
            cout<<"They are equal"<<endl;
        }
        cout << "Hello world!" << endl;
         */
        Binary aa, bb(10);
        Binary cc(bb);
        if(bb==cc)
        {
            cout<<"cc=bb"<<endl;
        }
        cout<<cc<<endl;
        Binary a, b(42), d = -13, x, y = x + 1;
        cout<<"Hello"<<endl;
        Binary c(b);
        x=6;
        cout<<x<<endl;
        //y=x+1;
        cout<<y<<endl;
        
        cout << "Enter integer to be converted to binary:  ";
        cin >> a;
        cout << "The binary representation of this number is: " << endl;
        cout << a << endl;
        cout << "The 4th bit (four bits away from bit 0) is: " << endl;
        cout << a.getBit(4) << endl << endl;
        
        cout << "Compute c = a + b" << endl;
        c = a + b;
        cout << "c = " << c << endl;
        cout << "a = " << a << endl;
        cout << "Compute d = a + b - c" << endl;
        d += a + b + c ;
        cout << "d = " << d << endl << endl;
        
        cout << "Does a == c? " << endl;
        cout << ( (a == c) ? "a == c" : "a != c") << endl << endl;
        
        cout << "Test assignment operators" << endl;
        x -= c = d = d;    y += a -= b += b;
        cout << "x = " << x << "    y = " << y << endl << endl;
        
        cout<<a<<endl;
        a.setBit(-1);			// handle bad input
        cout<<a<<endl;
        a.setBit(223);			// set 3rd bit (three over from bit zero)
        cout<<a<<endl;
        a.setBit(1000);			// set 1000th bit; handle as desired, but don't crash
        cout<<a<<endl;
        a.clearBit(3);			// clear 3rd bit
        cout<<a<<endl;
        a.clearBit(10000);		// clear 10000th bit
        a.toggleBit(3);			// toggle 3rd bit
        
        
        return 0;
}
