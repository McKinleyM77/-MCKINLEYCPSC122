#include <iostream>
using namespace std;

#include "queueP.h"


int main()
{

 PQueue* que = new PQueue;

 //for (int i = 5; i >= 0; i--)
  //que->Enqueue(i);
 que->Enqueue(3);
 que->Enqueue(9);
 que->Enqueue(2);
 que->Enqueue(1);
 que->Enqueue(0);
 que->Enqueue(100);
 que->Enqueue(5);



 que->Print();


 //que->Dequeue();
 //que->Print();
 //cout << que->Peek() << endl;

 delete que;
}
