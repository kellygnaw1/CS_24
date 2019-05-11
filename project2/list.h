//Kelly Wang 12.07.10
//5351010
//PROJECT 2
#ifndef LIST_H
#define LIST_H
#include "itemtype.h"
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

//look at word.h for explaination on my structure
struct NodeList
{
public:
    //data_f needs to be a pointer with type File so we can access the things in itemtype
    NodeList(File* d, NodeList* l=NULL, NodeList* p=NULL)
    {
        data_f = d;
        next_f = l;
        prev_f = p;
    }
    //modifier
    void set_data(File* d) {data_f = d;}
    void set_next(NodeList* l) {next_f = l;}
    void set_prev(NodeList* p) {prev_f = p;}

    //observers
    File* data() const {return data_f;}


    NodeList* next() {return next_f;}
    const NodeList* next() const {return next_f;}


    NodeList* prev() {return prev_f;}
    const NodeList* prev() const {return prev_f;}

private:
    File* data_f;
    NodeList* next_f;
    NodeList* prev_f;
};

class list
{
public: 
    //constructor
    list();
    //modifers
    //append
    void appendFile(string* fname);
    //insertion sort (refer to list.cpp for citing)
    void sortedInsert(NodeList*& head, NodeList*& newNode);
    NodeList* insertionSort(NodeList* head);
    //observers 
    NodeList* head(){return head_f;}
    NodeList* tail(){return tail_f;}

    //~list();

private: 
	NodeList* head_f;
	NodeList* tail_f;
};

#endif 