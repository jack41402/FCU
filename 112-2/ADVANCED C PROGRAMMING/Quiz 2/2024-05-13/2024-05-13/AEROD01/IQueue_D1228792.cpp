#include <iostream>
#include "IQueue_D1228792.h" 

// ***** Complete the following constructor and functions.
using namespace std;
// Default constructor.
IQueue::IQueue() {
	head = NULL;
	tail = NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *Newnode;
	Newnode = new Node(e);
	if(tail == NULL){
		head = Newnode;
		tail = Newnode;
	}
	else{
		Newnode->prev = tail;
		tail->next = Newnode;
		tail = Newnode;
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	Node *temp;
	temp = new Node();
	int e;
	if(head == NULL) return 0;
	else{
		e = head->elem;
		temp = head;
		head = head->next;
		delete(temp);
		return e;
	}
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return head == NULL;
}

// Clear queue.		
void IQueue::clear() {
	Node *temp;
	temp = new Node();
	while(head != NULL){
		temp = head;
		head = head->next;
		delete(temp);
	}
}
//void IQueue::printq(){
//	Node *temp;
//	temp = head;
//	while(temp!=NULL){
//		cout<<temp->elem<<" ";
//		temp = temp->next;
//	}
//}
