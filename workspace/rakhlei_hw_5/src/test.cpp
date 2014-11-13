//============================================================================
// Name        : rakhlei_hw_5.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "DataStructureTester.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace ods;

int main() {
	DataStructureTester<ChainedHashTable<int> > test;
	test.DoRandomAdd(100);
	return 0;
}
