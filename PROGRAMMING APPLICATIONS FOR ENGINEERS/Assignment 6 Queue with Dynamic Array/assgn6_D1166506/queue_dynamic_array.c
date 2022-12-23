#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        reset (que) ;
        que->capacity += SEGMENT ;
        que->elem = (int *) realloc (que->elem , que->capacity * sizeof (int)) ;
    }
    // If the queue is not full.
    *(que->elem+(que->tail%que->capacity)) = e ; // Place the element at the tail.
//    printf ("%4d %4d || %4d %4d\n" , *(que->elem+(que->tail%que->capacity)), e , que->tail%que->capacity , que->tail) ;
    que->tail++ ;
}

// Remove an element from the head of a queue.
// The elements are placed in the queue circularly.
int dequeue (Queue *que)
{
    if (is_empty (*que)) return -1;

    // FREE THE MEMORY!!!
    int e=-1 ; // Head element.
    e = *(que->elem+que->head++) ; // Get the element at the head of queue. Increment head index.
//    printf ("%3d %3d\n" , e , que->head) ;
    if (que->capacity-SEGMENT>get_size (*que))
    {
        reset (que) ;
        que->capacity -= SEGMENT ;
        que->elem = (int *) realloc (que->elem , que->capacity * sizeof (int)) ;
    }
    return e; // Return the head element.
}

// Reset the head of queue to the beginning position and shift the elements in the queue.
void reset (Queue *que)
{
    Queue temp ;
    temp.elem = (int *) calloc (que->capacity , sizeof (int)) ;
    memcpy (temp.elem , que->elem , que->capacity * sizeof (int)) ;
    temp.capacity = que->capacity , temp.head = que->head , temp.tail = que->tail ;
//    printf ("TEMPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP\n") ;
//    print_queue (temp) ;
    int count=0 ;
    for (int i=que->head ; i<que->tail ; ++i , ++count)
    { // Print all elements in queue.
        *(que->elem+count) = *(temp.elem+i%temp.capacity) ; // Print an element.
//        printf ("%3d %3d %3d %3d\n" , *(que->elem+count) , *(temp.elem+i%temp.capacity) , i , i%que->capacity) ;
    }
    que->head=0 , que->tail = count ;
    free (temp.elem) ;
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
            printf("%4d" , *(que.elem+i%que.capacity)) ; // Print an element.
            if ((i-que.head+1)%20==0) printf ("\n") ;
        }
        printf("\n") ;
    }
    else printf("\n  The queue is empty.\n") ; // The queue is empty.
}