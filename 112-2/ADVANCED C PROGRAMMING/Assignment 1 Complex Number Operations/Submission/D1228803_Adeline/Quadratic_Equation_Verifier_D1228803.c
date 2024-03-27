#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "complex_D1228803.h"

int main()
{
	float a, b, c; //declare the floating point of a, b, c
	float D; //declare the floating point of D;
	complex root1, root2; //declare the complex of root1, root2
	
	//enter coefficients for a quadratic equation
	printf("Enter coefficient a, b, and c for quadratic equation a x**2 + bx + c =  0: ");
	scanf("%f %f %f", &a, &b, &c); //read the coefficients entered by the user and store them in variables a, b, and c
	printf("The quadratic equation is: "); //display a message indicating that the quadratic equation is being processed
	
	D = b * b - 4 * a * c; //Discrimination of quadratic equation
	
	if(D > 0) //if discrimination is positive, only real part exist
	{
        root1.realpart = (-b + sqrt(D)) / (2.0 * a); //first root, plus square root of D
        root2.realpart = (-b - sqrt(D)) / (2.0 * a); //second root, plus square root of D
    } 
	else if(D == 0) //if discrimination equal to 0, double root exist
	{
        root1.realpart = (-b) / (2.0 * a); //first root, square root of D equal to 0
        root2.realpart = (-b) / (2.0 * a); //second root, square root of D equal to 0
    } 
	else 
	{
        root1.realpart = (-b) / (2.0 * a); //real part of first root
        root1.imaginarypart = sqrt(-D) / (2.0 * a); //imaginary part of first root
        root2.realpart = (-b) / (2.0 * a); //real part of second root
        root2.imaginarypart = sqrt(-D) / (2.0 * a); //imaginary part of second root
    }

	//loop to iterate over the power coefficients of the quadratic equation in decreasing order
    for(int i = 2; i >= 0; i--) 
	{
        float coefficient; //declare floating point for variable to store the current coefficient
        if(i == 2) //check if the current power is 2 (x^2)
		{
            coefficient = a; //assign the value of coefficient 'a' to the variable
            //check if the coefficient is not equal to 1 to avoid redundant printing
            if(coefficient != 1)
            {
            	printf("%4.4fX^2 ", coefficient); //print the coefficient and the term for x^2 if the coefficient is not 1
			}
			else
			{
				printf("X^2"); //print simplified 'X^2' if coefficient is 1
			}
            
        } 
		else if (i == 1) //check if the current power is 1 (x)
		{
            coefficient = b; //assign the value of coefficient 'b' to the variable
            if (coefficient > 0) //check if the coefficient is greater than 0 for proper formatting
			{
                printf("+"); //print a plus sign for positive coefficients
            }
            if(coefficient < 0)  //check if the coefficient is less than 0 for proper formatting
            {
            	printf("%4.4fX ", coefficient); //print the coefficient and the term for x
			}
        } 
		else //for constant term
		{
            coefficient = c; //assign the value of coefficient 'c' to the variable
            if (coefficient >= 0) //check if the coefficient is greater than or equal to 0 for proper formatting
			{
                printf("+ 1"); //print a plus sign for positive coefficients
            }
            printf("%4.4f ", coefficient); //print the constant term
        }
    }
    printf("= 0 are ");
    printComplex(root1); //print out the first root
    printf(" and ");
	printComplex(root2); //print out the second root
	printf(".\n");
  
	//Verify the roots
	if(Verify(root1, root2, a, b, c)) //check the validity of the roots obtained from the quadratic equation solution
	{
		//if the roots are valid, print a success message
		printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.\n");
	}
	else 
	{
		//if the roots are not valid, print a failure message
		printf("Quadratic equation solution is not valid. Verfication fails.\n");
	}
	
    return 0; //return 0 to indicate successful completion of the program
}

//verify the quadratic equation roots by checking if they satisfy the equation
int Verify(complex root1, complex root2, float a, float b, float c)
{
	//create complex variables to represent the terms of the quadratic equation
	complex ax2 = {0.0, 0.0}; //term ax^2
	complex bx1 = {0.0, 0.0}; //term bx
	complex cx0 = {0.0, 0.0}; //term of constant c
	complex result; //variable to store the sum of the terms
	
	//calculate ax^2 by multiplying the real part of a and the square of root1
	ax2 = multiply(realpartTOcomplexpart(a), multiply(root1, root1)); 
	//calculate bx by multiplying the real part of b and root1
	bx1 = multiply(realpartTOcomplexpart(b), root1);
	//convert the real part of constant c into a complex number
	cx0 = realpartTOcomplexpart(c);
	
	//sum the calculated terms to get the result of the quadratic equation
	result = add(add(ax2, bx1), cx0);
	
	//check if the absolute value of the result is less than the error of 0.000001
	if(absoluteComplex(result) < 0.000001)
	{
		return 1; //return 1 to indicate that the roots satisfy the quadratic equation
	}
	else
	{
		return 0; //return 0 to indicate that the roots do not satisfy the quadratic equation
	}
}
