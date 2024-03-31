#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1262058.h"
int main(){
	float a, b, c;
	float real, real1, real2, imaging, jdg;
	complex rt1, rt2, coefa, coefb, coefc, d;
	complex vrfy1, vrfy2;
	

	
	//input
	do{
		printf("Enter coefficients a, b and c for quadratic equation a x**2 + b x + c = 0");
		scanf("%f %f %f", &a, &b, &c);		
	}while(a == 0);


	//output quadratic formula
	printf("\nThe quadratic equation is : ");
	if (a != 0){
		if (a == 1){
			printf("X**2 ");
		}
		else if (a == -1){
			printf("-X**2 ");
		}
		else printf("%6.4f X**2 ", a);
	}
	if (b != 0){
		if (b == 1){
			printf("+ X ");
		}
		else if (b == -1){
			printf("- X ");
		}
		else if (b > 0){
			printf("+ %6.4f X ", b);
		}
		else if (b < 0){
			printf("- %6.4f X", -b);
		}
	}
	if (c != 0){
		if (c > 0){
			printf("+ %6.4f = 0.\n", c);
		}
		else if (c < 0){
			printf("- %6.4f = 0.\n", -c);
		}
	}

	//convert to complex
	jdg = pow(b,2) - 4*a*c;
	if (jdg >= 0){
		real1 = (-b + sqrt(pow(b,2) - 4*a*c))/ (2*a);
		real2 = (-b - sqrt(pow(b,2) - 4*a*c))/ (2*a);	
		rt1 = r2c(real1, 0);
		rt2 = r2c(real2, 0);
	}
	else{
		real = -b / (2*a);
		imaging = sqrt(4*a*c -pow(b,2))/ (2*a);		
		rt1 = r2c(real, imaging);
		rt2 = r2c(real, -imaging);
	}

	
    //print roots
	printf("\nThe two roots of quadratic equation are: ");
	printComplex(rt1);
	printf(" and ");
	printComplex(rt2);
	printf("\n");

	//verify
	coefa = r2c(a,0);
	coefb = r2c(b,0);
	coefc = r2c(c,0);
	vrfy1 = add(add(time(coefa, time(rt1, rt1)), time(coefb, rt1)), coefc);
	vrfy2 = add(add(time(coefa, time(rt2, rt2)), time(coefb, rt2)), coefc);
	if (absComplex(vrfy1)< 0.000001 && absComplex(vrfy2)<0.000001){
		printf("\nQuadratic solutions is a pair of valid roots. Verifications succeeds.");
	}
	else{
		printf("\nVerification failed.");
	}
	complex test1, test2;
    test1.re = 10, test1.im = -5;
    test2.re = 10, test2.im = -5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 10, test2.im = 0;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 0, test2.im = -5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 5, test2.im = 5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
}





