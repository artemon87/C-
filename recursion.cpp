#include <iostream>

using namespace std;

int sum(int);
int main()
{
  int total;
  while(true)
  {
  cout<<"Chose your number to add up"<<endl;
  cin>>total;
  //sum(total);
  cout<<"The answer is "<<sum(total)<<endl;
  }
  
    return 0;
}
int sum(int total)
{
    if(total==1)
    {
      return 1;
    }
    else
    {
      return (total+sum(total-1));
    }
 }
    