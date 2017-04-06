#include <iostream>
#include <string>

using namespace std;

void PrintBase(int num, int base, string &ans);

int main()
{
 //while(true)
 //{
   string answer;
   int base, num;
   cout<<"input a number and a base ";
   cin>>num>>base;
  //}
    return 0;
}
void PrintBase(int num, int base, string &ans)
{
    string static DIGIT_ARRAY="123456789ABCDEF"; //static only created once, no matter how many time we calls it
    if(num<base)
    {
      ans=DIGIT_ARRAY[num]+ans;
      cout<< ans;
    }
    else{
    ans=DIGIT_ARRAY[num % base]+ans;
    PrintBase(num/base, base, ans);
    }
 }
    