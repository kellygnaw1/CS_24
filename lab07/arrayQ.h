//Kelly Wang
//11.15.18
// arrayQ.h - queue class for CS 24 lab, array version
//            stores int - max capacity is 10

#ifndef QUEUE_H
#define QUEUE_H

// specialized exception classes
class EmptyQueue { };
class FullQueue { };

const int CAPACITY = 10;

class Queue {

public:
    Queue();             // constructor creates empty queue

    void enqueue(int n); // adds n to rear;
        // throws FullQueue if full

    int dequeue();       // removes and returns front;
        // throws EmptyQueue if empty

    void clear();        // makes queue logically empty
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const; // returns number of items in the queue

private:
    int front, rear;     // indices to keep track of front and rear
    int data[CAPACITY];  // array to store queue data
    int size;            // number of items in the queue
};

#endif