#define epsilon 0.000001
#include <stdio.h>
#include <math.h>
#include "complex.h"

void printEquation(float a, float b, float c) {
	printf("The quadratic equation is: ");
	
	// Print term aX**2 of degree 2.
	if (a==1.0) printf("X**2");
	else if (a==-1.0) printf("-X**2");
	else printf("%6.4f X**2", a);
	
	// Print term bX of degree 1.
	if (b==1.0) printf(" + X");
	else if (b==-1.0) printf(" - X");
	else if (b>0.0) printf(" + %6.4f X", b);
	else if (b<0.0) printf(" - %6.4f X", -b);
	
	// Print term c of the constant term.
	if (c>0.0) printf(" + %6.4f = 0.\n", c);
	else if (c<0.0) printf(" - %6.4f = 0.\n", -c);
	else printf(" = 0.\n");
}

int main(void) {
	float a, b, c; // Coefficients of the quadratic equation.
	float term; // The term of b**2-4ac.
	complex r1, r2; // Two roots of the quadratic equation.
	
	printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0: ");
	scanf("%f %f %f", &a, &b, &c);
	printEquation(a, b, c);
	
	term = b * b - 4 * a * c; // Compute b**2-4ac.
	// Compute two roots of the quadratic equation.
	if (term==0.0) { // When b**2-4ac is 0.0.
		if (b==0.0) { // The roots are 0.0.
			r1 = r2c(0.0);
			r2 = r2c(0.0);
		}
		else { // The roots are multiple root -b/2a.
			r1 = r2c(-b / (2 * a));
			r2 = r2c(-b / (2 * a));
		}
	}
	else if (term>0) { // When b**2-4ac is greater than 0.0.
		// Two real roots.
		r1 = r2c((-b + sqrt(term)) / (2 * a));
		r2 = r2c((-b - sqrt(term)) / (2 * a));
	} 
	else { // When b**2-4ac is less than 0.0.
		// Two complex roots.
		r1.re = -b / (2 * a);
		r1.im = sqrt(-term) / (2 * a);
		r2.re = -b / (2 * a);
		r2.im = -sqrt(-term) / (2 * a);
	} 
	
	// Print the two roots.
	printf("\nThe two roots of the quadratic equation are: ");
	printComplex(r1);
	printf(" and ");
	printComplex(r2);
	
	// Verify r1 and r2 are roots of the quadratic equation.
	if (absComplex(add(add(time(r2c(a),time(r1, r1)), time(r2c(b),r1)),r2c(c)))<epsilon &&
	    absComplex(add(add(time(r2c(a),time(r2, r2)), time(r2c(b),r2)),r2c(c)))<epsilon)
		printf("\n\nQuadratic equation solution is a pair of valid roots. Verification succeeds.\n");
	else printf("\n\nQuadratic equation solution is not a pair of valid roots. Verification fails.\n");

    complex test1, test2;
    test1.re = 10, test1.im = -5;
    test2.re = 10, test2.im = -5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 10, test2.im = 0;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 0, test2.im = -5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 5, test2.im = 5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
	return 0;
} 
