//IQueue.cpp
#include "IQueue.h"
#include <iostream>
#include <stdexcept> 

IQueue::IQueue() : head(NULL), tail(NULL) //initializing a queue data structure
{
    
}

//declares enqueue for IQueue class
void IQueue::enqueue(int value) 
{
    Node *newNode = new Node(value); //allocate dynamic memory for a new node
    if (tail) //checks if the tail pointer of the queue is pointing to a node
 	{
        tail->next = newNode; //link the new node to the end of the queue
        newNode->prev = tail; //sets prev node to point to the current tail node
        tail = newNode; //updates the last node in queue
    } 
 	else 
 	{
        head = tail = newNode; //set head and tail to the new node
    }
}

//declares dequeue for IQueue class,
int IQueue::dequeue() 
{
    if (head) //checks if the queue is empty
 	{
        Node *nodeToRemove = head; //temporary pointer nodeToRemove point to the current head node of the queue
        int value = head->elem; //take the value stored in the element of the current head node
        head = head->next; //updates head pointer point to the next node in the queue
        if (head) //checks if the new head node exists
  		{
            head->prev = NULL; //set previous to null
    	} 
  		else 
  		{
            tail = NULL; //set tail to null
        }
        
        delete nodeToRemove; //free the memory
        return value; // Return the value of the dequeued element
    }
    return -1; //indicate failure
}

int IQueue::headElem() //take the value of the element at the head of the queue
{
    if (head) //checks if the queue is empty
 	{
        return head->elem; // Return the value of the element at the head of the queue
    }
    return -1; //indicate failure
}

bool IQueue::isEmpty() //check if the queue is empty
{
    return head == NULL; //return true if the head pointer is null
}

//get the size of the queue
int IQueue::getSize() 
{
    int count = 0; //initialize counter
    for (Node *current = head; current; current = current->next) //go across the queue starting from the head
 	{
        ++count; //increase the count for each node
    }
    return count; //return the count, the size of the queue
}

Node *IQueue::getHead() //get a pointer to the head of the queue
{
    return head; //return the pointer to the head node
}

Node *IQueue::getTail() //get a pointer to the tail of the queue
{
    return tail; // Return the pointer to the htail node
}

void IQueue::printHeadToTail() //print the elements of the queue from head to tail
{
    for (Node *current = head; current; current = current->next) //go across the queue starting from the head
 	{
        std::cout << current->elem << " "; //print space
    }
    std::cout << std::endl;
}
