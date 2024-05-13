// Specify the class of character stack, CStack, using single-linked linear list.
// CStack needs to implement a constructor and four member functions: 
// void push(char), char pop(), char top(), and bool isEmpty(). 

#include "Node_D1166506.h"

class CStack
{
	public :
		CStack() ;
		void push(char) ;
		char pop() ;
		char top() ;
		bool isEmpty() ;
	private :
		Node *head ;
};
