#include <iostream>
#include <cstdlib>
#include "IQueue.h"
using namespace std;

IQueue::IQueue(){ head=NULL; tail=NULL; };

//Execute enqueue operation
int IQueue::enqueue(int a) {
    Node* current = head;
    Node* previous = tail;
    Node* newNode;
  int r=0;
    
    //Check if the queue is empty
    if (current==NULL) {
        
        newNode = new Node(a);
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
        return r;
        
    }
    
    //If the queue is not empty, the new node is inserted at the end.
    else{
        newNode = new Node(a);
        newNode->prev = previous;
        previous->next = newNode;
        newNode->next = current;
        current->prev = newNode;
        tail = newNode;
        return r;
    }
}

//Execute dequeue operation
int IQueue::dequeue() {
    Node* current = head;
    Node* previous = tail;
    
    if (current==NULL) {
        
        return -1;
        
    }
    
    if (current->next == current){
        head = NULL;
        tail = NULL;
    }
    else{
        previous->next = current->next;
        current->next->prev = previous;
        head = current->next;
    }
    delete current;
    return 0;
}

//Count the number of elements in the queue
int IQueue::getSize() {
    Node* current = head;
    int size = 0;
    
    if (current==NULL) {
        return size;
    }
    
    do {
        size++;
        current = current->next;
    } while (current!=head);
    
    return size;
}

//print out the result
void IQueue::printHeadToTail() {
    
    cout<<"Current queue size: "<<getSize()<<". Content of queue from head to tail:"<<endl;
    
    Node* current = head;
    int position = 0;
    
    if (current!=NULL) {
        
        while (current->next!=head) {
            
            cout.width(4);
            cout<<current->elem;
            if ((position+1)%20==0){ cout<<endl;}
            current = current->next;
            position++;
            
        }
        cout.width(4);
        cout<<current->elem<<endl;
    }
}

