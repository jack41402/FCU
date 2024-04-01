#include"complex_D1172268.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h> 

int main(){
	complex c1 = {0, 0}, c2 = {0, 0};
	float a, b, c;
	float r1, r2;
	printf("Enter a coefficients a, b, and c for quadratic equaitons a x**2 + b x + c = 0:");
	scanf("%f %f %f", &a, &b, &c);
	printf("\n");
	
	printf("The quadratic equation is: ");//print out the quadratic equation
	if(a != 1) printf("%.4fX**2", a);
	else if(a == -1) printf("-X**2 ");
	else if(a == 1) printf("X**2");// don't print out 1
    if(b > 0) printf(" +");
    else if(b == -1) printf(" - X");// make sure the result will look like the one on pdf
    else if(b < 0) printf(" - %.4f X ", fabs(b));
    else if(b != 0 && b != 1) printf(" %.4f X",b);
    else if(b == 1) printf(" X");
    if(c > 0) printf(" +");
    if(c < 0) printf(" - %.4f ", fabs(c));
    else if(c != 0) printf(" %.4f",c);
    printf(" = 0\n\n");
    
	int bb4ac = b*b - 4*a*c;//to know what kind of the result will the equation get
	
	
	printf("The two roots of quadratic equation are: ");
	if(bb4ac < 0){
        int nbb4ac = bb4ac * -1;
        c1.re = -b/(2*a); //real quantity 
        c1.im = sqrt(nbb4ac)/(2*a); // imaginary quantity
        c2.re = -b/(2*a); //real quantity 
        c2.im = -sqrt(nbb4ac)/(2*a); // imaginary quantity
        printComplex(c1);
    	printf(" and ");
    	printComplex(c2);
    }
	else{
		c1.re = (-b+sqrt(bb4ac))/(2*a);
	    c2.re = (-b-sqrt(bb4ac))/(2*a);
		printf(" %.4f and %.4f\n", c1.re, c2.re);
	}
	printf("\n\n");
		
	complex ac = r2c(a);// make all the number complex
	complex bc = r2c(b);
	complex cc = r2c(c);
    complex ans1 = time(ac, time(c1, c1));
    ans1 = add(add(ans1, time(bc, c1)), cc);
    
    complex ans2 = time(ac, time(c2, c2));
    ans2 = add(add(ans2, time(bc, c2)), cc);
	
    float t = 0.000001;
    if(absComplex(ans1) < t && absComplex(ans2) < t) {//make sure absolute value the result of substituting a root to the quadratic equation is less than 0.000001
        printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.\n");
    }
}

