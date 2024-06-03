#include <iostream>
#include "IQueue_D1262015.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head = NULL;
	tail = NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *newNode;
	newNode = new Node(e);
	if (head==NULL && tail==NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		tail = newNode; 
	}else{
		newNode->prev = tail;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	int e=head->elem;
	Node *temp=head;
	if(temp!=NULL){
		head = head->next;
		if(head==NULL) tail = NULL;
		delete(temp);
		return e;
	}else return -1;
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return head==NULL;
}

// Clear queue.		
void IQueue::clear() {
	while (!isEmpty()){
		dequeue();
	}

}
