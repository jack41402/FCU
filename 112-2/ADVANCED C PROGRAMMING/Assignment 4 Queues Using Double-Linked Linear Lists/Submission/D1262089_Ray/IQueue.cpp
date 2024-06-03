#include "IQueue.h"
#include <iostream>
#include <iomanip>
IQueue::IQueue() : head(NULL), tail(NULL) {}

void IQueue::enqueue(int val) {
    Node *newNode = new Node(val);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}



int IQueue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }
    int val = head->elem;
    Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    delete temp;
    return val;
}


int IQueue::headElem() {
    if (isEmpty()) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }
    return head->elem;
}

bool IQueue::isEmpty() {
    return head == NULL;
}

int IQueue::getSize() {
    int size = 0;
    Node *curr = head;
    while (curr != NULL) {
        size++;
        curr = curr->next;
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
    Node *curr = head;
    int count=1;
    while (curr != NULL) {
        std::cout << std::setw(2) << std::setfill(' ') << curr->elem << " ";
        if (count % 20 == 0)
            std::cout << std::endl;
        curr = curr->next;
        count++;
    }
    std::cout << std::endl;
} 

