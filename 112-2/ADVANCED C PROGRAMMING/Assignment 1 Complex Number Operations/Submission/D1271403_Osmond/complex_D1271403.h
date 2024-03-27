#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
    float real;
    float imag;
} complex;

complex complex_add(complex a, complex b);
complex complex_subtract(complex a, complex b);
complex complex_multiply(complex a, complex b);
complex complex_divide(complex a, complex b);
float complex_abs(complex a);
complex complex_from_real(float a);
void print_complex(complex a);

#endif
