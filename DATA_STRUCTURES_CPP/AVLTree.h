#pragma once
#include<iostream>
#include<queue>
using namespace std;

template<class T>
struct AVLNode {
	T data;
	AVLNode<T>* left;
	AVLNode<T>* right;
	int height;
	AVLNode(T data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

template<class T>
class AVLTree {
private:
	AVLNode<T>* root;
	AVLNode<T>* inorderSuccessor(AVLNode<T>* node) {
		if (!node || !node->left) return node;
		return inorderSuccessor(node->left);
	}
	int getHeight(AVLNode<T>* node) {
		if (!node) return 0;
		return node->height;
	}
	int balanceFactor(AVLNode<T>* node) {
		if (!node) return 0;
		return getHeight(node->left) - getHeight(node->right);
	}
	AVLNode<T>* leftRotate(AVLNode<T>* node) {
		AVLNode<T>* p = node->right;
		AVLNode<T>* q = p->left;
		node->right = q;
		p->left = node;
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		p->height = 1 + max(getHeight(p->left), getHeight(p->right));
		return p;
	}
	AVLNode<T>* rightRotate(AVLNode<T>* node) {
		AVLNode<T>* p = node->left;
		AVLNode<T>* q = p->right;
		node->left = q;
		p->right = node;
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		p->height = 1 + max(getHeight(p->left), getHeight(p->right));
		return p;
	}
	AVLNode<T>* insertNode(AVLNode<T>* currNode, T data) {
		if (!currNode) return new AVLNode<T>(data);

		if (data > currNode->data) {
			currNode->right = insertNode(currNode->right, data);
		}
		else if (data < currNode->data) {
			currNode->left = insertNode(currNode->left, data);
		}
		else { cout << "No duplicates allowed.\n"; return currNode; }
		currNode->height = 1 + max(getHeight(currNode->left), getHeight(currNode->right));
		int balance = balanceFactor(currNode);
		
		if (balance > 1 && data < currNode->left->data) { // left left case
			return rightRotate(currNode);
		}
		if (balance > 1 && data < currNode->left->data) { // left right case
			currNode->left = leftRotate(currNode->left);
			return rightRotate(currNode);
		}
		if (balance < -1 && data > currNode->right->data) { // right right case
			return leftRotate(currNode);
		}
		if (balance < -1 && data < currNode->right->data) { // right left case
			currNode->right = rightRotate(currNode->right);
			return leftRotate(currNode);
		}
		return currNode;
	}
	AVLNode<T>* deleteNode(AVLNode<T>* currNode, T data) {
		if (!currNode) return currNode;

		if (data > currNode->data) {
			currNode->right = deleteNode(currNode->right, data);
		}
		else if (data < currNode->data) {
			currNode->left = deleteNode(currNode->left, data);
		}
		else {
			if (!currNode->right) {
				AVLNode<T>* temp = currNode;
				currNode = currNode->left;
				delete temp;
				return currNode;
			}
			else if (currNode->right && !currNode->left) {
				AVLNode<T>* temp = currNode;
				currNode = currNode->right;
				delete temp;
				return currNode;
			}
			else {
				AVLNode<T>* inorder = inorderSuccessor(currNode->right);
				currNode->data = inorder->data;
				currNode->right = deleteNode(currNode->right, inorder->data);
			}
		}
		if (!currNode) return currNode;
		currNode->height = 1 + max(getHeight(currNode->left), getHeight(currNode->right));
		int balance = balanceFactor(currNode);
		if (balance > 1 && balanceFactor(currNode->left) >= 0) {
			return rightRotate(currNode);
		}
		if (balance > 1 && balanceFactor(currNode->left) < 0) {
			currNode->left = leftRotate(currNode->left);
			return rightRotate(currNode);
		}
		if (balance < -1 && balanceFactor(currNode->right) <= 0) {
			return leftRotate(currNode);
		}
		if (balance < -1 && balanceFactor(currNode->right) > 0) {
			currNode->right = rightRotate(currNode->right);
			return leftRotate(currNode);
		}
		return currNode;
	}
	void inorderTraversal(AVLNode<T>* node) {
		if (!node) return;
		inorderTraversal(node->left);
		cout << node->data << " ";
		inorderTraversal(node->right);
	}
	void preorderTraversal(AVLNode<T>* node) {
		if (!node) return;
		cout << node->data << " ";
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
	void postorderTraversal(AVLNode<T>* node) {
		if (!node) return;
		postorderTraversal(node->left);
		postorderTraversal(node->right);
		cout << node->data << " ";
	}
	bool searchData(AVLNode<T>* node, T data) {
		if (!node) return false;
		if (node->data == data) return true;
		return searchData(node->left, data) || searchData(node->right, data);
	}
public:
	AVLTree() : root(nullptr) {}
	void insert(T data) {
		root = insertNode(root, data);
	}
	void remove(T data) {
		root = deleteNode(root, data);
	}
	bool search(T data) {
		return searchData(root, data);
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
		queue<AVLNode<T>*> q;
		q.push(root);
		while (!q.empty()) {
			int levelSize = q.size();
			for (int i = 0; i < levelSize; i++) {
				AVLNode<T>* node = q.front();
				q.pop();
				cout << node->data << " ";
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
	}
};