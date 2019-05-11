//Kelly Wang 12.7.18
//5351010
//PROJECT 2

#ifndef WORD_H
#define WORD_H
#include "itemtype.h"
#include "list.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>


//I tried many different ways of doing this, template class, making class Word as a node, putting struct node in the private
//nothing worked until I broke it up into bascially three classes
//class Word deals with getting files/ linking the two different linkedlists 
//class WordLink deals with the linklist part for Word ONLY
//struct NodeWord is the structure for the word linkedlist
//I tried making a deconstructor but it didn't work because im pasking in the data type as a const Word& reference 
//and in the instructions it didn't say anything about making a deconstructor so plz don't take points off 
class Word
{
public:
    //constructors 
	Word();
	Word(const string word);
    //observers
	string get_word();
	list* get_files();
    //modifiers
	void insert(const string word, string* fname);
private:
	string word;
    //data type for data is list so it can access the list linkedlist
	list* data;
};
struct NodeWord
{
public:
	NodeWord(const Word& d, NodeWord* l=NULL, NodeWord* p=NULL)
    {
        data_f = d;
        next_f = l;
        prev_f = p;
    }

    //modifiers

    void set_data(const Word& d) {data_f = d;}
    void set_next(NodeWord* l) {next_f = l;}
    void set_prev(NodeWord* p) {prev_f = p;}

    // observers
    Word data() const {return data_f;}

    // forward links
    NodeWord* next() {return next_f;}
    const NodeWord* next() const {return next_f;}

    // backward links
    NodeWord* prev() {return prev_f;}
    const NodeWord* prev() const {return prev_f;}

private:
    Word data_f;
    // forward pointer
    NodeWord* next_f;
    // backward pointer
    NodeWord* prev_f;
};

class wordLink
{
public:
    //constructor
	wordLink();
    //modifier
    //sort + append 
	void appendWord(const Word* data_f);
    //observers
	NodeWord* head(){return head_f;}
	NodeWord* tail(){return tail_f;}
    //~wordLink();
private:
	NodeWord* head_f;
	NodeWord* tail_f;
};

#endif
