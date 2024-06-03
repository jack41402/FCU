#include "Node.h"
#include <iostream> 
Node::Node(){
	elem = 0;
    prev = nullptr;
    next = nullptr;
}

Node::Node(int e){
	elem = e;
    prev = nullptr;
    next = nullptr;
}
