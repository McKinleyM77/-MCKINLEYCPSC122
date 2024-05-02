// Charlie LaMotte, Federico Brown and McKinley Martsolf

//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queueP.h"
//note Queue is the queue implemented through inheritance or composition.  Find the files
//under B-Inheritance.  

PQueue::PQueue() : QueueI()
{
}

PQueue::PQueue(PQueue* q) : QueueI(q)
{}

void PQueue::Enqueue(itemType newItem)
{
  node* Enq = new node;
  Enq->item = newItem;
  node* prev = PtrTo(newItem);
  Enq->next = prev ->next;
  prev->next = Enq;
}

node* PQueue::PtrTo(itemType newItem)
{
  node* cur = head;
  if(newItem < head->item)
    return head;
  while (cur->next != nullptr && cur->next->item <= newItem)
      cur = cur->next;
 return cur;
}

