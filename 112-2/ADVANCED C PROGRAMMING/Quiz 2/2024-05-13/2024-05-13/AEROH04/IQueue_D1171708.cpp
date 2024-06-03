#include <iostream>
#include "IQueue_D1171708.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head = NULL;
	tail = NULL; 
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node* newNode = new Node;
	if(isEmpty()){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	if(isEmpty()){
		return 0;
	}
	else{
		int value = head->elem;
		Node* temp = new Node;
		temp = head->prev;
		delete temp;
		return value;		
	}
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return (tail==NULL);
}

// Clear queue.		
void IQueue::clear() {
	head = NULL;
	tail = NULL;
}
