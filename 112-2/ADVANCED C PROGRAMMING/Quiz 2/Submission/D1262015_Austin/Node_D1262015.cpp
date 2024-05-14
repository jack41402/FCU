#include <cstdlib>
#include "Node_D1262015.h" 

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	elem = 0;
	next = NULL;
	prev = NULL;
}
		
// Constructor with data element.
Node::Node(int e) {
	elem = e;
	next = NULL;
	prev = NULL;
}
