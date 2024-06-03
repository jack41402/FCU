#include <iostream>
#include <iomanip>
#include "IQueue.h"

using namespace std;// Using the standard namespace for convenience.

// Constructor for the IQueue class.
IQueue::IQueue(){
	head = NULL;// Initialize the head pointer to NULL.
	tail = NULL;// Initialize the tail pointer to NULL.
}

// Enqueues an element into the queue.
void IQueue::enqueue(int elem){
	Node *newNode, *current; // Pointers for the new node and traversal.
	// If the queue is empty (head is NULL), create a new node and set it as both head and tail.
	if(head == NULL){
		newNode = new Node(elem);  // Allocate memory for a new Node object and initialize its elem with the given value.
		head = newNode; // Set the new node as the head.
		tail = newNode; // Set the new node as the tail.
		return; // End the function.
	}
	else{ // If the queue is not empty.
		current = tail; // Set current to the current tail node.
		newNode = new Node(elem); // Create a new node with the given element.
		current->next = newNode; // Set the next pointer of the current tail node to the new node.
		tail = newNode; // Set the new node as the new tail.
		newNode->prev = current; // Set the previous pointer of the new node to the current tail node.
		return; // End the function.
	}
}


// Removes and returns the element at the front of the queue.
int IQueue::dequeue(){
	Node *current;
	// If the queue is empty (head is NULL), return 0 indicating failure to dequeue.
	if(head == NULL){
		return 0;
	}
	else{ // If the queue is not empty.
		current = head; // Set current to the head node.
		head = current->next;// Move head pointer to the next node.
		if (head != NULL)
			head->prev = NULL;// Update the previous pointer of the new head node to NULL.
		delete current;// Deallocate memory for the old head node.
		return 1;// Return 1 indicating successful dequeue.
	}
}

// Returns the element stored in the head node of the queue.
int IQueue::headElem(){
	return head->elem; // Return the elem member of the node pointed to by head.
}


// Checks if the queue is empty.
bool IQueue::isEmpty(){
	return head == NULL; // Returns true if head pointer is NULL, indicating an empty queue; otherwise, returns false.
}


// Returns the current size of the queue.
int IQueue::getSize(){
	Node *current; // Pointer for traversal.
	int size = 0; // Variable to store the size of the queue.
	// If the queue is empty (head is NULL), return size 0.
	if(head == NULL)
		return 0;
	else{
		current = head; // Set current to the head node.
		// Traverse the queue and count the number of nodes until the end.
		while(current->next != NULL){
			size++; // Increment size for each node visited.
			current = current->next; // Move to the next node.
		}
		size++;// Increment size for the last node.
		return size;// Return the size of the queue.
	}
}

 

// Returns the head pointer of the queue.
Node* IQueue::getHead(){
	return head;
}

// Returns the tail pointer of the queue.
Node* IQueue::getTail(){
	return tail;
}

// Prints the elements of the queue from head to tail.
void IQueue::printHeadToTail(){
	Node *current; // Pointer to traverse the queue.
	int i;
	// If the queue is empty, return without printing.
	if(head == NULL){
		return;
	}
	else{
		current = head; // Initialize current to the head of the queue.
		for(i=1; i <= getSize(); i++){	
			cout << setw(4) << current->elem; // Print the element of the current node.
			current = current->next; // Move to the next node.
			if(i % 20 == 0) cout << endl; // Add newline every 20 elements for better readability.
		}
	}
}

