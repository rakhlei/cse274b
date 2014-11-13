/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "array.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

	static const int w = 32;
	static const int r = 8;
	array<T> t;
	array<T> u;
	int n;   // total number values in both backing arrays
	int q;   // total number non-null entries in both backing arrays
	   // total length = 2^d
	int z;	// random number
	T null, del;
	void resize();
	int hash1(T x) {
		return ((unsigned) ((z * 3) * x)) % ((2) * 1 << d);
	}
	int hash2(T x) {
		return 1 + (hash1(x) % (((2) * 1 << d) - 1));
	}
	// Sample code for the book only -- never use this
	/*
	 int idealHash(T x) {
	 return tab[hashCode(x) >> w-d];
	 }
	 */

public:
	int d;
	// FIXME: get rid of default constructor
	LinearHashTable();
	LinearHashTable(T null, T del);
	virtual ~LinearHashTable();
	bool add(T x);
	bool addSlow(T x);
	T remove(T x);
	T find(T x);
	int size() {
		return n;
	}
	void clear();
	// FIXME: yuck
	void setNull(T null) {
		this->null = null;
		t.fill(null);
	}
	void setDel(T del) {
		this->del = del;
	}
	void PrintTable();
	void EvenlyLoaded();
};

/*
 template<>
 LinearHashTable<int>::LinearHashTable() : t(2, INT_MIN) {
 null = INT_MIN;
 del = INT_MIN + 1;
 n = 0;
 q = 0;
 d = 1;
 }
 */

/**
 * FIXME: Dangerous - leaves null and del uninitialized
 */
template<class T>
LinearHashTable<T>::LinearHashTable() :
		t(2) {
	/*
	 this->null = null;
	 this->del = del;
	 */
	srand(time(NULL));
	n = 0;
	q = 0;
	d = 1;
	z = rand() | 1;     // is a random odd integer
}
/**
 * Constructor which accepts value for null and delete
 */
template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) :
		t(2, null), u(2, null) {
	this->null = null;
	this->del = del;
	n = 0;
	q = 0;
	d = 1;
	z = rand() | 1;     // is a random odd integer
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
	// val is the element we are working with
	// initialized to equal null
	T val = null;
	// probe initialized to an arbitrary odd value
	int probe = -60;
	d = 1;
	while ((1 << d) < 3 * n)
		d++;
	// splits total size in half in order to store in 2 arrays
	int new_size = (1 << d) / 2;
	array<T> tnew(new_size, null);
	array<T> unew(new_size, null);
	int total_length = t.length + u.length;
	int new_total_length = tnew.length + unew.length;
	q = n;
	// insert everything into tnew and unew
	for (int k = 0; k < total_length; k++) {
		// sets val = item working with
		if (k < t.length)
			val = t[k];
		else
			val = u[k - t.length];

		// go into loop if val is not null or delete
		if ((val != null) && (val != del)) {
			int i = 0;
			probe = (hash1(val) + (i * hash2(val))) % (new_total_length);

			// loops continues until empty spot found in new arrays
			while (((probe < tnew.length) && (tnew[probe] != null))
					|| ((probe >= tnew.length) && (unew[probe - tnew.length] != null))) {
				i = (i == new_total_length - 1) ? 0 : i + 1; // increment i
				probe = (hash1(val) + (i * hash2(val))) % (new_total_length); // DOUBLE HASHING IMPLEMENTATION
			}

			// places value into new array
			if (probe < tnew.length)
				tnew[probe] = val;
			else if (probe >= tnew.length)
				unew[probe - tnew.length] = val;

		}

	}

	t = tnew;
	u = unew;
}

/**
 * Clears both backing arrays
 */
template<class T>
void LinearHashTable<T>::clear() {
	n = 0;
	q = 0;
	d = 1;
	array<T> tnew(2, null);
	array<T> unew(2, null);
	t = tnew;
	u = unew;
}

/**
 * If value not already in table, adds to correct backing array
 */
template<class T>
bool LinearHashTable<T>::add(T x) {
	int total_length = t.length + u.length;
	if (find(x) != null)
		return false;
	if (2 * (q + 1) > total_length)
		resize();   // max 50% occupancy
	int i = 0;
	int probe = (hash1(x) + (i * hash2(x))) % (total_length);

	// continues loop while value at given probe equals null or delete
	while ((probe < t.length && t[probe] != null && t[probe] != del)
			|| (probe >= t.length && u[probe - t.length] != null
					&& u[probe - t.length] != del)) {
		i = (i == total_length - 1) ? 0 : i + 1; // increment i
		probe = (hash1(x) + (i * hash2(x))) % (total_length); // DOUBLE HASHING IMPLEMENTATION
	}

	// add value to correct backing array
	if (probe < t.length) {
		if (t[probe] == null)
			q++;
		t[probe] = x;
	}
	// add value to correct backing array
	if (probe >= t.length) {
		if (u[probe - t.length] == null)
			q++;
		u[probe - t.length] = x;
	}

	n++;
	return true;
}
/**
 * Searches to see if value is present in hash table
 */
template<class T>
T LinearHashTable<T>::find(T x) {

	int total_length = t.length + u.length;
	int i = 0;
	int probe = (hash1(x) + (i * hash2(x))) % (total_length);

	// loops while value at probe doesn't equal null
	while ((probe < t.length && t[probe] != null)
			|| (probe >= t.length && u[probe - t.length] != null)) {

		// if value at probe != del and == value search for, return value at probe
		if (probe < t.length && t[probe] != del && t[probe] == x)
			return t[probe];

		// if value at probe != del and == value search for, return value at probe
		if (probe >= t.length && u[probe - t.length != del] && u[probe - t.length] == x)
			return u[probe - t.length];

			// if not, update probe and continue through loop
			i = (i == total_length - 1) ? 0 : i + 1; // increment i
			probe = (hash1(x) + (i * hash2(x))) % (total_length); // DOUBLE HASHING IMPLEMENTATION

	}
	// value never found so return null
	return null;
}

/**
 * Removes designated value from table
 */
template<class T>
T LinearHashTable<T>::remove(T x) {
	T val = null;
	int total_length = t.length + u.length;
	int i = 0;
	int probe = (hash1(x) + (i * hash2(x))) % (total_length);
	if (probe < t.length)
		val = t[probe];
	else
		val = u[probe - t.length];

	// continues through loop while value at probe != null
	while (val != null) {
		T y = val;
		// sets value at probe to del value
		if (y != del && x == y) {
			if (probe < t.length)
				t[probe] = del;
			if (probe >= t.length)
				u[probe - t.length] = del;
			n--;
			if (8 * n < total_length)
				resize(); // min 12.5% occupancy
			return y;
		}
		// updates probe
		i = (i == total_length - 1) ? 0 : i + 1; // increment i
		probe = (hash1(x) + (i * hash2(x))) % (total_length); // DOUBLE HASHING IMPLEMENTATION
		// updates val
		if (probe < t.length)
			val = t[probe];
		else
			val = u[probe - t.length];

	}
	// if value == null nothing to remove so return null
	return null;
}

/**
 * Adds element to correct array
 */
template<class T>
bool LinearHashTable<T>::addSlow(T x) {
	T val;
	int total_length = t.length + u.length;
	if (2 * (q + 1) > total_length)
		resize();   // max 50% occupancy
	int i = 0;
	int probe = (hash1(x) + (i * hash2(x))) % (total_length);

	// sets val equal to element at probe
	if (probe < t.length)
		val = t[probe];
	else
		val = u[probe - t.length];

	// continues through loop while element at probe not empty
	while (val != null) {
		// returns false if value already present in table
		if (val != del && x == val)
			return false;
		i = (i == t.length - 1) ? 0 : i + 1; // increment i
		probe = (hash1(x) + (i * hash2(x))) % (1 << d); // DOUBLE HASHING IMPLEMENTATION
		if (probe < t.length)
			val = t[probe];
		else
			val = u[probe - t.length];
	}
	// sets value in appropriate array
	if (probe < t.length)
		t[probe] = x;
	else if (probe >= t.length)
		u[probe - t.length] = x;
	n++;
	q++;
	return true;
}

/**
 * Print out entire table
 * Iterates through both backing arrays
 */
template<class T>
void LinearHashTable<T>::PrintTable() {
	for (int i = 0; i < t.length; i++) {
		cout << t[i] << ", ";
	}
	for (int i = 0; i < u.length; i++) {
		cout << u[i] << ", ";
	}
	cout << endl;

}

/**
 * Counts and prints number of nulls in each backing array
 */
template<class T>
void LinearHashTable<T>::EvenlyLoaded() {
	int null_t = 0;
	int values_t = 0;
	int null_u = 0;
	int values_u = 0;
	for (int i = 0; i < t.length; i++) {
		if (t[i] == null)
			null_t++;
		if (t[i]!=null && t[i]!=del)
			values_t++;
	}

	for (int i = 0; i < u.length; i++) {
		if (u[i] == null)
			null_u++;
		if (u[i]!=null && u[i]!=del)
					values_u++;
	}

	cout << "voids in list t: " << null_t << endl;
	cout << "voids in list u: " << null_u << endl;
	cout << "values in list t: " << values_t << endl;
	cout << "values in list u: " << values_u << endl;
}

} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
