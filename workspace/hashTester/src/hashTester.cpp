//============================================================================
// Name        : hashTester.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <iostream>
using namespace std;

int hash(int x) {
	srand(1);
	int z = (rand() | 1);
		int y = (rand() % 100 + 1);
	return ((unsigned) (z * x) % 100);
}

int main() {
	srand(1);

	int hashArray[100];
	int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0,
			seven = 0, eight = 0, nine = 0;
	for (int i = 0; i < 100; i++) {
		int x = rand();
		if (hash(x) < 10)
			zero++;
		else if (hash(x) < 20)
			one++;
		else if (hash(x) < 30)
			two++;
		else if (hash(x) < 40)
			three++;
		else if (hash(x) < 50)
			four++;
		else if (hash(x) < 60)
			five++;
		else if (hash(x) < 70)
			six++;
		else if (hash(x) < 80)
			seven++;
		else if (hash(x) < 90)
			eight++;
		else if (hash(x) < 100)
			nine++;

		//cout << hash(x) << endl;
	}

	cout << zero << endl;
	cout << one << endl;
	cout << two << endl;
	cout << three << endl;
	cout << four << endl;
	cout << five << endl;
	cout << six << endl;
	cout << seven << endl;
	cout << eight << endl;
	cout << nine << endl;

	return 0;
}


