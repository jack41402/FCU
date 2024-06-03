#include <iostream>
#include "IQueue_D1172268.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	this->head = NULL;
	this->tail = NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *n = new Node(e);
	if(isEmpty()){
		this->head = n;
		this->tail = n;
	}
	else{
		this->tail->next = n;
		n->prev = this->tail;
		this->tail = n; 
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	int a = this->head->elem;
	if(this->head == this->tail){
		delete [] this->head;
		this->head = NULL;
		return a;
	}
	else{
		this->head->next = this->head;
		delete [] this->head->prev;
		this->head->prev = NULL;
		return a;
	}
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	if(this->head == NULL) return true;
	else return false; 
}

// Clear queue.		
void IQueue::clear() {
		while (head!=NULL) this->dequeue();

}
