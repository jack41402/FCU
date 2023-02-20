#include <stdio.h>
#include "queue_array.h"

// Set a queue to empty, i.e., reset head and tail of a queue.
void initial_queue(Queue *que) {
  que->head = 0; // Head index is where the next element will be deleted if not empty.
  que->tail = 0; // Tail index is where the next element will be placed.
  que->cnt = 0; // When cnt==0, the queue is empty.
}

// Add an element to the tail of a queue.
// The elements are placed in the queue circularly.
void enqueue(Queue *que, int e) {
  if (que->cnt<max) { // If the queue is not full.
    que->elem[que->tail] = e; // Place the element at the tail.
    que->tail = (que->tail + 1) % max; // Increment tail index. 
    que->cnt++; // Increment the number of elements.
  }
  else printf("  Queue overflow.\n"); // The queue is overflow.
}

// Remove an element from the head of a queue.
// The elements are placed in the queue circularly.
int dequeue(Queue *que) {
  int e; // Head element.
  if (que->cnt>0) {
    e = que->elem[que->head]; // Get the element at the head of queue.
    que->head = (que->head + 1) % max; // Increment head index.
    que->cnt--; // Decrement the number of elements.
    return e; // Return the head element.
  }
  else {
    printf("\n  Queue underflow.\n"); // The queue is underflow.
    return -9999; // Value -9999 indicates underflow.
  }
}

// Get the element at the head of a queue.
int head(Queue que) {
  if (que.cnt>0) return que.elem[que.head]; // If queue is not empty, return the head element.
  else {
    printf("\n  The queue is empty.\n");
    return -9999; // No element is found.
  }
}

// Check if a queue is empty or not.
int is_empty(Queue que) {
  return (que.cnt==0); // Cnt==0 means empty queue.
}

// Print elements of a queue from the head to the tail. 
void print_queue(Queue que) {
  int h = que.head; // Printing starts from the head element.
  int i; // Loop index.
  
  if (que.cnt>0) {
    printf("\n  The queue elements are (from head to tail): ");
    for (i=que.cnt; i>0; i--) { // Print all elements in queue.
      printf("%d  ", que.elem[h]); // Print an element.
      h = (h + 1) % max; // Get the index of the next element circularly.
    }
    printf("\n");
  }
  else printf("\n  The queue is empty.\n"); // The queue is empty.
}
