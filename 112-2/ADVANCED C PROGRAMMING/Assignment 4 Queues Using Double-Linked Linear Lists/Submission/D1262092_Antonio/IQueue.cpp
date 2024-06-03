#include <iostream>
#include "IQueue.h"
#include <time.h>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Constructor for the IQueue class
IQueue::IQueue(){
    head = NULL; // Initialize head pointer to NULL
    tail = NULL; // Initialize tail pointer to NULL
}

// Function to enqueue an element into the queue
void IQueue::enqueue(int value) {
    Node* newNode = new Node(value); // Create a new node with the given value
    if (isEmpty()) { // If the queue is empty
        head = tail = newNode; // Set both head and tail pointers to the new node
    } else {
        tail->next = newNode; // Link the current tail node to the new node
        newNode->prev = tail; // Set the previous pointer of the new node to the current tail node
        tail = newNode; // Update the tail pointer to the new node
    }
}

// Function to dequeue an element from the queue
int IQueue::dequeue() {
    if (isEmpty()) { // If the queue is empty
        throw std::runtime_error("Queue is empty"); // Throw a runtime error
    }
    int value = head->elem; // Get the value of the head node
    Node* temp = head; // Store the pointer to the head node in a temporary variable
    head = head->next; // Move the head pointer to the next node
    if (head) { // If the new head is not NULL
        head->prev = NULL; // Set the previous pointer of the new head to NULL
    } else {
        tail = NULL; // If the queue becomes empty after dequeue, set tail to NULL
    }
    delete temp; // Delete the old head node
    return value; // Return the dequeued value
}

// Function to get the element at the head of the queue without removing it
int IQueue::headElem() {
    if (isEmpty()) { // If the queue is empty
        throw std::runtime_error("Queue is empty"); // Throw a runtime error
    }
    return head->elem; // Return the value of the head node
}

// Function to check if the queue is empty
bool IQueue::isEmpty() {
    return head == NULL; // Return true if head is NULL, indicating an empty queue
}

// Function to get the size of the queue
int IQueue::getSize() {
    int size = 0; // Initialize size counter to 0
    Node* temp = head; // Start from the head node
    while (temp) { // Loop until temp becomes NULL
        size++; // Increment size counter
        temp = temp->next; // Move to the next node
    }
    return size; // Return the size of the queue
}

// Function to get a pointer to the head of the queue
Node* IQueue::getHead() {
    return head; // Return the head pointer
}

// Function to get a pointer to the tail of the queue
Node* IQueue::getTail() {
    return tail; // Return the tail pointer
}

// Function to print the elements of the queue from head to tail
void IQueue::printHeadToTail() {
    Node* temp = head; // Start from the head node
    while (temp) { // Loop until temp becomes NULL
        std::cout << temp->elem << " "; // Print the value of the current node
        temp = temp->next; // Move to the next node
    }
    std::cout << std::endl; // Print a newline after printing all elements
}

