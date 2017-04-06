#include <iostream>

using namespace std;

int sumUp(int);
//int sum;
int main()
{
  int total;
  cout<<"How many? "<<endl;
  cin>>total;
  int number=sumUp(total);
  cout<<"Your number is" <<number<<endl;
  
    return 0;
}
int sumUp(int a)
{
    int sum=0;
    if(a==0)
    {
      return 0;
    }
    else
    {
      return sum= a+sumUp(a-1);
      //return sum;
    }
    //return sum;
 }
    