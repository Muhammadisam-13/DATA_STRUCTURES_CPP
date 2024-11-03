#include <iostream>
#include "BST.h"
#include "AVLTree.h"

int main() {
	BST tree;
	tree.insertNode(10);
	tree.insertNode(20);
	tree.insertNode(30);
	tree.insertNode(40);
	tree.insertNode(4);
	BSTNode* root = tree.getRoot();
	tree.PreorderTraversal(root);
	cout << endl;

	AVLTree<int> avl;
	avl.insert(10);
	avl.insert(20);
	avl.insert(30);
	avl.insert(40);
	avl.insert(4);
	AVLNode<int>* avlroot = avl.getRoot();
	avl.preorderTraversal(avlroot);


}

