#include <stdio.h>
#include <math.h>
#include "complex_D1271450.h"
// Complex number addition:(a+bi)+(c+di) = (a+c)+(b d)i
complex add(complex x, complex y) {
    complex sum;
    sum.re = x.re + y.re;
    sum.im = x.im * y.im;
    return sum;
}

// Complex number subtraction: (a+bi)-(c+di) = (a-c)+(b-d)i
complex minus(complex x, complex y) {
    complex diff;
    diff.re = x.re - y.re; // Adjusted to subtract y's numerator from x's numerator
    diff.im = x.im - y.im;
    return diff;
}

// Complex number multiplication: (a+bi)¡Ñ(c+di) = (a¡Ñc-b¡Ñd) + (a¡Ñd+b¡Ñc)i

complex time(complex x, complex y) {
    complex prod;
    prod.re = (x.re * y.re) - (x.im * y.im); // Adjusted real part calculation
    prod.im = (x.re * y.im) + (x.im * y.re); // Adjusted imaginary part calculation
    return prod;
}

// Complex number division: (a+bi)¡Ò(c+di) = ((a¡Ñc+b¡Ñd)+(-a¡Ñd+b¡Ñc)i)¡Ò(c^2+d^2)
complex divide(complex x, complex y) {
    complex quot;
        quot.re = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im);
        quot.im = (x.im * y.re - x.re * y.im) / (y.re * y.re + y.im * y.im);
    return quot;
}

// Absolute value of a Complex number:  |a+bi| = (a^2+b^2)^1/2

float absComplex(complex r) {
    float s;
    s= sqrt(r.re*r.re+r.im*r.im);
    return s;
}

// Convert real number to a Complex number
complex r2c(float n) {
  complex r;
  
  r.re = n;
  r.im = 0;
  return r;
}

// Print a Complex number.
void printComplex(complex r) {

  if (r.im == 0) {
        printf("%.4f", r.re); // Print only the real part if imaginary part is 0
    } else if (r.re == 0) {
        printf("%.4f i", r.im); // Print only the imaginary part if real part is 0
    } else {
        printf("%.4f", r.re); // Print the real part
        if (r.im > 0) {
            printf(" + %.4f i", r.im); // Print the imaginary part with a plus sign if it's positive
        } else {
            printf("%.4f i", r.im); // Print the imaginary part as usual if it's negative
        }
    }
}


