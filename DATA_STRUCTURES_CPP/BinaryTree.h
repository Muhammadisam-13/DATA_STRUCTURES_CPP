#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct TreeNode {
	T data;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : left(nullptr), right(nullptr), data(T()) {}
};

template<typename T>
class BinaryTree {
private:
	TreeNode<T>* root;
	int numNodes;
public:
	BinaryTree() : root(nullptr), numNodes(0) {}
	void insertNode(T data) {
		TreeNode<T>* newNode = new TreeNode<T>;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->data = data;

		if (!root) { // if tree is empty
			root = newNode;
		}

		else {
			TreeNode<T>* curr = root;
			while (curr) {
				if (curr->data > data) { // left subtree
					if (curr->left) { curr = curr->left; }
					else { curr->left = newNode; break; }
				}
				else if (curr->data < data) { // right subtree
					if (curr->right) { curr = curr->right; }
					else { curr->right = newNode; break; }
				}
				else { cout << "Duplicate value found in tree.\n"; break; } // duplicate values
			}
		}
		numNodes++;
	}
	bool search(T data) {
		TreeNode<T>* curr = root;
		while (curr) {
			if (curr->data == data) {
				return true; // value is found
			}
			else if (curr->data > data) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
		return false; // value is not found
	}
	~BinaryTree() {

	}
};
