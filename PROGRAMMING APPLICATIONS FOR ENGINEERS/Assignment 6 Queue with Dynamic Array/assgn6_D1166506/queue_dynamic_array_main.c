#include <stdio.h>
#include <stdlib.h>
#include "queue_dynamic_array.h"

int main(void)
{
    // Declare a queue.
    Queue Q ;
    // Declare trail_count , enqueue_count , dequeue_count.
    int trail_count , enqueue_count , dequeue_count ;
    int e ; // Queue element.

    initial_queue(&Q) ; // Initial queue q.
    trail_count = rand()%10 + 1 ;
    trail_count = 10 ;
    for (int i=1 ; i<=trail_count ; ++i)
    {
        printf (">>>> Trial %d:\n" , i) ;
        enqueue_count = rand()%100 + 1 ;
        printf ("Insert %d elements to queue Q. Content of queue Q after inserting elements:\n", enqueue_count) ;
        while (enqueue_count--)
        {
            e = rand()%100 + 1 ;
            enqueue (&Q , e) ;
        }
        printf ("Queue capacity: %d\n" , Q.capacity) ;
        printf ("Queue size    : %d\n" , get_size (Q)) ;
        print_queue (Q) ;
        dequeue_count = rand() %get_size (Q) + 1 ;
        printf ("\nRemove %d elements to queue Q. Content of queue Q after removing elements:\n" , dequeue_count) ;
        while (dequeue_count--) dequeue (&Q) ;
        reset (&Q) ;
        printf ("Queue capacity: %d\n" , Q.capacity) ;
        printf ("Queue size    : %d\n" , get_size (Q)) ;
        print_queue (Q) ;
        printf ("-------------------------------------------------------------------\n") ;
    }
    free (Q.elem) ;
    return 0;
}
