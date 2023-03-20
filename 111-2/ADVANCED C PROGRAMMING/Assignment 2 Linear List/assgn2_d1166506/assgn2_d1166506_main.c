#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assgn2_d1166506.h"

int main ()
{
    int n1 , n2 , temp , count ;
    List L1 , L2 ;
    srand(time(NULL)) ;
    // Initialize L1 and L2
    initial(&L1) ;
    initial(&L2) ;
    // Read the size of L1 and L2
    do
    {
        printf(">>>> Enter the size (between 20 and 200 (inclusive)) of the linear list L1: ") ;
        scanf("%d" , &n1) ;
    }
    while (n1<20 || n1>200) ;
    do
    {
        printf(">>>> Enter the size (between 20 and 200 (inclusive)) of the linear list L2: ") ;
        scanf("%d" , &n2) ;
    }
    while (n2<20 || n2>200) ;
    printf("-------------------------------------------\n\n") ;
    // Create the element of L1 and L2
    count = 0 ;
    while (count<n1)
    {
        if (insertElem(&L1 , rand()%1000)!=-1) count++ ;
    }
    count = 0 ;
    while (count<n2)
    {
        if (insertElem(&L2 , rand()%1000)!=-1) count++ ;
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

    // Free the List
    while (deleteElem(&L1 , getElem(L1 , 1))!=-1) ;
    while (deleteElem(&L2 , getElem(L2 , 1))!=-1) ;
    while (deleteElem(&L3 , getElem(L3 , 1))!=-1) ;
    while (deleteElem(&L4 , getElem(L4 , 1))!=-1) ;
    /*while (1)
    {
        int n , pos , elem , size=getSize(L1) ;
        scanf("%d" , &n) ;
        if (n==0) break ;
        switch (n)
        {
            case 1:
            {
                do
                {
                    printf("Enter the position which you want to get the element: ") ;
                    scanf("%d" , &pos) ;
                }
                while (pos<1 || pos>size) ;
                printf ("The element of L1 at %d is %d.\n" , pos ,  getElem(L1 , pos)) ;
                break ;
            }
            case 2:
            {
                do
                {
                    printf("Enter the position which you want to set the element: ") ;
                    scanf("%d" , &pos) ;
                }
                while (pos<1 || pos>size) ;
                do
                {
                    printf("Enter the element you want to set: ") ;
                    scanf("%d" , &elem) ;
                }
                while (elem<0 || elem>999) ;
                setElem(L1 , elem , pos) ;
                printList(L1) ;
                break ;
            }
            case 3:
            {
                do
                {
                    printf("Enter the element you want to delete: ") ;
                    scanf("%d" , &elem) ;
                }
                while (elem<0 || elem>999) ;
                pos = deleteElem(&L1 , elem) ;
                (pos==-1) ? printf("Delete element failed, please try again.\n") : printf("Delete Successfully, the position of delete element %d is %d.\n" , elem , pos) ;
                printList(L1) ;
                break ;
            }
            default:
            {
                break ;
            }
        }
    }*/
    return 0;
}