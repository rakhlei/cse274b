/*
 * SLList.h
 *
 *  Created on: 2011-11-25
 *      Author: morin
 *       FIXME: This code is completely untested (but was ported from tested Java code)
 */

#ifndef SLLIST_H_
#define SLLIST_H_
#include <stdlib.h>

using namespace std;

namespace ods {

template<class T>
class SLList {
	T null;
protected:
	class Node {
	public:
		T x;
		Node *next;
		Node(T x0) {
			x = 0;
			next = NULL;
		}
	};
	Node *head;
	Node *tail;
	int n;

public:

	SLList() {
		null = (T)NULL;
		n = 0;
		head = tail = NULL;
	}

	virtual ~SLList() {
		Node *u = head;
		while (u != NULL) {
			Node *w = u;
			u = u->next;
			delete w;
		}
	}

	int size() {
		return n;
	}

	T peek() {
		return head->x;
	}

	bool add(T x) {
		Node *u = new Node(x);
		u->x = x;
		if (n == 0) {
			head = u;
		} else {
			tail->next = u;
		}
		tail = u;
		n++;
		return true;
	}

	T push(T x) {
		Node *u = new Node(x);
		u->next = head;
		head = u;
		if (n == 0)
			tail = u;
		n++;
		return x;
	}

	T remove() {
		if (n == 0)	return null;
		T x = head->x;
		Node *u = head;
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}

	T pop() {
		if (n == 0)	return null;
		T x = head->x;
		Node *u = head;
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}

	T secondLast(){
		Node *u = head;
		if (u == tail) return -1;
		if (u->next == tail) return u->x;
		while (u->next != tail){
			u = u->next;
		}
		return u->x;
	}

	bool add(int i, T x){
		if (i > n-1) i = n;
		Node* u = new Node(x);
		Node* temp = head;
		if (i == 0) return push(x);
		for (int y = 0; y < i; y++){
			if (y == i-1){
				u->next = temp->next;
				temp->next = u;
				u->x = x;
				n++;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	bool set(int i, T x){
		if (i > n-1) return false;
		Node *u = head;
		for (int y = 0; y < i + 1; y++){
			if (y==i){
				u->x = x;
				return true;
			}
			u = u->next;
		}
		return false;
	}

	T get(int i){
		Node *u = head;
		if (i > n-1) return -1;
		for (int y = 0; i < i+1; y++){
			if (y == i) return u->x;
			u = u->next;
		}
		return -1;
	}

	bool remove(int i){
		if (i == 0) return pop();
		if (i > n-1) return false;
		Node* u = head;
		for (int y = 0; y < i+1; y++){
			if (y == (i-1) && (u->next != tail)){
				u-> next = u->next->next;
				n--;
				return true;
			}
			else if (y == i-1 && u->next == tail){
				tail = u;
				u->next->next = NULL;
				n--;
				return true;
			}
			u = u->next;
		}
		return false;
	}


	void PrintList() {
		// sets node pointer to equals pointer to first node
		Node* print_value = head;

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




};

} /* namespace ods */
#endif /* SLLIST_H_ */
