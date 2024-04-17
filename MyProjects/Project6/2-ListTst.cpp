#include "2-List.h"
#include <iostream>

using namespace std;

int main() {
    // Test PutItemH
    List lst;

  lst.PutItemH(4);  
  lst.PutItemH(5);
  lst.PutItemH(8);
  lst.PutItemH(5);
  lst.PutItemH(7);
  lst.PutItemH(5);
  lst.Print(); 
  cout << endl;
  lst.DeleteItem(5);
  lst.Print();
  cout << endl;
}
