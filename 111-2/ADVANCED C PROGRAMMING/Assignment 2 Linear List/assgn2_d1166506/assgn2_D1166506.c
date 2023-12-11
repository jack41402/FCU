#include <stdio.h>
#include <stdlib.h>
#include "assgn2_D1166506.h"

// Initialize a linear list, set its size to 0.
void initial (List *L)
{
    *L = NULL ;
}

// The length of a linear list, returns the number of elements, namely size.
int getSize (List L)
{
    int size=0 ;
    while (L!=NULL)
    {
        L = L->next ;
        size++ ;
    }
    return size;
}

// Get the element at a position from a linear list, return the designated element.
ElemType getElem (List L , int pos)
{
    if (L==NULL || getSize(L)<pos) return -1;
    int i=1 ;
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
    if (L==NULL || getSize(L)<pos) return -1;
    int i=1 ;
    while (i<pos)
    {
        L = L->next ;
        i++ ;
    }
    L->elem = e ;
    return 1;
}

// Find the position of an element in L.
// If successful, return the position of the element; otherwise, returns -1.
int search (List L , ElemType e)
{
    int pos=1 ;
    while (L!=NULL)
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
    if (*L==NULL) *L = node ;
    else
    {
        List temp=*L ;
        while (temp->next!=NULL) temp = temp->next ;
        temp->next = node ;
    }
    return getSize(*L)-1;
}

// Delete an element from a list. If the element is in the linear list, delete it and return its position; otherwise, return -1.
int deleteElem (List *L , ElemType e)
{
    if (*L==NULL || search(*L , e)==-1) return -1;
    int pos=1 ;
    List cur=*L , prev=NULL ;
    while (cur!=NULL)
    {
        if (cur->elem==e)
        {
            // Delete the first node
            if (prev==NULL) *L = cur->next ;
            // Delete the other node
            else  prev->next = cur->next ;
            free(cur) ;
            return pos;
        }
        prev = cur ;
        cur = cur->next ;
        pos++ ;
    }
    return -1;
}

// Print all elements of the linear list starting from the head.
void printList (List L)
{
    int count=0 , size=getSize(L) ;
    printf("The linear list has %d element%s.\n\n" , size , ((size==1) ? "" : "s")) ;
    while (L!=NULL)
    {
        printf(" %3d" , L->elem) ;
        L = L->next ;
        count++ ;
        if (count%20==0) printf("\n") ;
    }
    if (size%20!=0) printf("\n") ;
}

// Append list L2 at the end of L1.
// If an element of L2 exists in L1, discard that element.
// Return the result of append() operation.
List append (List L1 , List L2)
{
    List L3 , cur , temp=L1 ;
    initial(&L3) ;
    while (L1!=NULL)
    {
        Node *node=(Node *) malloc(sizeof(Node)) ;
        node->elem = L1->elem ;
        node->next = NULL ;
        if (L3==NULL)
        {
            L3 = node ;
            cur = L3 ;
        }
        else
        {
            cur->next = node ;
            cur = cur->next ;
        }
        L1 = L1->next ;
    }
    L1 = temp ;
    while (L2!=NULL)
    {
        if (search(L1 , L2->elem)==-1)
        {
            Node *node=(Node *) malloc(sizeof(Node)) ;
            node->elem = L2->elem ;
            node->next = NULL ;
            if (L3==NULL)
            {
                L3 = node ;
                cur = L3 ;
            }
            else
            {
                cur->next = node ;
                cur = cur->next ;
            }
        }
        L2 = L2->next ;
    }
    return L3;
}

// Join two lists L1 and L2.
// Return a list containing all common elements in L1 and L2.
// The elements of the resulting list are stored in the order of list L1.
List join (List L1 , List L2)
{
    List L4 , cur ;
    initial(&L4) ;
    while (L1!=NULL)
    {
        if (search(L2 , L1->elem)==-1)
        {
            L1 = L1->next ;
            continue ;
        }
//        insertElem(&L4 , L1->elem) ;
        Node *node=(Node *) malloc(sizeof(Node)) ;
        node->elem = L1->elem ;
        node->next = NULL ;
        if (L4==NULL)
        {
            L4 = node ;
            cur = L4 ;
        }
        else
        {
            cur->next = node ;
            cur = cur->next ;
        }
        L1 = L1->next ;
    }
    return L4;
}

// Sort list L. The elements of L are rearranged into the ascending order.
void sort (List *L)
{
    int size=getSize(*L) ;
    ElemType temp ;
    List cur ;
    for (int i=0 ; i<size-1 ; ++i)
    {
        cur = *L ;
        for (int j=i ; j<size-1 ; ++j)
        {
            if (cur->elem>cur->next->elem)
            {
                temp = cur->elem ;
                cur->elem = cur->next->elem ;
                cur->next->elem = temp ;
            }
            cur = cur->next ;
        }
    }
}