#pragma once
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void printList(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

class LinkedList {
private:
	Node* start;
public:
	LinkedList(Node* node = nullptr) : start(node) {}
	void displayList() const {
		Node* temp = start;
		if (temp == nullptr) {
			cout << "List is empty.\n";
			return;
		}

		while (temp != nullptr) {
			cout << temp->data;
			if (temp->next != nullptr) {
				cout << "->";
			}
			temp = temp->next;
		}
		cout << endl;
	}

	void insert(int element) {
		if (start == nullptr) {
			start = new Node;
			start->data = element;
			start->next = nullptr;
		}

		else {
			Node* temp = start;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = new Node{ element, nullptr };
		}
	}

	void insertAt(int n, int element) {

	}

	void deleteNode(int d) {
		Node* temp = start;
		if (start->data == d) {
			start = temp->next;
			delete temp;
		}


		else {
			Node* p, * q;
			p = start;
			q = start;

			while (p->next != nullptr) {
				if (p->next->data == d) {
					q = p->next;
					p->next = q->next;
					delete q;
					break;
				}
				p = p->next;
			}
		}
	}
};