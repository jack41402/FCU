#include "complex_D1262089.h" // Include the custom complex number header file
#include <stdio.h> // Include standard input/output library
#include <math.h> // Include math library for mathematical functions

// Function to calculate square root of a complex number
complex sqrtComplex(complex z) {
    float r = sqrt(z.re * z.re + z.im * z.im); // Calculate magnitude of the complex number
    float theta = atan2(z.im, z.re); // Calculate angle of the complex number
    float re = sqrt(r) * cos(theta / 2); // Calculate real part of the square root
    float im = sqrt(r) * sin(theta / 2); // Calculate imaginary part of the square root
    return (complex){re, im}; // Return the square root as a complex number
}

// Main function
int main() {
    float a, b, c; // Coefficients of the quadratic equation

    // Prompt user to enter coefficients
    printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0:");
    scanf("%f %f %f", &a, &b, &c); // Read coefficients from user input
    
    // Print the quadratic equation
    printf("The quadratic equation is:");

    // Print the coefficient 'a' if not equal to zero
    if (a!=0){
    	if (a!=1){
    		printf("%.4f x**2",a);
		}
		if (a==1){
			printf(" x**2");
		}
	} 

    // Print the coefficient 'b' if not equal to zero
    if (b != 0){
    	if (b > 0){
    	printf("+ %.4f x",b);
        }
		if (b < 0){
			printf(" %.4f x",b);
		}
	}

    // Print the constant term 'c' if not equal to zero
    if (c!=0){
    	if (c > 0){
    	printf("+ %.4f = 0 \n",c);
        }
		if (c < 0){
			printf(" %.4f = 0 \n",c);
		}
	}

    // Calculate the discriminant of the quadratic equation
    complex discriminant = minus(multiply(r2c(b), r2c(b)), multiply(r2c(4 * a), r2c(c)));
    // Calculate the square root of the discriminant
    complex sqrt_discriminant = sqrtComplex(discriminant);

    // Calculate the roots of the quadratic equation
    complex root1 = divide(add(r2c(-b), sqrt_discriminant), r2c(2 * a));
    complex root2 = divide(minus(r2c(-b), sqrt_discriminant), r2c(2 * a));

    // Print the roots of the quadratic equation
    printf("The two roots of the quadratic equation are: ");
    printComplex(root1);
    printf("  and  ");
    printComplex(root2);
    printf("\n");
    
    // Verify the roots
    float verification1 = a * (root1.re * root1.re - root1.im * root1.im) + b * root1.re + c;
    float verification2 = a * (root2.re * root2.re - root2.im * root2.im) + b * root2.re + c; 

    // Check if the roots are valid
    if (fabs(verification1) < 0.000001  && 
        fabs(verification2) < 0.000001 ) {
        printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.\n");
    } else {
        printf("Roots not verified.\n");
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
    return 0;
}
