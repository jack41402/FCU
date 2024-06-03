#include <iostream>
#include "IQueue_D1175125.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() {
	front = NULL;
	rear = NULL;
}
IQueue::~IQueue(){
	clear();
}
// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node* newNode = new Node(e);
	if(isEmpty()){
		front = newNode;
		rear = newNode;
	} else{
		rear->next = newNode;
		newNode->prev = rear;
		rear = newNode;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	if(isEmpty()){
		std::cout<<"Queue is empty."<<std::endl;
		return -1;
	}else{
		int value = front ->data;
		Node* temp = front;
			front = front->next;
			if(front != NULL)
			front->prev = NULL;
			delete temp;
			return value;
	}
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return front == NULL;
}

// Clear queue.		
int IQueue::clear() {
	while(!isEmpty())
		dequeue();
}
