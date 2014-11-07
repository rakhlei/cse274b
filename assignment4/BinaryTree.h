/*
 * BinaryTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <cstdlib>

#include "ArrayDeque.h"
using namespace std;

namespace ods {

template<class N>
class BTNode {
public:
	N *left;
	N *right;
	N *parent;
	BTNode() {
		left = right = parent = NULL;
	}
};

template<class Node>
class BinaryTree {
protected:
	Node *r;    // root node
	Node *nil;  // null-like node
	virtual int size(Node *u);
	virtual int height(Node *u);
	virtual void traverse(Node *u);
public:
	virtual ~BinaryTree();
	BinaryTree();
	BinaryTree(Node *nil);
	virtual void clear();
	virtual int depth(Node *u);
	virtual int size();
	virtual int size2();
	virtual int height();
	virtual void traverse();
	virtual void traverse2();
	virtual void bfTraverse();
	virtual int height2(Node* u);
	virtual bool isBalanced();
	virtual int isBalanced(Node* u);
};

class BTNode1: public BTNode<BTNode1> {
};

template<class Node>
BinaryTree<Node>::~BinaryTree() {
	clear();
}

template<class Node>
void BinaryTree<Node>::clear() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		if (next == u->parent)
			delete u;
		u = next;
	}
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree(Node *nil) {
	this->nil = nil;
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree() {
	nil = NULL;
	r = nil;
}

template<class Node>
int BinaryTree<Node>::depth(Node *u) {
	int d = 0;
	while (u != r) {
		u = u->parent;
		d++;
	}
	return d;
}

template<class Node>
int BinaryTree<Node>::size() {
	return size(r);
}

template<class Node>
int BinaryTree<Node>::size(Node *u) {
	cout << u->x << endl;
	if (u == nil)
		return 0;

	return 1 + size(u->left) + size(u->right);
}

template<class Node>
int BinaryTree<Node>::size2() {
	Node *u = r, *prev = nil, *next;
	int n = 0;
	while (u != nil) {
		if (prev == u->parent) {
			n++;
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
	return n;
}

template<class Node>
int BinaryTree<Node>::height() {
	return height2(r);
}

template<class Node>
int BinaryTree<Node>::height(Node *u) {
	if (u == nil)
		return -1;
	cout << u->x << endl;
	return 1 + max(height(u->left), height(u->right));
}

template<class Node>
void BinaryTree<Node>::traverse() {
	traverse(r);
}

template<class Node>
void BinaryTree<Node>::traverse(Node *u) {
	if (u == nil)
		return;
	traverse(u->left);
	traverse(u->right);
}

template<class Node>
void BinaryTree<Node>::traverse2() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
}

template<class Node>
void BinaryTree<Node>::bfTraverse() {
	ArrayDeque<Node*> q;
	if (r != nil)
		q.add(q.size(), r);
	while (q.size() > 0) {
		Node *u = q.remove(q.size() - 1);
		if (u->left != nil)
			q.add(q.size(), u->left);
		if (u->right != nil)
			q.add(q.size(), u->right);
	}
}


// method calculated the height of a node non-recursively
template<class Node>
int BinaryTree<Node>::height2(Node* u) {
	int height = 0; // starts with height = 0
	int offset = 0; // if offset = 0, height increases, else doesn't
	Node *prev = u->parent, *next;
	Node *n = u;

	// while we are descending the tree
	while (n != u->parent) {

		if (prev == n->parent) {
			if (n->left != nil) {
				next = n->left;
				if (offset == 0) // increase height because descending
					height++;
				else
					offset--; // decrease offset so it can get back to 0
			} else if (n->right != nil) {
				next = n->right;
				if (offset == 0) // increase height because
					height++;
				else
					offset--; // decrease offset so it can get back to 0
			} else {
				next = n->parent;
				offset++; // increase offset b/c traveling up so don't increase height
			}

		}
		// going back up from left
		else if (prev == n->left) {
			if (n->right != nil) {
				next = n->right;
				if (offset == 0)
					height++;
				else
					offset--; // decrease offset so it can get back to 0
			}
			// going back up from right
			else {
				next = n->parent;
				offset++; // increase offset b/c traveling up so don't increase height
			}
		}

		else {
			next = n->parent;
			offset++; // increase offset b/c traveling up so don't increase height
		}
		prev = n;
		n = next;
	}

	return height;

}

// checks whether tree is balanced recursively
template<class Node>
bool BinaryTree<Node>::isBalanced() {
	// if recursive function returns -2
	// then tree is not balanced
	if (isBalanced(r) == -2)
		return false;
	// if doesn't return -2, then tree is balanced
	else
		return true;
}

template<class Node>
int BinaryTree<Node>::isBalanced(Node* u) {
	if (u == nil) {
		return 0;
	}
	int left_size = isBalanced(u->left);
	int right_size = isBalanced(u->right);
	// if found that different is greater than 2 (specified by -2)
	// then return -2
	if (left_size == -2 || right_size == -2)
		return -2;
	else {
		// if difference is less than 2, return size
		if (abs(left_size - right_size) < 2)
			return 1 + left_size + right_size;
		else
			// if difference greater than 2, return -2
			return -2;
	}

}

} /* namespace ods */
#endif /* BINARYTREE_H_ */
