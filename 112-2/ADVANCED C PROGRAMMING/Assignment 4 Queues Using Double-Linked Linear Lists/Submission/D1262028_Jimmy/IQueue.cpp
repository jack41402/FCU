#include "IQueue.h"
#include <iostream>
#include <iomanip> // Include for std::setw
#include <cstddef> // Include for NULL definition

void IQueue::enqueue(int e) {
    Node* newNode = new Node(e);
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
        std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }
    int retValue = head->elem;
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
    size--;
    return retValue;
}

int IQueue::headElem() {
    if (!isEmpty()) {
        return head->elem;
    }
    std::cerr << "Queue is empty!" << std::endl;
    return -1;
}

bool IQueue::isEmpty() {
    return size == 0;
}

int IQueue::getSize() {
    return size;
}

void IQueue::printHeadToTail() {
    Node* current = head;
    int count = 0;  // Counter to track number of elements printed in a line

    std::cout << "  ";  // Start each line with two spaces
    while (current != NULL) {
        std::cout << std::setw(2) << current->elem;  // Print the element
        count++;
        if (count % 20 == 0) {
            std::cout << std::endl << "  ";  // Start a new line after every 20 elements
        } else {
            std::cout << "  ";  // Two spaces between elements
        }
        current = current->next;
    }
    if (count % 20 != 0) {  // Ensure not to add an extra newline if already at the end of a line
        std::cout << std::endl;
    }
    delete current;
}
