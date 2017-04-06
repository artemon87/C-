#include <iostream>

using namespace std;

template<class ItemType>
void swapAll(ItemType &a, ItemType &b);
void ttt(double &a, double &b);
int main()
{
   int a=9, b=13; //can use int, float, string
   cout<<"a = "<<a<<" b = "<<b<<endl;
   swapAll(a, b);
   cout<<"a = "<<a<<" b = "<<b<<endl;
   double k=1.5;
   double o=2.1;
   cout<<"Befor k= "<<k<<endl;
   cout<<"Befor o= "<<o<<endl;
   ttt(k, o);
   cout<<"Now k= "<<k<<endl;
   cout<<"Now o= "<<o<<endl;
   
    return 0;
}
template <class ItemType>
void swapAll(ItemType &a, ItemType &b)
{
    
    ItemType temp;
    temp=a;
    a=b;
    b=temp;
    //return;
}
void ttt(double &k, double &o)
{
  int z=k+o;
  k=int (k);
  o=9;
  //cout<<k<<endl;
  //cout<<z<<endl;
}