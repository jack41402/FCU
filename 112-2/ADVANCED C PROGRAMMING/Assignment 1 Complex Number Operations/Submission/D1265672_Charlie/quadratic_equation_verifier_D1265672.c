#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1265672.h"
void equation(float a, float b, float c) {      // print the equation
	
	if (a!=0){
		if (a == 1){
			printf("X**2 ");
		}
		else{
			printf("%.4f X**2 ", a);
		}
	}
	if (b!=0){
		if (b>0){
			printf("+ ");
			printf("%.4f X ", b);
		}
		else if (b<0){
			printf("- ");
			printf("%.4f X ", -1*b);
		}
	}
	if (c!=0){
		if (c>0){
			printf("+ ");
			printf("%.4f ", c);
		}
		else if (c<0){
			printf("- ");
			printf("%.4f ", -1*c);
		}
	}
	printf("= 0.\n\n");
}

int main() {
	
	float a, b, c;         
	float r1, r2, di;
	float ans1, ans2;
	int flag = 0;
	complex root1, root2;

	printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0: ");
	scanf("%f %f %f", &a, &b, &c);
	
	printf("The quadratic equation is: ");
	equation(a, b, c);        // print equation
	
	di = b * b - 4 *a * c;          // calculate discriminant
	if (di >= 0){                              // root calculation
		root1 = r2c((-b + sqrt(di)) / (2 * a));         
		root2 = r2c((-b - sqrt(di)) / (2 * a));
		printComplex(root1, root2);
		flag = 1;
	}
	else{
		root1.re = -b / (2 * a);
        root1.im = sqrt(-di) / (2 * a);
        root2.re = -b / (2 * a);
        root2.im = -sqrt(-di) / (2 * a);
		printComplex(root1, root2);
	}
	
	if (flag){
		ans1 = a * (root1.re * root1.re) + b * root1.re + c;         // verify roots
		ans2 = a * (root2.re * root2.re) + b * root2.re + c;
	}
	else{
		ans1 = absComplex(add(add(time(time(r2c(a), root1), root1), time(r2c(b), root1)), r2c(c)));
		ans2 = absComplex(add(add(time(time(r2c(a), root2), root2), time(r2c(b), root2)), r2c(c)));
	}

	
	if (fabs(ans1) < 0.000001 && fabs(ans2) < 0.000001){          
		printf("\nQuadratic equation solution is a pair of valid roots. Verification succeeds.");
	}
	else{
		printf("\nQuadratic equation solution is a pair of unvalid roots. Verification succeeds.");
	}
	
	return 0;
}
