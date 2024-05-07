#include <iostream>
using namespace std;

#include "list.h"

//Non-recursive functions. 
//I have written them for you.
List::List()
{
 head = NULL;
}

bool List::IsEmpty() 
{
 if (head == NULL)
  return true;
 return false; 
}

void List::PutItemH(itemType item)
{
 node* tmp = new node;
 tmp->item = item;
 tmp->next = head;
 head = tmp;
 tmp = NULL;
}

itemType List::GetItemH() 
{
 return head->item; 
}

void List::DeleteItemH()
{
 node* cur = head;
 head = head->next;
 delete cur;
 cur == NULL;
}

//Write the following functions recursively or in such a way that they use
//recursive functions. There is a pattern in the pairing of the functions.  

void List::Print()
{
  Print(head);
}

void List::Print(node* cur)
{
   if(cur != NULL)
    {
      cout << cur->item << endl;
      Print(cur->next);
    }
}

void List::PrintRev()
{
  PrintRev(head);
}

void List::PrintRev(node* cur)
{
  if(cur != NULL)
    {
      PrintRev(cur->next);
      cout << cur->item << endl;
    }
}

int List::GetLength()
{ 
  return 0;
}

int List::GetLength(node* cur)
{ 
  if (cur != NULL)
  {
  GetLength(cur->next);
  }
  return 0;
}

List::~List()
{
  Destructor(head);
}

void List::Destructor(node* cur)
{
  if(cur != NULL)
  {
    cout << "Destructor is running" << endl;
    Destructor(cur->next);
    delete cur;
  }
}
