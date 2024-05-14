#include "IQueue_D1265065.h"
#include <iostream>
IQueue::IQueue(){
	head = NULL;
	tail = NULL;
} // Default constructor.
		
void IQueue::enqueue(int e){
	Node *newnode;
	newNode->elem = e;
	if(isEmpty){
		head = newNode;
		tail = newNode;
		//prev&next = NULL
	}
	else{
		newNode->next = NULL;
		tail = newNode;
		//newNode->prev = head->next;
	}
} // Enqueue operation.
		
int IQueue::dequeue(){
	Node *curr;
	if(isEmpty){
		return -1;
	}
	else{
		head = head->next;
		head->prev = NULL;
		return head->elem;
	}
} // Dequeue operation.
		
bool IQueue::isEmpty(){
return head == NULL || tail == NULL;
} // Check whether the queue is empty.
		
void IQueue::clear(){
	head = NULL;
	tail = NULL;
} // Clear queue.
