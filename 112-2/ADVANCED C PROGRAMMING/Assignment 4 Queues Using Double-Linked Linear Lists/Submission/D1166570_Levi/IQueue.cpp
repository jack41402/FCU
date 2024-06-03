#include <iostream>
#include "IQueue.h"
using namespace std;
IQueue::IQueue() :head(nullptr), tail(nullptr) {}
void IQueue::enqueue(int elem) {
	Node* newNode = new Node(elem);
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}
int IQueue::dequeue() {
    if (isEmpty()) {
        cout << "The queue is empty, cannot exit the queue!" << endl;
        return -1;  
    }

    int dequeuedElem = head->elem;
    Node* temp = head;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    return dequeuedElem;
}
int IQueue::headElem() {
    if (isEmpty()) {
        cout << "Queue is empty, cannot get header element!" << endl;
        return -1;  
    }

    return head->elem;
}
bool IQueue::isEmpty() {
    if (head == nullptr && tail == nullptr) return 1;
    else return 0;
}
int IQueue::getSize() {
    if(head == nullptr && tail == nullptr) return 0;
    else {
        Node *temp = head;
        int size = 1;
        while (temp != tail) {
            size++;
            temp = temp->next;
        }
        return size;
    }
}
Node* IQueue::getHead() {
    return head;
}

Node* IQueue::getTail() {
    return tail;
}
void IQueue::printHeadToTail() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << " " << temp->elem;
            temp = temp->next;
    }

    cout << endl;
}
