#include <iostream>
#include "IQueue_D1265154.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head =NULL;
	tail =NULL;
	
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *newNode, *current;
	if(head==NULL){
		newNode = new Node(e);
		head = newNode;
		tail = newNode;
	}
	else{
		current = tail;
		newNode = new Node(e);
		current->next = newNode;
		tail = newNode;
		newNode->prev = current;
	
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	Node *current;
	if(head==NULL){
		return 0;
	}
	else{
		current = head;
		head = current->next;
		if(head!=NULL){
			head->prev = current;
			delete (current);
		}
		
	}
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return head==NULL;
}

// Clear queue.		
void IQueue::clear() {
	head == 0;
	tail == 0;
}
