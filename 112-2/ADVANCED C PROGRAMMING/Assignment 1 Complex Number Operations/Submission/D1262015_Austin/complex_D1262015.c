#include <stdio.h>
#include <math.h>
#include "complex_D1262015.h"

//complex addition:(a+bi)+(c+di) = (a+c)+(b+d)i
complex add(complex x, complex y){
	complex sum;
	sum.re = x.re + y.re;
	sum.im = x.im + y.im;
	return sum;
}
//Complex subtraction: (a+bi)-(c+di) = (a-c)+(b-d)i
complex minus(complex x, complex y){
	complex diff;
	diff.re = x.re - y.re;
	diff.im = x.im - y.im;
	return diff;
}
//Complex multiplication: (a+bi)¡Ñ(c+di) = (a¡Ñc-b¡Ñd) + (a¡Ñd+b¡Ñc)i
complex time(complex x, complex y){
	complex prod;
	prod.re = x.re*y.re - x.im*y.im;
	prod.im = x.re*y.im + y.re*x.im;
	return prod;
}
//Complex division: (a+bi)¡Ò(c+di) = ((ac+bd)+(-ad+bc)i)¡Ò(c^2+d^2)
complex divide(complex x, complex y){
	complex qout;
	qout.re = (x.re*y.re + x.im*y.im)/(pow(y.re, 2)+pow(y.im, 2));
      qout.im = (-(x.re*y.re) + x.im*y.im)/(pow(y.re, 2)+pow(y.im, 2));
      return qout;
}
//Complex absolute value: |a+bi| = (a2+b2)**1/2
float absComplex(complex x) {
    return sqrt(x.re * x.re + x.im * x.im);
}
// Convert a real number to a complex number
complex r2c(float x) {
    complex result;
    result.re = x;
    result.im = 0;
    return result;
}
// Print a complex number.
void printComplex(complex a) {
    if (a.re != 0) {
        printf("%.4f", a.re);
    }

    if (a.im != 0) {
        if (a.re != 0&&a.im>0) {
            printf(" + ");
            printf("%.4f i", a.im);
        }else if(a.re != 0&&a.im<0){
            printf(" - ");
            printf("%.4f i", -a.im);
        }
    }
    if (a.re == 0 && a.im == 0) {
        printf("0");
    }
}

