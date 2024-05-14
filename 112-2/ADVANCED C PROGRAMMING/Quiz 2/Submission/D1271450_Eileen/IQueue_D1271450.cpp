#include <iostream>
#include "IQueue_D1271450.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head=NULL;
	tail=NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *newNode;
	newNode=new Node(e);
	if(isEmpty()){
		head=newNode;
		tail=newNode;
	}
	else{
		newNode->prev=newNode;
		tail->next=newNode;
		tail=newNode;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	if(isEmpty()){
		throw "queue is empty";
	}
	else{
		Node *temp=head;
	    int e=head->elem;
	    head=head->next;
	    if(temp!=NULL){
	    	head->prev=NULL;
		}
		else{
			tail=NULL;
		}
		delete(temp);
		return e;
	}
	
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return head==NULL;
}

// Clear queue.		
void IQueue::clear() {
	head=NULL;
	tail=NULL;
}
