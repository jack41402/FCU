#include <stdio.h>
#include <stdlib.h>
#include "queue_dynamic_array.h"

// Set a queue to empty, i.e., reset head and tail of a queue.
void initial_queue(Queue *que)
{
    que->elem = (int *) malloc (SEGMENT * sizeof (int)) ;
    que->head = 0 ; // Head index is where the next element will be deleted if not empty.
    que->tail = 0 ; // Tail index is where the next element will be placed.
    que->capacity = SEGMENT ; // When capacity==0, the queue is empty.
}

// Add an element to the tail of a queue.
// The elements are placed in the queue circularly.
void enqueue(Queue *que , int e)
{
    // Expand the capacity if the queue is full.
    printf ("%d %d\n" , get_size (*que) , que->capacity) ;
    if (get_size (*que)==que->capacity)
    {
        que->elem = (int *) realloc (que->elem , (que->capacity+SEGMENT) * sizeof (int)) ;
        // Update queue capacity.
        que->capacity += SEGMENT ;
        que->tail = get_size(*que);
    }
    // If the queue is not full.
    *(que->elem+que->tail++) = e ; // Place the element at the tail.
//    printf ("%d %d\n" , *(que->elem+que->tail) , que->tail) ;
//    que->tail++ ; // Increment tail index.
}
//    S->elem[++S->top] = e; // Insert an element and increment the top index.
//    if (get_size(*S)==S->capacity) {// If the stack is full, expand the stack capacity.
//        // Reallocate memory space, add one more segement.
//        S->elem = (ElemType *) realloc(S->elem,
//                                       (S->capacity+SEGMENT)*sizeof(ElemType));
//        S->capacity += SEGMENT; // Update stack capacity.
//    }


// Remove an element from the head of a queue.
// The elements are placed in the queue circularly.
int dequeue(Queue *que)
{
    // FREE THE MEMORY!!!
    int e ; // Head element.
    if (que->capacity>0)
    {
        e = que->elem[que->head] ; // Get the element at the head of queue.
        que->head = que->head + 1 ; // Increment head index.
        que->capacity-- ; // Decrement the number of elements.
        return e; // Return the head element.
    }
    else
    {
        printf("\n  Queue underflow.\n") ; // The queue is underflow.
        return -9999; // Value -9999 indicates underflow.
    }
}

// Get the element at the head of a queue.
int head(Queue que)
{
    if (que.capacity>0) return que.elem[que.head] ; // If queue is not empty, return the head element.
    else
    {
        printf("\n  The queue is empty.\n") ;
        return -9999; // No element is found.
    }
}

// Check if a queue is empty or not.
int is_empty(Queue que)
{
    return (que.capacity==0); // capacity==0 means empty queue.
}

// Get size of queue.
int get_size(Queue que)
{
    return que.tail-que.head-1;
}

// Clear queue and set capacity to one segment.
//void clear(Queue *que)
//{
//
//}

// Print elements of a queue from the head to the tail.
void print_queue(Queue que)
{
    if (que.capacity>0)
    {
        printf("****Queue elements from head to tail:\n") ;
        for (int i=que.head+1 ; i<que.tail ; i++)
        { // Print all elements in queue.
            printf(" %d" , *(que.elem+i)) ; // Print an element.
        }
        printf("\n") ;
    }
    else printf("\n  The queue is empty.\n") ; // The queue is empty.
}
