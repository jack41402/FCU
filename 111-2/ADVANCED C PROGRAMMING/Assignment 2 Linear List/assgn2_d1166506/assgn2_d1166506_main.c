#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assgn2_d1166506.h"

int main ()
{
    int n1 , n2 , temp , count ;
    int arr[50]={0} ;
    List L1 , L2 ;
    srand(time(NULL)) ;
    // Initialize L1 and L2
    initial(&L1) ;
    initial(&L2) ;
    // Read the size of L1 and L2
    do
    {
        printf(">>>> Enter the size (between 1 and 100 (inclusive)) of the linear list L1: ") ;
        scanf("%d" , &n1) ;
    }
    while (n1<1 || n1>100) ;
    do
    {
        printf(">>>> Enter the size (between 1 and 100 (inclusive)) of the linear list L2: ") ;
        scanf("%d" , &n2) ;
    }
    while (n2<1 || n2>100) ;
    printf("-------------------------------------------\n\n") ;
    // Create the element of L1 and L2
    count = 0 ;
    while (count<n1)
    {
        temp = rand()%1000 ;
        if (search(L1 , temp)!=-1) continue ;
        insertElem(&L1 , temp) ;
        count++ ;
    }
    count = 0 ;
    while (count<n2)
    {
        temp = rand()%1000 ;
        if (search(L2 , temp)!=-1) continue ;
        insertElem(&L2 , temp) ;
        count++ ;
    }
    printf(">>>> Linear list L1:\n") ;
    printList(L1) ;
    printf("\n") ;

    printf(">>>> Linear list L2:\n") ;
    printList(L2) ;
    printf("\n") ;

    List L3=append(L1 , L2) ;
    printf(">>>> Appended linear list of L1 and L2:\n") ;
    printList(L3) ;
    printf("\n") ;

    List L4= join(L1 , L2) ;
    printf(">>>> Joined linear list of L1 and L2:\n") ;
    printList(L4) ;
    printf("\n") ;

    sort(&L3) ;
    printf(">>>> Sorted linear list of L3:\n") ;
    printList(L3) ;
    printf("\n") ;

    sort(&L4) ;
    printf(">>>> Sorted linear list of L4:\n") ;
    printList(L4) ;
    return 0;
}
