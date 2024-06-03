#include <cstdlib>
#include "Node_D1262075.h" 

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	
}
		
// Constructor with data element.
Node::Node(int e) {
	elem = e;
	elem ->prev = NULL;
	elem->next = NULL;
}
