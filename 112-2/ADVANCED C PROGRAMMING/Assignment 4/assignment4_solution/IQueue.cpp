#include <iostream>
#include "IQueue.h" 

// Default constructor.
IQueue::IQueue() {
	head = NULL; // The queue is empty.
	tail = NULL; // The queue is empty.
}

// Enqueue operation. Insert to tail.
void IQueue::enqueue(int e) {
	Node *newNode;
	
	newNode = new Node(e); // Store the data element of the new node.	
	if (head==NULL && tail==NULL) { // The first node is enqueued. 
		newNode->prev = NULL; // Only one node in the queue, no previous node.
		newNode->next = NULL; // No next node.
		head = newNode; // Head points to the first node.
		tail = newNode; // Tail points to the first node. 
	}
	else {
		newNode->prev = tail; // The original tail becomes previous of the new tail.
		newNode->next = NULL; // No next node of the tail node.
		tail->next = newNode; // Update the next pointer of the original tail.
		tail = newNode; // Update the tail of the queue.
	}
}

// Dequeue operation. Delete from head..
int IQueue::dequeue() {
	int e = head->elem; // Get the data element of the head.
	Node *temp = head;  // Temporary head.
	if (temp!=NULL) { // If stack is not empty.
		head = head->next; // Update head, i.e., top of the stack.
		if (head==NULL) tail = NULL; // If the queue has only one node, it becomes after dequeue.
		delete(temp); // Free the old head node.
		return e; // Reutrn the popped data element.
	}
	else return -1; // The queue is empty. Dequeue fails.
}
	
// Check head element of the queue.	
int IQueue::headElem() {
	if (head!=NULL) return head->elem; // If queue is not empty, return the head data element.
	else return -1; // The queue is empty. No head element is returned.
}
	
// Check whether the queue is empty.	
bool IQueue::isEmpty() {
	return head==NULL; // If empty, returns true.
}

// Get the size of the stack.
int IQueue::getSize() {
	Node *current = head; // Current node pointer.
	int cnt = 0; // Initial count is 0.
	
	while (current!=NULL) { // Repeate until the NULL pointer.
		current = current->next; // Get pointer of the next node.
		cnt++; // Increment size by 1.
	}
	return cnt; // Return the size of the stack.
}

// Get the head pointer of the stack, i.e., the top pointer.
Node *IQueue::getHead() {
	return head;
}

// Print the queue from head to tail.
void IQueue::printHeadToTail() {
	Node *current = head; // Pointer to the current node.
	int cnt = 0; // Node count.
	while (current!=NULL) { // Repeat until the current is NULL.
		printf(" %3d", current->elem); // Print the data element of the current node.
		current = current->next; // Get the next node.
		if((++cnt%20)==0) printf("\n"); // If print 20 nodes, print a new line.
	}
	if (cnt%20!=0) printf("\n"); // If the last line is less than 20 nodes, print a new line.
}
