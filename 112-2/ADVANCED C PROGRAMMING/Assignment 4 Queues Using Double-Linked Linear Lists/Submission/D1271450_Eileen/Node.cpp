#include "Node.h"
#include<iostream>
#include<iomanip>
Node::Node() {//default constructor
    elem = 0;
    prev = NULL;
    next = NULL;
}
Node::Node(int data) {//constructor with data element
    elem = data;
    prev = NULL;
    next = NULL;
}

