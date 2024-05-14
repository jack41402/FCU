#include <iostream>
#include "IQueue_D1265686.h"

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	head = 0;
	tail = 0;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	
	
	ele[tail] =  e ;
	tail = tail + 1 ;
	
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	
	head = head + 1 ;
	return ele[head-1];
	
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	
	if (head == 0 && tail== 0 )
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
	
}

// Clear queue.		
void IQueue::clear() {	
	clear = []ele;
}
