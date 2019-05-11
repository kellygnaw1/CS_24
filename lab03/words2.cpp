// words2.cpp - implements class Words
// (Dynamic version)
//Kelly Wang 10/25/18

#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab04_2
{
    Words::Words(unsigned int initial_capacity) {
        used = 0;
        capacity = initial_capacity;
        data = new string[initial_capacity];
        // initial_capacity = new int[];
        // string* data = &initial_capacity;
    }

    Words::Words(const Words &source){
        used = source.used;
        capacity = source.get_capacity();
        //capacity = source.size();
        data = new string[capacity];
        //data = new string[capacity];
        for(int i = 0; i < used; i++){
            data[i] = source[i];
        }
        //copy(source.data, source.data + used, data);

    }

    void Words::append(string word) {
        if(used == capacity){
            string *data2 = new string[used*2];
            copy(data, data + used, data2);// start of data, end of data that needs to be copied -> data2
            delete [] data;
            data = data2;
            capacity = used *2;
        }
            data[used] = word;
            used++;;
         
    }
    
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
    }
    
    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }

    Words& Words::operator=(const Words &source){
        //checks that source is not the object on which it's invoked
        if(this == &source){
            return *this;
        }
        //changes capacity if necessary
        if(capacity != source.get_capacity()){
            this -> ~Words();
            data = new string[source.get_capacity()];
        }
        //copies all strings from source
        for(int i = 0; i < source.size(); i++){
            data[i] = source.data[i];
        }
        //copies the size from source
        used = source.size();
        return *this;
    }

    Words::~Words() {
        delete [] data;
    }
    
}



