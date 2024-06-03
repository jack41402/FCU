#include <iostream>
#include "IQueue_D1265315.h.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node newcode;
	*newcode ->next = 'null';
	*tail ->next = e;
	*e ->prev = tail;
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	*head ->next ='null'
	*head ->prev ='null'
	return;	
}

// Clear queue.		
void IQueue::clear() {
}
