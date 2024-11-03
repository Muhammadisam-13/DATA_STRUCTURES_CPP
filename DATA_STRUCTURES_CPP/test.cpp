#include <iostream>
#include "BST.h"

int main() {
	BST tree;
	tree.insertNode(54);
	tree.insertNode(25);
	tree.insertNode(71);
	tree.insertNode(11);
	tree.insertNode(28);
	BSTNode* root = tree.getRoot();



	tree.PreorderTraversal(root);
	cout << boolalpha << tree.search(11) << endl;

	tree.deleteNode(11);
	tree.PreorderTraversal(root);
	cout << boolalpha << tree.search(11);
}

