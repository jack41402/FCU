#include "IQueue.h"
#include <iostream>
#include <iomanip>

IQueue::IQueue() : head(NULL), tail(NULL), size(0) {}

void IQueue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

int IQueue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty" << std::endl;
        return -1;
    }
    int ret = head->elem;
    Node* temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    } else {
        head->prev = NULL;
    }
    delete temp;
    size--;
}

int IQueue::headElem() {
    if (isEmpty()) {
        return -1;
    }
    return head->elem;
}

bool IQueue::isEmpty() const {
    return size == 0;
}

int IQueue::getSize() const {
    return size;
}

Node* IQueue::getHead() {
    return head;
}

Node* IQueue::getTail() {
    return tail;
}

void IQueue::printHeadToTail() const {
    Node* current = head;
    int i = 0;
    while (current != NULL) {
    	if (i % 20 == 0){
    		std::cout << std::endl;
		}
        std::cout << std::setw(4) << current->elem;
        current = current->next;
        i+=1;
    }
    std::cout << std::endl;
}
