#pragma once
#include<iostream>
using namespace std;

template<class T>
struct AVLNode {
	T data;
	AVLNode<T>* left;
	AVLNode<T>* right;
	int height;
	AVLNode(int data) : 
		data(data), 
		left(nullptr), 
		right(nullptr), 
		height(1) 
	{}
};

template<class T>
class AVLTree {
private:
	AVLNode<T>* root;
	int Height(AVLNode<T>* node) {
		if (node == nullptr) return 0;
		return node->height;
	}
	int balanceFactor(AVLNode<T>* node) {
		if (node == nullptr) return 0;
		return Height(node->left) - Height(node->right);
	}
	AVLNode<T>* rightRotate(AVLNode<T>* node) {
		AVLNode<T> newRoot = node->left;
		AVLNode<T> temp = newRoot->right;

		newRoot->right = node;
		node->left = temp;

		newRoot->height = max(Height(newRoot->left) - Height(newRoot->right)) + 1;
		node->height = max(Height(node->left) - Height(node->right)) + 1;
		return newRoot;
	}
	AVLNode<T>* leftRotate(AVLNode<T>* node) {
		AVLNode<T> newRoot = node->right;
		AVLNode<T> temp = newRoot->left;

		newRoot->left = node;
		node->right = temp;

		newRoot->height = max(Height(newRoot->left) - Height(newRoot->right)) + 1;
		node->height = max(Height(node->left) - Height(node->right)) + 1;
		return newRoot;
	}
	AVLNode<T>* insert(AVLNode* node, int data) {
		if (node == nullptr) // if the node is nullptr
			return new AVLNode<T>(data);
		
		if (data < node->data)
			node->left = insert(node->left, data);
		else if (data > node->data)
			node->right = insert(node->right, data);
		else return node;

		node->height = 1 + max(Height(node->left), Height(node->right));

		int balance = balanceFactor(node);

		if (balance > 1 && data < node->left->data) { // left left case
			return rightRotate(node);
		}
		if (balance < -1 && data > node->right->data) { // right right case
			return leftRotate(node);
		}
		if (balance > 1 && data > node->left->data) { // left right case
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		if (balance < -1 && data < node->right->data) { // right left case
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}

public:
	AVLTree() : 
		root(nullptr) {}

	// inserting a key into the AVL Tree
	void insert(T key) {
		root = insert(root, key);
	}
};