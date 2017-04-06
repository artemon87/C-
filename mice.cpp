#include <iostream>

using namespace std;

int mice(int);
int main()
{
  int total;
  cout<<"How many? "<<endl;
  cin>>total;
   int number=mice(total);
  //}
  
    return 0;
}
int sum(int a)
{
    
    if(a==1 || a==2)
    {
      return 2;
    }
    else
    {
      int temp= mice(a-1)+mice(a-2);
      a++;
      return temp;
    }
 }
    