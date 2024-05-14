#include "Node_D1228817.h" 
// Integer Queue Class
class IQueue {
	private:
		Node *head; // Point to head of the queue. 
		Node *tail; // Point to tail of the queue. 
		
	public:
		IQueue(); // Default constructor.
		
		void enqueue(int); // Enqueue operation.
		
		int dequeue(); // Dequeue operation.
		
		bool isEmpty(); // Check whether the queue is empty.
		
		void clear(); // Clear queue.
}; 
