#include "3-ListT.h"
#include <iostream>
using namespace std;

ListT::ListT()
{
    // Constructor
    length = 0;
    head = nullptr;
    tail = nullptr;
}

ListT::~ListT()
{
    // Destructor
    while (!IsEmpty()) {
        DeleteItemH();
    }
}

bool ListT::IsEmpty() const
{
    // Check if the list is empty
    return length == 0;
}

int ListT::GetLength() const
{
    // Get the length of the list
    return length;
}

void ListT::PutItemH(itemType item)
{
    // Add an item to the head of the list
    node* tmp = new node;
    tmp->item = item;
    tmp->next = head;

    head = tmp;
    if (length == 0)
        tail = tmp;
    length++;
}

itemType ListT::GetItemH() const
{
    // Get the item at the head of the list
    if (!IsEmpty()) {
        return head->item;
    } else {
        cerr << "Error: List is empty." << endl;
        exit(EXIT_FAILURE);
    }
}

void ListT::DeleteItemH()
{
    // Delete the item at the head of the list
    if (!IsEmpty()) {
        node* tmp = head;
        head = head->next;
        delete tmp;
        length--;
        if (length == 0)
            tail = nullptr;
    } else {
        cerr << "Error: List is empty." << endl;
        exit(EXIT_FAILURE);
    }
}

void ListT::PutItemT(const itemType itemIn)
{
    // Add an item to the tail of the list
    node* tmp = new node;
    tmp->item = itemIn;
    tmp->next = nullptr;

    if (IsEmpty()) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
    length++;
}

itemType ListT::GetItemT() const
{
    // Get the item at the tail of the list
    if (!IsEmpty()) {
        return tail->item;
    } else {
        cerr << "Error: List is empty." << endl;
        exit(EXIT_FAILURE);
    }
}

void ListT::DeleteItemT()
{
    // Delete the item at the tail of the list
    if (!IsEmpty()) {
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            node* cur = head;
            while (cur->next != tail) {
                cur = cur->next;
            }
            delete tail;
            tail = cur;
            tail->next = nullptr;
        }
        length--;
    } else {
        cerr << "Error: List is empty." << endl;
        exit(EXIT_FAILURE);
    }
}

void ListT::Print() const
{
    // Print the contents of the list
    node* cur = head;
    while (cur != nullptr)
    {
        cout << cur->item << endl;
        cur = cur->next;
    }
}

int ListT::FindItem(const itemType target) const
{
    // Find the number of occurrences of a target item in the list
    int count = 0;
    node* cur = head;
    while (cur != nullptr) {
        if (cur->item == target)
            count++;
        cur = cur->next;
    }
    return count;
}

int ListT::DeleteItem(const itemType target)
{
    // Delete all occurrences of a target item from the list
    int count = 0;
    node* cur = head;
    node* prev = nullptr;
    while (cur != nullptr) {
        if (cur->item == target) {
            if (prev == nullptr) {
                DeleteItemH(); // If target is at head
                cur = head; // Re-initialize cur
            } else {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                if (cur == nullptr) // If cur becomes nullptr, then the last element was deleted
                    tail = prev;
            }
            length--;
            count++;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return count;
}

node* ListT::PtrTo()
{
    // Helper function to find the node before the tail
    node* cur = head;
    while (cur->next != tail) {
        cur = cur->next;
    }
    return cur;
}
