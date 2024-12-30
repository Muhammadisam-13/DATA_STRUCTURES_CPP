#pragma once
#include<iostream>
using namespace std;

template<class T, int ORDER>
class BNode {
public:
	T keys[ORDER - 1];
	BNode* children[ORDER];
	int n;
	bool leaf;
	BNode(bool leaf) : leaf(leaf), n(0) {
		for (int i = 0; i < ORDER; i++) {
			children[i] = nullptr;
		}
	}
};

template<class T, int ORDER>
class BTree {
private: 
	BNode<T, ORDER>* root;
	void splitChild(BNode<T, ORDER>* currNode, int i) {
		BNode<T, ORDER>* child1 = currNode->children[i];
		BNode<T, ORDER>* child2 = new BNode<T, ORDER>(child1->leaf);

		// Add keys of z from y and children if y is not a leaf 
		child2->n = ORDER / 2 - 1;
		for (int j = 0; j < ORDER / 2 - 1; j++) {
			child2->keys[j] = child1->keys[j + ORDER / 2];
		}

		if (!child1->leaf) {
			for (int j = 0; j < ORDER / 2; j++) {
				child2->children[j] = child1->children[j + ORDER / 2];
			}
		}
		child1->n = ORDER / 2 - 1;

		// Make space for new child
		for (int j = currNode->n; j >= i + 1; j--) {
			currNode->children[j + 1] = currNode->children[j];
		}
		currNode->children[i + 1] = child2;

		for (int j = currNode->n - 1; j >= i; j--) {
			currNode->keys[j + 1] = currNode->keys[j];
		}
		currNode->keys[i] = child1->keys[ORDER / 2 - 1];
		currNode->n++;
	}
	void insertNonFull(BNode<T,ORDER>* currNode, T data) { // current Node in first call of ftn is not full
		int i = currNode->n - 1;
		if (currNode->leaf) { // leaf case
			while (i >= 0 && data < currNode->keys[i]) {
				currNode->keys[i + 1] = currNode->keys[i];
				i--;
			}
			currNode->keys[i + 1] = data;
			currNode->n++;
		}
		else { // internal node case
			while (i >= 0 && data < currNode->keys[i])
				i--;
			i++;
			if (currNode->children[i]->n == ORDER - 1) {
				if (data > currNode->keys[i]) 
					i++;				
			}
			insertNonFull(currNode->children[i], data);
		}
	}
	void traverseTree(BNode<T, ORDER>* node) {
		int i;
		for (i = 0; i < node->n; i++) {
			if (!node->leaf)
				traverseTree(node->children[i]);
			cout << " " << node->keys[i];
		}
		if (!node->leaf) {
			traverseTree(node->children[i]);
		}
	}
public:
	BTree() : root(new BNode<T, ORDER>(true)) {}
	void insert(T data) {
		if (root->n == ORDER - 1) { // root contains max number of keys
			BNode<T, ORDER>* newNode = new BNode<T, ORDER>(false);
			newNode->children[0] = root;
			root = newNode;
			splitChild(newNode, 0);
			insertNonFull(newNode, data);
		}
		else {
			insertNonFull(root, data);
		}
	}
	void traverse() {
		traverseTree(root);
	}
	
};