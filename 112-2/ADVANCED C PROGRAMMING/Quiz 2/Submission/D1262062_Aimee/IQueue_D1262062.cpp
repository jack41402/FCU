#include <iostream>
#include "IQueue_D1262062.h" 

// ***** Complete the following constructor and functions.
using namespace std;
// Default constructor.
IQueue::IQueue() {
	head = NULL;
	tail = NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	if(!isEmpty()){
		Node *newnode = new Node[e]; 
		Node *temp = tail;
		temp->next = newnode;
		newnode->prev = temp;
		tail = newnode;
	}
	else{
		Node *newnode = new Node[e];
		head = newnode;
		newnode->next = NULL;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	if(isEmpty()) return -1;
	else{
		Node *temp = head;
		int e = head->elem;
		head = head->next;
		delete [] temp;
		return e;
	}
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return head==0;
}

// Clear queue.		
void IQueue::clear() {
	if(isEmpty()) cout << "The Queue is empty.\n";
	else{
		if(!tail) {
			Node *temp = head;
			head = head->next;
			delete [] temp;
		}
		head = NULL;
		tail = NULL;
	}
}
