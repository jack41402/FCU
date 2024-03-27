#include <math.h>
#include "complex_D1271403.h"

complex complex_add(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

complex complex_subtract(complex a, complex b) {
    complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

complex complex_multiply(complex a, complex b) {
    complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

complex complex_divide(complex a, complex b) {
    complex c;
    float denom = b.real * b.real + b.imag * b.imag;
    c.real = (a.real * b.real + a.imag * b.imag) / denom;
    c.imag = (a.imag * b.real - a.real * b.imag) / denom;
    return c;
}

float complex_abs(complex a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

complex complex_from_real(float a) {
    complex c;
    c.real = a;
    c.imag = 0;
    return c;
}

void print_complex(complex a){
    if(a.real==0&&a.imag!=0) printf("%.4f i", a.imag);
    else if(a.real!=0&&a.imag==0) printf("%.4f", a.real);
    else if(a.real!=0&&a.imag>0) printf("%.4f+%.4f i", a.real, a.imag);
    else printf("%.4f%.4f i", a.real, a.imag);
}
