#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assgn3_d1166506.h"

int main ()
{
    Polynomial P1 , P2 ;
    Degree deg1 , deg2 ;
    Coeff coeff ;
    double a , sum ;
    srand(time(NULL)) ;
    do
    {
        printf("Enter degree of the polynomial P1 (between 0 and 100): ") ;
        scanf("%d" , &deg1) ;
    }
    while (deg1<0 || deg1>100) ;
    do
    {
        printf("Enter degree of the polynomial P2 (between 0 and 100): ") ;
        scanf("%d" , &deg2) ;
    }
    while (deg2<0 || deg2>100) ;
    do
    {
        printf("Enter a of a (between -1.0 and 1.0): ") ;
        scanf("%lf" , &a) ;
    }
    while (a<-1.0 || a>1.0) ;
    // Initialize Polynomial P1
    initial(&P1) ;
    coeff = (rand()%2001 / 100.0) - 10.0 ;
    replaceTerm(&P1 , deg1 , coeff) ;
    for (int i=deg1-1 ; i>=0 ; --i)
    {
        if (rand()%3==0)
        {
            coeff = (rand()%2001 / 100.0) - 10.0 ;
            replaceTerm(&P1 , i , coeff) ;
        }
    }
    printf(">>>> Polynomial P1(x) has %d non-zero coefficient term%s.\n" , getTerm(P1) , ((getTerm(P1)>1) ? "s" : "")) ;
    printPoly(P1) ;
    printf("\n") ;
    // Initialize Polynomial P2
    initial(&P2) ;
    coeff = (rand()%2001 / 100.0) - 10.0 ;
    replaceTerm(&P2 , deg2 , coeff) ;
    for (int i=deg2-1 ; i>=0 ; --i)
    {
        if (rand()%3==0)
        {
            coeff = (rand()%2001 / 100.0) - 10.0 ;
            replaceTerm(&P2 , i , coeff) ;
        }
    }
    printf(">>>> Polynomial P2(x) has %d non-zero coefficient term%s.\n" , getTerm(P2) , ((getTerm(P2)>1) ? "s" : "")) ;
    printPoly(P2) ;
    printf("\n") ;

    printf(">>>> a=%.2lf\n" , a) ;
    printf(">>>> Evaluation of Polynomial P1(a): ") ;
    sum = 0 ;
    for (int i=99 ; i>=0 ; --i)
    {
        coeff = getCoeff(P1 , i) ;
        if (coeff!=-99) sum += coeff * power(a , i) ;
    }
    printf("%.4E\n" , sum) ;
    printf(">>>> Evaluation of Polynomial P2(a): ") ;
    sum = 0 ;
    for (int i=99 ; i>=0 ; --i)
    {
        coeff = getCoeff(P2 , i) ;
        if (coeff!=-99) sum += coeff * power(a , i) ;
    }
    printf("%.4E\n" , sum) ;
    printf("\n") ;

    // Polynomial addition
    Polynomial P3=polyAdd(P1 , P2) ;
    printf(">>>> Polynomial (P1+P2)(x) has %d non-zero coefficient term%s.\n" , getTerm(P3) , ((getTerm(P3)>1) ? "s" : "")) ;
    printPoly(P3) ;
    printf("\n") ;

    // Polynomial subtraction
    Polynomial P4=polyMinus(P1 , P2) ;
    printf(">>>> Polynomial (P1+P2)(x) has %d non-zero coefficient term%s.\n" , getTerm(P4) , ((getTerm(P4)>1) ? "s" : "")) ;
    printPoly(P4) ;
    printf("\n") ;

    // Polynomial subtraction
    Polynomial P5=polyTime(P1 , P2) ;
    printf(">>>> Polynomial (P1+P2)(x) has %d non-zero coefficient term%s.\n" , getTerm(P5) , ((getTerm(P5)>1) ? "s" : "")) ;
    printPoly(P5) ;
    printf("\n") ;
    return 0;
}