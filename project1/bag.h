//Kelly Wang 5351010
#ifndef BAG_H
#define BAG_H
#include <cstdlib>
#include <iostream>
#include "itemtype.h"

using namespace std;

class bag
{
public:
    // constructor
    bag();

    // modifiers
    void addFile(const string& fname); //add unadded files/ increment counter  if file exists

    //observer
    void print() const; // print the file names and its occurences

private:
    File file_names[100]; // max number of files allowed
    int used; 
};

#endif

