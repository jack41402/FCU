#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"complex_D1265209.h"


//addition
complex add(complex x, complex y){
	complex sum;
	
	sum.re = x.re + y.re;
	sum.im = x.im + y.im;
	return sum;
}

//subtraction
complex minus(complex x, complex y){
	complex diff;
	
	diff.re = x.re - y.re;
	diff.im = x.im - y.im;
	return diff;
}

//multiplication
complex times(complex x, complex y){
	complex prod;
	
	prod.re = x.re * y.re - x.im * y.im;
	prod.im = x.re * y.im + x.im * y.re;
	return prod;
}

//division
complex divide(complex x, complex y){
	complex quot;
	
	if(y.re != 0 || y.im != 0){
		quot.re = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im); 
		quot.im = (-x.re * y.im + x.im * y.re) / (y.re * y.re + y.im * y.im);
	}
	else{
		quot.re = 0;
		quot.im = 1;
	}
	return quot;
}

//absolute value
float absComplex(complex x){
	
	return sqrt(x.re * x.re + x.im * x.im);
}

// Convert a real number to a complex number
complex r2c(float a){
	complex x;
	
	x.re = a;
	x.im = 0;
	return x;
}

//print complex number
void printComplex(complex x){
	if(x.re == 0){
		printf("%.4f i", x.im);
	}
	else if(x.im == 0){
		printf("%.4f", x.re);
	}
	else{
		if(x.im < 0){
			printf("%.4f - %.4f i", x.re, -x.im);
		}
		else{
			printf("%.4f + %.4f i", x.re, x.im);
		}
	}
}






