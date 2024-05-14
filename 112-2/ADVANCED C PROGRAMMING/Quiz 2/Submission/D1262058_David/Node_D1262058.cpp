#include <cstdlib>
#include "Node_D1262058.h" 

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	elem = 0; // Data of a node.
	prev = NULL; // Link of the previous node. 
	next = NULL;
}
		
// Constructor with data element.
Node::Node(int e) {
	elem = e; // Data of a node.
	prev = NULL; // Link of the previous node. 
	next = NULL;
}
