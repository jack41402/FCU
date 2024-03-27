#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1171708.h"

int main(void) {
  	complex e, f, verifyxx, verifyx; // Four rational number variables.
  	float r1=0, r2=0; // root1 root2
  	float r1img=0, r2img=0;
	float a, b, c, d;
	
  
	printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0: ");
	scanf("%f %f %f", &a, &b, &c);
  	d = b*b - (4*a*c); //discriminant
  	
	if(d>0){
		e = r2c((-b + sqrt(b*b-4*a*c))/(2*a));
		f = r2c((-b - sqrt(b*b-4*a*c))/(2*a));
	}
	
	if(d==0){//r 2 c
		e = r2c((-b)/(2*a));
		f = r2c((-b)/(2*a));
	}
	
	if(d<0){
		e.re = (-b)/(2*a);
		e.im = sqrt(4*a*c-b*b)/(2*a);
		f.re = (-b)/(2*a);
		f.im = -sqrt(4*a*c-b*b)/(2*a);
	}
	
	//printf("%f %f %f %f\n",r1,r2, r1img, r2img);
	printf("The quadratic equation is ");
	if(a==1){
		printf("X**2 ");
	}
	else{
		printf("%.4f X**2 ",a);
	}
	
	if(b>0){
		if(b==1){
			printf("+ X ");
		}
		else{
			printf("+ %.4f X ",b);
		} 
	}
	else if(b<0){
		if(b==-1){
			printf("- X ");
		}
		else{
			printf("- %.4f X ",-b);
		} 		
	}
	else{
		printf("");
	}
	

	if(c>0){
		printf("+ %.4f ",c); 
	}
	else if(c<0){
		printf("- %.4f ",-c); 		
	}
	else{
		printf("");
	}
	

	printf("= 0.");
	
	printf("\n\nThe two roots of quadratic equation are: ");
	printComplex(e,f);
	verifyxx = time(r2c(a),time(e,e));
	verifyx = time(r2c(b),e);	
	if(absComplex(add(verifyxx,add(verifyx,r2c(c)))) < 0.000001){
		printf("\n\nQuadratic equation solution is a pair of valid roots. Verification succeeds.");
	}	
	return 0;
}
