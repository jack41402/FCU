#include "Node.h"

// Integer Queue Class
class IQueue
{
    private:
        Node *head ; // Point to front of the queue.
        Node *tail ; // Point to back of the queue.

    public:
        IQueue() ; // Default constructor.
        void push(int) ; // Push operation.
        int pop() ; // Pop operation.
        int front() ; // Check front element of the queue.
        int back() ; // Check back element of the queue.
        bool isEmpty() ; // Check whether the queue is empty.
        int getSize() ; // Get the size of the queue.
        Node *getHead() ; // Get the head pointer of the queue, i.e., the front pointer.
        Node *getTail() ; // Get the tail pointer of the queue, i.e., the back pointer.
        void printHeadToTail() ; // Print the queue from head to tail.
} ;
