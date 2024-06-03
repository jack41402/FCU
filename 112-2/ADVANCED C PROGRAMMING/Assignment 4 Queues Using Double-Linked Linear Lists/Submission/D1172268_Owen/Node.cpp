#include "Node.h"
#include <cstdlib>

Node::Node(){
	this->elem = 0;//Set elem to 0 and prev and next to NULL.
	this->prev = NULL;
	this->next = NULL; 
}

Node::Node(int a){
	this->elem = a;//Set elem to the parameter value and prev and next to NULL.
	this->prev = NULL;
	this->next = NULL; 
}
