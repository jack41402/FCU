#include <stdio.h>
#include <math.h>
#include "complex.h"

// Complex addition.
complex add(complex c1, complex c2) {
	complex sum;
	
	sum.re = c1.re + c2.re;
	sum.im = c1.im + c2.im;
	return sum; 
}

// Complex subtraction.
complex minus(complex c1, complex c2) {
	complex difference;
	
	difference.re = c1.re - c2.re;
	difference.im = c1.im - c2.im;
	return difference; 
} 

// Complex multiplication.
complex time(complex c1, complex c2) {
	complex product;
	
	product.re = c1.re * c2.re - c1.im * c2.im;
	product.im = c1.re * c2.im + c1.im * c2.re;
	return product; 
}

// Complex division.
complex divide(complex c1, complex c2) {
	complex quotient;
	
	quotient.re = (c1.re * c2.re + c1.im * c2.im) / (c2.re * c2.re + c2.im * c2.im);
	quotient.im = (-c1.re * c2.im + c1.im * c2.re) / (c2.re * c2.re + c2.im * c2.im);
	return quotient; 
}

// Absolute value of a complex number.
float absComplex(complex c) {
	return (float) sqrt(c.re * c.re + c.im * c.im);
} 

// Convert a real number to a complex number.
complex r2c(float r) {
	complex c;
	
	c.re = r;
	c.im =0.0;
	return c;
}

// Print a complex number.
void printComplex(complex c) {
	if (c.re==0.0) {
		if (c.im!=0) printf("%6.4f i", c.im);
		else printf("%6.4f", c.re);
	}
	else {
		printf("%6.4f", c.re);
		if (c.im>0.0) printf("+%6.4f i", c.im);
		else if (c.im<0.0) printf ("-%6.4f i", -c.im);
	}
}
