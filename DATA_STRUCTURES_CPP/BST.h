#pragma once
#include<iostream>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode() : left(nullptr), right(nullptr) {}
};

class BST { 
private:
	BSTNode* root;
	int numNodes;
public:
	BST() : root(nullptr), numNodes(0) {}
	BSTNode*& getRoot() {
		return root;
	}
	void insertNode(int data) {
		BSTNode* newNode = new BSTNode;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->data = data;

		if (!root) { // if tree is empty
			root = newNode;
		}

		else {
			BSTNode* curr = root;
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

	void InorderTraversal(BSTNode* treeNode) {
		if (treeNode) {
			InorderTraversal(treeNode->left);
			cout << treeNode->data << " ";
			InorderTraversal(treeNode->right);

		}
	}

	void PreorderTraversal(BSTNode* treeNode) {
		if (treeNode) {
			cout << treeNode->data << " ";
			PreorderTraversal(treeNode->left);
			PreorderTraversal(treeNode->right);

		}
	}
	void PostorderTraversal(BSTNode* treeNode) {
		if (treeNode) {
			PostorderTraversal(treeNode->left);
			PostorderTraversal(treeNode->right);
			cout << treeNode->data << " ";
		}
	}

	BSTNode* getInorderSuccessor(BSTNode* node) {
		if (!node || !node->left) return node;
		return getInorderSuccessor(node->left);
	}

	BSTNode* deleteNodeHelper(BSTNode*& root, int data) {
		if (!root) return root;
		
		if (data < root->data) root->left = deleteNodeHelper(root->left, data); // if value to find is 
		else if (data > root->data) root->right = deleteNodeHelper(root->right, data);
		
		else {
			if (!root->right) { // leaf node case and left subtree existing case
				BSTNode* temp = root;
				temp = temp->left;
				delete root;
				return temp;
			}
			else if (root->right && !root->left) { // only right subtree existing case
				BSTNode* temp = root;
				temp = temp->right;
				delete root;
				return temp;
			}
			
			else { // both subtrees existing case
				BSTNode* inorderSuccessor = getInorderSuccessor(root->right);
				root->data = inorderSuccessor->data;
				BSTNode* temp = inorderSuccessor;
				root->right = deleteNodeHelper(root->right, inorderSuccessor->data);
			}
		}
	}

	BSTNode* deleteNode(int data) {
		if (!root) return root;

		if (data < root->data) root->left = deleteNode(data); // if value to find is 
		else if (data > root->data) root->right = deleteNode(data);

		else {
			if (!root->right) { // leaf node case and left subtree existing case
				BSTNode* temp = root;
				temp = temp->left;
				delete root;
				return temp;
			}
			else if (root->right && !root->left) { // only right subtree existing case
				BSTNode* temp = root;
				temp = temp->right;
				delete root;
				return temp;
			}

			else { // both subtrees existing case
				BSTNode* inorderSuccessor = getInorderSuccessor(root->right);
				root->data = inorderSuccessor->data;
				BSTNode* temp = inorderSuccessor;
				root->right = deleteNode(data);
			}
		}
	}
	bool search(int data) {
		BSTNode* curr = root;
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
	~BST() {

	}
};
