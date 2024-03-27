#include <stdio.h> 
typedef struct {
	double re;
	double im;
}complex;
//bulid a struction of complex numbers in re part and im part.
complex add(complex, complex); 
// complex addition.
complex minus(complex, complex); 
// complex subtraction.
complex time(complex, complex); 
// complex multiplication.
complex divide(complex, complex); 
// complex division.
double absComplex(complex); 
// Absolute value of a complex number.
complex r2c(double); 
// Convert a real number to a complex number
void printComplex(complex); 
// Print a complex number
 
