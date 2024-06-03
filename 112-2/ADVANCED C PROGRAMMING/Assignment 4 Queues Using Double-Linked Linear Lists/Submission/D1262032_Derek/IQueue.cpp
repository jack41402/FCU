#include <iostream>
#include <cstdlib>
#include "IQueue.h"
using namespace std;

IQueue::IQueue(){ head=NULL; tail=NULL; };

int IQueue::enqueue(int e) {//enqueue operation
    Node* current = head;
    Node* previous = tail;
    Node* newNode;
  int position=0;
    
    if (current==NULL) {
        newNode = new Node(e);
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
        return position;
    }
    else{
        newNode = new Node(e);
        newNode->prev = previous;
        previous->next = newNode;
        newNode->next = current;
        current->prev = newNode;
        tail = newNode;
        return position;
    }
}

int IQueue::dequeue() {//dequeue operation
    Node* current = head;
    Node* previous = tail;
    if (current==NULL) return -1;
    if (current->next==current){
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

int IQueue::getSize() {
    Node* current = head;
    int size = 0;
    
    if (current==NULL) return size;
    do {
        size++;
        current = current->next;
    } while (current!=head);
    return size;
}

void IQueue::printHeadToTail() {
    Node* current = head;
    int position = 0;
    
    cout<<"Current queue size: "<<getSize()<<". Content of queue from head to tail:"<<endl;
    if (current!=NULL) {
        while (current->next!=head) {
            cout.width(4);
            cout<<current->elem;
            if ((position+1)%20==0){ cout<<endl; }
            current = current->next;
            position++;
        }
        cout.width(4);
        cout<<current->elem<<endl;
    }
}
