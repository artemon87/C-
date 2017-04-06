#include "Binary.h"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//invariant: Number that we want to convert to binary is limited to an integer//
////////////////////////////////////////////////////////////////////////////////

//Default constructor: allocates a new array and assignes default values to private members.
//Postcond: array is dinamically allocated
Binary:: Binary()
{
    array = new bool[64];
    for(int i = 0; i < 64; i++)
    {
        array[i] = false;
    }
    count = 0;
    sign = true;
}


//Constructor that takes an int and converts it to binary number. Size of an allocated array depends on a size of an
//integer. Constructor calls decimalToBinary method to do actual converting.
//Precond: n is a real number
//Postcond: array can no be extended to more than having 64 elements
Binary:: Binary(int n)
{
    // if(n >= -128 && n <= 127)
    // {
    //    array = new bool[8];
    // }
    if(n >= -32768 && n <= 32767)
    {
        array = new bool[16];
    }
    else if((n > 32767 && n <= 2147483647) || (n < -32768 && n >= - 2147483648))
    {
        array = new bool[32];
    }
    else
    {
        array = new bool[64];
    }
    sign = true;
    count = 0;
    decimalToBinary(array, n, count);
}


//Copy constructor: dealocating an array and creating a new one, then copy values to a new array
Binary:: Binary(const Binary &input)
{
    //delete []array;
    //array=NULL;
    array = new bool[input.count];
    for(int i = 0; i < input.count; i++)
    {
        array[i] = input.array[i];
    }
    count = input.count;
    sign = input.sign;
}


//Dealocating everything that was stored in dynamic memory
Binary:: ~Binary()
{
    delete [] array;
    array=NULL;
}


bool Binary:: getBit(int n)const
{
    if(n < 0 || n > count)
    {
        return false;
    }
    else
    {
        return array[n];
    }
}


bool Binary:: setBit(int n)
{
    if(n < 0 || n > count)
    {
        return false;
    }
    else
    {
        array[n] = true;
        return true;
    }
}


bool Binary:: clearBit(int n)
{
    if(n < 0 || n > count)
    {
        return false;
    }
    else
    {
        array[n] = false;
        return true;
    }
}


bool Binary:: toggleBit(int n)
{
    if (n < 0 || n > count)
    {
        return false;
    }
    else if(array[n] == true)
    {
        array[n] = false;
        return true;
    }
    else
    {
        array[n] = true;
        return true;
    }
}


//Decimal to binary convertion
//Precond: checks if integer is negative
//Postcond: assigns "sign" private member to false if int is negative
bool Binary:: decimalToBinary(bool *array, int n, int &count)
{
    if(n < 0)
    {
        sign = false;
        n *= -1;
    }
    int traversal = 0;
    count = 0;
    while(n != 0)
    {
        if(n % 2 == 1)
        {
            array[traversal] = true;
        }
        else if(n%2 == 0)
        {
            array[traversal] = false;
        }
        traversal++;
        count++;
        n = n / 2;
    }
    return true;
}


//Method to convert an array of booleans to an array of numbers 0-1,
//and then creating a single integer from an array of numbers
//Precond: initial array has to contain only booleans. Also, to be able to convert an array of numbers to a single int/long
//I'm using signed long long in case of a really large number(0-19 digits). With numer larger than 19 digits long result is unexpected
//Postcond: this method will return signed long long (pos or neg)
signed long long Binary:: toInteger(const Binary &bin)const
{
    //creating an array of 32 integers, even though signed long long can handle only 19 digits
    int arr1[32];
    {
        for(int i = 0; i < 32; i++)
        {
            arr1[i]=0;
        }
    }
    
    signed long long integer = 0;
    
    for(int i = bin.count-1; i >= 0; i--)
    {
        if(bin.array[i] == true)
        {
            arr1[i] = 1;
        }
        else
        {
            arr1[i] = 0;
        }
    }
    
    //converting an array of numbers to signed long long
    for(int i = bin.count-1; i >= 0; i--)
    {
        integer = integer * 10;
        integer = integer + arr1[i];
        
    }
    //cheking if a given binary number was negative
    if(bin.sign == false)
    {
        integer *= -1;
    }
    return integer;
}

//Converting binary number back to decimal for +,-,+=, -= operators.
//Precond: signed long long can handle only 19 digit-long number
//Postcond: method will return a decimal (int) number wich can be both pos or neg.
int Binary:: binaryToDecimal(signed long long num)const
{
    //checking if "num" is negative and making it positive, if so.
    bool positive = true;
    if(num < 0)
    {
        num *= -1;
        positive = false;
    }
    int dec = 0;
    int remain = 0, base = 1;
    while(num > 0)
    {
        remain = num % 10;
        dec  = dec + remain * base;
        num = num / 10;
        base *= 2;
    }
    if(positive != false)
    {
        return dec;
    }
    else
    {
        return dec * (-1);
    }
}


//Helper method to return count
int Binary:: getCount()const
{
    return count;
}


//helper method to set count
bool Binary:: setCount(int n)
{
    count = n;
    return true;
}


//first we convert both numbers back to decimal (int)
//and then dealocate a new Binary object that we will return from a function
//Precond: sign long long is limited to 19 digit number only
//Postcond: operator returns a refference of an object
Binary & Binary:: operator-(const Binary &input)
{
    signed long long num1 = toInteger(*this);
    signed long long num2 = toInteger(input);
    int dec1 = binaryToDecimal(num1);
    int dec2 = binaryToDecimal(num2);
    int sum = dec1 - dec2;
    Binary *output=new Binary(sum);
    decimalToBinary(output->array, sum, output->count);
    return *output;
}


//same as with "operator-"
Binary & Binary:: operator+(const Binary &input)
{
    signed long long num1 = toInteger(*this);
    signed long long num2 = toInteger(input);
    int dec1 = binaryToDecimal(num1);
    int dec2 = binaryToDecimal(num2);
    int sum = dec1 + dec2;
    Binary *output=new Binary(sum);
    decimalToBinary(output->array, sum, output->count);
    return *output;
}


Binary & Binary:: operator=(const Binary &input)
{
    if(this == &input)
    {
        return *this;
    }
    else
    {
        count = input.count;
        sign = input.sign;
        
        //clearing an array
        for(int i = 0; i < count; i++)
        {
            array[i] = false;
        }
        //inserting new elements
        for(int i = 0; i < input.count; i++)
        {
            array[i] = input.array[i];
        }
        
    }
    return *this;
}


Binary & Binary:: operator-=(const Binary &input)
{
    *this = *this - input;
    return (*this);
}


Binary & Binary:: operator+=(const Binary &input)
{
    *this = *this + input;
    return (*this);
}


//checking for equality
bool Binary:: operator==(const Binary &input) const
{
    if (count == input.count && sign == input.sign)
    {
        for(int i = 0; i < input.count; i++)
        {
            if(array[i] != input.array[i])
            {
                return false;
                break;
            }
        }
        return true;
    }
    return false;
}


//checking for inequality
bool Binary:: operator!=(const Binary &input)const
{
    if (count != input.count || sign != input.sign)
    {
        return true;
    }
    else
    {
        for(int i = 0; i < input.count; i++)
        {
            if(array[i] != input.array[i])
            {
                return true;
            }
        }
    }
    return false;
}

//Precond: function can handle only integer inputs
istream& operator>>(istream &in, Binary & bin)
{
    int number;
    in >> number;
    bin.decimalToBinary(bin.array, number, bin.count);
    return in;
}


//ouput method where I first check if a binary nember is negative or pos and then display its actual bits.
//Precond: array is in order where its first far more left digit is at position 0.
//Postcond: binary number is displayed without leading 0s
ostream& operator<<(ostream &out, const Binary &output)
{
    if(output.sign == false)
    {
        out<<"-";
    }
    if(output.count==0)
    {
        out<<output.count;
    }
    for(int i = output.count-1; i >= 0; i--)
    {
        out<<output.array[i];
    }
    return out;
}



