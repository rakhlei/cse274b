/*
 * DataStructureTester.h
 *
 *  Created on: Nov 10, 2014
 *      Author: Irina
 */

#ifndef DATASTRUCTURETESTER_H_
#define DATASTRUCTURETESTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctime>
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "List.h"

namespace ods {
template<class L>
class DataStructureTester {
	clock_t t_;
protected:
	L list;
public:
	DataStructureTester() {
		srand(0);
		t_ = -1;
	}
	~DataStructureTester() {
	}
	int DoSequentialAdd(int start, int end, int step);
	int DoRandomAdd(int n);
	int DoSequentialRemove(int start, int end, int step);
	int DoRandomRemove(int n);
	int DoSequentialFind(int start, int end, int step);
	int DoRandomFind(int n);
};

template<class L>
int DataStructureTester<L>::DoSequentialAdd(int start, int end, int step) {

	t_ = clock();
	for (int i = start; i <= end; i += step) {
		list.add(i);
	}
	t_ = clock() - t_;

	return ((float) t_) / CLOCKS_PER_SEC * 1000;
}

template<class L>
int DataStructureTester<L>::DoRandomAdd(int n) {
	//srand(0);
	t_ = clock();
	for (int i = 0; i < n; i++) {
		int x = rand() % 100000;
		list.add(x);
	}
	t_ = clock() - t_;
	return (float) t_ / CLOCKS_PER_SEC * 1000;

}

template<class L>
int DataStructureTester<L>::DoSequentialRemove(int start, int end, int step) {
	t_ = clock();
	for (int i = start; i <= end; i += step) {
		list.remove(i);
	}
	t_ = clock() - t_;
	return (float) t_ / CLOCKS_PER_SEC * 1000;
}

template<class L>
int DataStructureTester<L>::DoRandomRemove(int n) {
	t_ = clock();
	srand(0);
	for (int i = 0; i < n; i++) {
		int x = rand();
		list.remove(x);
		//cout << x << endl;
	}
	t_ = clock() - t_;
	return (float) t_ / CLOCKS_PER_SEC * 1000;
}

template<class L>
int DataStructureTester<L>::DoSequentialFind(int start, int end, int step) {
	t_ = clock();
	for (int i = start; i <= end; i += step) {
		list.find(i);
	}
	t_ = clock() - t_;
	return (float) t_ / CLOCKS_PER_SEC * 1000;
}

template<class L>
int DataStructureTester<L>::DoRandomFind(int n) {
	t_ = clock();
	//srand(0);
	for (int i = 0; i < n; i++) {
		int x = rand();
		list.find(x);
	}
	t_ = clock() - t_;
	return (float) t_ / CLOCKS_PER_SEC * 1000;
}
}

#endif /* DATASTRUCTURETESTER_H_ */
