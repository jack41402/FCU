#include <cstdlib>
#include "Node_D1265065.h" 

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	elem = NULL;
	prev = NULL;
	next = NULL;
}
		
// Constructor with data element.
Node::Node(int e) {
	elem = e;
	prev = NULL;
	next = NULL;
}