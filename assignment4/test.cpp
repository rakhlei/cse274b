//============================================================================
// Name        : rakhlei_hw_4.cpp
// Author      : IrinaRakhlenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
using namespace std;
using namespace ods;

void testPart1() {
	cout << "Part 1" << endl;
	BinarySearchTree<BSTNode1<int>, int> tree;
	tree.add(15);
	tree.add(5);
	tree.add(16);
	tree.add(3);
	tree.add(12);
	tree.add(10);
	tree.add(13);
	tree.add(6);
	tree.add(7);
	tree.add(20);
	tree.add(18);
	tree.add(23);

	cout << "height of node: " << tree.height2(tree.getNode(5)) << endl;
	cout << "height of tree: " << tree.height() << endl;
	cout << endl;
}

void testPart2() {
	cout << "Part 2" << endl;
	BinarySearchTree<BSTNode1<int>, int> tree1;
	tree1.add(8);
	tree1.add(3);
	tree1.add(10);
	tree1.add(13);
	tree1.add(9);
	tree1.add(2);
	tree1.add(4);
	cout << "Is tree balanced?: " << tree1.isBalanced() << endl;
	cout << endl;

	BinarySearchTree<BSTNode1<int>, int> tree2;
	tree2.add(15);
	tree2.add(10);
	tree2.add(5);
	tree2.add(20);
	tree2.add(25);
	cout << "Is tree balanced?: " << tree2.isBalanced() << endl;
	cout << endl;
}

void testPart3() {
	cout << "Part 3" << endl;
	BinarySearchTree<BSTNode1<int>, int> tree;
	tree.add(15);
	tree.add(5);
	tree.add(3);
	tree.add(12);
	tree.add(10);
	tree.add(6);
	tree.add(7);
	tree.add(13);
	tree.add(16);
	tree.add(20);
	tree.add(18);
	tree.add(23);
	cout << "pre order: " << endl;
	tree.preOrder();
	cout << endl;
	cout << "in order: " << endl;
	tree.inOrder();
	cout << "post order: " << endl;
	tree.postOrder();

}

void testPart4() {
	cout << "Part 4" << endl;
		BinarySearchTree<BSTNode1<int>, int> tree;
		tree.add(15);
		tree.add(5);
		tree.add(3);
		tree.add(12);
		tree.add(10);
		tree.add(6);
		tree.add(7);
		tree.add(13);
		tree.add(16);
		tree.add(20);
		tree.add(18);
		tree.add(23);

		DLList<int> treeTester1 = tree.getLE(5);
		DLList<int> treeTester2 = tree.getLE(12);
		DLList<int> treeTester3 = tree.getLE(18);
		DLList<int> treeTester4 = tree.getLE(23);
		DLList<int> treeTester5 = tree.getLE(50);

		BinarySearchTree<BSTNode1<int>, int> tree2;
		tree2.add(10);
		tree2.add(5);
		tree2.add(3);
		tree2.add(7);
		tree2.add(20);
		tree2.add(15);
		tree2.add(22);
		tree2.getLE(20);

}

int main() {

	testPart1();
	testPart2();
	testPart3();
	testPart4();

	return 0;
}
