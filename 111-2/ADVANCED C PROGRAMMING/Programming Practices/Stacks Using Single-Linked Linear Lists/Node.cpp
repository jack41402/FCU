#include <cstdlib>
#include "Node.h" 

// Default constructor.
Node::Node() {
	elem = 0;
	next = NULL;
}
		
// Constructor with data element.
Node::Node(int e) {
	elem = e;
	next = NULL;
}
