#pragma once

#include"Libraries.h"

class nno {
public:
	int data;
	nno* next;
};

template <typename T>
class Queue {
	nno* front;
	nno* rear;
	int size;

public:
	Queue() {
		front = nullptr;
		rear = nullptr;
	}
	void enqueue(int data) {
		nno* newNode = new nno;
		newNode->data = data;
		newNode->next = nullptr;

		if (rear == nullptr) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		size++;
	}

	void dequeue() {
		if (front == nullptr) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}

		nno* temp = front;
		front = front->next;
		delete temp;

		if (front == nullptr) {
			rear = nullptr;
		}
		size--;
	}
	int getsize()
	{
		return size;
	}
	int peek() {
		if (front == nullptr) {
			std::cout << "Queue is empty" << std::endl;
			return -1;
		}
		return front->data;
	}

	bool isEmpty() {
		return (front == nullptr);
	}
};