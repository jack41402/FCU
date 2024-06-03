#include <iostream>
#include "Node.h" 
Node::Node(){
	elem = 0;
	prev = NULL;
	next = NULL;
}//Initialize the Node.
Node::Node(int e){
	elem = e;
	prev = NULL;
	next = NULL;
}//Initialize the Node().
