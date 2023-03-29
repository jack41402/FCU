#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "assgn3_d1166506.h"
#define eps 1e-4

int main ()
{
    setbuf(stdout , NULL) ;
    Polynomial P1 , P2 ;
    Degree deg1 , deg2 ;
    Coeff coeff ;
    double a , sum ;
    srand(0) ;
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
    printf("\n") ;
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

    // P1(a) and P2(a)
    printf(">>>> a=%.2lf\n" , a) ;
    printf(">>>> Evaluation of Polynomial P1(a): ") ;
    printf("%.4E\n" , evaluate(P1 , a)) ;
    printf(">>>> Evaluation of Polynomial P2(a): ") ;
    printf("%.4E\n" , evaluate(P2 , a)) ;
    printf("\n") ;

    // Polynomial addition
    Polynomial P3=polyAdd(P1 , P2) ;
    printf(">>>> Polynomial (P1+P2)(x) has %d non-zero coefficient term%s.\n" , getTerm(P3) , ((getTerm(P3)>1) ? "s" : "")) ;
    printPoly(P3) ;
    printf("\n") ;

    // Polynomial subtraction
    Polynomial P4=polyMinus(P1 , P2) ;
    printf(">>>> Polynomial (P1-P2)(x) has %d non-zero coefficient term%s.\n" , getTerm(P4) , ((getTerm(P4)>1) ? "s" : "")) ;
    printPoly(P4) ;
    printf("\n") ;

    // Polynomial subtraction
    Polynomial P5=polyTime(P1 , P2) ;
    printf(">>>> Polynomial (P1*P2)(x) has %d non-zero coefficient term%s.\n" , getTerm(P5) , ((getTerm(P5)>1) ? "s" : "")) ;
    printPoly(P5) ;
    printf("\n") ;

    // (P1+P2)(a), (P1-P2)(a), and (P1*P2)(a)
    printf(">>>> Evaluation of Polynomial (P1+P2)(a): ") ;
    printf("%.4E\n" , evaluate(P3 , a)) ;
    printf(">>>> Evaluation of Polynomial (P1-P2)(a): ") ;
    printf("%.4E\n" , evaluate(P4 , a)) ;
    printf(">>>> Evaluation of Polynomial (P1*P2)(a): ") ;
    printf("%.4E\n" , evaluate(P5 , a)) ;
    printf("\n") ;

    // Proof the equivalence of polynomial
    printf(">>>> Prove: P1(a)+P2(a) == (P1+P2)(a): ") ;
    (fabs(evaluate(P1 , a)+evaluate(P2 , a)-evaluate(P3 , a))<eps) ? printf("True\n") : printf("False\n") ;
    printf(">>>> Prove: P1(a)-P2(a) == (P1-P2)(a): ") ;
    (fabs(evaluate(P1 , a)-evaluate(P2 , a)-evaluate(P4 , a))<eps) ? printf("True\n") : printf("False\n") ;
    printf(">>>> Prove: P1(a)*P2(a) == (P1*P2)(a): ") ;
    (fabs(evaluate(P1 , a)*evaluate(P2 , a)-evaluate(P5 , a))<eps) ? printf("True\n") : printf("False\n") ;

    return 0;
}