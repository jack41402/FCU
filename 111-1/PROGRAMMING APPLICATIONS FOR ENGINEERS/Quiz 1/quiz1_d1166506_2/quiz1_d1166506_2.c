#include <stdio.h>
#include <math.h>

// Computer the greatest common divisor of m and n,
// where m and n are positive integers.
int gcd(int m, int n)
{
    if (m%n==0) return n;
    else return gcd (n, m%n);
}

int main(void) {
    int p, q; // Numerator and denominator.
    int sign; // Sing of fraction a=p/q, 1: no sign, 0: '-' sign.
    int g; // GCD of p and q.

    while (1)
    {
        //a. Read two integers p and q as the numerator and denominator of
        //   fraction number a, where q!=0.
        printf("Input two integers p and q (terminates if q is 0): ");
        scanf("%d %d", &p, &q); // Input two integers p and q.
        if (q==0) return 0; // Program terminates if q is 0.

        // Complete the following two steps.

        // b. Simplify fraction number a to make p and q to be two non-negative
        //    relatively prime integers.

        // c. Determine whether a is a proper fraction or an improper fraction;
        //    if a is an improper fraction, determine, further, whether it is
        //    an integer or a mixed number. Output a as a proper fraction,
        //    an integer, or a mixed number.
        g = gcd (abs(p) , abs(q)) ;
        if (p%q==0)
        {
            printf ("Integer: %d\n\n" , p/q) ;
        }
        else if(abs(p/q)<1)
        {
            printf ("Proper fraction: ") ;
            (p*q>0) ? printf("%d/%d\n\n" , abs(p/g) , abs(q/g)) : printf ("-%d/%d\n\n" , abs(p/g) , abs(q/g)) ;
            continue ;
        }
        else
        {
            printf ("Mixed number: %d %d/%d\n\n" , p/q , abs(p%q/g) , abs(q/g)) ;
        }
    }
    return 0;
}
