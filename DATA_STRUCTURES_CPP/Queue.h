#pragma once
#include<iostream>
using namespace std;

template<class T> class Queue {
private:
	T* queue;
	int Front;
	int rear;
	int size;
	int numElements;
public:
	Queue(int size = 10) :
		size(size), 
		queue(new T[size]),
		Front(-1),
		rear(-1),
		numElements(0)
	{}
	void enqueue(T x) {
		if (numElements > size) return;
		
		if (numElements == 0) {
			Front++;
		}
		numElements++;
		rear++;
		queue[rear] = x;
	}
	T dequeue() {
		if (numElements == 0) cout << "Queue is empty.\n";
		else {
			T temp = queue[Front];
			Front++;
			if (Front > rear) {
				Front = -1;
				rear = -1;
				numElements = 0;
			}
			
			else numElements--;
			return temp;
		}
		return T();
	}
	T front() {
		if (Front != -1) return queue[Front];
		cout << "Queue is empty.\n";
		return T();
	}
	bool empty() {
		return numElements == 0;
	}
	void clear() {
		delete[] queue;
		queue = new T[size];
		numElements = 0;
		Front = -1;
		rear = -1;
	}
	int Size() const {
		return size;
	}
};