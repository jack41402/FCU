//
//  Node.cpp
//  Assignment_4_D1265065
//
//  Created by Corrine  on 2024/4/29.
//

#include "Node.h"

using namespace std;
// Default constructor for Node class
Node::Node() : elem(0), prev(NULL), next(NULL) {}// Initialize elem to 0 // Set prev and next pointers to nullptr
// Constructor with data element for Node class
Node::Node(int data) : elem(data), prev(NULL), next(NULL) {}// Set elem to the provided data // Set prev and next pointers to nullptr

