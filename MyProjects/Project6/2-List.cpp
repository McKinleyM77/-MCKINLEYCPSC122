#include "2-List.h"
#include <iostream>

using namespace std;

// Constructor
List::List() 
{
    length = 0;
    head = nullptr; // Use nullptr instead of NULL in C++
}

// Destructor
List::~List() 
{
    // Implement the destructor to release dynamically allocated memory
    node* current = head;
    while (current != nullptr) 
    {
        node* next = current->next;
        delete current;
        current = next;
    }
}

// PutItemH function
void List::PutItemH(const itemType itemIn) 
{
    node* newNode = new node;
    newNode->item = itemIn;
    newNode->next = head;
    head = newNode;
    length++;
}

// GetItemH function
itemType List::GetItemH() const {
    if (head != nullptr) {
        return head->item;
    } else {
        cerr << "Error: List is empty. Returning default itemType value." << endl;
        return itemType(); // Default value for itemType (usually 0)
    }
}

// DeleteItemH function
void List::DeleteItemH() {
    if (head != nullptr) {
        node* temp = head;
        head = head->next;
        delete temp;
        length--;
    } else {
        cerr << "Error: List is empty. Cannot delete." << endl;
    }
}

// IsEmpty function
bool List::IsEmpty() const {
    return (head == nullptr);
}

// GetLength function
int List::GetLength() const {
    return length;
}

// Print function
void List::Print() const {
    node* current = head;
    while (current != nullptr) {
        cout << current->item << endl;
        current = current->next;
    }
}

// Find function
int List::Find(const itemType target) const {
    int count = 0;
    node* current = head;
    while (current != nullptr) {
        if (current->item == target) {
            count++;
        }
        current = current->next;
    }
    return count;
}
/* int List::DeleteItem(const itemType target)
{
  int count = 0;
  while (head -> item == target)
    {
      DeleteItemH();
      count++;
    }

  return count;
}
*/


// DeleteItem function

int List::DeleteItem(const itemType target) {
    // Initialize count of deleted items
    int count = 0;

    // Check if the list is empty
    if (head == nullptr) {
        return count; // Return 0 if list is empty
    }

    // Initialize pointers for traversal
    node* current = head; // Pointer to traverse the list
    node* previous = nullptr; // Pointer to track previous node

    // Iterate through the list
    while (current != nullptr) {
        // Check if current node contains target item
        if (current->item == target) {
            // Delete node containing target item
            if (previous == nullptr) { 
                // If target is found at head
                head = current->next; // Update head to skip current node
            } else {
                previous->next = current->next; // Update previous node's next to skip current node
            }

            // Delete current node
            node* temp = current; // Store current node in temp
            current = current->next; // Move to the next node
            delete temp; // Delete the current node

            // Update counters
            length--; // Update length of the list
            count++; // Increment count of deleted items
        } else {
            // Move pointers to next nodes
            previous = current; // Move previous pointer to current node
            current = current->next; // Move current pointer to the next node
        }
    }

    // Return count of deleted items
    return count;
}
