//
//  main.c
//  Qudratic_Equation_Verifier_D1265065
//
//  Created by Corrine  on 2024/2/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1265065.h"

int main(void) {

	complex r1, r2, V1, V2;//Create structures to save complex numbers.
    float a, b, c, D;//Create variables to save coefficients.
    do{
    	printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0: ");
    	scanf("%f %f %f", &a, &b, &c);
	}while(a == 0);//scan the coefficients.
    printf("The quadratic equation is: ");
    
    //print out the equation.
    if (a < 0) printf(" - ");
    if (a == 1) printf("X**2");
    else printf("%.4f X**2", fabs(a));
    
    if (b == 0) printf("");
    else if (b > 0) printf(" + ");
    else if (b < 0) printf(" - ");
    if (b == 1) printf("X");
    else if (b != 0) printf("%.4f X", fabs(b));
    
    if (c > 0) printf(" + ");
    else if (c < 0) printf(" - ");
    else printf("");
    printf("%.4f", fabs(c));
    printf(" = 0.\n\n");
    
    printf("The two roots of the quadratic equation are: ");
    //use discriminant to judge if the roots are complex number and calculate the roots.
    D = pow(b, 2)-4*a*c;
    if (D >= 0) {
        r1.re = (-b+sqrt(D)) / (2*a);
        r1.im = 0;
        r2.re = (-b-sqrt(D)) / (2*a);
        r2.im = 0;
    } else {
        r1.re = -b / (2*a);
        r1.im = sqrt(-D) / (2*a);
        r2.re = -b / (2*a);
        r2.im = -sqrt(-D) / (2*a);
    }
    //print out the complex number.
    printComplex(r1);
    printf(" and ");
    printComplex(r2);
    printf("\n\n");
    //verification.
    V1 = add(add(multiply(multiply(r1, r1), r2c(a)), multiply(r1, r2c(b))), r2c(c));
    V2 = add(add(multiply(multiply(r2, r2), r2c(a)), multiply(r2, r2c(b))), r2c(c));
    if (absComplex(V1) < 0.000001 && absComplex(V2) < 0.000001) {
        printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.\n");
    } else {
        printf("Quadratic equation solution is not a pair of valid roots. Verification fails.\n");
    }
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
