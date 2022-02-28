#include "Stack.h"

class Node {
public:
	int data;
	Node* next; //Stores memory address of next top/node
	Node* back; //Stores memory address of previous top/node
private:
};

//Description : Defining top
//Precondition : Top is undefined
//Postcondition : Top is set to NULL
Stack::Stack() {
	top = NULL;
}

//Description : Setting unwanted memory to NULL 
//Precondition : Memory still storing information
//Postcondition : Deleting information from memory
Stack::~Stack() {
	Node* temp;
	while (top != NULL) {
		temp = top; //Sets temp equal to current top
		top = top->back; //Pushes top back to previous top
		delete temp; //Deletes temp ptr which is equal to current top
	}
}

//Description : Adding another node to the top of the stack
//Precondition : Want to add another node to make the list longer
//Postcondition : Adds another node to the top of the stack
void Stack::push(int x) {
	if (!isFull()) { //Adds to the top of the stack if there is more memory available
		Node* temp = new Node();
		Node* previous = top;
		temp->data = x;
		temp->next = NULL;
		temp->back = NULL;

		if (top == NULL) { //Sets top equal to temp if there is nothing in the stack yet
			top = temp;
		}
		else {
			top->next = temp; //next location within top is equal to temp ptr
			top = top->next; //new top is equal to temp ptr
			top->back = previous; //back ptr within new top is equal to previous top
		}
	}
	else {
		cout << "List is Full" << endl;
	}
}

//Description : Deleting a node from the top of the stack
//Precondition : Want to delete a node from the top of the stack
//Postcondition : Deletes a node from the top of the stack
void Stack::pop() {
	Node* temp;
	if (!isEmpty()) { //Deletes from the top of the stack if the stack is not empty
		temp = top;
		top = top->back;
		delete temp;
	}
	else {
		cout << "List is empty" << endl;
	}
}

//Description : Checks to see if the stack is empty
//Precondition : Dont know if the stack is empty
//Postcondition : Returns true if the stack is empty preventing other parts of the program from doing things
bool Stack::isEmpty() {
	if (top == NULL) {
		return true;
	}
	else {
		return false;
	}
}

//Description : Checks to see if the stack is full
//Precondition : Dont know if there is anymore available memory to allocate
//Postcondition : Returns true if the stack is full
bool Stack::isFull() {
	Node* temp = new Node();
	if (!temp) {
		return true;
	}
	else {
		return false;
	}
	delete temp;
}

//Description : Gets the data from the top of the stack
//Precondition : Dont know whats in the top of the stack
//Postcondition : Returns the data from the top of the stack
int Stack::getTop() {
	if (!isEmpty()) {
		return top->data; //Returns data if stack is not empty
	}
	else {
		return 0;
	}
}