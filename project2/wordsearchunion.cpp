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
#include "wordsearchunion.h"

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
//refer to wordsearchunion.cpp for commentation on opening files and getting words
  wordLink* wordList = new wordLink();
  // reading into the files v/putting it in the array 
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
        //cout << word;
        NodeWord* cursor = wordList->head();
        //cout<<"5"<<endl;
        while(cursor){
          if(cursor->data().get_word() == word){
            //cout<<"6"<<endl;
            cursor->data().get_files()->appendFile(&files[i]);
            //cout<<"7"<<endl;
            break;
          }
          cursor = cursor->next();
        }
        
        if(cursor == NULL){
          Word* addWord = new Word(word);
          addWord->get_files()->appendFile(&files[i]);
          wordList->appendWord(addWord);
        }
  // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
  // Use these two strings to search/insert in your array/list of words.
      }
    }
    fin.close();
  }
    string inputWord1;
    string inputWord2;
    int count = 0;

    cout << "Enter two words to find union or 'exit' to quit." << endl;
    cin >> inputWord1;
    cin >> inputWord2;
    if(inputWord1 == "exit"){
      return 0;
    }
    //create a list object
    list* listlist = new list();
    //access the head of the wordList
    NodeWord* wordCursor = wordList->head();
    while(wordCursor != NULL){
      if(wordCursor->data().get_word() == inputWord1){
        count++;
        NodeList* getFileList = wordCursor->data().get_files()->head();
        while(getFileList != NULL){
          string* file1 = new string(getFileList->data()->fileName());
          //append every file that has input1 into listlist
          listlist ->appendFile(file1);
          getFileList= getFileList->next();
        }
      }
      wordCursor = wordCursor->next();
    }
    //access the head of the new list made from inputWord1 (listlist)
    NodeList* fileCompare = listlist->head();
    //access the head of the wordList again
    wordCursor = wordList->head();

    //if inputWord1 is not in any of the files then we take all the files with inputWord2 and put it in listlist
    if(fileCompare == NULL){
      while(wordCursor != NULL){
        if(wordCursor->data().get_word() == inputWord2){
          count++;
          NodeList* getFileList = wordCursor->data().get_files()->head();
          while(getFileList!=NULL){
            string* file2 = new string(getFileList->data()->fileName());
            listlist ->appendFile(file2);
            getFileList = getFileList->next();
          }
        }
        wordCursor = wordCursor->next();
      }
    }else{ //if both words are in files, we make sure there are no dups
      while(wordCursor != NULL){
        if(wordCursor->data().get_word() == inputWord2){
          count++;
          NodeList* getFileList = wordCursor->data().get_files()->head();
          while(getFileList != NULL){
            while(fileCompare->next()!=NULL){
              string* file2 = new string(getFileList->data()->fileName());
              //if the filenames don't match we put file2 onto listlist
              if(fileCompare->data()->fileName() != getFileList->data()->fileName()){
                listlist->appendFile(file2);
              }
              fileCompare = fileCompare->next();
            }
            getFileList = getFileList->next();
          }
        }
        wordCursor = wordCursor->next();
      }
    }

    fileCompare = listlist->head();
    //print out everything from listlist
    while(fileCompare != NULL){
      cout<< "file: "<< fileCompare->data()->fileName()<<endl;
      fileCompare = fileCompare->next();
    }

    if(count == 0)
      cout<<"Word: "<<inputWord1<<" and "<< inputWord2 <<" does not have union" <<endl;
    return 0;
}



