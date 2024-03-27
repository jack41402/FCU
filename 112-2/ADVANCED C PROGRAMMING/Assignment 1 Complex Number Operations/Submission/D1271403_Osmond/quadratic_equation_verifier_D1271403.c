#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1271403.h"

#define EPSILON 0.000001

void print_equation(float a, float b, float c) {
    printf("The quadratic equation is: ");

    if (a == 1) {
        printf("X**2 ");
    } else if (a == -1) {
        printf("-X**2 ");
    } else {
        printf("%.4f X\**2 ", a);
    }

    if (b > 0) {
        printf("+ %.4f X ", b);
    } else if (b < 0) {
        printf("- %.4f X ", fabs(b));
    } else {
        printf("");
    }

    if (c != 0 && c > 0) {
        printf("+ %.4f = 0.\n", c);
    } else if (c != 0 && c < 0) {
        printf("- %.4f = 0.\n", fabs(c));
    } else {
        printf("= 0.\n");
    }
}

void verify(float a, float b, float c, complex r1, complex r2) {
    printf("\n\nQuadratic equation is a pair of valid roots. ");
    complex v1 = complex_add(complex_add(complex_multiply(complex_from_real(a), complex_multiply(r1, r1)), complex_multiply(complex_from_real(b), r1)), r2);
    complex v2 = complex_add(complex_add(complex_multiply(complex_from_real(a), complex_multiply(r2, r2)), complex_multiply(complex_from_real(b), r2)), r2);

    if (fabs(complex_abs(v1) - 0) <= EPSILON && fabs(complex_abs(v2) - 0) <= EPSILON) {
        printf("Verification failed.");
    } else {
        printf("Verification succeeds.");
    }
}

int main() {
    float a, b, c;
    complex root1, root2;

    printf("Enter the coefficients a, b and c for quadratic equation a X**2 + b X + c = 0: ");

    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        do {
            printf("'a' cannot be 0. Try entering another real number. ");
            scanf("%f", &a);
        } while (a == 0);
    }

    print_equation(a, b, c);

    if (b * b - 4 * (a * c) < 0) {
        root1.real = -b / (2 * a);
        root1.imag = sqrt(fabs(b * b - 4 * a * c)) / (2 * a);
        root2.real = -b / (2 * a);
        root2.imag = -sqrt(fabs(b * b - 4 * a * c)) / (2 * a);

    } else if (b * b - 4 * (a * c) >= 0) {
        root1.real = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        root1.imag = 0;
        root2.real = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        root2.imag = 0;
    }

    printf("\nThe two roots of the quadratic equation are: ");
    print_complex(root1);
    printf(" and ");
    print_complex(root2);
    verify(a, b, c, root1, root2);

    return 0;
}
