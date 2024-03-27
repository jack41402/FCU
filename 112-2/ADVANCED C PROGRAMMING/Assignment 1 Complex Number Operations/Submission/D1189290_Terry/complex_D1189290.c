#include <stdio.h>
#include <math.h>
#include "complex_D1189290.h"

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
    float denom = b.re * b.re + b.im * b.im;
    result.re = (a.re * b.re + a.im * b.im) / denom;
    result.im = (a.im * b.re - a.re * b.im) / denom;
    return result;
}

float absComplex(complex z) {
    return sqrt(z.re * z.re + z.im * z.im);
}

complex r2c(float x) {
    complex result;
    result.re = x;
    result.im = 0;
    return result;
}

void printComplex(complex z) {
    if (z.im >= 0)
        printf("%.4fi",z.im);
    else
        printf("- %.4fi\n",-z.im);
}

