#include "Node_D1271403.h" 
class IQueue {
	private:
		Node *head;  
		Node *tail; 
		
	public:
		IQueue();
		
		void enqueue(int);
		
		int dequeue(); 
		
		bool isEmpty();
		
		void clear();
}; 
