#include <cstdlib>
#include "Node_D1175125.h" 

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	data=0;
	next = NULL;
	prev = NULL;
}
		
// Constructor with data element.
Node::Node(int e) {
	data = e;
	next = NULL;
	prev = NULL;
}
