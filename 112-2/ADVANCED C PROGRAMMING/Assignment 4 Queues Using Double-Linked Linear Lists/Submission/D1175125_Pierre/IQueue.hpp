#ifndef IQueue_hpp
#define IQueue_hpp

#include <stdio.h>

struct Node;

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue();
    void displayAfterEnqueue();
    void enqueue(int val);
    int dequeue();
    void display();
    bool isEmpty();
    int getSize();
};

#endif /* IQueue_hpp */
