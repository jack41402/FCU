

#include "complex_D1166570.h"
#include "math.h"

// Function to add two complex numbers
complex add(complex a, complex b) {
    complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

// Function to subtract two complex numbers
complex minus(complex a, complex b) {
    complex result;
    result.re = a.re - b.re;
    result.im = a.im - b.im;
    return result;
}

// Function to multiply two complex numbers
complex time(complex a, complex b) {
    complex result;
    result.re = a.re * b.re - a.im * b.im;
    result.im = a.re * b.im + a.im * b.re;
    return result;
}

// Function to divide two complex numbers
complex divide(complex a, complex b) {
    complex result;
    float denominator = b.re * b.re + b.im * b.im;
    result.re = (a.re * b.re + a.im * b.im) / denominator;
    result.im = (a.im * b.re - a.re * b.im) / denominator;
    return result;
}

// Function to calculate the absolute value of a complex number
float absComplex(complex a) {
    return sqrt(a.re * a.re + a.im * a.im);
}

// Function to convert a real number to a complex number
complex r2c(float a) {
    complex result;
    result.re = a;
    result.im = 0;
    return result;
}

// Function to print a complex number
void printComplex(complex a) {
    if (a.re == 0 && a.im == 0)
    {
        printf("0");
    }
    else if (a.re == 0)
    {
        printf("%.4f i", a.im);
    }
    else if (a.im == 0)
    {
        printf("%.4f", a.re);
    }
    else
    {
        if(a.im>0){
        	printf("%.4f +%.4f i", a.re, a.im);
		}
		else{
			printf("%.4f %.4f i", a.re, a.im);
		}
    }
}

