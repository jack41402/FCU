//
//  complex.c
//  Qudratic_Equation_Verifier_D1265065
//
//  Created by Corrine  on 2024/2/27.
//

#include "complex_D1265065.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

complex add(complex a, complex b) {//Create a function to calculate addition.
    complex c;//Create a structure complex c to collect sum.
    c.re = a.re + b.re;//Add two real numbers together.
    c.im = a.im + b.im;//Add two imaginary numbers together.
    return c;
}

complex minus(complex a, complex b) {//Create a function to calculate subtraction.
    complex c;//Create a structure complex c to collect difference.
    c.re = a.re - b.re;//Subtract two real numbers.
    c.im = c.im - c.im;//Subtract two imaginary numbers.
    return c;
}

complex multiply(complex a, complex b) {//Create a function to calculate multiplication.
    complex c;//Create a structure complex c to collect product.
    c.re = a.re * b.re - a.im * b.im;//Time real numbers together.
    c.im = a.re * b.im + a.im * b.re;//Time imaginary numbers together.
    return c;
}

complex divide(complex a, complex b) {//Create a function to calculate division.
    complex c;//Create a structure complex c to collect product.
    c.re = (a.re * b.re + a.im * b.im) / (pow(b.re, 2)+pow(b.im, 2));//Divde real numbers.
    c.im =(-a.re * b.im + a.im * b.re) / (pow(b.re, 2)+pow(b.im, 2));//Divide imaginary numbers.
    return c;
}

float absComplex(complex a) {
    float value;
    value = sqrt(pow(a.re, 2)+pow(a.im, 2));
    return value;
}

complex r2c(float x) {
    complex a;
    a.re = x;
    a.im = 0;
    return a;
}

void printComplex(complex a) {
    
    if (a.re == 0) printf("");
    else if (a.re < 0) {
		printf("-");
    	printf("%.4f", fabs(a.re));
 	}
 	else printf("%.4f", a.re);
    
    if (a.im == 0) printf("");
    else if (a.im < 0) printf("-");
    else if (a.im > 0 && a.re != 0) printf("+");
    if (a.im != 0) printf("%.4f i", fabs(a.im));
}
