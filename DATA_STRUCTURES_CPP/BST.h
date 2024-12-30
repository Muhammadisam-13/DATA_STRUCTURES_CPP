#pragma once
#include<iostream>
#include<queue>
using namespace std;

template<class T>
struct BSTNode {
	T data;
	BSTNode* left;
	BSTNode* right;
	BSTNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

template<class T>
class BST {
private:
	BSTNode<T>* inorderSuccessor(BSTNode<T>* node) {
		if (!node || !node->left) return node;
		inorderSuccessor(node->left);
	}
	BSTNode<T>* deleteNode(BSTNode<T>* currNode, T data) {
		if (!currNode) return currNode;
		if (currNode->data > data) {
			currNode->left = deleteNode(currNode->left, data);
		}
		else if (currNode->data > data) {
			currNode->right = deleteNode(currNode->right, data);
		}
		else { // key found
			if (!currNode->right) { // left subtree and leafnode case
				BSTNode<T>* temp = currNode;
				currNode = currNode->left;
				delete temp;
				return currNode;
			}
			else if (currNode->right && !currNode->left) { // right subtree only case
				BSTNode<T>* temp = currNode;
				currNode = currNode->right;
				delete temp;
				return currNode;
			}
			else { // both left and right subtree case
				BSTNode<T>* inorder = inorderSuccessor(currNode->right);
				currNode->data = inorder->data;
				currNode->right = deleteNode(currNode->right, inorder->data);
			}
		}
	}
	void inorderTraversal(BSTNode<T>* node) {
		if (!node) return;
		inorderTraversal(node->left);
		cout << node->data << " ";
		inorderTraversal(node->right);
	}
	void preorderTraversal(BSTNode<T>* node) {
		if (!node) return;
		cout << node->data << " ";
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
	void postorderTraversal(BSTNode<T>* node) {
		if (!node) return;
		postorderTraversal(node->left);
		postorderTraversal(node->right);
		cout << node->data << " ";
	}

	BSTNode<T>* root;
public:
	BST() : root(nullptr) {}
	void insert(T data) {
		BSTNode<T>* newNode = new BSTNode<T>(data);
		if (!root) {
			root = newNode;
			return;
		}
		BSTNode<T>* curr = root;
		while (curr) {
			if (curr->data > data) {
				if (curr->left) curr = curr->left;
				else { curr->left = newNode; break; }
			}
			else if (curr->data < data) {
				if (curr->right) curr = curr->right;
				else { curr->right = newNode; break; }
			}
			else { cout << "No duplicates allowed.\n"; break; } // no duplicates allowed
		}
	}
	void remove(T data) {
		root = deleteNode(root, data);
	}
	void inorder() {
		inorderTraversal(root);
	}
	void preorder() {
		preorderTraversal(root);
	}
	void postorder() {
		postorderTraversal(root);
	}
	void levelOrder() {
		queue<BSTNode<T>*> q;
		q.push(root);
		while (!q.empty()) {
			int levelSize = q.size();
			for (int i = 0; i < levelSize; i++) {
				BSTNode<T>* node = q.front();
				q.pop();
				cout << node->data << " ";
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
	}
};