#include <iostream>
#include "IQueue_D1228803.h" 

// ***** Complete the following constructor and functions.

// Default constructor.
IQueue::IQueue() 
{
	head = NULL;
	tail = NULL;
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) 
{
	Node *newNode = new Node(e);
	
	if(tail)
	{
		tail->next = newNode;
		newNode->prev = tail;
		newNode = tail;
	}
	else
	{
		head = newNode = tail;
	}
	
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() 
{
	if(head)
	{
		
		//Node *nodeDeleteFromHead = head->elem;
		Node *nodeDeleteFromHead = head;
		int e = head->next;
		
		if(head)
		{
			head->prev = NULL;
		}
		else
		{
			tail = NULL;
		}
		delete(nodeDeleteFromHead);
		return e;
	}
	else
	{
		return -1;
	}
	
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() 
{
	return head == NULL;
}

// Clear queue.		
void IQueue::clear() 
{
	for(Node *current = head; current; current = current->next)
	{
		std::cout<<current->elem<<" ";
	}
	std::cout<<std::endl;
}


