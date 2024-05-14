#include "Node_D1175125.h"

class IQueue {
	private:
		Node* front;
		Node* rear;
	public:
		IQueue();
		
		~IQueue();
		
		bool isEmpty();
			
		void enqueue(int value);
		
		int dequeue();
		
		int clear(); 
};
