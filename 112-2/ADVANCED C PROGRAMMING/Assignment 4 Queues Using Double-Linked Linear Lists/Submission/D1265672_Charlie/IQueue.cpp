#include "IQueue.h"
#include <iostream>
#include <iomanip>

IQueue::IQueue() : front(NULL), rear(NULL), size(0) {}

void IQueue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    size++;
}

int IQueue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty" << std::endl;
        return -1;
    }
    int ret = front->data;
    Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }
    delete temp;
    size--;
}

bool IQueue::isEmpty() const {
    return size == 0;
}

int IQueue::getSize() const {
    return size;
}

void IQueue::display() const {
    Node* current = front;
    int i = 0;
    while (current != NULL) {
    	if (i % 20 == 0){
    		std::cout << std::endl;
		}
        std::cout << std::setw(4) << current->data;
        current = current->next;
        i+=1;
    }
    std::cout << std::endl;
}
