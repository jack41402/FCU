#ifndef IQUEUE_H
#define IQUEUE_H

#include "Node.h"

class IQueue {
	private:
		Node *head; // Point to head of the queue. 
		Node *tail; // Point to tail of the queue. 
public:
    int size;
	
	IQueue();
    void enqueue(int);
    int dequeue();
    int headElem(); // Check head element of the queue.
    bool isEmpty() const;
    int getSize() const;
    Node *getHead(); // Get the head pointer of the queue.
	Node *getTail(); // Get the tail pointer of the queue.
    void printHeadToTail() const;
};

#endif
