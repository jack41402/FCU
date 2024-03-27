#include <stdio.h>
#include <math.h>
#include "complex_D1171708.h"

complex add(complex x, complex y){
	complex sum;
	sum.re = x.re + y.re;
	sum.im = x.im + y.im;
	return sum;
}

complex minus(complex x, complex y){
	complex sub;
	sub.re = x.re - y.re;
	sub.im = x.im - y.im;
	return sub;
}

complex time(complex x, complex y){
  	complex prod;
  	prod.re = x.re * y.re - x.im * y.im; 
  	prod.im = x.re * y.im + x.im * y.re;
  	return prod;
}

complex divide(complex x, complex y){
	complex div;
	//((a×c+b×d)+(-a×d+b×c)i)÷(c2+d2)
	div.re = (x.re * y.re + x.im * y.im)/(y.re * y.re + y.im * y.im);
	div.im = (-x.re * y.im + x.im * y.re)/(y.re * y.re + y.im * y.im);
	
	return div;
}

float absComplex(complex x){
	float abs;
	abs = sqrt(x.re * x.re + x.im * x.im);
	return abs;
}

complex r2c(float r){ //D == 0 real = ... im = 0
	complex c;
	c.re = r;
	c.im = 0;
	return c;
}


void printComplex(complex r1, complex r2){
	if(r1.re != 0 && r1.im !=0 ){
		printf("%.4f%+.4f i and %.4f%+.4f i", r1.re, r1.im, r2.re, r2.im);
	}
	else if(r1.re != 0 && r1.im ==0){
		printf("%.4f and %.4f", r1.re, r2.re);		
	}
	else if(r1.re == 0 && r1.im ==0){
		printf("%.4f and %.4f", -r1.re, -r2.re);
	}
	else{
		printf("%.4f i and %.4f i", r1.im, r2.im);
	}
}


