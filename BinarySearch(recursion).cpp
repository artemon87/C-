#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE=7;

int BinarySearch(int value, int arra[], int low, int high);

int main()
{
 //while(true)
 //{
   int arr[7]={2, 4, 6, 17, 29, 67, 101};
   while(true)
   {
     int num=0;
     int ans=0;
     cout<<"input a number to search ";
     cin>>num;
     ans=BinarySearch(num, arr, 0, ARRAY_SIZE-1);
  }
    return 0;
}
int BinarySearch(int value, int arr[], int low, int high)
{
    if(value ==arr[low])
    {
      return low;
    }
    else if (value==arr[high])
    {
      return high;
    }
    else if((high-1)<=low)
    {
      return -1;
    }
    else
    {
      int midpoint=(high +low)/2;
      if(arr[midpoint]>value)
      {
        return BinarySearch(value, arr, low, midpoint);
      }
      else
      {
        return BinarySearch(value, arr, high, midpoint);
      }
    }
 }