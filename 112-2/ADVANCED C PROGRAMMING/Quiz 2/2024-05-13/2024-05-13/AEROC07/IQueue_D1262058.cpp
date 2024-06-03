#include <iostream>
#include "IQueue_D1262058.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	Node *newnode;
	head = newnode;
	tail = newnode; 
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *newnode;
	newnode->elem = e;
	newnode->prev = tail;
	tail->next = newnode;
	tail = newnode;
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	Node *temp;
	temp = head;
	head = head->next;
	head->prev = NULL;
	return temp->elem;
	delete temp;	
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return head == NULL;
}

// Clear queue.		
void IQueue::clear() {
	Node *current;
	current = head;
	while(current != NULL){
		current = current->next;
		delete current;
	}
}
