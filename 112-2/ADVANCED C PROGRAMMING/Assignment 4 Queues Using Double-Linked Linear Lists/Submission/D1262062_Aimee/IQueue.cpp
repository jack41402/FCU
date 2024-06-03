#include "IQueue.h"


IQueue::IQueue() : head(NULL), tail(NULL) {}

void IQueue::enqueue(int data) {
    Node* newNode = new Node(data);
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
        return -1;
        cout << "dequeue failed" << endl;
    }
    int data = head->elem;
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    delete temp;
    return data;
}

int IQueue::headElem() {
    if (isEmpty()) {
        return -1; // Or throw an exception
    }
    return head->elem;
}

bool IQueue::isEmpty() {
    return head == NULL;
}

int IQueue::getSize() {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

Node* IQueue::getHead() {
    return head;
}

Node* IQueue::getTail() {
    return tail;
}

void IQueue::printHeadToTail() {
    Node* current = head;
    int position = 0;
    while (current != NULL) {
    	if(current->elem < 10) cout << "   ";
    	else cout << "  ";
        cout << current->elem;
        current = current->next;
        if ((position+1)%20==0) printf("\n");
        position++;
    }
    cout << endl;
}

