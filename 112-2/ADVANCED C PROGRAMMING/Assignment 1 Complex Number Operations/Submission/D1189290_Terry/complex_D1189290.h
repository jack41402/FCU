#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
    float re; // real part;
    float im; // imaginary part;
} complex;

complex add(complex a, complex b);
complex minus(complex a, complex b);
complex multiply(complex a, complex b);
complex divide(complex a, complex b);
float absComplex(complex z);
complex r2c(float x);
void printComplex(complex z);

#endif 

