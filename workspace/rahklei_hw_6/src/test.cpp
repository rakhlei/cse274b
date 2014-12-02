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
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	tester.print();
	cout << "remove(5)" << endl;
	tester.remove(5);
	tester.print();
	cout << "remove(2)" << endl;
	tester.remove(2);
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	tester.print();
	cout << "remove(7)" << endl;
	tester.remove(7);
	tester.print();
	cout << "remove(6)" << endl;
	tester.remove(6);
	tester.print();
	cout << "remove(3)" << endl;
	tester.remove(3);
	tester.print();
	cout << "remove(4)" << endl;
	tester.remove(4);
	tester.print();
	cout << "remove(1)" << endl;
	tester.remove(2);
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	tester.print();
	cout << "remove(0)" << endl;
	tester.remove(0);
	tester.print();
	return 0;
}