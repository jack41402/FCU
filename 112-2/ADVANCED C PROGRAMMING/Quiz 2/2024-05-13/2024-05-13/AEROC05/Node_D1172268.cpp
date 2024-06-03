#include <cstdlib>
#include "Node_D1172268.h"

// ***** Complete the following constructors.

// Default constructor.
Node::Node() {
	this-> elem = 0;
	this-> next = NULL;
	this-> prev = NULL;
}
		
// Constructor with data element.
Node::Node(int e) {
	this-> elem = e;
	this-> next = NULL;
	this-> prev = NULL;
}
