//Kelly Wang 12.07.18
//5351010
//PROJECT 2	
#include "word.h"
#include "list.h"
#include "itemtype.h"
#include <iostream>
#include <string>

using namespace std;

//implementations
Word::Word(){
	word = "";
	data = new list();
}

Word::Word(const string word){
	this->word = word;
	data = new list();
}

string Word::get_word(){
	return word;
}

list* Word::get_files(){
	return data;
}

void Word::insert(const string word, string* fname){
	this->word = word;
	data->appendFile(fname);
}

wordLink::wordLink(){
	head_f = NULL;
	tail_f = NULL;
}

//Sort while appending
void wordLink::appendWord(const Word* data_f){
	NodeWord* temp = head_f;
	NodeWord* wordNode = new NodeWord(*data_f, NULL, NULL);

	//If there's nothing in the list
	if(head_f == NULL && tail_f == NULL){
		head_f = tail_f = wordNode;
		return;
	}
	//head insert
	if(wordNode->data().get_word() < temp->data().get_word()){
		wordNode->set_next(temp);
		temp->set_prev(wordNode);
		head_f = wordNode;
		return;
	}
	//pointer temp will stop at the node that goes after the node we are trying to append
	while(temp->data().get_word() < wordNode->data().get_word() && temp->next() !=NULL){
		temp = temp->next();
	}
	if(temp->next() != NULL){
		//inserting somewhere in the linkedlist
		temp->prev()->set_next(wordNode);
		wordNode->set_next(temp);
		wordNode->set_prev(temp->prev());
		temp->set_prev(wordNode);
	}else if(temp->next()==NULL && temp->data().get_word() > wordNode->data().get_word()){
		//insert one before the tail
		temp->set_prev(wordNode);
		temp->prev()->set_next(wordNode);
		wordNode->set_next(temp);
		wordNode->set_prev(temp->prev());
	}else if(temp->next() == NULL && temp->data().get_word()<wordNode->data().get_word()){
		//insert one after the tail
		temp->set_next(wordNode);
		wordNode->set_prev(temp);
		tail_f = wordNode;
	}

}

// wordLink::~wordLink(){
// 	NodeWord* temp = head_f;
// 	while(head_f != NULL){
// 		head_f = head_f->next();
// 		temp->data().get_files()-> ~list();
// 		temp->set_next(NULL);
// 		delete temp;
// 	}
// 	tail_f = NULL;
// }


