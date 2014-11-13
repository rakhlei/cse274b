/*
 * treque.h
 *
 *  Created on: Sep 10, 2014
 *      Author: Irina Rakhlenko
 */

#ifndef TREQUE_H_
#define TREQUE_H_
#include "array.h"
#include "ArrayDeque.h"
#include "utils.h"


// Triple ended queue utilizes two ArrayDeque objects and implements List Interface
// Modifications fast if near either end or near middle the list

using namespace std;
namespace ods {

template<class T>
class Treque {
protected:
	ArrayDeque<T> front_array_;
	ArrayDeque<T> back_array_;

public:
	Treque();
	virtual ~Treque();
	int size();
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual T remove(int i);
	virtual void Balance();
	virtual void CheckBalance();
	virtual void Clear();
};

// constructor that instantiates front and back ArrayDeque
template<class T>
Treque<T>::Treque() :
		front_array_(), back_array_() {
}

// empty destructor
template<class T>
Treque<T>::~Treque() {
}

// returns total number of elements in treque by summing elements in both ArrayDeque
template<class T>
int Treque<T>::size() {
	return (front_array_.size() + back_array_.size());
}

// returns element at index i of list
template<class T>
T Treque<T>::get(int i) {
	if (i < front_array_.size())
		return front_array_.get(i);
	else
		return back_array_.get(i - front_array_.size());
}

// sets element x at index i of list
template<class T>
T Treque<T>::set(int i, T x) {
	if (i < front_array_.size())
		front_array_.set(i, x);
	else
		back_array_.set(i - front_array_.size());
}

// removes element at index i in list
template<class T>
T Treque<T>::remove(int i) {
	if (i < front_array_.size()) {
		Balance();
		CheckBalance();
		return front_array_.remove(i);
	}

	else {
		Balance();
		CheckBalance();
		return back_array_.remove(i - front_array_.size());
	}
}

// prints out the front and back ArrayDeque sizes
// to confirm balance method executed properly
template<class T>
void Treque<T>::CheckBalance() {
	cout << "front size: " << front_array_.size() << endl;
	cout << "back size: " << back_array_.size() << "\n" << endl;
}

// clears the front and back ArrayDeque
template<class T>
void Treque<T>::Clear() {
	front_array_.clear();
	back_array_.clear();
}

// adds element x to index i in list
template<class T>
void Treque<T>::add(int i, T x) {
	if (i < front_array_.size()) {
		front_array_.add(i, x);
	} else {
		back_array_.add(i - front_array_.size(), x);
	}
	Balance();
	CheckBalance();
}

// checks to see if dequeue arrays are same size
// moves elements from one array to the other if not equal
// one array never is never 2 or more elements larger than the other
template<class T>
void Treque<T>::Balance() {
	int nums_move;
	int index_move;
	T val_move;

	// checks whether more elements in front
	if (front_array_.size() > back_array_.size()) {
		nums_move = front_array_.size() - size() / 2;
		index_move = size() / 2;

		// moves elements from front ArrayDeque to back
		for (int i = 0; i < nums_move; i++) {
			val_move = front_array_.get(index_move);
			back_array_.add(i, val_move);
			front_array_.remove(index_move);
			index_move++;
		}

	}

	// checks whether more elements in back
	if (front_array_.size() < back_array_.size()) {
		nums_move = (size() / 2) - front_array_.size();
		index_move = front_array_.size();

		// moves elements from back ArrayDeque to front
		for (int i = 0; i < nums_move; i++) {
			val_move = back_array_.get(i);
			front_array_.add(index_move, val_move);
			back_array_.remove(i);
			index_move++;
		}

	}

}

}

#endif /* TREQUE_H_ */
