#include <stdio.h>
#include <math.h>
#include "complex_D1262092.h"

// complex addition.
//(a+bi)+(c+di) = (a+c)+(b d)i
complex add(complex a, complex b){
	complex result;
	result.re = a.re + b.re;
	result.im = a.im + b.im;
	
	return result;
}

// complex subtraction.
//(a+bi)-(c+di) = (a-c)+(b-d)i
complex minus(complex a, complex b){
	complex result;
	result.re = a.re - b.re;
	result.im = a.im - b.im;
	
	return result;
}

// complex multiplication.
//(a+bi)¡Ñ(c+di) = (a¡Ñc-b¡Ñd) + (a¡Ñd+b¡Ñc)i
complex time(complex a, complex b){
	complex result;
	result.re = a.re*b.re - a.im*b.im;
	result.im = a.re*b.im + a.im*b.re;
	
	return result;
}

// complex division.
//(a+bi)¡Ò(c+di) = ((a¡Ñc+b¡Ñd)+(-a¡Ñd+b¡Ñc)i)¡Ò(c2+d2)
complex divide(complex a, complex b){
	complex result;
	result.re = (a.re*b.re+a.im*b.im) / (pow(b.re, 2) + pow(b.im, 2));
	result.im = (-a.re*b.im+a.im*b.re) / (pow(b.re, 2) + pow(b.im, 2));
	
	return result;
}

// Absolute value of a complex number.
//|a+bi| = (a2+b2)1/2
float absComplex(complex x){
	float abst;
	abst = sqrt(pow(x.re, 2) + pow(x.im, 2));
	
	return abst;
}

// Convert a real number to a complex number
complex r2c(float a){
	complex cmp;
		cmp.re = a;
		cmp.im = 0;
	
	return cmp;
}

// Print a complex number.
void printComplex(complex x){
	if (x.im == 0){
		if (x.re == 0){
			printf("%f", 0);
		}
		else{
			printf("%6.4f", x.re);	
		}
	}
	else{
		if(x.re == 0){
			printf("%6.4f i", x.im);
		}
		else{
			if (x.im > 0){
				printf("%6.4f+%6.4f i", x.re, x.im);
			}
			else{
				printf("%6.4f%6.4f i", x.re, x.im);
			}
		}
	}	
}

