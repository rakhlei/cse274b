//============================================================================
// Name        : rakhlei_hw_1.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "utils.h"
#include "array.h"
#include "ArrayDeque.h"
#include "Treque.h"

using namespace std;
using namespace ods;

int main() {

	Treque <int> tester;

	// loops 50 times and adds elements to Treque
	// add has CheckBalance function which prints out ArrayDeque sizes
	for (int i = 0; i < 50; i++) {
		tester.add(0,rand() % 100);
	}

	// ensures balance function works when elements are removed
	tester.remove(1);
	tester.remove(5);
	tester.remove(12);
	tester.remove(6);
	tester.remove(0);


	return 0;
}
