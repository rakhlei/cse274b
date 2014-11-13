/*
 * List.h
 *
 *  Created on: Nov 11, 2014
 *      Author: Irina
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// this is an abstract class
// interface that FORCES each subclass to have find, remove, and add

namespace ods {

template<class T>
class List {
public:
	//virtual ~List();
	virtual T find(T x)=0;
	virtual T remove(T x)=0;
	virtual bool add(T x)=0;
};
}

#endif /* LIST_H_ */
