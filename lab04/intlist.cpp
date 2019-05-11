// intlist.cpp
// Implements class IntList
// KELLY WANG 11.01.18

#include "intlist.h"

#include <iostream>
using std::cout;

// return sum of values in list
int IntList::sum() const {
    int sum = 0; 
    Node* n = first;
    while(n){
        sum += n->info;
        n = n-> next;
    }
    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first; 
    while(n){
        if(n->info == value )
            return true;
        n = n->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0; 
    if(count() == 0)// empty linked list
        return max;
    Node *n = first;
    while(n){
        if(n->info > max)
            max = n->info;
        n = n->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
    
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double avg = 0.0; 
    if(count() == 0)
        return avg;
    Node *n = first; 
    while(n){
        avg += n->info;
        n = n->next;  
    }
    return avg/IntList::count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT
    Node *n = new Node;
    n->info = value;
    n->next = first;
    first = n;
    return;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = first;
    while (n) {
        Node *garbage = n;
        n = n->next;
        delete garbage;
    }
}

// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}