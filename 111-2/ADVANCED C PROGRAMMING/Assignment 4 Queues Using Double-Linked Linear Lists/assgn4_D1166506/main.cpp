#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IQueue.h"

int main ()
{
    srand(time(NULL)) ;
    int trail=rand()%10+1 ;
    printf("Trail count: %d\n\n" , trail) ;
    for (int i=1 ; i<=trail ; ++i)
    {
        printf(">>>> Trail %d: enqueue and dequeue operations\n" , i) ;
        IQueue q ;
        int enqueue_count=0 ;
        while (enqueue_count==0) enqueue_count = rand()%100 ;
        int temp=enqueue_count ;
        printf("Enqueue %d element%s to the queue.\n" , enqueue_count , ((enqueue_count==1) ? "" : "s")) ;
        while (enqueue_count--) q.push(rand()%100) ;
        printf("Current queue size: %d. Content of queue from head to tail:\n" , q.getSize()) ;
        q.printHeadToTail() ;
        int dequeue_count=0 ;
        while (dequeue_count==0) dequeue_count = rand()%temp ;
        printf("\nDequeue %d element%s to the queue.\n" , dequeue_count , ((dequeue_count==1) ? "" : "s")) ;
        while (dequeue_count--) q.pop() ;
        printf("Current queue size: %d. Content of queue from head to tail:\n" , q.getSize()) ;
        q.printHeadToTail() ;
        printf("------------------------------------------------------------------\n\n") ;
    }
    return 0;
}
