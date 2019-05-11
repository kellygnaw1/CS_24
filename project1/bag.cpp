//Kelly Wang 5351010
#include <iostream>
#include <string>
#include <cstdlib>
#include "itemtype.h"
#include "bag.h"

using namespace std;

//implement default constructor
bag::bag(){
    used = 0; //starting with nothing in bag
}

//if file already exists count++
//otherwise put file in bag
void bag::addFile(const string& fname){
    for(int i = 0; i< used; i++){
        if(file_names[i].fileName() == fname){ //if file_name[i].getfilename is the same as fname
            file_names[i].incrCount(); // then count increments by 1, refer to itemtype.cpp
            return;
        }
    }

    //loop exists if there is currently nothing in the bag/ the file doesn't exist yet
    file_names[used].set_fname(fname); //if file doesn't already exists then we add it 
    file_names[used].incrCount();// the counter is now at 1 for the file that doesn't exist
    used++;
    return;

}

void bag::print() const{
    for(int i = 0; i < used; i++){
        //print file name and occurences 
        cout << "File: " << file_names[i].fileName() << "; Count: " << file_names[i].count() << endl;
    }
}