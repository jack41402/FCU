#ifndef IQUEUE_H
#define IQUEUE_H

#include "Node.h"
#include <cstddef> // for NULL

class IQueue {
private:
    Node *head; // Pointer to the head node
    Node *tail; // Pointer to the tail node
    int size; // Size of the queue

public:
    IQueue() : head(NULL), tail(NULL), size(0) {} // Constructor

    void enqueue(int e);
    int dequeue();
    int headElem();
    bool isEmpty();
    int getSize();
    void printHeadToTail();
};

#endif
