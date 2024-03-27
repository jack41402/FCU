#include "complex_D1262028.h"
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

complex time(complex a, complex b) {
	complex result;
	result.re = a.re * b.re - a.im * b.im;
	result.im = a.im * b.re + a.re * b.im;
	return result;
}

complex divide(complex a, complex b) {
	complex result;
	result.re = (a.re * b.re + a.im * b.im) / (pow(b.re,2) + pow(b.im,2));
	result.im = (-a.re * b.im + a.im * b.re) / (pow(b.re,2) + pow(b.im,2));
	return result;
}

float absComplex(complex a) {
	complex result;
	return pow((a.re * a.re) + (a.im * a.im) , 0.5);
}

complex r2c(float a) {
	complex result;
	result.re = a;
	result.im = 0;
	return result;
}

void printComplex(complex a) {
	if ((a.re != 0) && (a.im != 0))
	printf("%1.6f + %1.6fi", a.re, a.im);
	else if ((a.re != 0) && (a.im == 0))
	printf("%1.6f", a.re);
	else if ((a.re == 0) && (a.im != 0))
	printf("%1.6fi", a.im);
	else if ((a.re == 0) && (a.im == 0))
	printf("0.000000");
}
