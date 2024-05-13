// Implement the class of character stack, CStack, using single-linked linear list.
// CStack needs to implement a constructor and four member functions: 
// void push(char), char pop(), char top(), and bool isEmpty(). 
#include <iostream>
#include <cstdlib>
#include "CStack_D1166506.h"

CStack::CStack ()
{
	head = NULL ;
}

void CStack::push(char ch)
{
	Node *node=(Node*) malloc(sizeof(Node)) ;
	node->next = NULL ;
	node->data = ch ;
//	std::cout << node->data << '\n' ;
	if (this->isEmpty())
	{
		head = node ;
		return ;
	}
	Node *temp=head ;
	while (temp!=NULL)
	{
		if (temp->next==NULL)
		{
			temp->next = node ;
			return ;
		}
		temp = temp->next ;
	}
}

char CStack::pop()
{
	Node *temp=head ;
	char ch ;
	while (temp!=NULL)
	{
		if (temp->next==NULL)
		{	
			char ch = temp->data ;
			if (temp==head)	head = NULL ;
			free(temp) ;
			return ch ;
		}
		temp = temp->next ;
	}
}

char CStack::top()
{
	Node *temp=head ;
	while (temp!=NULL)
	{
		if (temp->next==NULL)
		{
			return temp->data ;
		}
		temp = temp->next ;
	}
}

bool CStack::isEmpty()
{
	return (head==NULL);
}

