//Kelly Wang 5351010
//11.16.18

#include <iostream>
#include "arrayQ.h"

Queue::Queue(){
	size = 0; 
	front = 0; 
	rear = 0; 
}

void Queue::enqueue(int n){
	if(isFull())
		throw FullQueue();
	rear = (rear + 1)%CAPACITY;
	data[rear] = n;
	size++;
}

int Queue::dequeue(){
	if(isEmpty())
		throw EmptyQueue();
	front = (front + 1)%CAPACITY;
	size --; 
	return data[front];
}

void Queue::clear(){
	front = 0; 
	rear = 0; 
	size = 0;
}

bool Queue::isEmpty()const{
	return(size == 0);
}

bool Queue::isFull()const{
	return(size == CAPACITY);
}

int Queue::getSize()const{
	return size; 
}