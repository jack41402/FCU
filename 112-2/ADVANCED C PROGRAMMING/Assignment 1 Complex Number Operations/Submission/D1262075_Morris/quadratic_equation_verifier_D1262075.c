#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1262075.h"

int main(void){//difine every coefficients. and print out. 
	float re, im;
	complex x, y;
	float  a, b, c;
	int D; 
	
	printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0:");
	scanf("%f %f %f",&a, &b, &c);
	printf("\nThe quadratic equation is: ");
	//consider every case of a b c. 
	if(a == 1.0) printf("X**2");
	else printf(" %6.4f X**2",a);
	if(b>0.0) printf(" + %6.4f X",b);
	else if(b == 1) printf(" + X");
	else if(b<0.0) printf(" %6.4f X",b); 
	else printf(""); 
	if(c == 0.0) printf("");
	else if(c>0.0) printf(" + %6.4f",c); 
	else printf(" %6.4f",c); 
	printf(" = 0");
	D = (b*b) - (4*a*c); //Discriminant.
	
	if(D == 0){//If D==0 will have two same real roots. 
		x.re = (-b)/(2*a);
		x.im = 0;
		y = x; 
		printf("\nThe two roots of the quadratic equation are: ");
		printcomplex(x);
		printf(" and ");
		printcomplex(x); 
	}
	else if(D>0){//real roots. 
		x.re = (-b+sqrt(D))/(2*a);
		x.im = 0; 
		y.re = (-b-sqrt(D))/(2*a);
		y.im = 0; 
		printf("\nThe two roots of quadratic equation are: ");
		printcomplex(x);
		printf(" and ");
		printcomplex(y);
	} 
	else {//if D<0 will have complex roots. 
		x.re = (-b)/(2*a);
		x.im = sqrt(-D)/(2*a);
		y.re = (-b)/(2*a);
		y.im = -sqrt(-D)/(2*a);
		printf("\nThe two roots of quadratic equation are: ");
		printcomplex(x);
		printf(" and ");
		printcomplex(y);
	} 
	complex t1,t2;//verificition
	t1 = add(add(time(r2c(a),time(x,x)),time(r2c(b),x)),r2c(c));
	t2 = add(add(time(r2c(a),time(y,y)),time(r2c(b),y)),r2c(c)); 
	if(abscomplex(t1)<=0.000001 && abscomplex(t2)<=0.000001)
		printf("\nQuadratic equation solution is a pair of valid roots. Verification succeeds."); 
	else 
		printf("\nQuadratic equation solution is not a pair of valid roots. Verification failed.");
	
	complex test1, test2;
    test1.re = 10, test1.im = -5;
    test2.re = 10, test2.im = -5;
    printf("test1: "), printcomplex(test1), printf("\n");
    printf("test2: "), printcomplex(test2), printf("\n");
    printcomplex(minus(test1, test2));
    printf("\n");
    printcomplex(divide(test1, test2));
    printf("\n");
    test2.re = 10, test2.im = 0;
    printf("test1: "), printcomplex(test1), printf("\n");
    printf("test2: "), printcomplex(test2), printf("\n");
    printcomplex(minus(test1, test2));
    printf("\n");
    printcomplex(divide(test1, test2));
    printf("\n");
    test2.re = 0, test2.im = -5;
    printf("test1: "), printcomplex(test1), printf("\n");
    printf("test2: "), printcomplex(test2), printf("\n");
    printcomplex(minus(test1, test2));
    printf("\n");
    printcomplex(divide(test1, test2));
    printf("\n");
    test2.re = 5, test2.im = 5;
    printf("test1: "), printcomplex(test1), printf("\n");
    printf("test2: "), printcomplex(test2), printf("\n");
    printcomplex(minus(test1, test2));
    printf("\n");
    printcomplex(divide(test1, test2));
    printf("\n");
	return 0; 
} 
