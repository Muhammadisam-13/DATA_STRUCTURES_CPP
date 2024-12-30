#pragma once
#include<iostream>
using namespace std;

template<typename T> class Stack {
private:
	T* list;
	int maxSize;
	int currentElements;
public:
	Stack() {
		maxSize = 20;
		currentElements = 0;
		list = new T[maxSize];
		for (int i = 0; i < currentElements; i++) {
			list[i] = 0;
		}
	}

	void initializeStack() {
		for (int i = 0; i < currentElements; i++) {
			list[i] = 0;
		}
		currentElements = 0;
	}

	bool isEmpty() const {
		return (currentElements == 0);
	}

	bool isFull() const {
		return (currentElements == maxSize);
	}

	void push(const T& item) {
		if (!isFull()) {
			list[currentElements++] = item;
		}
		else {
			cout << "Stack is currently full.\n";
		}
	}

	T top() const {
		if (currentElements != 0) {
			return list[currentElements - 1];
		}
		cout << "Stack is currently empty.\n";
		return T();
	}

	T front() const {
		if (currentElements != 0) {
			return list[0];
		}
		cout << "Stack is currently empty.\n";
		return T();
	}

	void pop() {
		if (!isEmpty()) {
			currentElements--;
		}
		else {
			cout << "Cannot remove from an empty stack." << endl;
		}
	}

	void pop_front() {
		if (!isEmpty()) {
			for (int i = 0; i < currentElements - 1; i++) {
				list[i] = list[i + 1];
			}
			currentElements--;
		}
		else {
			cout << "Cannot remove from an empty stack";
		}
	}

	void copyStack(const Stack<T>& other) {
		if (list != nullptr)
			delete[] list;
		this->maxSize = other.maxSize;
		this->currentElements = other.currentElements;
		list = new T[maxSize];
		for (int i = 0; i < currentElements; i++) {
			list[i] = other.list[i];
		}
	}

	~Stack() {
		delete[] list;
		list = nullptr;
	}
};