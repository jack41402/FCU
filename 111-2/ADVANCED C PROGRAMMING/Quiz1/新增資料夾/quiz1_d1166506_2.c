#include <stdio.h>
#include <stdlib.h>
#include "quiz1_d1166506_2.h" 

// ***** Complete the following functions.

// Initialize a linear list, set its size to 0.
void initial(List *L)
{
	L->size = 0 ;
} 

// The length of a linear list, returns the number of elements, namely size.
int getSize(List L)
{
	return L.size;
}

// Get the element at a position from a linear list, return the designated element.
ElemType getElem(List L, int i)
{
	return L.elem[i];
}

// Set the element at a position in a linear list to a specific element.
ElemType setElem(List *L, ElemType e, int i)
{
	L->elem[i] = e ;
	return L->elem[i];
}

// Find the position of an element in L. If successful, return the position of the 
// element; otherwise, returns -1.
int search(List L, ElemType e)
{
	int i ;
	for (i=0 ; i<L.size ; ++i)
	{
		if (L.elem[i]==e) return i;
	}
	return -1;
}

// Insert an element after the end of a linear list, return the position of the
// inserted element. If the inserted element exists in the linear list or the linear list
// is overflow, insertElem() fails, and returns -1.
int insertElem(List *L, ElemType e)
{
	if (search(*L , e)!=-1 || L->size==100) return -1;
	L->elem[L->size] = e ;
	L->size++ ;
	return L->size-1;
} 

// Delete an element from a list. If the element is in the linear list, delete it and
// return its position; otherwise, return -1.
int deleteElem(List *L, ElemType e)
{
	if (search(*L , e)==-1) return -1;
	int i ;
	for (i=0 ; i<L->size ; ++i)
	{
		if (L->elem[i]==e) return i;
	}
	return -1;
}

// Print all elements of the linear list starting from the head.
// Print 20 elements in a line.
void printList(List L)
{
	int i ;
	printf ("The list has %d elements\n" , L.size) ;
	for (i=0 ; i<L.size ; ++i)
	{
		printf (" %3d" , L.elem[i]) ;
		if ((i+1)%20==0) printf ("\n") ;
	}
	if (L.size%20!=0) printf ("\n\n") ;
}
