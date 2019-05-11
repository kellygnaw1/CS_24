//Kelly Wang 5351010
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "itemtype.h"
#include "bag.h"
#include "word.h"
#include "wordsearch.h"

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
  

  Word wordsArr[1000];
  int used = 0;
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

        //cout<<files[i] << "::" << word << endl;
        //make forloop to to insert the word and file name if getWord == word
        for(int j = 0; j < used; j++){
          if(wordsArr[j].getWord() == word){
            wordsArr[j].insert(word, files[i]);
            break;
          }
        }
        wordsArr[used].insert(word, files[i]);
        used++;
  // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
  // Use these two strings to search/insert in your array/list of words.
      }
    }
    fin.close();
  }

    //handeling getting the actual files ^
  while(true){
    string inputWord;
    cout << "Enter a word to search in files or exit to quit." << endl;
    cin >> inputWord;

    if(inputWord == "exit"){
      break;
    }
    int i;
    for(i = 0; i < used; i++){
      if(wordsArr[i].getWord() == inputWord){
        wordsArr[i].getBag().print();//use print function in bag 
        break;
      }
    }
      if(i == used){
        cout << "No occurences of word: " + inputWord <<endl;
      }
    }


}



