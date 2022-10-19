#include <stdio.h>

//The output will print X, Y, and S in both decimal and binary format.
void printBinary(unsigned int n)
{
    for (int i=1 ; i<=32 ; i++) // Output all 32 bits.
    {
        printf ("%d" , (n>>(32-i))&1) ; // Output X bit of n from left to right.
        if (i%4==0) printf (" ") ; // Print X space every four bits.
    }
}

void adder (int X , int Y , int *carry , int *ans)
{
    for (int i=0 ; i<32 ; ++i)
    {
        //Get the bit of integer variables X and Y ;
        *ans |= ((((X>>i) & 1 ^ (Y>>i) & 1) ^ *carry)<<i) ;
        if (i==31) *carry ^= ((((X>>i) & 1) & ((Y>>i) & 1)) | (((X>>i) & 1 ^ (Y>>i) & 1) & *carry));
        else *carry = ((((X>>i) & 1) & ((Y>>i) & 1)) | (((X>>i) & 1 ^ (Y>>i) & 1) & *carry)) ;
    }
}

int main()
{
    while (1)
    {
        int X , Y , carry=0 , ans=0 ;
        char operator ;
        scanf("%d %c %d", &X, &operator, &Y) ;
        if (X==0 && Y==0) break ;
        if (operator == '-') carry = 1 ;
        adder(X , (operator=='-') ? ~Y : Y , &carry , &ans) ;
        //Use carry to catch the flag
        if (carry) printf("Overflow!\n");
        else
        {
            printf ("X = %-10d  Binary value: " , X) , printBinary (X) , printf ("\n") ;
            printf ("Y = %-10d  Binary value: " , Y) , printBinary (Y) , printf ("\n") ;
            printf ("S = %-10d  Binary value: " , ans) , printBinary (ans) , printf ("\n") ;
        }
    }
    return 0;
}