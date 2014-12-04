//============================================================================
// Name        : rahklei_hw_6.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryHeap.h"
using namespace std;
using namespace ods;

int main() {
	BinaryHeap<int> tester;
	cout << "original heap" << endl;
	tester.add(4);
	tester.add(9);
	tester.add(17);
	tester.add(26);
	tester.add(19);
	tester.add(69);
	tester.add(32);
	tester.add(93);
	tester.add(6);
	tester.add(8);
	tester.add(16);
	tester.add(55);
	tester.add(50);
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(5)" << endl;
	tester.remove(5);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(2)" << endl;
	tester.remove(2);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(7)" << endl;
	tester.remove(7);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(6)" << endl;
	tester.remove(6);
	tester.print();
	cout << "remove(3)" << endl;
	tester.remove(3);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(4)" << endl;
	tester.remove(4);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(1)" << endl;
	tester.remove(2);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	cout << tester.checkHeap() << endl;
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	cout << tester.checkHeap() << endl;
	tester.print();


	BinaryHeap<int> tester2;
	for (int i = 1000; i < 2000; i++){
		tester2.add(i);
	}

	int counter = 0;
	for (int i = 0; i < 1000; i++){
		tester2.remove(i);
		if (tester2.checkHeap()) counter++;
	}
	cout << "After 1000 adds() and removes(), heap property maintained " << counter << " times" << endl;




	return 0;
}
