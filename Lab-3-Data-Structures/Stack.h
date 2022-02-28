#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class Node;

class Stack {
public:
	Stack();
	~Stack();

	//Description : Adds to the top of the stack
	void push(int x);

	//Description : Deletes from the top of the stack
	void pop();

	//Description : Checks if the stack is empty
	bool isEmpty();

	//Description : Checks if the stack is full (no more available memory to allocate)
	bool isFull();

	//Description : Gets information from the top of the stack
	int getTop();

private:
	Node* top;
};

#endif