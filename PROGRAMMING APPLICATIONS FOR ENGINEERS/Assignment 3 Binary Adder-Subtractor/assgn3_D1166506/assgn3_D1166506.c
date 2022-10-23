#include <stdio.h>

void printBinary(int n) // Print the integer variable in binary.
{
    // Output all 32 bits of n from left to right and print space every four bits.
    for (int i=1 ; i<=32 ; i++) printf ("%d%s" , (n>>(32-i))&1 , (i%4) ? "" : " ") ;
}

void adder (int X , int Y , int *carry , int *ans , int *overflow) // full adder
{
    for (int i=0 ; i<32 ; ++i)
    {
        *ans |= ((((X>>i) & 1 ^ (Y>>i) & 1) ^ *carry)<<i) ; // Use Leftshift and OR to add the C_in^(X^Y) to the i-th digit.
        // To determine whether to carry in a normal situation, one calculates ((X & Y)|(XY) & carry). Record the overflow at the same time.
        *overflow = *carry , *carry = ((((X>>i) & 1) & ((Y>>i) & 1)) | (((X>>i) & 1 ^ (Y>>i) & 1) & *carry)) , *overflow ^= *carry ;
    }
}

int main()
{
    while (1)
    {
        int X , Y , carry=0 , ans=0 , overflow , compare ;
        char operator , str[32] ;
        printf ("Enter \"X + Y\" or \"X - Y\" (X, Y: -2,147,483,648 to 2,147,483,647): ") , fflush(stdout) ;
        scanf("%d %c %d", &X, &operator, &Y) ;
        if (X==0 && Y==0) break ; // Break the loop while X and Y are both equal to 0.
        (operator=='-') ? (compare = X - Y , carry = 1) : (compare = X + Y); // Determine carry in at the first digit equal to 1 while the operator is negative.
        adder(X , (operator=='-') ? ~Y : Y , &carry , &ans , &overflow) ; // Use the function adder to sum up X and Y.
        // print the variables X, Y, and S in both decimal and binary.
        printf ("X = %-10d  Binary value: " , X) , printBinary (X) , printf ("\n") ;
        printf ("Y = %-10d  Binary value: " , Y) , printBinary (Y) , printf ("\n") ;
        printf ("S = %-10d  Binary value: " , ans) , printBinary (ans) , printf ("\n") ;
        int flag=(compare==ans) ;
        printf("%s Adder-subtractor operation test: %d %c %d %s %d\n" , (flag) ? "Correct!" : "Incorrect!" ,  X , operator , Y  , (flag) ? "=" : "!=" , ans) ;
        // Use overflow to catch the flag, and if overflow is true then print this sentence.
        if (overflow) printf("**** The addition-subtraction operation is overflow.\n") ;
        printf ("-----------------------------------------------------\n") ;
    }
    return 0;
}