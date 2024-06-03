#include <cstdlib>
#include "Node_D1265154.h" 

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	prev=NULL;
	next=NULL;
	elem=' ';
}
		
// Constructor with data element.
Node::Node(int e) {
	prev=NULL;
	next=NULL;
	elem=e;
}
