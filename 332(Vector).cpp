#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int temp;
  vector<int> first;
  vector<int> second(4, 100);
  vector<int> third(second.begin(), second.end());
  vector<int> fourth(third);
  int myints[]={16, 2, 77, 29};
  vector<int> fifth(myints, myints +sizeof(myints)/sizeof(int));//passing an array to vector from beg of a pointer to the end
  for(int i=0; i<second.size(); i++)
  {
    cout<<fifth.at(i)<<endl;
    cout<<fifth[i];
    cout<<endl;
  }
  second.push_back(56);
  temp=second.back();
  second.pop_back();
  
  cout<<temp;
 return 0;
 }