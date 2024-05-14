#include <cstdlib>
#include "Node_D1228817.h" 

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	prev=NULL;
	next=NULL;
}
		
// Constructor with data element.
Node::Node(int e) {
	prev=NULL;
	next=NULL;
	elem=e;
}
