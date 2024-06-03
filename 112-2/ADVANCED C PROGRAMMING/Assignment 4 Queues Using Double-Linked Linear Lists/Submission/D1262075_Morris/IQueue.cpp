#include <iostream>
#include "IQueue.h" 

IQueue::IQueue() {
	head = NULL; 
	tail = NULL; 
}
void IQueue::enqueue(int e) {
	Node *newNode;
	newNode = new Node(e); 
	if (head==NULL && tail==NULL) { 
		newNode->prev = NULL; 
		newNode->next = NULL; 
		head = newNode; 
		tail = newNode;  
	}
	else {
		newNode->prev = tail; 
		newNode->next = NULL; 
		tail->next = newNode; 
		tail = newNode; 
	}
}
int IQueue::dequeue() {
	int e = head->elem;
	Node *temp = head; 
	if (temp!=NULL) { 
		head = head->next;
		if (head==NULL) tail = NULL; 
		delete(temp); 
	}
	else return -1; 
}
	
int IQueue::headElem() {
	if (head!=NULL) return head->elem; 
	else return -1; 
}  	
bool IQueue::isEmpty() {
	return head==NULL; 
}
int IQueue::getSize() {
	Node *current = head; 
	int count = 0; 
	
	while (current!=NULL) { 
		current = current->next; 
		count++; 
	}
	return count; 
}
Node *IQueue::getHead() {
	return head;
}
Node *IQueue::getTail(){
	return tail; 
} 
void IQueue::printHeadToTail() {
	Node *current = head; 
	int count = 0; 
	while (current!=NULL) { 
		printf(" %3d", current->elem); 
		current = current->next; 
		count++;
		if(count%20==0) printf("\n"); 
	}
	if (count%20!=0) printf("\n"); 
}
