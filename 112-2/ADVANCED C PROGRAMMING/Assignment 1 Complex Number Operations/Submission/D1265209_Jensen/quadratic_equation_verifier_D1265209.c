#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"complex_D1265209.h"

int main(){
	float a, b, c;
	//Enter the number of a, b, c, also cheack the a not equal to 0
	do{
		printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0: ");
		scanf("%f %f %f", &a, &b, &c);
	}while(a == 0);
	
	//print for the equation
	printf("The quadratic equation is: ");
	//print the part of a of equation
	if(a == 1 || a == -1){
		if(a == -1){
			printf("-X**2 ");
		}
		else if(a == 1){
			printf("X**2 ");
		}
	}
	else{
		printf("%.4f X**2 ", a);
	}
	//print the part of b of equation
	if(b > 0){
		printf("+ %.4f X ", b);
	}
	else if(b < 0){
		printf("- %.4f X ", -b);
	}
	//print the part of c of equation
	if(c > 0){
		printf("+ %.4f", c);
	}
	else if(c < 0){
		printf("- %.4f", -c);
	}
	//print the end of equation
	printf(" = 0.\n\n");
	
	//do the calculation of discriminant
	printf("The two roots of the quadratic are: ");
	double D;
	//discriminant
	D = b * b - 4 * a * c;
	complex root1,  root2;
	complex root;
	
	//calculate for root of part for discriminant bigger than 0
	if(D > 0){
		//there are two different roots, both are real part
		root1.re = (-b + sqrt(D)) / (2 * a);
		root2.re = (-b - sqrt(D)) / (2 * a);
		//print out the roots
		printComplex(root1);
		printf(" and ");
		printComplex(root2);
	}
	//calculate for root of part for discriminant equal to 0
	else if(D == 0){
		//there are two same roots, the real part
		root1.re = -b / (2 * a);
		root2 = root1;
		//print out the roots
		printComplex(root1);
		printf(" and ");
		printComplex(root1);
	}
	//calculate for root of part for discriminant smaller than 0
	else{
		//there are two different roots, both including real part and imaginary part
		root1.re = -b / (2 * a);
		root1.im = sqrt(-D) / (2 * a);
		root2.re = -b / (2 * a);
		root2.im = -sqrt(-D) / (2 * a); 
		//print out the roots
		printComplex(root1);
		printf(" and ");
		printComplex(root2);
	}
	printf("\n\n");
	
	//verify
	complex test1, test2;
	double error = 1e-6;
	//put the roots into original equation, and the answer must be 0
	test1 = add(add(times(r2c(a), times(root1, root1)), times(r2c(b), root1)), r2c(c));
   	test2 = add(add(times(r2c(a), times(root2, root2)), times(r2c(b), root2)), r2c(c));
   	//verify the answer if equal to 0
   	if (absComplex(test1) <= error && absComplex(test2) <= error) 
       	printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.");
   	else 
   		printf("Quadratic equation solution is a pair of valid roots. Verification failed."); 
}
