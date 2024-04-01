#ifndef COMPLEX_D1262028_H
#define COMPLEX_D1262028_H

typedef struct {
    float re; // real part;
    float im; // imaginary part;
} complex;

complex add(complex, complex);

complex minus(complex, complex);

complex time(complex, complex);

complex divide(complex, complex);

float absComplex(complex);

complex r2c(float);

void printComplex(complex);

#endif /* COMPLEX_D1262028_H */
