#pragma once
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

class DoublyLinkedList {
private:
	Node* first;
	Node* last;
	int count;
public:
	DoublyLinkedList() : count(0), first(nullptr), last(nullptr) {}
	bool isEmptyList() const {
		return first == nullptr;
	}

	Node*& getHead() {
		return first;
	}

	Node*& getLast() {
		return last;
	}

	bool destroy() {
		Node* current = first;
		while (first != nullptr) {
			current = first;
			first = first->next;
			delete current;
		}
		last = nullptr;
		count = 0;
	}

	void print() const {
		Node* current = first;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
	}

	void reversePrint() const {
		Node* current = last;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->prev;
		}
	}

	// insert and delete
	void insert(const int& data) { // data is entered in sorted manner
		Node* current = nullptr;
		Node* trailCurrent = current;
		Node* newNode;
		bool found;
		newNode = new Node{ data,nullptr,nullptr };

		if (first == nullptr) {
			first = newNode;
			last = newNode;
			++count;
		}

		else {
			found = false;
			current = first;
			while (current != nullptr && !found) {
				if (current->data >= data) {
					found = true;
				}
				else {
					trailCurrent = current;
					current = current->next;
				}
			}

			if (current == first) { // if data is smaller than first, insert the node before first
				first->prev = newNode;
				newNode->next = first;
				first = newNode; // first one is now newNode
				count++;
			}

			else {
				if (current != nullptr) {
					trailCurrent->next = newNode;
					newNode->prev = trailCurrent;
					newNode->next = current;
					current->prev = newNode;
				}
				else {
					trailCurrent->next = newNode;
					newNode->prev = trailCurrent;
					last = newNode;
				}
				count++;
			}
		}
	}

	void deleteNode(int position) {
		if (first == nullptr) return;
		if (position == 0 || position > count) {
			cout << "Invalid Position.";
			return;
		}

		if (position == 1) {
			Node* current = first;


			Node* temp = first->next;
		}


		Node* current = first;
		Node* prev = nullptr;
		int num = 0;

		while (current != nullptr && num < position - 1) {
			num++;
			prev = current;
			current = current->next;
		}

		if (!prev || !prev->next) return;
		Node* temp = prev->next;
		prev->next = temp->next;
		current->next->prev = prev;
		delete temp;
		count--;
	}
};