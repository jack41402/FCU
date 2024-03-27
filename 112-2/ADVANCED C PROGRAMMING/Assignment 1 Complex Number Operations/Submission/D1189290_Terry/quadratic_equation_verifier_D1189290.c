#include <stdio.h>
#include <math.h>
#include "complex_D1189290.h"

int main() {
    // Declare variables for coefficients and roots
    float a, b, c;
    // Eenter coefficients for the quadratic equation
    printf("Enter coefficients a, b, and c for the quadratic equation ax^2 + bx + c = 0: ");
    // Read coefficients from user input
    scanf("%f %f %f", &a, &b, &c);

    // Calculate the discriminant
    float discriminant = b * b - 4 * a * c;
    // Declare complex numbers to store the roots
    complex root1, root2;

    // Check if discriminant is non-negative (real roots)
    if (discriminant >= 0) {
        // Calculate real roots
        root1.re = (-b + sqrt(discriminant)) / (2 * a);
        root1.im = 0;
        root2.re = (-b - sqrt(discriminant)) / (2 * a);
        root2.im = 0;
    } else { // If discriminant is negative (complex roots)
        // Calculate real and imaginary parts of complex roots
        root1.re = -b / (2 * a);
        root1.im = sqrt(-discriminant) / (2 * a);
        root2.re = -b / (2 * a);
        root2.im = -sqrt(-discriminant) / (2 * a);
    }

    // Print the quadratic equation
    printf("The quadratic equation is ");

    // Print x^2 term
    if (a != 0) {
        if (a != 1) {
            printf("%.4f", a);
        }
        printf("X**2");
    }

    // Print x term
    if (b != 0) {
        if (b > 0 && a != 0) {
            printf(" + ");
        }
        printf("%.4fX", b);
    }

    // Print constant term
    if (c != 0) {
        if (c > 0 && (a != 0 || b != 0)) {
            printf(" + ");
        }
        printf("%.4f", c);
    }

    printf(" = 0\n");

    // Print the roots of the quadratic equation
    printf("The two roots of the quadratic equation are: ");

    // Print root 1
    if (root1.re != 0 || root1.im == 0) {
        printf("%.4f", root1.re);
    }

    if (root1.im != 0) {
        if (root1.re != 0 || root1.im < 0) {
            printf(" - ");
        } else if (root1.re != 0) {
            printf(" + ");
        }
        printf("%.4fi", fabs(root1.im));
    }

    printf(" and ");

    // Print root 2
    if (root2.re != 0 || root2.im == 0) {
        printf("%.4f", root2.re);
    }

    if (root2.im != 0) {
        if (root2.re != 0 || root2.im < 0) {
            printf(" - ");
        } else if (root2.re != 0) {
            printf(" + ");
        }
        printf("%.4fi", fabs(root2.im));
    }

    // Verifying the roots
    float result1 = a * root1.re * root1.re + b * root1.re + c;
    float result2 = a * root2.re * root2.re + b * root2.re + c;

    // Check if the calculated roots satisfy the quadratic equation
    if ((fabs(result1) < 0.000001 || (root1.im != 0 && fabs(result1 - root1.im * root1.im) < 0.000001)) &&
        (fabs(result2) < 0.000001 || (root2.im != 0 && fabs(result2 - root2.im * root2.im) < 0.000001)))
        printf("\nQuadratic equation solution is a pair of valid roots. Verification succeeds.\n");
    else
        printf("\nQuadratic equation solution is not a pair of valid roots. Verification fails.\n");

    return 0;
}

