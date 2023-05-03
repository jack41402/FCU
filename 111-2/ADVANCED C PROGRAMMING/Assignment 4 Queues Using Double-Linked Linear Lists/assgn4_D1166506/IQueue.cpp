#include <iostream>
#include <cstdlib>
#include "IQueue.h"

IQueue::IQueue ()
{
    head = NULL ;
    tail = NULL ;
}

void IQueue::push (int e)
{
    Node *NewNode ;
    NewNode = new Node(e) ;
    if (tail==NULL)
    {
        NewNode->prev = NULL ;
        NewNode->next = NULL ;
        head = NewNode ;
        tail = NewNode ;
    }
    else
    {
        NewNode->prev = tail ;
        NewNode->next = NULL ;
        tail->next = NewNode ;
        tail = NewNode ;
    }
}

int IQueue::pop ()
{
    if (head==NULL) return -1;
    else
    {
        int e=head->elem ;
        Node *temp=head ;
        head = head->next ;
        delete(temp) ;
        return e;
    }
}

int IQueue::front ()
{
    if (head!=NULL) return head->elem;
    else return -1;
}

int IQueue::back ()
{
    if (tail!=NULL) return tail->elem;
    else return -1;
}

bool IQueue::isEmpty ()
{
    return (head==NULL);
}

int IQueue::getSize ()
{
    if (head==NULL) return 0;
    else
    {
        int count=0 ;
        Node *temp=head ;
        while (temp!=NULL)
        {
            count++ ;
            temp = temp->next ;
        }
        return count;
    }
}

Node *IQueue::getHead ()
{
    return head;
}

Node *IQueue::getTail ()
{
    return tail;
}

void IQueue::printHeadToTail ()
{
    int count=0 ;
    Node *current=head ;
    while (current!=NULL)
    {
        printf(" %3d" , current->elem) ;
        current = current->next ;
        if (++count%20==0) printf("\n") ;
    }
    if (count%20!=0) printf("\n") ;
}