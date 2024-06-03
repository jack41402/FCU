#include "Node.h"
#include <cstdlib>

Node::Node(){//default constructor
	elem = 0;
	prev = NULL;
	next = NULL;	
}

Node::Node(int e){//constructor with data element
	elem = e;
	prev = NULL;
	next = NULL;
}
