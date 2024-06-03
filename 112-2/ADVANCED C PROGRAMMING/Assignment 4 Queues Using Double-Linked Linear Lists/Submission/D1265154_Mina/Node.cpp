#include <iostream>
#include "Node.h" 

// Definition of the default constructor for the Node class.
Node::Node()
{
	next = NULL;// Initialize the next pointer to NULL.
	prev = NULL;// Initialize the prev pointer to NULL.
	elem = 0;// Initialize the elem data member to 0.
}

// Definition of the constructor for the Node class with an integer parameter.
Node::Node(int elem)
{
	next = NULL;// Initialize the next pointer to NULL.
	prev = NULL;// Initialize the prev pointer to NULL.
	this->elem = elem;// Assign the value of the parameter elem to the elem data member.
}

