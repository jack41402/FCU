#include <iostream>
#include "IQueue_D1265672.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue(): head(NULL), tail(NULL), size(0) {
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *newNode = new Node(e);
	if (isEmpty()){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	size++;
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	int k;
	if (isEmpty()){
		return -1;
	}
	else{
		Node *temp = head;
		k = head->elem;
		head = head->next;
		if (head == NULL){
			tail = NULL;
		}
		else{
			head->prev = NULL;
		}
		delete temp;
	}
	size--;
	return k;
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return size == 0;
}

// Clear queue.		
void IQueue::clear() {
	while (head != NULL){
		dequeue();
	}
}
