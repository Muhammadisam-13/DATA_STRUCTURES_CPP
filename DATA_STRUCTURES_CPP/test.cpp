#include <iostream>
#include "BST.h"
#include "BTree.h"
#include "AVLTree.h"

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

	/*BST<int> bst;
	bst.insert(65);
	bst.insert(45);
	bst.insert(78);
	bst.insert(42);
	bst.insert(47);
	bst.insert(75);
	bst.insert(81);
	bst.levelOrder(); cout << endl;
	bst.remove(65);
	bst.remove(75);
	bst.levelOrder();*/

	AVLTree<int> avl;
	avl.insert(10);
	avl.insert(20);
	avl.insert(30);
	avl.insert(40);
	avl.insert(50);
	avl.insert(25);
	avl.levelOrder(); cout << endl;
	avl.remove(10);
	avl.levelOrder(); cout << endl;
	avl.remove(50);
	avl.remove(40);
	avl.levelOrder(); cout << endl;
	cout << boolalpha << avl.search(25) << endl;
	cout << boolalpha << avl.search(20) << endl;
	cout << boolalpha << avl.search(30) << endl;
	cout << boolalpha << avl.search(10) << endl;

}