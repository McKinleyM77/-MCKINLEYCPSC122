/*
Name: Charlie LaMotte, Federico Brown and McKinley Martsolf
Class: CPSC 122
Date Submitted: 5/3/2024
Assignment: Project 12
Description: Priority Queue Assignmemt
To Compile: make
To Execute: ./pqueue"
*/

#include <iostream>
using namespace std;
#include "queueP.h"

//Constructor
PQueue::PQueue() : QueueI()
{
}

//Copy Constructor
PQueue::PQueue(PQueue* q) : QueueI(q)
{}

//Enqueue function puts items into a list in priority order
void PQueue::Enqueue(itemType newItem)
{
  node* Enq = new node;
  Enq->item = newItem;
  if(head == NULL)
  {
    tail = Enq;
    head = Enq;
  } 
  else if (head->item > newItem)
  {
    Enq->next = head;
    head = Enq;
  }
  else
  {
    node* prev = PtrTo(newItem);
    Enq->next = prev ->next;
    prev->next = Enq;
  }
}


//PtrTo function returns a pointer to a node in the list that is before the node that contains an item greater than newItem
node* PQueue::PtrTo(itemType newItem)
{
  node* cur = head;
  //if(head == nullptr || head->item > newItem)
    //return nullptr;
  while (cur != nullptr && cur->next != nullptr && cur->next->item <= newItem)
      cur = cur->next;
  return cur;
}