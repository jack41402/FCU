#include <iostream>
#include "IQueue_D1265273.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head = NULL;
	tail = NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *newelem;
	newelem = new Node(e);
	if (head == NULL && tail == NULL){
		newelem->next = NULL;
		newelem->prev = NULL;
		head = newelem;
		tail = newelem;
	}
	else{
		tail->next = newelem;
		newelem->prev = tail;
		tail = newelem;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	Node *temp;
	while(head!=NULL){
		temp = head;
		head->next>prev = NULL;
		return temp->elem;
		delete(temp);
	}
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return (head == NULL && tail == NULL)
}

// Clear queue.		
void IQueue::clear() {
	while(head!=NULL){
		head = NULL;
		head = head->next;
	}
}
