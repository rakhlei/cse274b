//============================================================================
// Name        : rakhlei_hw_2.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DLList.h"
using namespace std;

using namespace ods;
void TestingIsPalindrome() {
	cout << "TESTING IsPalindrome()" << endl;
	DLList<char> dllist;
	dllist.add('i');
	dllist.add('r');
	dllist.add('i');
	dllist.add('n');
	dllist.add('a');
	dllist.PrintList();
	cout << "Is this a palindrome? " << dllist.IsPalindrome() << endl;

	DLList<char> dllist2;
	dllist2.add('a');
	dllist2.add('n');
	dllist2.add('n');
	dllist2.add('a');
	dllist2.PrintList();
	cout << "Is this a palindrome? " << dllist2.IsPalindrome() << endl;

	DLList<char> dllist3;
	dllist3.add('a');
	dllist3.add('n');
	dllist3.add('b');
	dllist3.add('n');
	dllist3.add('a');
	dllist3.PrintList();
	cout << "Is this a palindrome? " << dllist3.IsPalindrome() << endl;

	DLList<char> dllist4;
	dllist4.add('a');
	dllist4.add('b');
	dllist4.add('c');
	dllist4.PrintList();
	cout << "Is this a palindrome? " << dllist4.IsPalindrome() << endl;

	cout << endl;
}

void TestingAbsorb() {
	cout << "TESTING Absorb(l2)" << endl;
	DLList<int> absorb1;
	absorb1.add(1);
	absorb1.add(3);
	absorb1.add(5);
	absorb1.add(7);

	DLList<int> absorb2;
	absorb2.add(21);
	absorb2.add(23);
	absorb2.add(25);
	absorb2.add(27);

	cout << "Before" << endl;
	cout << "l1: ";
	absorb1.PrintList();
	cout << "l2: ";
	absorb2.PrintList();

	absorb1.Absorb(absorb2);
	cout << "After call" << endl;

	cout << "l1: ";
	absorb1.PrintList();
	cout << "l2: ";
	cout << endl;
	absorb2.PrintList();

	cout << endl;
}

void TestingRotate() {
	DLList<int> rotate;
	rotate.add(15);
	rotate.add(25);
	rotate.add(62);
	rotate.add(3);
	rotate.add(43);
	rotate.add(79);
	rotate.add(31);
	cout << "TESTING Rotate()" << endl;
	cout << "Before" << endl;
	rotate.PrintList();
	rotate.Rotate(25);
	cout << "After calling Rotate(25)" << endl;
	rotate.PrintList();
	rotate.Rotate(0);
	cout << "After calling Rotate(0)" << endl;
	rotate.PrintList();
	rotate.Rotate(2);
	cout << "After calling Rotate(2)" << endl;
	rotate.PrintList();

	cout << endl;
}

void TestingDeal() {
	cout << "TESTING Deal()" << endl;
	DLList<char> list1;
	list1.add('a');
	list1.add('b');
	list1.add('c');
	list1.add('d');
	list1.add('e');
	list1.add('f');

	cout << "Original list (odd number of elements)" << endl;
	list1.PrintList();
	cout << "list2 that is returned" << endl;
	list1.Deal().PrintList();
	cout << "Original list after Deal" << endl;
	list1.PrintList();

	DLList<char> list2;
	list2.add('a');
	list2.add('b');
	list2.add('c');
	list2.add('d');
	list2.add('e');

	cout << "Original list (even number of elements)" << endl;
	list2.PrintList();
	cout << "list2 that is returned" << endl;
	list2.Deal().PrintList();
	cout << "Original list after Deal" << endl;
	list1.PrintList();

}

int main() {

	TestingIsPalindrome();
	TestingAbsorb();
	TestingRotate();
	TestingDeal();

	return 0;
}

