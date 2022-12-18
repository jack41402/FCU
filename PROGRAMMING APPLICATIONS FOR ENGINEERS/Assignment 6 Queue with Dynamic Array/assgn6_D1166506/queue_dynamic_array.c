#include <stdio.h>
#include <stdlib.h>
#include "queue_dynamic_array.h"

// Set a queue to empty, i.e., reset head and tail of a queue.
void initial_queue (Queue *que)
{
    que->elem = (int *) calloc (SEGMENT , sizeof (int)) ;
    que->head = 0 ; // Head index is where the next element will be deleted if not empty.
    que->tail = 0 ; // Tail index is where the next element will be placed.
    que->capacity = SEGMENT ; // When capacity==0, the queue is empty.
}

// Add an element to the tail of a queue.
// The elements are placed in the queue circularly.
void enqueue (Queue *que , int e)
{
    // Increase the capacity if the queue is full.
    if (get_size (*que)+1==que->capacity)
    {
        que->capacity += SEGMENT ;
        que->elem = (int *) realloc (que->elem , que->capacity * sizeof (int)) ;
        reset (que) ;
    }
    // If the queue is not full.
    *(que->elem+(que->tail%que->capacity)) = e ; // Place the element at the tail.
    que->tail++ ;
}

// Remove an element from the head of a queue.
// The elements are placed in the queue circularly.
int dequeue (Queue *que)
{
    // FREE THE MEMORY!!!
    int e=-1 ; // Head element.
    if (!is_empty (*que))
    {
        e = *(que->elem+que->head++) ; // Get the element at the head of queue. Increment head index.
//        printf ("%4d\n" , e) ;
    }
    if (que->capacity-SEGMENT>get_size (*que))
    {
        que->capacity -= SEGMENT ;
        reset (que) ;
        que->elem = (int *) realloc (que->elem , que->capacity * sizeof (int)) ;
    }
    return e; // Return the head element.
}

// Reset the head of queue to the beginning position and shift the elements in the queue.
void reset (Queue *que)
{
    int count=0 , size=get_size (*que);
    for (int i=que->head ; i<que->tail ; ++i , ++count)
    { // Print all elements in queue.
        *(que->elem+count) = *(que->elem+i%size) ; // Print an element.
    }
    que->head=0 , que->tail = count ;
}

// Get the element at the head of a queue.
int head (Queue que)
{
    if (get_size (que)>0) return que.elem[que.head] ; // If queue is not empty, return the head element.
    else
    {
        printf("\n  The queue is empty.\n") ;
        return -9999; // No element is found.
    }
}

// Check if a queue is empty or not.
int is_empty (Queue que)
{
    return (get_size (que)==0); // size==0 means empty queue.
}

// Get size of queue.
int get_size (Queue que)
{
    return que.tail-que.head;
}

// Clear queue and set capacity to one segment.
void clear(Queue *que)
{
    // Free the used memory in the elem of que.
    free (que->elem) ;
    que->elem = (int *) realloc (que->elem , SEGMENT * sizeof (int)) ;
    que->head = 0 ; // Head index is where the next element will be deleted if not empty.
    que->tail = 0 ; // Tail index is where the next element will be placed.
    que->capacity = SEGMENT ; // When capacity==0, the queue is empty.
}

// Print elements of a queue from the head to the tail.
void print_queue (Queue que)
{
    if (que.capacity>0)
    {
        printf("****Queue elements from head to tail:\n") ;
        for (int i=que.head , count=1 , size=get_size (que) ; i<que.tail ; ++i, ++count)
        { // Print all elements in queue.
            printf("%4d i=%3d" , *(que.elem+i%que.capacity) , i) ; // Print an element.
            if (count%20==0) printf ("\n") ;
        }
        printf("\n") ;
    }
    else printf("\n  The queue is empty.\n") ; // The queue is empty.
}