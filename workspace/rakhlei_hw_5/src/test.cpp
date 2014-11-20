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

void testChainedHashTable(
		DataStructureTester<ChainedHashTable<int> > &chained_tester) {
	int random_add_sum = 0;
	int random_find_sum = 0;
	int random_remove_sum = 0;
	int sequential_add_sum = 0;
	int sequential_find_sum = 0;
	int sequential_remove_sum = 0;

	for (int i = 0; i < 20; i++) {
		srand(0);
		random_add_sum += chained_tester.DoRandomAdd(50000);
		srand(0);
		random_find_sum += chained_tester.DoRandomFind(50000);
		srand(0);
		random_remove_sum += chained_tester.DoRandomRemove(50000);
	}
	cout << "Chained Hash Table Averages in Milliseconds" << endl;
	cout << "Random add: " << random_add_sum / 20 << endl;
	cout << "Random find: " << random_find_sum / 20 << endl;
	cout << "Random remove: " << random_remove_sum / 20 << endl;

	for (int i = 0; i < 20; i++) {
		sequential_add_sum += chained_tester.DoSequentialAdd(1, 50000, 1);
		sequential_find_sum += chained_tester.DoSequentialFind(1, 50000, 1);
		sequential_remove_sum += chained_tester.DoSequentialRemove(1, 50000, 1);
	}
	cout << "Sequential add: " << sequential_add_sum / 20 << endl;
	cout << "Sequential find: " << sequential_find_sum / 20 << endl;
	cout << "Sequential remove: " << sequential_remove_sum / 20 << endl;
	cout << endl;

}

void testLinearHashTable(
		DataStructureTester<LinearHashTable<int> > &linear_tester) {
	int random_add_sum = 0;
	int random_find_sum = 0;
	int random_remove_sum = 0;
	int sequential_add_sum = 0;
	int sequential_find_sum = 0;
	int sequential_remove_sum = 0;

	for (int i = 0; i < 20; i++) {
		srand(0);
		random_add_sum += linear_tester.DoRandomAdd(50000);
		srand(0);
		random_find_sum += linear_tester.DoRandomFind(50000);
		srand(0);
		random_remove_sum += linear_tester.DoRandomRemove(50000);
	}
	cout << "Linear Hash Table Averages in Milliseconds" << endl;
	cout << "Random add: " << random_add_sum / 20 << endl;
	cout << "Random find: " << random_find_sum / 20 << endl;
	cout << "Random remove: " << random_remove_sum / 20 << endl;

	for (int i = 0; i < 20; i++) {
		sequential_add_sum += linear_tester.DoSequentialAdd(1, 50000, 1);
		sequential_find_sum += linear_tester.DoSequentialFind(1, 50000, 1);
		sequential_remove_sum += linear_tester.DoSequentialRemove(1, 50000, 1);
	}
	cout << "Sequential add: " << sequential_add_sum / 20 << endl;
	cout << "Sequential find: " << sequential_find_sum / 20 << endl;
	cout << "Sequential remove: " << sequential_remove_sum / 20 << endl;
	cout << endl;

}

void testBinarySearchTree(
		DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > &bst_tester) {
	int random_add_sum = 0;
	int random_find_sum = 0;
	int random_remove_sum = 0;
	int sequential_add_sum = 0;
	int sequential_find_sum = 0;
	int sequential_remove_sum = 0;

	for (int i = 0; i < 20; i++) {
		srand(0);
		random_add_sum += bst_tester.DoRandomAdd(50000);
		srand(0);
		random_find_sum += bst_tester.DoRandomFind(50000);
		srand(0);
		random_remove_sum += bst_tester.DoRandomRemove(50000);
	}
	cout << "Binary Search Tree Averages in Milliseconds" << endl;
	cout << "Random add: " << random_add_sum / 20 << endl;
	cout << "Random find: " << random_find_sum / 20 << endl;
	cout << "Random remove: " << random_remove_sum / 20 << endl;

	for (int i = 0; i < 20; i++) {
		sequential_add_sum += bst_tester.DoSequentialAdd(1, 50000, 1);
		sequential_find_sum += bst_tester.DoSequentialFind(1, 50000, 1);
		sequential_remove_sum += bst_tester.DoSequentialRemove(1, 50000, 1);
	}
	cout << "Sequential add: " << sequential_add_sum / 20 << endl;
	cout << "Sequential find: " << sequential_find_sum / 20 << endl;
	cout << "Sequential remove: " << sequential_remove_sum / 20 << endl;
	cout << endl;

}

void testRedBlackTree(
		DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > &red_black_tester) {
	int random_add_sum = 0;
	int random_find_sum = 0;
	int random_remove_sum = 0;
	int sequential_add_sum = 0;
	int sequential_find_sum = 0;
	int sequential_remove_sum = 0;

	for (int i = 0; i < 20; i++) {
		srand(0);
		random_add_sum += red_black_tester.DoRandomAdd(50000);
		srand(0);
		random_find_sum += red_black_tester.DoRandomFind(50000);
		srand(0);
		random_remove_sum += red_black_tester.DoRandomRemove(50000);
	}
	cout << "Red Black Tree Averages in Milliseconds" << endl;
	cout << "Random add: " << random_add_sum / 20 << endl;
	cout << "Random find: " << random_find_sum / 20 << endl;
	cout << "Random remove: " << random_remove_sum / 20 << endl;

	for (int i = 0; i < 20; i++) {
		sequential_add_sum += red_black_tester.DoSequentialAdd(1, 50000, 1);
		sequential_find_sum += red_black_tester.DoSequentialFind(1, 50000, 1);
		sequential_remove_sum += red_black_tester.DoSequentialRemove(1, 50000, 1);
	}
	cout << "Sequential add: " << sequential_add_sum / 20 << endl;
	cout << "Sequential find: " << sequential_find_sum / 20 << endl;
	cout << "Sequential remove: " << sequential_remove_sum / 20 << endl;
	cout << endl;

}

int main() {

	DataStructureTester<ChainedHashTable<int> > chained_tester;
	DataStructureTester<LinearHashTable<int> > linear_tester;
	DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > bst_tester;
	DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > red_black_tester;

	testChainedHashTable(chained_tester);
	testLinearHashTable(linear_tester);
	testRedBlackTree(red_black_tester);
	testBinarySearchTree(bst_tester);

	return 0;
}
