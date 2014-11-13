/*
 * DLList.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef DLLIST_H_
#define DLLIST_H_

#include <string>
#include <iostream>

using namespace std;
namespace ods {

template<class T>
class DLList {
protected:
	struct Node {
		T x;
		Node *prev, *next;
	};
	Node dummy;
	int n;
	void remove(Node *w);
	Node* addBefore(Node *w, T x);
	Node* getNode(int i);
public:
	DLList();
	virtual ~DLList();
	int size() {
		return n;
	}
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual void add(T x) {
		add(size(), x);
	}
	virtual T remove(int i);
	virtual void clear();
	virtual bool IsPalindrome();
	virtual void Rotate(int r);
	virtual void Absorb(DLList<T>& l2);
	virtual void PrintList();
	virtual DLList<T> Deal();
};

// Constructor for DLList
template<class T>
DLList<T>::DLList() {
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
	Node *u = new Node;
	u->x = x;
	u->prev = w->prev;
	u->next = w;
	u->next->prev = u;
	u->prev->next = u;
	n++;
	return u;
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
	Node* p;
	if (i < n / 2) {
		p = dummy.next;
		for (int j = 0; j < i; j++)
			p = p->next;
	} else {
		p = &dummy;
		for (int j = n; j > i; j--)
			p = p->prev;
	}
	return (p);
}

// Destructor for DLList
template<class T>
DLList<T>::~DLList() {
	clear();
}

template<class T>
void DLList<T>::clear() {
	Node *u = dummy.next;
	while (u != &dummy) {
		Node *w = u->next;
		delete u;
		u = w;
	}
	n = 0;
}

template<class T>
void DLList<T>::remove(Node *w) {
	w->prev->next = w->next;
	w->next->prev = w->prev;
	delete w;
	n--;
}

template<class T>
T DLList<T>::get(int i) {
	return getNode(i)->x;
}

template<class T>
T DLList<T>::set(int i, T x) {
	Node* u = getNode(i);
	T y = u->x;
	u->x = x;
	return y;
}

template<class T>
void DLList<T>::add(int i, T x) {
	addBefore(getNode(i), x);
}

template<class T>
T DLList<T>::remove(int i) {
	Node *w = getNode(i);
	T x = w->x;
	remove(w);
	return x;
}

// Checks whether the items in the DLList are a palindrome
// Returns true if DLList is palindrome, false if it is not
template<class T>
bool DLList<T>::IsPalindrome() {
	// Two node pointers
	// Originally point to the first and last items in the list
	Node* tmp1 = dummy.next;
	Node* tmp2 = dummy.prev;

	// Loops through list and compares elements
	// starts with first and last elements
	// if elements aren't equal, returns false
	for (int i = 0; i < n / 2; i++) {
		if (tmp1->x != tmp2->x) {
			return false;
		}
		// increments tmp1 by 1 and decrements tmp2 by 1
		// moving towards center of list
		// continues through loop
		tmp1 = tmp1->next;
		tmp2 = tmp2->prev;
	}

	// if corresponding elements never unequal, returns true
	return true;
}

// Rotates DLList so item i becomes (i+r)%n
template<class T>
void DLList<T>::Rotate(int r) {
	// Node pointer to keep track of where to move dummy node
	Node* orig_first = dummy.next;
	Node* orig_last = dummy.prev;
	Node* new_first = getNode(size() - (r % size()));
	Node* new_last = new_first->prev;

	if ((r % n) != 0) { // checks whether list needs to be rotated
		// Removes dummy
		// Original first and last point to each other instead of dummy
		orig_first->prev = orig_last;
		orig_last->next = orig_first;

		// Changes position of dummy
		// New first and last now point to dummy node
		new_first->prev = &(dummy);
		new_last->next = &(dummy);
		// dummy node points to new first and last
		dummy.next = new_first;
		dummy.prev = new_last;
	}

}

// Empties l2 and appends it to function that calls absorb
template<class T>
void DLList<T>::Absorb(DLList<T>& l2) {
	// Node pointers that keep track of first and last items
	Node* l1_last_node = getNode(size() - 1);
	Node* l2_first_node = l2.getNode(0);
	Node* l2_last_node = l2.getNode(l2.size() - 1);

	// Appends first element of l2 to the end of original list
	// Thus, all of l2 is appended to original list
	l1_last_node->next = l2_first_node;
	l2_first_node->prev = l1_last_node;
	// sets original dummy.prev to point to last item in l2
	dummy.prev = l2_last_node;
	// sets last item in l2 to point to dummy
	l2_last_node->next = &dummy;
	// empties l2
	l2.dummy.prev = &(l2.dummy);
	l2.dummy.next = &(l2.dummy);
	// updates sizes of both lists
	n += l2.size();
	l2.n = 0;
}

// Prints out DLList elements in order
template<class T>
void DLList<T>::PrintList() {
	// sets node pointer to equals pointer to first node
	Node* print_value = getNode(0);

	if (size() > 0) {
		cout << print_value->x; // prints first element without comma in front
		// traverses through list updating pointer
		// prints out each value with comma in front
		for (int i = 1; i < size(); i++) {
			print_value = print_value->next;
			cout << ", ";
			cout << print_value->x;
		}
		cout << endl;
	}
}

template<class T>
DLList<T> DLList<T>::Deal() {

	DLList<T> l2;							// New list to return
	int orig_size = size();
	Node* temp = getNode(1);	//temp node pointer instantiated to first odd index
	Node* last_l2;
	Node* next_node;

	for (int i = 0; i < orig_size / 2; i++) {
		// updates temp node every time AFTER first iteration
		if (i > 0) {
			temp = next_node;
			if (temp->next == &(dummy)) // if temp is last index, exits loop
				break;
		}
		// updates sizes of original list and list that is returned
		l2.n++;
		n--;
		// removes temp node from original list
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		next_node = temp->next->next;

		// adds temp node on to list that is being returned
		last_l2 = l2.dummy.prev;
		last_l2->next = temp;
		temp->prev = last_l2;
		temp->next = &(l2.dummy);
		l2.dummy.prev = temp;
	}

	// runs if temp is last element and size of original list greater than 2
	if ((orig_size % 2) == 0 && orig_size > 2) {
		// sets last even element to point to dummy & dummy to point to element
		temp->prev->next = &dummy;
		dummy.prev = temp->prev;

		last_l2 = l2.dummy.prev;	// sets last_l2 to second to last element in l2
		last_l2->next = temp;			// update last_l2 to point to actual last element
		temp->prev = last_l2;			// actual last element prev to point to last_l2
		temp->next = &(l2.dummy);	// actual last element next to point to dummy
		l2.dummy.prev = temp;			// l2 dummy next to point to last element
		// updates size of l2 and original list
		l2.n++;
		n--;
	}
	return l2;
}

} /* namespace ods */
#endif /* DLLIST_H_ */
