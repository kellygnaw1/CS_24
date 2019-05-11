//Kelly Wang 5351010
#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
#include "bag.h"

using namespace std;

class Word
{
public:
    //constructor and default 
    Word(string word);
    Word(); //makes it possible to set array size in wordSearch.cpp

    //modifier
    void insert(string word, string fname);// insert word and file name 

    //observers
    string getWord();
    bag getBag();

private:
    string words;
    bag* data;

};

#endif
