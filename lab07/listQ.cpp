//Kelly Wang 5351010
//11.16.18

#include <iostream>
#include "listQ.h"
Queue::Queue(){
	front = NULL; 
	rear = NULL;
	size = 0; 
}

Queue::~Queue(){
	clear();
}

void Queue::enqueue(int n){
	node* temp = new node(n);
	if(isEmpty()){
		front = rear = temp;
	}
	rear -> next = temp;
	rear = temp;
	size ++;
}

int Queue::dequeue(){
	node* temp = front; 
	if(isEmpty()){
		throw EmptyQueue();
	}
	int front_data = front->data;
	front = front -> next;
	delete temp; 
	size--;
	return front_data;
}

void Queue::clear(){
	node* temp; 
	while(front != NULL){
		temp = front; 
		front = front -> next;
		delete temp; 
	}
	size = 0; 
}

bool Queue::isEmpty()const{
	return(size == 0);
}

int Queue::getSize()const{
	return size; 
}

