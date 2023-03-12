#include <stdlib.h>
#include <stdio.h>
#include "queue_fixed_array.h"

// ***** Complete the following functions.

// Initialize Q. 
void initial(Queue *Q)
{
	Q->head = 0 ;
	Q->tail = 0 ;
}

// Enqueue operation. 
void enqueue(Queue *Q, ElemType e)
{
	Q->elem[Q->tail%MAXIMUM] = e ;
	Q->tail++ ;
} 

// Dequeue operation.
ElemType dequeue(Queue *Q)
{
	Q->head++ ;
	return Q->elem[(Q->head-1)%MAXIMUM] ;
} 

//void reset (Queue *Q)
//{
//	
//}

// Clear queue operation.
void clear(Queue *Q)
{
	int i ;
	for (i=0 ; i<MAXIMUM ; ++i) Q->elem[i] = 0 ;
	Q->head = 0 ;
	Q->tail = 0 ;
}
