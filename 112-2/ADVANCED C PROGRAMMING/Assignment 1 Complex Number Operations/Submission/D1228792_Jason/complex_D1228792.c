#include <stdio.h>
#include <math.h>
#include "complex_D1228792.h"
complex add(complex x, complex y){
	complex sum;
	sum.re = x.re + y.re;
	sum.im = x.im + y.im;
	return sum;
}// complex addition.
complex minus(complex x, complex y){
	complex diff;
	diff.re = x.re - y.re;
	diff.im = x.im - y.im;
	return diff;
}// complex subtraction.
complex time(complex x, complex y){
	complex mult;
	mult.re = x.re * y.re - x.im * y.im;
	mult.im = x.re * y.im + x.im * y.re;
	return mult;
}// complex multiplication.
complex divide(complex x, complex y){
	complex div;
	div.re = (x.re * y.re + x.im * y.im) /(y.re*y.re+y.im*y.im);
	div.im = (-1*x.re * y.im + x.im * y.re) / (y.re*y.re+y.im*y.im);
	return div;
}// complex division.
double absComplex(complex x){
	double abs;
	abs = pow((x.re*x.re+x.im*x.im),0.5);
	return abs;
}// Absolute value of a complex number.
complex r2c(double x){
	complex rtc;
	rtc.re = x;
	rtc.im = 0.0;//add 0 to im part
	return rtc;
}// Convert a real number to a complex number
void printComplex(complex x){
	//verify the zero parts
	if(x.im==0 && x.re==0) printf("0.0000");
	else if(x.im!=0 && x.re==0) printf("%.4f i",x.im);
	else if(x.im==0 && x.re!=0) printf("%.4f",x.re);
	else if(x.im<0) printf("%.4f%.4f i",x.re,x.im);
	else printf("%.4f+%.4f i",x.re,x.im);
}// Print a complex number
