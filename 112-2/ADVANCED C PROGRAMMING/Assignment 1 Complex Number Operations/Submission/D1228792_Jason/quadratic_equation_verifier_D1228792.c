#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1228792.h"
int main(void){
	float a,b,c;//set variables for the coefficients
	complex ans1,ans2,equ1,equ2,com_a,com_b,com_c;
	printf("Enter coefficients a, b, and c for quadraic equation a x**2 + b x + c = 0:");
	scanf("%f %f %f",&a,&b,&c);//scan the coefficients
	printf("The quadratic equation is: ");
	if(a!=0.0){
		if(a!=1 && a!=-1) printf("%.4f ",a);//verify if it is 1 or -1
		if(a==-1) printf("-");
		printf("x**2 ");
	}
	if(b!=0){
		if(b>0){
			if(b!=1) printf("+ %.4f",b);//verify if it is 1 or -1
		}
		else if(b<0){
			if(b!=-1) printf("- %.4f",-1*b);//verify if it is 1 or -1
			else if(b==-1) printf("-");
		} 
		printf(" x ");
	}
	if(c!=0){
		if(c>0) printf("+ %.4f ",c);
		else if(c<0) printf("- %.4f ",-1*c);
	}
	printf("= 0.\n\n");
	//print the equation without zero part.
	if(b*b-4*a*c>0){
		ans1=r2c((-1*b+sqrt(b*b-4*a*c))/(2*a));
		ans2=r2c((-1*b-sqrt(b*b-4*a*c))/(2*a));
	}
	else if(b*b-4*a*c==0){
		ans1=r2c((-1*b+sqrt(b*b-4*a*c))/(2*a));
		ans2=r2c((-1*b+sqrt(b*b-4*a*c))/(2*a));
	}
	else{
		ans1.re=(-1*b)/(2*a);
		ans2.re=(-1*b)/(2*a);
		ans1.im=(sqrt(-1*(b*b-4*a*c)))/(2*a);
		ans2.im=-1*(sqrt(-1*(b*b-4*a*c)))/(2*a);
	}
	//use formula to calculate the two roots(ans1, ans2)
	printf("The two roots of the quadratic equation	are: ");
	printComplex(ans1);
	printf(" and ");
	printComplex(ans2);
	//print the two roorts
	com_a=r2c(a);
	com_b=r2c(b);
	com_c=r2c(c);
	equ1=add(add(time(com_a,time(ans1,ans1)),time(com_b,ans1)),com_c);
	equ2=add(add(time(com_a,time(ans2,ans2)),time(com_b,ans2)),com_c);
	//use function to calculate the equation.
	if(absComplex(equ1)<0.000001&&absComplex(equ2)<0.000001){
		printf("\n\nQuadratic equation solution is a pair of valid roots. Verification succeeds.");
	}//verify if the absolute value the result of substituting 
	//a root to the quadratic equation is less than 0.000001.
	else printf("\nVerify failed!!!");
	
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
