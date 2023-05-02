#include <iostream>
//#include "Node.h" 
#include "IStack.h" 

// Default constructor.
IStack::IStack() {
	head = NULL; // The stack is empty.
}

// Push operation.
void IStack::push(int e) {
	Node *newNode;
	
	newNode = new Node(e); // Store the data element of the new node.
	newNode->next = head; // Store the next link of the new node.
	head = newNode; // Update head, i.e., top of the stack.
}

// Pop operation.
int IStack::pop() {
	int e = head->elem; // Get the data element of the top.
	Node *temp = head;  // Temporary head.
	if (temp!=NULL) { // If stack is not empty.
		head = head->next; // Update head, i.e., top of the stack.
		delete(temp); // Free the old head node.
		return e; // Reutrn the popped data element.
	}
	else return -1; // The stack is empty. Pop fails.
}
	
// Check top element of the stack.	
int IStack::top() {
	if (head!=NULL) return head->elem; // If stack is not empty, return the top data element.
	else return -1; // The stack is empty. No top element is returned.
}
	
// Check whether the stack is empty.	
bool IStack::isEmpty() {
	return head==NULL; // If empty, returns true.
}

// Get the size of the stack.
int IStack::getSize() {
	Node *current = head; // Current node pointer.
	int cnt = 0; // Initial count is 0.
	
	while (current!=NULL) { // Repeate until the NULL pointer.
		current = current->next; // Get pointer of the next node.
		cnt++; // Increment size by 1.
	}
	return cnt; // Return the size of the stack.
}

// Get the head pointer of the stack, i.e., the top pointer.
Node *IStack::getHead() {
	return head;
}

// Print the stack from top to bottom.
void IStack::printTopToBottom() {
	Node *current = head; // Pointer to the current node.
	int cnt = 0; // Node count.
	while (current!=NULL) { // Repeat until the current is NULL>
		printf(" %3d", current->elem); // Print the data element of the current node.
		current = current->next; // Get the next node.
		if((++cnt%20)==0) printf("\n"); // If print 20 nodes, print a new line.
	}
	if (cnt%20!=0) printf("\n"); // If the last line is less than 20 nodes, print a new line.
	
}
