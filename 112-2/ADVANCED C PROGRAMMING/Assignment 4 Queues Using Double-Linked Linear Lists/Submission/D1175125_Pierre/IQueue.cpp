#include "Node.hpp" // Include Node.h directly
#include "IQueue.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor for Queue
Queue::Queue() : front(NULL), rear(NULL), size(0) {}
// Enqueue operation
void Queue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

void Queue::displayAfterEnqueue() {
    Node* current = front;

    cout << "Current queue size: " << size << ". Content of queue from head to tail: "<<endl;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
// Dequeue operation
int Queue::dequeue() {
    if (isEmpty()) {
        cerr << "Queue is empty!" << endl<<endl;
        return -1; // Error value
    }
    int val = front->data;
    Node* temp = front;
    if (front == rear) {
           front = NULL;
           rear = NULL;
       } else {
           front = front->next;
           front->prev = NULL;
       }

       delete temp;
       size--;
    return val;
}

// Display the queue
void Queue::display() {
    Node* current = front;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Current queue size: " << size << ". Content of queue from head to tail: "<<endl<<endl;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return size == 0;
}

// Get current size of the queue
int Queue::getSize() {
    return size;
}
