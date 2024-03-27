#include <stdio.h>
#include <math.h>
#include "complex_D1262028.h"

int main(void) {
    float a, b, c;
    complex r1, r2;
    printf("Solving root of equation a*X^2 + b*X + c = 0.\n");
    printf("Please enter the coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        printf("Error! 'a' coefficient must not be zero.\n");
    } else {
        // Calculate the discriminant
        complex discriminant = minus(multiply(r2c(b), r2c(b)), multiply(r2c(4 * a), r2c(c)));

        // Print the type of roots
        printf("The ");
        if (discriminant.im == 0) {
            printf("multiple real root of equation ");
        } else if (discriminant.re > 0) {
            printf("real roots of equation ");
        } else {
            printf("complex roots of equation ");
        }

        // Print the equation
        printf("%.0fX^2", a);
        if (b != 0) {
            printf(" + %.0fX", b);
        }
        if (c != 0) {
            printf(" + %.0f", c);
        }
        printf(" = 0 ");

        // Calculate and print roots
        if (b * b - 4 * a * c == 0) {
            r1.re = -b / (2 * a);
            printf("are: ");
            printComplex(r1);
            printf(" and ");
            printComplex(r2);
        } else if (b * b - 4 * a * c > 0) {
            r1.re = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            r2.re = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
            printf("are: ");
            printComplex(r1);
            printf(" and ");
            printComplex(r2);
        } else if (b * b - 4 * a * c < 0) {
            r1.re = -b / (2 * a);
            r2.re = -b / (2 * a);
            r1.im = sqrt(-1 * (b * b - 4 * a * c)) / (2 * a);
            r2.im = -sqrt(-1 * (b * b - 4 * a * c)) / (2 * a);
            printf("are: ");
            printComplex(r1);
            printf(" and ");
            printComplex(r2);   
        }
    }

    return 0;
}

