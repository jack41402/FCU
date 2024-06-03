#ifndef IQUEUE_H
#define IQUEUE_H

#include "Node.h"

class IQueue {
public:
    Node* front;
    Node* rear;
    int size;
	
	IQueue();
    void enqueue(int val);
    int dequeue();
    bool isEmpty() const;
    int getSize() const;
    void display() const;
};

#endif
