//Kelly Wang 5351010
#include <iostream>
#include "itemtype.h"
#include "bag.h"
#include "word.h"
using namespace std;

//implement constructor
Word::Word(string word){
	words = word;
	data = new bag();

}

//implement default constructor
Word::Word(){
	words = "";
	data = new bag();
}

//implement modifier 
void Word::insert(string word, string fname){//insertWord
	words = word;
	data -> addFile(fname);
	return;
}

//implement observers
string Word::getWord(){
	return words;
}

bag Word::getBag(){
	return *data;
}
