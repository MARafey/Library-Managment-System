#pragma once
#include"Libraries.h"

template <typename T>
class node_0
{
public:
	T data;
	node_0<T>* next;

	node_0(T d)
	{
		this->data = d;
		next = nullptr;
	}
};


template <typename T>
class Stack
{
	node_0<T>* top;
	int position;
public:
	Stack()
	{
		top = NULL;
	}
	void setposition(int a)
	{
		position = a;
	}
	int getposition()
	{
		return position;
	}
	void push(T x)
	{
		node_0<T>* n = new node_0<T>(x);
		n->data = x;
		n->next = top;
		top = n;
	}
	void pop()
	{
		if (top == NULL)
		{
			return;
		}
		node_0<T>* temp = top;
		top = top->next;
		delete temp;
	}
	T peek()
	{
		if (!IsEmpty())
		{
			return top->data;
		}
	}
	bool IsEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};