#include <stdio.h>
#include <math.h>
#include "complex_D1265672.h"

complex add(complex x, complex y){      // complex add
	complex sum;
	sum.re = x.re + y.re;
	sum.im = x.im + y.im;
	return sum;
}

complex minus(complex x, complex y){      // complex minus
	complex diff;
	diff.re = x.re - y.re;
	diff.im = x.im - y.im;
	return diff;
} 

complex time(complex x, complex y){       // complex times
	complex prod;
	prod.re = x.re * y.re - x.im * y.im;
	prod.im = x.re * y.im + x.im * y.re;
	return prod;
}

complex divide(complex x, complex y){     // complex divide
	complex quot;
	quot.re = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im);
	quot.im = (x.im * y.re - x.re * y.im) / (y.re * y.re + y.im * y.im);
	return quot;
}

float absComplex(complex num){          // absolute complex
	return sqrt(num.re * num.re + num.im * num.im);
}

complex r2c(float r){           // real to complex
	complex result;
	result.re = r; 
	result.im = 0.0;
	return result;
}

void printComplex(complex num1, complex num2){                  // print complex
	if (num1.re == 0 && num1.im == 0 && num2.re == 0 && num2.im == 0){
		printf("The two roots of the quadratic equation are: 0\n");
	}
	else if (num1.im == 0 && num2.im == 0){
		printf("The two roots of the quadratic equation are: %.4f and %.4f\n", num1.re, num2.re);
	}
	else if (num1.re != 0){
		printf("The two roots of the quadratic equation are: %.4f%+.4f i and %.4f%+.4f i\n", num1.re, num1.im, num2.re, num2.im);
	}
	else{
		printf("The two roots of the quadratic equation are: %.4f i and %.4f i\n", num1.im, num2.im);
	}
}
