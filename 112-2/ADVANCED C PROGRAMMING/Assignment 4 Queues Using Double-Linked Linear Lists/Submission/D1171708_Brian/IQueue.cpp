#include <iostream>
#include <iomanip>
#include "IQueue.h"
using namespace std;

IQueue::IQueue() {
    head = nullptr;
    tail = nullptr;
}

void IQueue::enqueue(int e) {
    Node *newNode = new Node(e); //c++ malloc
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int IQueue::dequeue() {
    if (isEmpty()) {
        return 0; // no queue
    } else {
        int value = head->elem;
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp; //  c++ free.
        return value;
    }
}

int IQueue::headElem() {
    if (isEmpty()) {
        return 0;
    } else {
        return head->elem;
    }
}

bool IQueue::isEmpty() {
    return head == nullptr;
}

int IQueue::getSize() {
    int size = 0;
    Node *current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

Node *IQueue::getHead() {
    return head;
}

Node *IQueue::getTail() {
    return tail;
}

void IQueue::printHeadToTail() {
    Node *current = head;
    int count = 0;
    while (current != nullptr) {
    	count = count + 1;
        cout << setw(3) <<current->elem <<"  ";
        if(count%20==0){
        	cout << endl; 
		}
        current = current->next;
        
    }
    cout <<endl;
}

