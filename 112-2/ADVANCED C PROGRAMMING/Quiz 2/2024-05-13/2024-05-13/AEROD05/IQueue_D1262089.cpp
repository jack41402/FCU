#include <iostream>
#include "IQueue_D1262089.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head=NULL;
	tail=NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {	
    Node* newNode=new Node(e);
	if(isEmpty()){
		head=tail=newNode;
	}else{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	}
	

}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	int e=head->elem;
	Node*temp=head;	
	head=head->next;
	head->prev=NULL;
	delete temp;
	return e;
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
