//============================================================================
// Name        : rakhlei_hw_3.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace ods;

void TestingChainedHashTable(){

	 srand(time(NULL));
	 ChainedHashTable<int> table;
	 cout << "load factor = 8, increasing n to show size of array (2^d) changes" << endl;
	 table.SetLocalFactor(8);
	 table.TestHashMethod(5000);

	 table.SetLocalFactor(8);
	 table.TestHashMethod(6000);

	 table.SetLocalFactor(8);
	 table.TestHashMethod(7000);

	 table.SetLocalFactor(8);
	 table.TestHashMethod(8000);

	 table.SetLocalFactor(8);
	 table.TestHashMethod(9000);

	 table.SetLocalFactor(8);
	 table.TestHashMethod(10000);


 	 cout << "longest list: " << table.GetLongestList() << endl;

}

void TestingLinearHashTable1() {
	srand(time(NULL));
	LinearHashTable<int> tester(-1, -2);
	for (int i = 0; i < 100; i++) {
		tester.add(i);
	}

	tester.PrintTable();
	tester.EvenlyLoaded();
	cout << "Remove two items" << endl;
	tester.remove(0);
	tester.remove(4);
	tester.PrintTable();
	tester.EvenlyLoaded();
	cout << "d = " << tester.d << endl;
}

void TestingLinearHashTable2() {

	LinearHashTable<int> linear_table(-1, -2);

	for (int i = 0; i < 100; i++) {
		linear_table.add(i);
	}

	for (int i = 60; i < 80; i++) {
		linear_table.remove(i);
	}

	for (int i = 0; i < 60; i++) {
		if (linear_table.find(i) == -1)
			cout << "could not find value: " << i << endl;
	}

	for (int i = 80; i < 100; i++) {
		if (linear_table.find(i) == -1)
			cout << "could not find value: " << i << endl;
	}

	linear_table.PrintTable();

}

void TestingAddSlow() {
	srand(time(NULL));
	LinearHashTable<int> tester(-1, -2);
	for (int i = 0; i < 100; i++) {
		tester.addSlow(i);
	}

	tester.PrintTable();
	tester.EvenlyLoaded();
	cout << "Remove two items" << endl;
	tester.remove(0);
	tester.remove(4);
	tester.PrintTable();
	tester.EvenlyLoaded();
}

int main() {

	cout << "Testing Chained Hash Table" << endl;
	TestingChainedHashTable();
	cout << endl;
	cout << "Testing Linear Hash Table, first method" << endl;
	TestingLinearHashTable1();
	cout << endl;
	cout << "Testing Linear Hash Table, second method" << endl;
	TestingLinearHashTable2();
	cout << endl;
	cout << "Testing AddSlow Method" << endl;
	TestingAddSlow();
	return 0;
}

