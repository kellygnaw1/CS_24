//Kelly Wang 12.07.18
//5351010
//PROJECT 2
#ifndef WORDSEARCHCOUNT_H
#define WORDSEARCHCOUNT_H
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

using namespace std;

class wordsearch
{
public: 
	static int getdir(string dir, vector<string> &files);
};

#endif