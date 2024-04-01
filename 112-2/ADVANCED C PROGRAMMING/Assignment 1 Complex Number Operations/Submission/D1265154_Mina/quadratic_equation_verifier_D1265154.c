#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1265154.h"

int printFun(float, int); // Declaration of the printFun function, which will print the coefficient of the quadratic equation term based on the degree of the term
int verify(complex, complex, complex, complex); // Declaration of the verify function, which will verify the roots of the quadratic equation

int main(void){
	float a, b, c; // Coefficients of the quadratic equation
	complex root1 = {0.0, 0.0}, root2 = {0.0, 0.0}; // Complex numbers to store the roots
	
	printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0: "); // Prompting the user to enter coefficients
	scanf("%f %f %f", &a, &b, &c); // Reading coefficients from user input
	
	float dis = b * b - 4 * a * c; // Calculating the discriminant of the quadratic equation
	
	printf("The quadratic equation is: "); // Printing the quadratic equation
	if(printFun(a, 2)) printf("X**2 "); // Printing the coefficient of x^2 if it's non-zero
	if(printFun(b, 1)) printf("X ");    // Printing the coefficient of x if it's non-zero
	if(c != 0) printFun(c, 0);          // Printing the constant term if it's non-zero
	printf("= 0\n\n");
	
	if(dis > 0){ // If the discriminant is positive
		root1.re = (-b + sqrt(dis)) / (2 * a); // Calculating the first real root
		root2.re = (-b - sqrt(dis)) / (2 * a); // Calculating the second real root
		printf("The two roots of the quadratic equations are: %.4f and %.4f ", root1.re, root2.re); // Printing the real roots
	}else if(dis == 0) { // If the discriminant is zero
        root1.re = -b / (2 * a); // Calculating the real root (double root)
        root2.re = -b / (2 * a);
        printf("The two roots of the quadratic equations are: %.4f and %.4f ", root1.re, root2.re); // Printing the real roots
    }else { // If the discriminant is negative
        root1.re = -b / (2 * a); // Calculating the real part of the first complex root
        root1.im = sqrt(-dis) / (2 * a); // Calculating the imaginary part of the first complex root
        root2.re = -b / (2 * a); // Calculating the real part of the second complex root
        root2.im = -sqrt(-dis) / (2 * a); // Calculating the imaginary part of the second complex root
        printf("The two roots of the quadratic equations are: ");
        printComplex(root1); // Printing the first complex root
        printf("and ");
        printComplex(root2); // Printing the second complex root
    }
	
	// Verify the roots
	if(verify(root1, r2c(a), r2c(b), r2c(c)) && verify(root2, r2c(a), r2c(b), r2c(c))) 
		printf("\n\nQuadratic equation solution is a pair of valid roots. Verification succeeds."); // Printing verification result

    
	return 0; // Returning 0 to indicate successful execution	
}


int printFun(float x, int index)
{
	if(x != 0) // If the coefficient is not zero
	{
		if(index == 2) // If the term is for x^2
		{
			if(abs(x) == 1) // If the absolute value of coefficient is 1
			{
				if(x < 0) printf("-"); // Print - if the coefficient is negative
			}
			else // If the absolute value of coefficient is not 1
			{
				if(x < 0) printf("% .4f ", x); // Print the coefficient if negative
				else printf("%.4f ", x); // Print the coefficient if positive
			}
		}
		else if(index == 1) // If the term is for x^1
		{
			if(abs(x) == 1) printf("%c ", x > 0 ? '+' : '-'); // Print + or - if the coefficient is 1
			else
				if(x < 0) printf("- %.4f ", x * -1); // Print the coefficient if negative
				else printf("+ %.4f ", x); // Print the coefficient if positive
		}
		else // If the term is for constant 
		{
			if(x < 0) printf("- %.4f ", x * -1); // Print the coefficient if negative
			else printf("+ %.4f ", x); // Print the coefficient if positive
		}
		return 1; // Return 1 to indicate that coefficient is non-zero
	}
	else
		return 0; // Return 0 to indicate that coefficient is zero
}
int verify(complex root, complex a, complex b, complex c)
{
    complex idx2 = {0.0, 0.0}, idx1 = {0.0, 0.0}, result; // Declare variables to store intermediate results
    
    // Check if the real or imaginary part of coefficient a is non-zero
    if (a.re != 0 || a.im != 0) {
        // If a is non-zero, compute idx2 = a * root^2
        idx2 = time(time(root, root), a); // Compute the product of a and square of 'root'
    }
    
    // Check if the real or imaginary part of coefficient b is non-zero
    if (b.re != 0 || b.im != 0) {
        // If b is non-zero, compute idx1 = b*root
        idx1 = time(root, b); // Compute the product of b and 'root'
    }

    // Compute the sum of idx2, idx1, and coefficient c
    result = add(add(idx2, idx1), c); // Compute the sum of idx2, idx1, and c
    
	if (absComplex(result) < 0.000001 && absComplex(result) < 0.000001) {
      return 1; //the absolute value the result of substituting a root to the quadratic equation is less than 0.000001

    } else {
        return 0; 
    }
}




