#include <iostream>
#include<iomanip>
#include "IQueue.h"
using namespace std;

IQueue::IQueue(){
    // The queue is empty.
	head = NULL;
	tail = NULL;
}
// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e){
	Node *newnode;
	newnode = new Node(e);// Store the data element of the new node.
	if (head == NULL && tail == NULL){
        // The first node is enqueued.
		newnode->prev = NULL; 
		newnode->next = NULL; 
		head = newnode;
		tail = newnode;
	}
	else{
		newnode->prev = tail;
		newnode->next = NULL;
		tail->next = newnode;
		tail = newnode;
	}
}
// Dequeue operation. Delete from head
int IQueue::dequeue(){
	int e;
	Node *temp;
	
	temp = head;
	e = temp->elem;
	if(temp != NULL){
		head = head->next;
		head->prev = NULL;
		delete temp;
		return e;
	}
	else{
		return -1;
	}
	
}
// Check head element of the queue.
int IQueue::headElem(){
	if (head == NULL){
		return -1;
	}
	else{
		return head->elem;
	}
}
		
bool IQueue::isEmpty(){
	return head == NULL;
}
		
int IQueue::getSize(){
	int i = 0;
	Node *current;
	
	current = head;
	while(current!= NULL){
		current = current->next;
		i++;
	}
	delete current;
	return i;
}
		
Node *IQueue::getHead(){
	return head;
}
		
Node *IQueue::getTail(){
	return tail;
}

void IQueue::printHeadToTail(){
	Node *current;
	current = head;
	int i = 1;
	
	while(current != NULL){
		cout << setw(4) << current->elem;
		if (i%20 == 0){
			cout<<"\n";
		}
		current = current->next;
		i++;
	}
	if (i%20!=0) cout<<"\n";
	delete current;
}




