#include "3-ListT.h"
#include <iostream>

using namespace std;

int main() {
    // Test PutItemH
    ListT lst;
   for (int i = 0; i < 5; i++) 
     lst.PutItemH(i);
  lst.PutItemH(2);
  lst.PutItemT(2);
  lst.PutItemT(2);
  lst.Print();
  cout << endl;
  cout << lst.DeleteItem(2) << endl;
  lst.Print();





  /*
   cout << endl;

    lst.PutItemH(5);
    cout << "Test PutItemH: ";
    if (lst.GetItemH() == 5) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    // Test Print
    cout << "Test Print: Correct if out is 5" << endl;
    lst.Print();

    // Test GetItemH (assuming previous PutItemH is still there)
    cout << "Test GetItemH: ";
    if (lst.GetItemH() == 5) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    // Test DeleteItemH
    lst.DeleteItemH();
    cout << "Test DeleteItemH: Correct if list is empty after deletion" << endl;
    lst.Print(); // Should print nothing

    // Test IsEmpty
    cout << "Test IsEmpty: ";
    if (lst.IsEmpty()) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    // Test GetLength
    cout << "Test GetLength: ";
    if (lst.GetLength() == 0) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    // Test Find (assuming previous PutItemH is still there)
    cout << "Test Find: ";
    if (lst.FindItem(5) == 1) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    // Test DeleteItem (assuming previous PutItemH is still there)
    cout << "Test DeleteItem: Correct if 1 is returned after deletion" << endl;
    cout << "Number of items deleted: " << lst.DeleteItem(5) << endl;
*/


    return 0;
}
