#ifndef __Binary__Binary__
#define __Binary__Binary__

#include <stdio.h>
#include <iostream>

using namespace std;

class Binary
{
    
private:
    
    bool *array;
    bool sign;
    int count;
    
public:
    
    Binary();
    Binary(int number);
    Binary(Binary const &input);
    ~Binary();
    
    bool getBit(int n)const;
    int getCount()const;
    bool setBit(int n);
    bool clearBit(int n);
    bool toggleBit(int n);
    bool decimalToBinary(bool *array, int n, int &count);
    bool setCount(int n);
    
    signed long long toInteger(const Binary &bin)const;
    int binaryToDecimal(signed long long num)const;
    
    Binary & operator-(const Binary &input);
    Binary & operator+(const Binary &input);
    Binary & operator=(const Binary &input);
    Binary & operator+=(const Binary &input);
    Binary & operator-=(const Binary &input);
    bool operator==(const Binary &input) const;
    bool operator!=(const Binary &input)const;
    
    friend istream& operator>>(istream &in, Binary & bin);
    friend ostream& operator<<(ostream &out, const Binary &output);
    
    
};


#endif /* defined(__Binary__Binary__) */
