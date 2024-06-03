#include"IQueue.h"
#include<iostream>
#include<iomanip>

IQueue::IQueue(){//set the head and tail to NULL
	head = NULL;
	tail = NULL;
}

void IQueue::enqueue(int e){//enqueue function
	Node* newelem;//define the newelem
	newelem = new Node(e);
	if (head == NULL){//set head and tail to newelem
		head = newelem;
		tail = newelem;
	}
	else{
		newelem->prev = tail;//set previous to tail
		tail->next = newelem;//set next to newelem
		tail = newelem;//set tail to newelem
	}
}

int IQueue::dequeue(){//dequeue function
	Node* temp = head;//define the temp pointer
	head = head->next;//set head to head->next
	if (head !=NULL){
		head->prev = NULL;//if head isn't NULL, previous = NULL
	}
	else{
		tail = NULL;//if head is NULL, tail = NULL
	}
	delete temp;//delete memory space
}

int IQueue::headElem(){
	return head->elem;//return head 
}

bool IQueue::isEmpty(){
	return head == NULL;//head = NULL
}

int IQueue::getSize(){
	int size = 0;//define size to 0
	Node* current;//define current pointer
	current = head;//set current to head
	while(current != NULL){
		size++;//size +1 when doing the while loop
		current = current->next;//define current to the next pointer
	}
	return size;//return the size number
	delete current;//release memory space
}

Node* IQueue::getHead(){
	return head;//return head
}

Node* IQueue::getTail(){
	return tail;//return tail
}

void IQueue::printHeadToTail(){
	Node* current;//define current pointer
	current = head;//set current to head
	int i=0;//count 
	while(current != NULL){
		if (i%20 ==0){
			if (i==0){
				std::cout<<"  ";//start each line with two spaces
			}
			else{
				std::cout<<"\n";//change line when every 20 element are printed
				std::cout<<"  ";//start eacch line with two spaces
			}
		}
		std::cout<<std::setw(2)<<current->elem<<"  ";//print the element
		current = current->next;//set pointer to the next pointer
		i++;//counter plus one
	}
	std::cout<<"\n";//change line
	delete current;//release memory space
}
