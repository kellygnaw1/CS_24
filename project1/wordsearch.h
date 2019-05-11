//Kelly Wang 5351010
#ifndef WORDSEARCH_H
#define WORDSEARCH_H
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

using namespace std;

class wordsearch
{
public: 
	static int getdir(string dir, vector<string> &files);
};

#endif