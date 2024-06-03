#include <iostream>
#include "IQueue_D1228817.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head=NULL;
	tail=NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *new_node=new Node(e);
	
	if(head==NULL){
		head=new_node;
		tail=new_node;
	}
	else{
		tail->next=new_node;
		new_node->prev=tail;
		new_node->next=NULL;
		tail=new_node;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	if(head==NULL) return -1;
	
	int element=head->elem;
	head=head->next;
	delete head->prev;
	head->prev=NULL;
	return element;
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	if(head==NULL) return true;
	else return false;
}

// Clear queue.		
void IQueue::clear() {
	while(head!=NULL){
		head=head->next;
		delete head->prev;
	}
	head=NULL;
	tail=NULL;
}
