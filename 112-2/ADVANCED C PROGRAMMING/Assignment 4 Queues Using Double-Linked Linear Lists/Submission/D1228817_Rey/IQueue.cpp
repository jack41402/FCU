#include<iostream>
#include<cstdlib>
#include<iomanip>
#include"IQueue.h"
using namespace std;


IQueue::IQueue(){//Contructor sets head and tail pointer to NULL
	head=NULL;
	tail=NULL;
}

void IQueue::enqueue(int e){
	
	Node *new_node=new Node(e);//Allocate memory for the new node and initialize its value.
	
	if(head==NULL){//If queue is empty
		head=new_node;//Let the head pointer point to new_node
		tail=new_node;//Let the tail pointer point to new_node
	}
	else{//If queue is not empty
		tail->next=new_node;//Update "next" of the original tail node
		new_node->prev=tail;//Let "prev" of new_node point to the original tail node
		tail=new_node;//Update tail pointer
	}

}

int IQueue::dequeue(){
	if(head==NULL){//If queue is empty 
		return -1;//Dequeue fails
	}
	else{
		head=head->next;//Update the head pointer to the second node in the queue
		delete head->prev;//Deleate the first node
		head->prev=NULL;//Set "prev" of the new head node to NULL
	}
}

void IQueue::printHeadToTail(){
	
	int i=0;//Loop variable
	Node *curr=head;//Let curr start from the head of the queue
	while(curr!=NULL){//Loop continues as long as the end of the queue is not reached
		cout<<setw(4)<<curr->elem;
		i++;//Increment "i" by 1
		if(i%20==0) cout<<endl;//Changes lines after printing 20 elements
		curr=curr->next;//Update curr to the next node in the queue
	}
}

int IQueue::getSize(){
	Node *curr=head;//Let curr start from the head of the queue
	int cnt=0;//Initialize the number if nodes counted in the queue to 0
	
	while(curr!=NULL){//Loop continues as long as the end of the queue is not reached
		cnt++;//Increment "cnt" by 1
		curr=curr->next;//Update curr to the next node in the queue
	}
	return cnt;
}


int IQueue::headElem(){
	if(head==NULL) return -1;
	else return head->elem;
}

bool IQueue::isEmpty(){
	if(head==NULL) return true;
	else return false;
}

Node* IQueue::getHead(){
	return head;
}

Node* IQueue::getTail(){
	return tail;
}
