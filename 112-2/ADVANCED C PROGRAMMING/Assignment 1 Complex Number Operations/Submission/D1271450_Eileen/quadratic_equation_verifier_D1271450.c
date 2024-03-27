#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1271450.h"
int main(void){
	// Variable declarations
	float positiveNum;
	float a,b,c;// Coefficients of the quadratic equation
	float D,d,e,f,h;// Discriminant and intermediate values
	complex root1,root2;// Roots of the quadratic equation
	do{// Input coefficients from the user, ensuring 'a' is not zero
	printf("Enter coefficients a, b, and c for quadratic equations a x**2 + b x + c = 0: ");
	scanf("%f %f %f",&a,&b,&c);
    }while(a==0);
	printf("\n");
	 // Display the entered quadratic equation
	printf("The quadratic equation is: ");
	if(a>1){
		printf("%.4f X**2 ",a);
	}
	else if(a<0){
		positiveNum = abs(a);
		printf("- %4f X**2 ",positiveNum);
	}
	else{
		printf("X**2 ");
	}
	// Display 'b' term
	if(b>0){
		printf(" + %.4f X ",b);
	}
	else if(b<0){
		positiveNum = abs(b);
		printf(" - %.4f X ",positiveNum);
	}
	else{
		printf("");
	}
	 // Display 'c' term
	if(c>0){
		printf("+ %.4f = 0.", c);
	}
	else if(c<0){
		positiveNum = abs(c);
		printf("- %.4f = 0.", positiveNum);
	}
	else{
		printf("= 0.");
	}
	printf("\n\n");
	D=b*b-4*a*c;// Calculate discriminant
	d=(-b+sqrt(D))/(2*a);//Defining d, equals (-b+sqrt(pow(b,2)-4*a*c))/(2*a)
	e=(-b-sqrt(D))/(2*a);//Defining e, equals (-b-sqrt(pow(b,2)-4*a*c))/(2*a)
	f=sqrt(-D)/(2*a);//Defining f equals sqrt((-1)*(pow(b,2)-4*a*c))/(2*a)
	h = -b/(2*a);//Defining h equals -b/(2*a)
	// Calculate roots based on discriminant
	if(D==0){
		// Real and equal roots
		root1 = r2c(h);
		root2 = r2c(h);
	}
	else if(D<0){
		// Complex roots
		root1.re = h;
		root1.im = f;
		root2.re = h;
		root2.im = -f;
	}
	else{
		// Real and distinct roots
		root1 = r2c(d);
		root2 = r2c(e);
	}
	// Display the roots of the quadratic equation
	printf("The two roots of the quadratic equation are: ");
	printComplex(root1);
	printf(" and ");
	printComplex(root2);
	printf("\n\n");
	// Verification of roots by substituting them back into the equation
	complex result1 = add(add(time(r2c(a), time(root1, root1)) , time(r2c(b), root1) ), (r2c(c)));
    complex result2 = add(add(time(r2c(a),time(root2, root2)), time(r2c(b) , root2) ),(r2c(c)));
    // Check if roots satisfy the equation within a tolerance
    if (absComplex(result1) < 0.000001 && absComplex(result2) < 0.000001) {
        printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.\n");
    } else {
        printf("Quadratic equation solution verification failed. At least one root is not valid.\n");
    }
return 0;
}


