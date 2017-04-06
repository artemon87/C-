#include <iostream>

using namespace std;

int Nfact(int);

int main()
{
  int n;
  cout<<"Input n "<<endl;
  cin>>n;
  cout<<"The answer is "<<Nfact(n)<<endl;
  return 0;
}
int Nfact(int n)
{
  if(n==1)
  {
    return 1;
  }
  else{
    return n*Nfact(n-1);
  }
}