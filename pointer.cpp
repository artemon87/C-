#include <iostream>

using namespace std;

void PrintArray(int *arr, int length);
void Reverse(int *arr, int length);

int main()
{
  int *dynamicArray;
  int arr[5]={1, 2, 3, 4, 5};
  int size;
  cout<<"Whats your array size "<<endl;
  cin>>size;
  dynamicArray=new int[size];
  
  for(int i=0; i<size; i++)
  {
    dynamicArray[i]=i+1;
  }
  
  PrintArray(dynamicArray, size);
  Reverse(dynamicArray, size);
  for(int i=0; i<5; i++)
  {
    cout<<"Array at "<<i<<": "<<arr[i]<<endl;
  }
  delete(dynamicArray);
return 0;
}

void PrintArray(int *arr, int length)
{
  int *point;
  point=arr;
  for(int i=0; i<length; i++)
  {
    //p++;
    cout<<"Value of i "<<i<<" Pointer "<<*point+i<<endl;  
    //point++; 
    //cout<<"Value of i "<<i<<" Pointer "<<*(arr+i)<<endl;
    
  }
}
void Reverse(int *arr, int length)
{
  for(int i=0; i<length/2; i++)
  {
    int temp;
    temp=*(arr+i);
    *(arr+i)=*(arr+length-1-i);
    *(arr+length-1-i)=temp;
    //cout<<"Value of i "<<i<<" Pointer "<<*(arr+i)<<endl;
  }
}
    