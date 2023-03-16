#include <stdio.h>
#include <stdlib.h>
#include "assgn2_d1166506.h"

// Initialize a linear list, set its size to 0.
void initial (List *L)
{
    (*L)->next = NULL ;
}

// The length of a linear list, returns the number of elements, namely size.
int getSize (List L)
{
    int size=0 ;
    while (L->next!=NULL)
    {
        L = L->next ;
        size++ ;
    }
    return size;
}

// Get the element at a position from a linear list, return the designated element.
ElemType getElem (List L , int pos)
{
    int i=0 ;
    while (i<pos)
    {
        L = L->next ;
        i++ ;
    }
    return L->elem;
}

// Set the element at a position in a linear list to a specific element.
ElemType setElem (List L , ElemType e , int pos)
{
    int i=0 ;
    while (i<pos)
    {
        L = L->next ;
        if (L->next==NULL) return -1;
        i++ ;
    }
    L->elem = e ;
    return 1;
}

// Find the position of an element in L.
// If successful, return the position of the element; otherwise, returns -1.
int search (List L , ElemType e)
{
    int pos=0 , size=getSize(L);
    while (pos<size)
    {
        if (L->elem==e) return pos;
        L = L->next ;
        pos++ ;
    }
    return -1 ;
}

// Insert an element after the end of a linear list, return the position of the inserted element.
// If the inserted element exists in the linear list or the linear list is overflow, insertElem() fails, and returns -1.
int insertElem (List *L , ElemType e)
{
    if (search(*L , e)!=-1) return -1;
    Node *node=(Node *) malloc(sizeof(Node)) ;
    node->elem = e ;
    node->next = NULL ;
    while ((*L)->next!=NULL) *L = (*L)->next ;
    (*L)->next = node ;
    return getSize(*L)-1;
}

// Delete an element from a list. If the element is in the linear list, delete it and return its position; otherwise, return -1.
int deleteElem (List *L , ElemType e)
{
    if (search(*L , e)==-1) return -1;
    int pos=search(*L , e) , i=0 ;
    List *now=L , *dist ;
    while ((*L)->next!=NULL)
    {
        if (i==pos-1) now = L ;
        else if (i==pos)
        {
            dist = now ;
            (*now)->next = (*L)->next ;
            free ((*dist)->next) ;
            return pos;
        }
        *L = (*L)->next ;
        i++ ;
    }
    return -1;
}

// Print all elements of the linear list starting from the head.
void printList (List L)
{
    int count=0 ;
    while (L->next!=NULL)
    {
        printf(" %3d" , L->elem) ;
        count++ ;
        if (count%20==0) printf("\n") ;
    }
    if (getSize(L)%20!=0) printf("\n") ;
}

// Append list L2 at the end of L1.
// If an element of L2 exists in L1, discard that element.
// Return the result of append() operation.
List append (List L1 , List L2)
{
    List L3 ;
    initial(&L3) ;
    while (L1->next!=NULL)
    {
        L3
    }
}

// Join two lists L1 and L2.
// Return a list containing all common elements in L1 and L2.
// The elements of the resulting list are stored in the order of list L1.
List join (List , List);

// Sort list L. The elements of L are rearranged into the ascending order.
void sort (List *);