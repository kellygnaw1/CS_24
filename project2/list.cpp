//Kelly Wang 12.07.18
//5351010
//PROJECT 2
#include "list.h"
#include "itemtype.h"
#include "word.h"
#include <string>
#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;

//implementations
list::list(){
	head_f = NULL;
	tail_f = NULL;
}

void list::appendFile(string* fname){	
	NodeList* temp = head_f;
    //check to see if the filenames match 
	while(temp != NULL){
		if(temp -> data() -> fileName() == *fname){
			temp -> data() -> incrCount();
            temp = head_f;
            head_f = insertionSort(temp);
			return;
		}
        temp = temp -> next();
	}
    //reset temp to head
    temp = head_f;
    //to make a new node we need to make a pointer to File (refer to NodeList to see data_f's data type)
	File* file = new File(*fname, 1);
	NodeList* fileNode = new NodeList(file, NULL, NULL);
	if(head_f == NULL){
		head_f = tail_f = fileNode;
	}
    //iterating from the end of the linked list
    //list goes in increasing order so 
    //1->3->6->9 
    //when we call this we need to call it from the tail to get 9, 6, 3, 1
    else if(tail_f->data()->count() <= fileNode->data()->count()){
        fileNode->set_prev(tail_f); 
        fileNode->prev()->set_next(fileNode); 
        tail_f = fileNode;
    }
    else{
        temp = tail_f;
        while (temp->prev()!=NULL && temp->prev()->data()->count() > fileNode->data()->count()) 
            temp = temp -> prev();
        fileNode->set_prev(temp->prev());
        if (temp->prev()!=NULL) 
            fileNode->prev()->set_next(fileNode); 
        else{
            head_f = fileNode;
        }
        temp->set_prev(fileNode); 
        fileNode->set_next(temp);
    }
	return;
}
//I tried using my logic for word append for list but it didn't work 
//since temp might change if the file names matched
//INSERTIONSORT AND SORTEDINSERT FROM GEEKSFORGEEKS 
//https://www.geeksforgeeks.org/insertion-sort-doubly-linked-list/
void list::sortedInsert(NodeList*& headRef, NodeList*& newNode){
    NodeList* current;  
    // if list is empty 
    if (headRef == NULL) 
        headRef = newNode;  
    // if the node is to be inserted at the beginning 
    // of the doubly linked list 

    else if (headRef -> data()->count() >= newNode -> data() -> count()) { 
        newNode -> set_next(headRef); 
        newNode -> next() -> set_prev(newNode); 
        headRef = newNode; 
    } 
    else { 
        current = headRef; 
        // locate the node after which the new node 
        // is to be inserted 
        while (current -> next() != NULL && (current -> next() -> data() -> count() < newNode -> data() -> count())) {
            current = current -> next(); 
        }
        /*Make the appropriate links */
        newNode -> set_next(current -> next()); 
        // if the new node is not inserted 
        // at the end of the list 
        if (current -> next() != NULL) 
            newNode -> next() -> set_prev(newNode); 
        current -> set_next(newNode); 
        newNode -> set_prev(current); 
    } 
} 
  
// function to sort a doubly linked list using insertion sort 
NodeList* list::insertionSort(NodeList* headRef) { 
    // Initialize 'sorted' - a sorted doubly linked list 
    NodeList* sorted = NULL;  
    // Traverse the given doubly linked list and 
    // insert every node to 'sorted' 
    NodeList* current = headRef; 
    while (current != NULL) { 
        // Store next for next iteration 
        NodeList* next = current->next(); 
        // removing all the links so as to create 'current' 
        // as a new node for insertion 
        current -> set_prev(NULL);
        current -> set_next(NULL);  
        // insert current in 'sorted' doubly linked list 
        sortedInsert(sorted, current);  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted doubly linked list 
    headRef = sorted; 
    return headRef;
} 

// list::~list(){
//     NodeList* temp = head_f;
//     while(head_f != NULL){
//         head_f = head_f->next();
//         temp->set_next(NULL);
//         temp->set_data(NULL);
//         delete temp;
//     }
//     tail_f = NULL;
// }
