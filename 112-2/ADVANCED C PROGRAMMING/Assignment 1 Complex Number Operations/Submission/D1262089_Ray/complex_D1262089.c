#include "complex_D1262089.h"
#include <stdio.h>
#include <math.h>

complex add(complex a, complex b) {
    complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

complex minus(complex a, complex b) {
    complex result;
    result.re = a.re - b.re;
    result.im = a.im - b.im;
    return result;
}

complex multiply(complex a, complex b) {
    complex result;
    result.re = a.re * b.re - a.im * b.im;
    result.im = a.re * b.im + a.im * b.re;
    return result;
}

complex divide(complex a, complex b) {
    complex result;
    float denominator = b.re * b.re + b.im * b.im;
    result.re = (a.re * b.re + a.im * b.im) / denominator;
    result.im = (a.im * b.re - a.re * b.im) / denominator;
    return result;
}

float absComplex(complex a) {
    return sqrt(a.re * a.re + a.im * a.im);
}

complex r2c(float real) {
    complex result;
    result.re = real;
    result.im = 0.0;
    return result;
}

void printComplex(complex a) {
	if (a.re != 0 || a.im != 0) {
        if (a.re > 0.000001 || a.re < -0.000001   ) {
            printf("%.4f", a.re);
        }
        if (a.im > 0 && a.re > 0.000001) {
            printf("+");
        } else if (a.im < 0 ) {
            printf("-");
        }
        if (a.im != 0) {
            printf("%.4fi", fabs(a.im));
        }
        //printf("\n");
    } else {
        printf("0\n");
    }
    
}







