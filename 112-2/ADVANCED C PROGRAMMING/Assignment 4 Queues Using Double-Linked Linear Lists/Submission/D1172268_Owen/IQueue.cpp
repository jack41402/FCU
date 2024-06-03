#include "IQueue.h"
#include <cstdio>

IQueue::IQueue(){
	this->head = NULL;//nothing in it
	this->tail = NULL;
}

void IQueue::enqueue(int a){
	Node* n = new Node(a);
	if(isEmpty()){//if it is empty, head and tail be the same node
		this->head = n;
		this->tail = n;
	}
	else{
		this->tail->next = n;//put the new node behind tail
		n->prev = tail;
		this->tail = n;//change the new node to tail
	}
}

int IQueue::dequeue(){
	if(getSize() == 1){//delete the only node
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    }
    else {
        this->head = this->head->next;//change head to the next head
        delete this->head->prev;//delete the first node
        this->head->prev = NULL;
    }
	return 0;
}
		
int IQueue::headElem(){
	return this->head->elem;// Check head element of the queue.
}
 
bool IQueue::isEmpty(){// Check whether the queue is empty.
	if(this->head == NULL) return true;
	else return false;
}

int IQueue::getSize(){ // Get the size of the queue.
	Node* cur = this->head;
	int count = 0;
	while(cur != NULL){
		count++;
		cur = cur->next;
	}
	return count;
}
		
Node* IQueue::getHead(){// Get the head pointer of the queue.
	return this->head;
}
		
Node* IQueue::getTail(){// Get the tail pointer of the queue.
	return this->tail;
}
		
void IQueue::printHeadToTail(){// Print the queue from head to tail.
	int position = 0;
	Node* cur = this->head;
	
	printf("Current queue size: %d. Content of queue from head to tail:\n", getSize());
	if (cur != NULL) {
		while(cur->next != NULL){
			printf("%4d", cur->elem);
			if ((position + 1) % 20 == 0) printf("\n");//print the element 20 in a row
			cur = cur->next;
			position++; 
		}
		printf("%4d\n", cur->elem);//change the row if there is no more node.
	}
}
