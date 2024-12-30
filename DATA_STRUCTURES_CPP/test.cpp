#include <iostream>
#include "BST.h"
#include "BTree.h"

int main() {
	//BTree<int, 4> btree;
	//btree.insert(10);
	//btree.insert(20);
	//btree.insert(30);
	//btree.traverse(); cout << endl;
	//btree.insert(40);
	//// btree.insert(50);
	//btree.traverse(); cout << endl;
	//// btree.traverse(); cout << endl;
	//btree.insert(5);
	//btree.insert(15);
	//btree.insert(18);
	//btree.traverse(); cout << endl;

	BST<int> bst;
	bst.insert(65);
	bst.insert(45);
	bst.insert(78);
	bst.insert(42);
	bst.insert(47);
	bst.insert(81);
	bst.levelOrder();
}