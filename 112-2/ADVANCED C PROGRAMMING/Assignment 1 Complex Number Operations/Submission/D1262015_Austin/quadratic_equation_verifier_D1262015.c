#include <stdio.h>
#include <math.h>
#include "complex_D1262015.h"

int main(void) {
    float a, b, c, verification1, verification2;
    complex r1, r2, sqrtDiscriminant;

    printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0:");
    scanf("%f%f%f", &a, &b, &c);

    if(a == 1)
        printf("The quadratic equation is: X**2 ");
    else if(a == -1)
        printf("The quadratic equation is: -X**2 ");
    else
        printf("The quadratic equation is: %.4f X**2 ", a);

    if(b == 1)
        printf("+ X ");
    else if(b == -1)
        printf("- X ");
    else if(b > 0)
        printf("+ %.4f X ", b);
    else if(b < 0)
        printf("- %.4f X ", -b);

    if(c > 0)
        printf("+ %.4f = 0.\n\n", c);
    else if(c < 0)
        printf("- %.4f = 0.\n\n", c);

    sqrtDiscriminant = r2c(pow(fabs(b * b - 4 * a * c), 0.5));

    if(b * b - 4 * a * c < 0) {
        r1.re = (-b) / (2 * a);
        r1.im = sqrtDiscriminant.re / (2 * a);
        r2.re = (-b) / (2 * a);
        r2.im = -sqrtDiscriminant.re / (2 * a);
    } else {
        r1.re = ((-b) + sqrtDiscriminant.re) / (2 * a);
        r1.im = 0;
        r2.re = ((-b) - sqrtDiscriminant.re) / (2 * a);
        r2.im = 0;
    }

    printf("The two roots of the quadratic equation are: ");
    printComplex(r1);
    printf(" and ");
    printComplex(r2);

    verification1 = absComplex(add(add(time(r2c(a), time(r1, r1)), time(r2c(b), r1)), r2c(c)));
    verification2 = absComplex(add(add(time(r2c(a), time(r2, r2)), time(r2c(b), r2)), r2c(c)));

    if(verification1 < 0.000001 && verification2 < 0.000001) {
        printf("\n\nQuadratic equation solution is a pair of valid roots. Verification succeeds.\n");
    } else {
        printf("\n\nQuadratic equation solution is a pair of invalid roots. Verification failed.\n");
    }

    return 0;
}

