#pragma once

#include <iostream>
#include <fstream>
#include <string>

// which user defined headers should we include? just BST.h? yes, that's all we need, because it includes the others...
#include "BST.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BSTTests
{
public:
	void testInsertOnEmptyTree();
	void testClassTemplateDataConstruction();
private:
	BST<int> tree;
};