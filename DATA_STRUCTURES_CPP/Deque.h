#pragma once
#include<iostream>
using namespace std;


template <typename T>
struct queueNode {
	T data;
	queueNode* next;
};

template<class T>
class deque {
private:
	queueNode<T>* front;
	queueNode<T>* rear;
	int length;
public:
	deque() : front(nullptr), rear(nullptr), length(0) {}

	void operator=(deque<T> other) {
		// clear();
		if (other.isEmpty()) return;

		queueNode<T>* curr = other.front;
		while (curr) {
			push_back(curr->data);
			curr = curr->next;
		}
	}

	void push_back(T data) {
		queueNode<T>* newNode = new queueNode<T>{ data, nullptr };

		if (!front) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		length++;
	}

	void push_front(T data) {
		queueNode<T>* newNode = new queueNode<T>{ data, front };
		if (!front) {
			rear = newNode;
		}
		front = newNode;
		length++;
	}
	T pop_front() {
		if (!front) return T();

		queueNode<T>* temp = front;
		T poppedState = temp->data;
		front = front->next;

		if (!front) {
			rear = nullptr;
		}
		delete temp;
		length--;
		return poppedState;
	}

	T pop_back() {
		if (!front) return T();

		if (front == rear) {
			T popped = front->data;
			delete front;
			front = nullptr;
			rear = nullptr;
			length--;
			return popped;
		}
		queueNode<T>* curr = front;
		while (curr->next != rear) {
			curr = curr->next;
		}
		T popped = rear->data;
		delete rear;

		curr->next = nullptr;
		rear = curr;
		return popped;
	}

	T top() {
		if (!front) return T();
		return rear->data;
	}

	T peek() {
		if (!front) return T();
		return front->data;
	}

	int size() const {
		return length;
	}
	bool isEmpty() {
		return front == nullptr;
	}
	void clear() {
		while (!isEmpty()) { // Continue until the stack is empty
			pop_front(); // Remove the front node (head) to delete it
		}
	}
};