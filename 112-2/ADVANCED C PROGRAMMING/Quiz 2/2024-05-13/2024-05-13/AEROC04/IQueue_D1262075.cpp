#include <iostream>
#include "IQueue_D1262075.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	Node newNode;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	elem = e;
	tail->next = newNode;
	newNode = tail;
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return NULL;
}

// Clear queue.		
void IQueue::clear() {
}
