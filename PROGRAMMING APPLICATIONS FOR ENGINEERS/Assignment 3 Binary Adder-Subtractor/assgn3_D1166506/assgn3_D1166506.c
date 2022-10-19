#include <stdio.h>

void printBinary(unsigned int n) // Print the integer variable in binary.
{
    for (int i=1 ; i<=32 ; i++) // Output all 32 bits of the variable in binary.
    {
        printf ("%d" , (n>>(32-i))&1) ; // Output bits of n from left to right.
        if (i%4==0) printf (" ") ; // Print space every four bits.
    }
}

void adder (int X , int Y , int *carry , int *ans) // full adder
{
    for (int i=0 ; i<32 ; ++i)
    {
        *ans |= ((((X>>i) & 1 ^ (Y>>i) & 1) ^ *carry)<<i) ; // Use Leftshift and OR to add the C_in^(X^Y) to the i-th digit.
        if (i==31) *carry ^= ((((X>>i) & 1) & ((Y>>i) & 1)) | (((X>>i) & 1 ^ (Y>>i) & 1) & *carry)); // Use XOR to catch the flag of overflow. The sum of two positive or negative numbers won't be negative or positive.
        else *carry = ((((X>>i) & 1) & ((Y>>i) & 1)) | (((X>>i) & 1 ^ (Y>>i) & 1) & *carry)) ; // To determine whether to carry in a normal situation, one calculates ((X & Y)|(XY) & carry).
    }
}

int main()
{
    while (1)
    {
        int X , Y , carry=0 , ans=0 ;
        char operator ;
        scanf("%d %c %d", &X, &operator, &Y) ;
        if (X==0 && Y==0) break ; // Break the loop while X and Y are both equal to 0.
        if (operator == '-') carry = 1 ; // Carry in at the first digit while the operator is negative.
        adder(X , (operator=='-') ? ~Y : Y , &carry , &ans) ; // Use the function adder to sum up X and Y.
        if (carry) printf("Overflow!\n");  // Use carry to catch the flag
        else // print the variables X, Y, and S in both decimal and binary.
        {
            printf ("X = %-10d  Binary value: " , X) , printBinary (X) , printf ("\n") ;
            printf ("Y = %-10d  Binary value: " , Y) , printBinary (Y) , printf ("\n") ;
            printf ("S = %-10d  Binary value: " , ans) , printBinary (ans) , printf ("\n") ;
        }
    }
    return 0;
}