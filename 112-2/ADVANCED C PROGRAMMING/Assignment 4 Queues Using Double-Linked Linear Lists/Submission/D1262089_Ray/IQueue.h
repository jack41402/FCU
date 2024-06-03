#include "Node.h" 
// Integer Queue Class
class IQueue {
	private:
		Node *head; // Point to head of the queue. 
		Node *tail; // Point to tail of the queue. 
		
	public:
		IQueue(); // Default constructor.
		
		void enqueue(int); // Enqueue operation.
		
		int dequeue(); // Dequeue operation.
		
		int headElem(); // Check head element of the queue.
		
		bool isEmpty(); // Check whether the queue is empty.
		
		int getSize(); // Get the size of the queue.
		
		Node *getHead(); // Get the head pointer of the queue.
		
		Node *getTail(); // Get the tail pointer of the queue.
		
		void printHeadToTail(); // Print the queue from head to tail.
}; 


