#include "Node.h"
// Integer Queue Class
class IQueue {
    private:
        Node *head; // Point to head of the queue.
        Node *tail; // Point to tail of the queue.
        
    public:
        IQueue(); // Default constructor.
        
        int enqueue(int); // Enqueue operation.
        
        int dequeue(); // Dequeue operation.

        int getSize(); // Get the size of the queue.
        
        void printHeadToTail(); // Print the queue from head to tail.
};

