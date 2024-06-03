#include <iostream>
#include "IQueue.h"
#include <time.h>
#include <iomanip>
using namespace std;
IQueue::IQueue(){
	head = NULL;
	tail = NULL;
}//Initialize the IQueue class.
void IQueue::enqueue(int e){
	Node *newnode;
	newnode = new Node(e);
	if(head==NULL){
		head = newnode;
		tail = newnode;
	}//verify if head is NULL or not.
	else{
		tail->next = newnode;
		newnode->prev = tail;	
		tail = newnode;
	}
}//enqueue the queue.
int IQueue::dequeue(){
	if(head == NULL) return -1;
	int e=head->elem;
	Node *current = head;
	head = head->next;
	head->prev = NULL;
	delete current;//delete the current.
	return e;
}//dequeue the queue
int IQueue::headElem(){
	return head->elem;
}//return head element.
bool IQueue::isEmpty(){
	return (head == NULL);
}//check if the queue is empty or not.
int IQueue::getSize(){
	if(head == NULL) return 0;
	Node *current;
	int n=0;
	current = head;
	while(current != NULL){
		n++;
		current = current->next;
	}
	delete current;//delete the current.
	return n;
}//get the size of the queue
Node *IQueue::getHead(){
	return head;
} //get the head pointer
Node *IQueue::getTail(){
	return tail;
}//get the tail pointer
void IQueue::printHeadToTail(){
	Node *current;
	int n=0;
	current = new Node();
	current = head;
	while(current != NULL){
		cout<<right<<setw(4)<<current->elem;
		n++;
		if(n%20==0) cout<<'\n';
		current = current->next;
	}
	delete current;//delete the current.
}//print the queue from head to tail

