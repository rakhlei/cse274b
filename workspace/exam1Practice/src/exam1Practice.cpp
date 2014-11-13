//============================================================================
// Name        : exam1Practice.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void foo(int& x){
	cout << x << endl;
	++(x);
}

int main() {
	/*
	int i = 15,j,*p,*q;
	p = &i;
	cout << "p= " << p << endl;
	*p = 20;
	cout << "*p= " << *p << endl;
	cout << "i= " << i << endl;
	j = 2**p;
	cout << "j= " << j << endl;
	q = &i;
	cout << "q= " << q << endl;
	*p = *q-1;
	cout << "*p= " << *p << endl;
	cout << "i= " << i << endl;
	q = &j;
	cout << "q= " << q << endl;
	*p = *q-1;
	cout << "*p= " << *p << endl;
	cout << "i= " << i << endl;


	int nNumber;
	int *pPointer;
	nNumber = 15;
	pPointer = &nNumber;
	cout << nNumber << endl;
	*pPointer = 25;
	cout << nNumber << endl;

	int i;
	int *p;
	p = &i;
	cout << p << endl;

	int *p1 = new int;
	int *p2 = new int[3];

	int* q;
	*q=25;
*/

int i = 10;
foo(i);
cout << i << endl;


	return 0;
}
