#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"complex_D1228817.h"

#define epsilon 0.000001

void print_equation(float a, float b, float c){//Prints the quadratic equation.
	
printf("The quadratic equation is: ");

if(a==1){
	printf("X**2 ");
}
else if(a==-1){
	printf("-X**2 ");
}
else printf("%.4f X**2 ", a);

if(b>0){
	printf("+ %.4f X ", b);
}	
else if(b<0){
	printf("- %.4f X ", fabs(b));
}

if(c!=0&&c>0){
	printf("+ %.4f = 0.\n", c);
}	
else if(c!=0&&c<0){
	printf("- %.4f = 0.\n", fabs(c));
}
else printf("= 0.\n");
}

void verify(float a, float b, float c, complex r1, complex r2){//Verifies the roots of the quadratic equation.
	printf("\n\nQuadratic equation is a pair of valid roots. ");
	complex v1=add( add( time(r2c(a), time(r1, r1)), time(r2c(b), r1) ), r2c(c) );//Substitute root1 into the quadratic equation.
	complex v2=add( add( time(r2c(a), time(r2, r2)), time(r2c(b), r2) ), r2c(c) );//Substitute root2 into the quadratic equation.
	
	if(absComplex(v1)<=epsilon&&absComplex(v2)<=epsilon){
//Checks if the value of the absolute value the result of substituting a root to the quadratic equation is less than 0.000001.
	 printf("Verification succeeds.");
}
	else printf("Verification fails.");
}

int main() {

float a, b, c;
complex root1, root2;

printf("Enter coefficients a, b and c for quadratic equation a X**2 + b X + c = 0: ");

scanf("%f %f %f", &a, &b, &c);

if(a==0){//Tell the user to enter another value for 'a' if the initial input was 0.
	do{
		printf("\'a\' cannot be 0. Try entering another real number for \'a\'. ");
		scanf("%f", &a);
	}while(a==0);
}

print_equation(a, b, c);//Print the equation.

if(b*b-4*(a*c)<0){//Calculate the roots if the determinant is less than 0.
	root1.re=-b/(2*a);
	root2.re=-b/(2*a);
	root1.im=sqrt(fabs(b*b-4*(a*c)))/(2*a);
	root2.im=-sqrt(fabs(b*b-4*(a*c)))/(2*a);
	
}

else if(b*b-4*(a*c)>=0){//Calculate the roots if the determinant is equal to or greater than 0.
	root1.re=(-b+sqrt(b*b-4*a*c))/(2*a);
	root1.im=0;
	root2.re=(-b-sqrt(b*b-4*a*c))/(2*a);
	root2.im=0;
}

printf("\nThe two roots of the quadratic equation are: ");
printComplex(root1);
printf(" and ");
printComplex(root2);
verify(a, b, c, root1, root2);

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
return 0;
}
