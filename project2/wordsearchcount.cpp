//Kelly Wang 12.07.18
//5351010
//PROJECT 2
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "itemtype.h"
#include "list.h"
#include "word.h"
#include "wordsearchcount.h"

using namespace std;

/*function... might want it in some class?*/
int wordsearch::getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}


int main(int argc, char* argv[])
{
  string dir; //
  vector<string> files = vector<string>();

  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (wordsearch::getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }

  wordLink* wordList = new wordLink();
  // reading into the files v/putting it in the linkedlist
  string slash("/");
  for (unsigned int i = 0;i < files.size();i++) {
    if(files[i][0]=='.')continue;
 //skip hidden files
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file...
    string word;
    while(true){
      fin >> word;
      if(fin.eof()){//cout << "EOF " << files[i] << endl; 
        break;
      }
      else {
        NodeWord* cursor = wordList->head();
        while(cursor){
          if(cursor->data().get_word() == word){
            cursor->data().get_files()->appendFile(&files[i]);
            break;
          }
          cursor = cursor->next();
        }
        //first iteration cursor == NULL so we a new word object 
        if(cursor == NULL){
          Word* addWord = new Word(word);
          //retrieve the files and call append from list to access file list
          addWord->get_files()->appendFile(&files[i]);
          //add word to the word list
          wordList->appendWord(addWord);
        }
      }
    }
    fin.close();
  }

    string inputWord;
    int threshold;
    int count = 0;

    cout << "Enter a word to search in files or 'exit' to quit." << endl;
    cin >> inputWord;
    if(inputWord == "exit"){
      return 0;
    }

    cout << "Enter threshold or -1 to break"<<endl;
    cin >> threshold;
    if(threshold == -1){
      return 0;
    }
    //accessing the head of the wordList
    NodeWord* wordCursor = wordList->head();
    while(wordCursor != NULL){
     //cout<<wordCursor->data().get_word()<<endl;
      //check to see if the user input matches any words in wordList
      if(wordCursor->data().get_word() == inputWord){
        //if it does check to see if the file count matches the threshold input
        //biggest count is at the tail so the order is flipped
        NodeList* getFileList = wordCursor->data().get_files()->tail();
        while(getFileList!=NULL){
          if(getFileList->data()->count() >= threshold){
            count++;
            //print if the conditions meet
            cout<<"File: "<<getFileList->data()->fileName()<<"; Count: "<<getFileList->data()->count()<<endl; 
          }
          getFileList = getFileList ->prev();
        }
      }
      wordCursor = wordCursor->next();
    }
    //if the input word and threshold don't match then count == 0
    //print error message 
    if(count == 0)
      cout<<"Word: "<<inputWord<<" and threshold: "<< threshold <<" does not match" <<endl;
    //refer to word.h as to why I didn't deallocate memory
    //wordList->~wordLink();
    return 0;
}



