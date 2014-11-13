/*
 * DLList.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef DLLIST_H_
#define DLLIST_H_

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
	virtual void reverse();
	virtual void PrintList();
	virtual void Truncate(int i);
	virtual void Replace(int i, int new_pos);
};

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
	if (i > n - 1)
		return -1;
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

template<class T>
void DLList<T>::reverse() {
	Node *u = &dummy;
	Node *temp;
	do {
		temp = u->next;
		u->next = u->prev;
		u->prev = temp;
		u = u->prev;
	} while (u != &dummy);
	//u = head;
	//head = tail;
	//tail = u;

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
void DLList<T>::Truncate(int i) {

	DLList<T> l2;

	Node *u = &dummy;
	Node *u2 = &l2.dummy;

	if (i <= n / 2) {
		for (int y = 0; y < i; y++) {
			u = u->next;
		}

		n = i;
		u->next = &dummy;
		dummy.prev = u;
	} else if (i > n / 2 && i < n) {
		u = u->prev;
		for (int y = 0; y < i - n / 2; y++) {
			u->prev->next = u->next;
			u = u->prev;
			if (i == size() - 1)
				break;
		}
		n = i;
	}

}

template<class T>
void DLList<T>::Replace(int i, int new_pos) {
	Node* u = &dummy;
	for (int y = 0; y < i + 1; y++) {
		u = u->next;
		if (y == i) {
			u->prev->next = u->next;
			u->next->prev = u->prev;
		}
	}
	Node* w = &dummy;

	if (new_pos > size()-1) return;
	if (new_pos == size()-1)
	for (int j = 0; j < new_pos+1; j++){
		w = w->next;
		if (j == new_pos){
			w->prev->next = u;
			u->prev = w->prev;
			if (j == size()-1){
				w->next = u;
				u->prev = w;
				u->next = &dummy;
				dummy.prev = u;
			}
			else{
			w->prev = u;
			u->next = w;}
		}
	}

} /* namespace ods */
#endif /* DLLIST_H_ */
