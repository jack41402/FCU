#include <stdio.h>
#include <math.h>
#include "complex_D1262075.h"

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
	
	prod.re = x.re*y.re - x.im*y.im;
	prod.im = x.re*y.im + x.im*y.re;
	return prod; 
} 
complex divide(complex x, complex y){
	complex quot;
	
	quot.re = x.re*y.re + x.im*y.im;
	quot.im = -x.re*y.im + x.im*y.re;
	return quot; 
} 
float abscomplex(complex x){
	 
	return sqrt(x.re*x.re + x.im*x.im) ; 
}
complex r2c(float x){
	complex i;
	i.re = x;
	i.im = 0;
	return i; 
} 

void printcomplex(complex x){
	if(x.re==0&&x.im!=0) printf("%6.4f i ",x.im);
	else if(x.re!=0&&x.im==0) printf("%6.4f",x.re);
	else if(x.re!=0&&x.im>0) printf("%6.4f + %6.4f i",x.re, x.im);
	else if(x.re!=0&&x.im<0) printf("%6.4f  %6.4f i",x.re, x.im); 
} 
