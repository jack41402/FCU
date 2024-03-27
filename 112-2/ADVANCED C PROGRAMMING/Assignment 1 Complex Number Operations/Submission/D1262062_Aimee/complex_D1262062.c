#include <stdio.h>
#include <math.h>
#include "complex_D1262062.h"

complex add(complex x, complex y){
	complex sum;
	sum.re = x.re + y.re;
	sum.im = x.im + y.im;
	return sum; 
} 

complex minus(complex x, complex y){
	complex diff;
	diff.re = x.re - y.re;
	diff.im = x.im - y.im;
	return diff;
} 

complex time(complex x, complex y){
	complex prod;
	prod.re = x.re * y.re - x.im * y.im;
	prod.im = x.re * y.im + x.im * y.re;
	return prod;
}

complex divide(complex x, complex y){
	complex quot;
    float deno = y.re * y.re + y.im * y.im;
    quot.re = (x.re * y.re + x.im * y.im) / deno;
    quot.im = (x.im * y.re - x.re * y.im) / deno;
    return quot;
}

float absComplex(complex c){
	float value;
	value = sqrt(c.re * c.re + c.im * c.im);
	return value;
}

complex r2c(float f){
	complex c;
	c.re = f;
	c.im = 0;
	return c;
}

void printComplex(complex c){
	if(c.im == 0) printf("%6.4f ", c.re);
	else if(c.re == 0) printf("%6.4f i ", c.im);
	else{
		if(c.im > 0) printf("%6.4f+%6.4f i ", c.re, c.im);
		else printf("%6.4f%6.4f i ", c.re, c.im);
	} 
}
