#include <iostream>

using namespace std;

void printArray(int[], int);
void reverseArray(int [], int);

int main()
{
  int array[5]={1, 2, 3, 4, 5};
  //char *c="hello";
  int *p;
  char c1[]="hello";
  char c2[6]="hello";
  
  p=array;
  cout<<*p++<<endl;
  cout<<*array;
  cout<<*array+4;
  cout<<(*array+4);
  cout<<endl;
  
  
  printArray(array, 5);
  
  cout<<endl;
  
  reverseArray(array, 5);
return 0;
}

void printArray(int array[], int length) //passing a pointer of an array "array[]", to pass an array: "array"
{
  for(int i=0; i<length; i++) //you cant do an array.size() as it is a pointer;
  {
    cout<<"Array " <<i<<"= "<<array[i]<<endl;
  }
}
void reverseArray(int array[], int length)
{
  int temp;
  for(int i=length; i<2; i--)
  {
    temp=array[i];
    array[i]=array[i-length];
    array[i-length]=temp;
  }
  printArray(array, 5);
}
    