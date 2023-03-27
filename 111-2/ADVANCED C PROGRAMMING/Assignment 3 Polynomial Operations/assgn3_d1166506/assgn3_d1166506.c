#include <stdio.h>
#include <stdlib.h>
#include "assgn3_d1166506.h"

// Initialize polynomial.
void initial (Polynomial *P)
{
    *P = NULL ;
}

// Get number of terms of the polynomial.
int getTerm (Polynomial P)
{
    int term=0 ;
    while (P!=NULL)
    {
        P = P->next ;
        term++ ;
    }
    return term;
}

// Get a polynomial term with given degree.
// If no term with the specified degree, return -99.
Coeff getCoeff (Polynomial P , Degree degree)
{
    while (P!=NULL)
    {
        if (P->degree==degree) return P->coeff;
        P = P->next ;
    }
    return -99;
}

// Search a polynomial term with a specified degree.
// If successful, return the degree of the term; otherwise, return -1.
Degree searchTerm (Polynomial P , Degree degree)
{
    while (P!=NULL)
    {
        if (P->degree==degree) return P->degree;
        P = P->next ;
    }
    return -1;
}

// Replace a polynomial term of a specified degree with given coefficient.
// If coefficient is 0.0, the correspoinding term is removed.
// If the term of specified degree does not exist, insert a new term.
// Return degree of the term.
Degree replaceTerm (Polynomial *P , Degree degree , Coeff coeff)
{
    if (searchTerm(*P , degree)!=-1)
    {
        Term cur=*P , prev=NULL ;
        if (coeff==0.0)
        {
            while (cur!=NULL)
            {
                if (cur->degree==degree)
                {
                    if (prev==NULL) *P = cur->next ;
                    else prev->next = cur->next ;
                    free (cur) ;
                    return degree;
                }
                prev = cur ;
                cur = cur->next ;
            }
        }
        else
        {
            while (cur!=NULL)
            {
                if (cur->degree==degree)
                {
                    cur->coeff = coeff ;
                    return degree;
                }
            }
        }
    }
    if (searchTerm(*P , degree)==-1 && coeff!=0.0)
    {
        Node *term=(Node *) malloc(sizeof(Node)) ;
        term->degree = degree ;
        term->coeff = coeff ;
        term->next = NULL ;
        if (*P==NULL) *P = term ;
        else
        {
            Term cur=*P , prev=NULL ;
            while (cur->next!=NULL)
            {
                if (cur->degree<term->degree)
                {
                    if (prev==NULL)
                    {
                        term->next = cur ;
                        *P = term ;
                        return term->degree;
                    }
                    else
                    {
                        term->next = cur ;
                        prev->next = term ;
                        return term->degree;
                    }
                }
                prev = cur ;
                cur = cur->next ;
           }
            cur->next = term ;
            return term->degree;
        }
    }
    return -1;
}

// Clear the polynomial.
void clear (Polynomial *P)
{
    Term cur ;
    while ((*P)!=NULL)
    {
        cur = *P ;
        *P = (*P)->next ;
        free(cur) ;
    }
}

// Checks whether the polynomial is empty. Return 1, if empty; otherwise, return 0.
int is_empty (Polynomial P)
{
    return ((P==NULL) ? 1 : 0);
}

// Print the polynomial.
void printPoly (Polynomial P)
{
    int first=1 ;
    while (P!=NULL)
    {
        (first==1) ? printf("%.3f " , P->coeff) , first=0 : printf("%+.3f " , P->coeff) ;
        if (P->degree>1) printf("X^%d" , P->degree) ;
        else if (P->degree==1) printf("X") ;
        P = P->next ;
    }
    printf("\n") ;
}

// Polynomial addition
Polynomial polyAdd (Polynomial P1 , Polynomial P2)
{
    Polynomial P ;
    initial(&P) ;
    while (P1!=NULL || P2!=NULL)
    {
        if (P1==NULL)
        {
            replaceTerm (&P , P2->degree , P2->coeff) ;
            P2 = P2->next ;
        }
        else if (P2==NULL)
        {
            replaceTerm(&P , P1->degree , P1->coeff) ;
            P1 = P1->next ;
        }
        else if (P1->degree<P2->degree)
        {
            replaceTerm (&P , P2->degree , P2->coeff) ;
            P2 = P2->next ;
        }
        else if (P1->degree>P2->degree)
        {
            replaceTerm(&P , P1->degree , P1->coeff) ;
            P1 = P1->next ;
        }
        else
        {
            replaceTerm(&P , P1->degree , P1->coeff + P2->coeff) ;
            P1 = P1->next ;
            P2 = P2->next ;
        }
    }
    return P;
}

// Polynomial subtraction
Polynomial polyMinus (Polynomial P1 , Polynomial P2)
{
    Polynomial P ;
    initial(&P) ;
    while (P1!=NULL || P2!=NULL)
    {
        if (P1==NULL)
        {
            replaceTerm (&P , P2->degree , -P2->coeff) ;
            P2 = P2->next ;
        }
        else if (P2==NULL)
        {
            replaceTerm(&P , P1->degree , P1->coeff) ;
            P1 = P1->next ;
        }
        else if (P1->degree<P2->degree)
        {
            replaceTerm (&P , P2->degree , -P2->coeff) ;
            P2 = P2->next ;
        }
        else if (P1->degree>P2->degree)
        {
            replaceTerm(&P , P1->degree , P1->coeff) ;
            P1 = P1->next ;
        }
        else
        {
            replaceTerm(&P , P1->degree , P1->coeff - P2->coeff) ;
            P1 = P1->next ;
            P2 = P2->next ;
        }
    }
    return P;
}

// Polynomial multiplication
Polynomial polyTime (Polynomial P1 , Polynomial P2)
{
    Polynomial P , temp ;
    Coeff coeff ;
    initial(&P) ;
    while (P1!=NULL)
    {
        temp = P2 ;
        while (temp!=NULL)
        {
            coeff = getCoeff(P , P1->degree + temp->degree) ;
            if (coeff!=-99) coeff += P1->coeff * temp->coeff ;
            else coeff = P1->coeff * temp->coeff ;
            replaceTerm(&P , P1->degree + temp->degree , coeff) ;
            printf ("%d\n" , P1->degree + temp->degree) ;
            temp = temp->next ;
        }
        P1 = P1->next ;
    }
    return P;
}

double power (double base , Degree pow)
{
    if (base==0) return 0;
    double ans=1 ;
    while (pow)
    {
        if (pow&1) ans *= base ;
        base *= base ;
        pow >>= 1 ;
    }
    return ans;
}