#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val);
};

#endif /* Node_hpp */
