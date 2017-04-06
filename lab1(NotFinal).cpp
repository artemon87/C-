// ----------------------------------------------------------------------------
// Nothing was changed in this section

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;            
int const MAXLENGTH = 31;           
int const MAXGRADE = 100;           
int const LOWGRADE = 0;             
int const GROUP = 10;               
int const HISTOGRAMSIZE = (MAXGRADE-LOWGRADE)/GROUP + 1;    

struct StudentType  {               
  int grade;                       
  char last[MAXLENGTH];            
  char first[MAXLENGTH];           
};
//-----------------------------------------------------------------------------
// Prototypes
bool sortInput(istream &, StudentType [], int &);
void displayList(const StudentType [], int);
void setHistogram(int (&histogram)[HISTOGRAMSIZE][3], StudentType [], int);
void displayHistogram(int (&histogram)[HISTOGRAMSIZE][3]);
int findAverage(StudentType [], int);

//-----------------------------------------------------------------------------
int main()  {
    
  StudentType students[MAXSIZE];   
  int size = 0;                   
  int histogram[HISTOGRAMSIZE][3];  // 2D array to store histogram 
  int average = 0;                 
    
  ifstream infile("data1.txt");
  if (!infile)  {
      cout << "File could not be opened." << endl;
      return 1;
  }
    
  bool successfulRead = sortInput(infile, students, size);
  if (successfulRead)  {
      cout<<" List of names sorted:"<<endl;
      displayList(students, size);
      cout << endl;
      setHistogram(histogram, students, size);
      cout << "Histogram of grades: " << endl;
      displayHistogram(histogram); 
      average = findAverage(students, size);
      cout << endl << "Average grade: " << average << endl << endl;
  }
  infile.close(); //closes file after its done with avarage function
  return 0;
}
//---------------------------------------------------------------------------
//SortImput function per your request reads data
//And at the same time it sorts it in alfa. order 

bool sortInput(istream &infile, StudentType students [], int &size)
{
  char temp[MAXLENGTH]; 
  infile >> temp; 
  int circle=0;
  
  StudentType tempArray[1]; //constracts/initializes temprorary StudentType
  char error[MAXLENGTH];
    
  while(size<MAXSIZE &&!infile.eof())
  {
    if(strcmp(temp, "error") != 0 && circle==0) //if sircle >0 it will 
    {                                           //skip this 'if' statement
      strcpy(students[size].last, temp);        //next loop.
      infile >> students[size].first >> students[size].grade;
      size++;
      circle++; //makes circle to be 1;
      infile >> temp;
    }
    else if(strcmp(temp, "error") != 0 && circle!=0)
    {
      strcpy(tempArray[0].last, temp);
      infile >> tempArray[0].first >> tempArray[0].grade;
          
      for(int i=size; i>=0; i--)
      {
        if(strcmp(tempArray[0].last, students[i-1].last)<0) //comares l.names
        {
          strcpy(students[i].last, students[i-1].last);  //duplicates studen's
          strcpy(students[i].first, students[i-1].first);//info to a new loc.
          students[i].grade=students[i-1].grade;
        }
        else if(strcmp(tempArray[0].last, students[i-1].last) == 0 &&
                strcmp(tempArray[0].first, students[i-1].first)<0)
        {
          strcpy(students[i].last, students[i-1].last);
          strcpy(students[i].first, students[i-1].first);
          students[i].grade=students[i-1].grade;
        }
        else
        {
          strcpy(students[i].last, tempArray[0].last);  //copies temprorary
          strcpy(students[i].first, tempArray[0].first);//stored studen's
          students[i].grade=tempArray[0].grade;         //info into correct
                                                        //sorted position
          size++;
          infile>>temp;
          break;                         //breakes the loop once copied
         }
       }
     }
     else{
        infile >> error >> error >> temp; //takes out an error check line
     }
  }
  return true;
}
//--------------------------------------------------------------------------
//displayList prints out sorted list of students and their grades
void displayList(const StudentType students [], int size)
{
  for(int i=0; i<size; i++)
  {
    cout<<setw(4)<<students[i].grade<<"  "
    <<students[i].last<<"  "<<students[i].first<<endl;
  }
}

//--------------------------------------------------------------------------
//setHistogram function puts grades in a desired order
//inside the 2D array (histogram)
void setHistogram(int (&histogram)[HISTOGRAMSIZE][3], 
                  StudentType students [], int size)
{
  memset(histogram, 0, sizeof(int [HISTOGRAMSIZE][3])); //resets array
  int temp1=0;          //left side of a histogram
  int temp2=9;          //right side of a histogram
  int startFrame=0;     //left side of a grade window (to use for stars "*")
  int endFrame=10;      //right side of agrade window (to use for stars "*")
    
  for(int i=0; i<HISTOGRAMSIZE; i++)
  {
    histogram[i][0]=temp1;
    histogram[i][1]=temp2;
    temp1+=10;          //increases lest side by 10
    temp2+=10;          //increases right side by 10
        
    if(temp2>MAXGRADE){ //to make sure that there is
       temp2=MAXGRADE;  //no grade higher then 100
    }
  }
  for(int a=0; a<HISTOGRAMSIZE; a++)
  {
    for(int b=0; b<=size; b++)
    {
      if(students[b].grade<endFrame && students[b].grade>=startFrame)
      {
        histogram[a][2]+=1; //this 2D array column is for the stars "*"
      }
    }
    startFrame+=10;
    endFrame+=10;
  }
}
//----------------------------------------------------------------------------
//displayHistogram uses created 2D "histogram" array and
//prints out whatever was stored in it from the previous setHistogram function      
void displayHistogram(int (&histogram) [HISTOGRAMSIZE][3])
{
  for(int i=0; i<HISTOGRAMSIZE; i++)
  {
    cout<<setw(4)<<histogram[i][0]<<"-->"<<setw(4)<<histogram[i][1]<<": ";
    if(histogram[i][2]!=0)
    {
      for(int star=0; star<histogram[i][2]; star++)
      {
        cout<<"*"; //prints *
      }
    }
    cout<<endl;
  }
}
//----------------------------------------------------------------------------
//findArray adds all the grades and divides to the number of students
int findAverage(StudentType students [], int size)
{
  int total[size];
  int sum=0;
  for(int i=0; i<size; ++i)
  {
    total[i]=students[i].grade;
    sum+=total[i];
  }
  return sum/size;
}
//---------------------------------------------------------------------------