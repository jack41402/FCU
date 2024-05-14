#include <cstdlib>
#include "Node_D1262032.h" 

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	elem=0; prev=NULL; next=NULL;
}
		
// Constructor with data element.
Node::Node(int e) {
	elem=e; prev=NULL; next=NULL;
}
