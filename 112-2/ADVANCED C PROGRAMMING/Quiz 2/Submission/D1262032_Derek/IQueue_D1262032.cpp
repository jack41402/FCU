#include <iostream>
#include "IQueue_D1262032.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head=NULL;
	tail=NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node* current=head;
	Node* previous=tail;
	Node* newNode;
	if(current==NULL){
		newNode=new Node;
		newNode->elem=e;
		newNode->next=newNode;
		newNode->prev=newNode;
		head=newNode;
		tail=newNode;
	}
	else{
		newNode=new Node;
		newNode->elem=e;
		newNode->next=NULL;
		newNode->prev=previous;
		previous->next=newNode;
		tail=newNode;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	Node* current=head;
	Node* previous=tail;
	int e;
	if(isEmpty()) return -1;
	else{
		e=current->elem;
		current->next->prev=NULL;
		head=current->next;
		return e;
	}
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return (head==NULL);
}

// Clear queue.		
void IQueue::clear() {
	head=NULL;
	tail=NULL;
}
