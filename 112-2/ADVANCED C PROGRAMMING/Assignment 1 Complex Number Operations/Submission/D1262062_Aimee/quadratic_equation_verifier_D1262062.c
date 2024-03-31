#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1262062.h"

//print the first term of the equation
void printa(float a){
	if(a == 1)printf("X**2 ");
	else if(a == -1)printf("-X**2 ");
	else printf("%6.4f X**2 ", a);
}

//print the second and third term of the equation
void printbc(float b){
	if(b == 0)printf("");
	else if(b>0)printf("+ %6.4f ", b);
	else printf("- %6.4f ", -b);
}

//get the two roots
void root(float a, float b, float c, complex *root1, complex *root2){
	float D, r1, r2, r3, r4;
	D = b*b-4*a*c;
	r1 = -b/(2*a);// The value of the roots when D=0 and it's also the real number part of the complex roots.
	r2 = (-b+sqrt(D))/(2*a);// The value of the first root when D>0.
	r3 = (-b-sqrt(D))/(2*a);// The value of the second root when D>0.
	r4 = sqrt(-D)/(2*a);// The value of the imaginary number of an comlex root.
	if(D == 0){
		*root1 = r2c(r1);
		*root2 = r2c(r2);
	}
	else if(D > 0){
		*root1 = r2c(r2);
		*root2 = r2c(r3);
	}
	else{
		root1->re = r1;
		root1->im = r4;
		root2->re = r1;
		root2->im = -r4;
	}
}

//verify the two roots
void verify(float a, float b, float c, complex root1, complex root2){
	complex verify1, verify2;
	verify1 = add(add(time(r2c(a), time(root1, root1)), time(r2c(b), root1)), r2c(c));
	verify2 = add(add(time(r2c(a), time(root2, root2)), time(r2c(b), root2)), r2c(c));
	if(absComplex(verify1) < 0.000001 && absComplex(verify2) < 0.000001){
		printf("\n\nQuadratic equation solution is a pair of valid roots. Verification succeeds.");
	}
	else printf("\n\nQuadratic equation solution is not a pair of valid roots. Verification fails.");
}

int main(void) {
	float a, b, c;
	complex root1, root2;
	do {
		printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0:");
		scanf("%f %f %f", &a, &b, &c);	
	} while (a == 0);
	printf("The quadratic eqution is: ");
	printa(a);// print the first term
	printbc(b);// print the second term
	if(b != 0)printf("X ");
	printbc(c);// print the third term
	printf("= 0.");
	root(a, b, c, &root1, &root2);// get the two roots
	printf("\n\nThe two roots of the quadratic equation are: ");
	printComplex(root1);
	printf("and ");
	printComplex(root2);
	verify(a, b, c, root1, root2);
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
