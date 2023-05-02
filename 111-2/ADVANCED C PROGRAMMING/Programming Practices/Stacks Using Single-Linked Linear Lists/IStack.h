#include "Node.h" 
// Integer Stack Class
class IStack {
	private:
		Node *head; // Point to top of the stack. 
		
	public:
		IStack(); // Default constructor.
		
		void push(int); // Push operation.
		
		int pop(); // Pop operation.
		
		int top(); // Check top element of the stack.
		
		bool isEmpty(); // Check whether the stack is empty.
		
		int getSize(); // Get the size of the stack.
		
		Node *getHead(); // Get the head pointer of the stack, i.e., the top pointer.
		
		void printTopToBottom(); // Print the stack from top to bottom.
}; 
