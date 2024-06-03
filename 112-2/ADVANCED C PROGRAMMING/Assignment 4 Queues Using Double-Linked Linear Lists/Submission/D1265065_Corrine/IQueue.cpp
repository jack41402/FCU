//
//  IQueue.cpp
//  Assignment_4_D1265065
//
//  Created by Corrine  on 2024/4/29.
//

#include "IQueue.h"
#include <iostream>//standard library
#include <iomanip>//In order to use setw() to output fixed numbers
using namespace std;//standard namespace
IQueue::IQueue(){//Initialization list
    head = NULL;
    tail = NULL;
}

void IQueue::enqueue(int data){//Enqueue elements
    Node *newNode = new Node(data);//Allocate the memory space. (new像C的malloc一樣)
    if (isEmpty()){//If Queue is empty, set head and tail pointers to new Node.
        head = newNode;
        tail = newNode;
    }
    else{//If Queue is not empty,
        tail->next = newNode;// Set the next pointer of the current tail node to the new node
        newNode->prev = tail;// Set the previous pointer of the new node to the current tail node
        tail = newNode;// Update the tail pointer to point to the new node, making it the new tail
    }
}

int IQueue::dequeue(){
    if(isEmpty()){// Return -1 if the queue is empty
        //std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }
    int data = head->elem;// Store the data of the node to be dequeued
    Node *temp = head;// Create a temporary pointer to the head node
    head = head->next;// Move the head pointer to the next node in the queue
    if(head != NULL){// If the new head is not nullptr,
        head->prev = NULL;//update its previous pointer to nullptr
    }
    else{
        tail = NULL;//else the queue becomes empty, so update the tail pointer to nullptr
    }
    delete temp;// Delete the node pointed to by the temporary pointer, freeing the memory
    return data;
}

int IQueue::headElem(){
    if(isEmpty()){// If the queue is empty, return -1
        //std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }
    return head->elem;//If the queue is not empty, return the data of the head node
}

bool IQueue::isEmpty(){
    return (head==NULL);
}// Check if the head pointer is nullptr
// If head is nullptr, it means the queue is empty, so return true
// Otherwise, return false

int IQueue::getSize(){
    int size = 0;
    Node *current = head;// Start from the head of the queue
    while (current != NULL) {// Traverse the queue until reaching the end
           size++;// Increment the size counter for each node visited
           current = current->next;// Move to the next node in the queue
       }
    return size;// Return the total size of the queue
}

Node *IQueue::getHead(){
    return head;
}

Node *IQueue::getTail(){
    return tail;
}

void IQueue::printHeadToTail(){
    Node* current = head;
    int i = 0;// Counter for formatting purposes
        while (current != NULL) {// Traverse the queue from head to tail
            // Print the data of the current node
            // Use setw(4) to ensure each element is printed in a fixed width of 4 characters
            cout << setw(4) << current->elem << " ";
            if((i+1) % 20 == 0) cout << endl;// Print a newline after every 20 elements
            current = current->next;// Move to the next node in the queue
               i++;// Increment the counter
        }
        cout << endl;
}
