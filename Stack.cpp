#include <iostream>

using namespace std;

class Stack
{
protected:
   struct Node
   {
      Node *next;
      int *item;
   };
private: 
   Node *head;
   int size;
public:
   Stack()
   {
      head = NULL;
      size = 0;
   }
   ~Stack(){}
   void push(int v)
   {
      Node *newNode = new Node();
      if(newNode && head == NULL)
      {
         newNode->item = new int(v);
         newNode->next = NULL;
         head = newNode;
      }
      else if (newNode)
      {
         newNode->item = new int(v);
         newNode->next = head;
         head = newNode;
      }
   }
   int *pop()
   {
      if (head!= NULL)
      {
         Node *temp = head;
         int *t = head->item;
         head = temp->next;
         delete temp->item;
         delete temp;
         return t;
      }
      else
      {
         return NULL;
      }
   }

};
int main()
{
   Stack s;
   s.push(1);
   s.push(2);
   s.push(3);
   //cout << *s.pop() << endl;
   return 0;
}