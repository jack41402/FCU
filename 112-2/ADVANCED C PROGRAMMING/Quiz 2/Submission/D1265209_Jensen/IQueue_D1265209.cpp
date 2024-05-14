#include <iostream>
#include "IQueue_D1265209.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	Node *head;
	Node *tail;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *newNode;
	newNode = new Node(e);
	if(tail!=NULL){
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	else{
		tail = newNode;
		head = newNode;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	Node *temp;
	temp = head;
	if(temp!=NULL){
		head = head->next;
		tail->next = head;
		delete(temp);
	}
	else return 0;
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	if(head==NULL && tail==NULL)
		return 1;
}

// Clear queue.		
void IQueue::clear() {
	Node *current;
	do{
		current = head;
		head = head->next;
		tail->next = head;
		delete(current);
	} while(head==NULL);
}
