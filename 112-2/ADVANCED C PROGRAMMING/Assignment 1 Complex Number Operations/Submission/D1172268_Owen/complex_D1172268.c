#include<stdio.h>
#include<math.h>
#include"complex_D1172268.h"


// complex addition.
complex add(complex a, complex b){
	complex res = {a.re + b.re, a.im + b.im};
	return res;	
}

// complex subtraction.
complex minus(complex a, complex b){
	complex res = {a.re - b.re, a.im - b.im};
	return res;
}

// complex multiplication
complex time(complex a, complex b){
	complex res = {a.re * b.re - a.im * b.im, a.im * b.re + a.re * b.im};
	return res;
}

// complex division.
complex divide(complex a, complex b){
	float tmp = b.re * b.re + b.im * b.im;
	complex res = {(a.re * b.re + a.im * b.im) / tmp, (-a.re * b.im + a.im *b.re)/tmp};
	return res;
} 
// Absolute value of a complex number.
float absComplex(complex a){
	return sqrt(a.re * a.re + a.im * a.im);
}

// Convert a real number to a complex number
complex r2c(float f){
	complex res = {f, 0};
	return res;
} 

// Print a complex number.
void printComplex(complex a){
	if(a.re != 0) printf("%.4f",a.re);
	if(a.im > 0){
		if(a.re != 0) printf("+");
		printf("%.4f i", a.im);
	} 
	else if(a.im < 0){
		printf("%.4f i",a.im);
	}
	if(a.re == 0 && a.im == 0) printf("0");
	
}

//printf("%f + %f i and %f - %f i\n\n", a.re, a.im, a.re, a.im);

