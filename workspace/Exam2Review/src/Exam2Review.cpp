//============================================================================
// Name        : Exam2Review.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SLList.h"
#include "DLList.h"
using namespace std;
using namespace ods;

int main() {

	SLList<int> tester;
	tester.add(1);
	tester.add(2);
	tester.add(3);
	tester.add(4);
	tester.PrintList();

	cout << tester.secondLast() << endl;
	cout << tester.get(4) << endl;
	cout << tester.set(4, 10) << endl;
	tester.PrintList();
	cout << tester.get(1) << endl;
	cout << tester.set(3, 7) << endl;
	tester.PrintList();
	cout << tester.get(3) << endl;
	cout << tester.secondLast() << endl;
	cout << tester.add(20, 12) << endl;
	tester.PrintList();
	cout << tester.remove(3) << endl;
	tester.PrintList();

	DLList<int> tester2;
	tester2.add(1);
	tester2.add(2);
	tester2.add(3);
	tester2.add(4);
	tester2.add(5);
	tester2.add(6);
	tester2.add(7);
	tester2.add(8);
	tester2.PrintList();
	tester2.reverse();
	tester2.PrintList();
	tester2.Truncate(7);
	tester2.PrintList();
	tester2.Replace(4, 6);
	tester2.PrintList();

	return 0;
}
}

