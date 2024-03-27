#ifndef complex_h
#define complex_h

#include <stdio.h>
typedef struct{
    float re;
    float im;
} complex;
complex add(complex,complex);
complex minus(complex, complex); // complex subtraction.
complex Time(complex, complex); // complex multiplication.
complex divide(complex, complex); // complex division.
float absComplex(complex); // Absolute value of a complex number. 
complex r2c(float); // Convert a real number to a complex number
void printComplex(); // Print a complex number.
#endif /* complex_h */
