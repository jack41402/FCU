#include "IQueue.h"
#include<iostream>
#include<iomanip>
IQueue::IQueue() {//default constructor
    head = NULL;//initialize head pointer as NULL
    tail = NULL;//initialize tail pointer as NULL
}
void IQueue::enqueue(int data) {//enqueue operation
    Node *newNode = new Node(data);//create a new node
    if (isEmpty()) {//check if the queue is empty
        head = newNode;//set head to new node
        tail = newNode;//set tail to new node
    } else {//if not
        tail->next = newNode;//set the current tail's next node is the new node
        newNode->prev = tail;//set the new node's previous as tail
        tail = newNode;//update new node as tail
    }
}
int IQueue::dequeue() {//dequeue operation
    if (isEmpty()) {//check if the queue is empty
        throw "queue is empty";//throw an exception if the queue is empty
    }
    int data = head->elem;
    Node *temp = head;//store head in temporary 
    head = head->next;//move head to the next node
    if (head != NULL) {//if head node is not empty
        head->prev = NULL;//update the previous of head to NULL
    } 
	else {//else, update tail to NULl
        tail = NULL;
    }
    delete temp;//delete the old head node
    return data;
}
int IQueue::headElem() {//check the head element
    if (isEmpty()) {//check if the queue is empty
        throw "queue is empty";//throw an exception if the queue is empty
    }
    return head->elem;//return head element
}
bool IQueue::isEmpty() {//check if the queue is empty
    return head == NULL;//returns true if head is NULL
}
int IQueue::getSize() {//get the size of the queue
    int size = 0;
    Node *current = head;//start at the head
    while (current != NULL) {//while the current is not NULL 
        size++;//enlarge size
        current = current->next;//move to the next node
    }
    return size;//return size
}
Node *IQueue::getHead() {//get the head pointer
    return head;//return the head pointer of the queue
}
Node *IQueue::getTail() {//get the tail pointer
    return tail;//return the tail pointer of the queue
}
void IQueue::printHeadToTail() {//print the queue from head to tail
    Node *current = head;//start at the head
    while (current != NULL) {//while the current is not NULL 
        std::cout << current->elem << " ";//print out the current element
        current = current->next;//move to the next node
    }
    std::cout << std::endl;//print new line
}

