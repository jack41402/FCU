#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "complex_D1228803.h"

//complex addition: (a + bi) + (c + di) = (a + c) + (b + d)i
complex add(complex x, complex y) //Function to add two complex numbers 
{
	complex sum; //create a complex variable to store the sum 
	sum.realpart = x.realpart + y.realpart;  //calculate the real part of the sum by adding the real parts of x and y
	sum.imaginarypart = x.imaginarypart + y.imaginarypart;  //calculate the imaginary part of the sum by adding the imaginary parts of x and y
	return sum; //Return the result, which is the sum of the two complex numbers
}

//complex subtraction: (a + bi) - (c + di) = (a - c) + (b - d)i
complex subtract(complex x, complex y) //Function to subtract two complex numbers 
{
	complex difference; //create a complex variable to store the difference
	difference.realpart = x.realpart - y.realpart; //Calculate the real part of the difference by subtracting the real parts of x and y
	difference.imaginarypart = x.imaginarypart - y.imaginarypart; //Calculate the imaginary part of the difference by subtracting the imaginary parts of x and y
	return difference; //Return the result, which is the difference of the two complex numbers
}

//complex multiplication: (a + bi) กั(c + di) = (a กัc - b กัd) + (a กัd + b กัc)i
complex multiply(complex x, complex y) //Function to multiply two complex numbers
{
	complex product; //Create a complex variable to store the product
	//Calculate the real part of the product by subtracting the product of real parts of x and y amd the product of imaginary parts of x and y
	product.realpart = (x.realpart * y.realpart) - (x.imaginarypart * y.imaginarypart); 
	//Calculate the imaginary part of the product by subtracting the product of real parts of x and imaginary part of y and the product of imaginary parts of x and realpart of y
	product.imaginarypart = (x.realpart * y.imaginarypart) + (x.imaginarypart * y.realpart);
	return product; //Return the result, which is the product of the two complex numbers
} 

//complex division: (a + bi) กา(c + di) = ((a กัc + b กัd) + (-a กัd + b กัc)i) กา(c^2 + d^2)
complex divide(complex x, complex y) //Function to divide two complex numbers
{
	complex quotient; //Create a complex variable to store the quotient
	//Calculate the real part of the quotient by dividing the sum of real parts of x and y and imaginary part of x and y and the sum of real parts of y and imaginary part of y
	quotient.realpart = (x.realpart * y.realpart + x.imaginarypart * y.imaginarypart) / (y.realpart * y.realpart + y.imaginarypart * y.imaginarypart);
	//Calculate the imagnary part of the quotient by dividing the sum of minus real parts of x and imaginary part of y and imaginary part of x and real part of y and the sum of real parts of y and imaginary part of y
	quotient.imaginarypart = (-(x.realpart) * y.imaginarypart + x.imaginarypart * y.realpart) / (y.realpart * y.realpart + y.imaginarypart * y.imaginarypart);
	return quotient; //Return the result, which is the quotient of the two complex numbers
}

//Absolute value of a complex number: |a + bi| = (a^2 + b^2) ^ (1/2)
float absoluteComplex(complex z) //Function to calculate the absolute value of complex
{ 
	return sqrt(z.realpart * z.realpart + z.imaginarypart * z.imaginarypart); //Return the result, which is the absolute value of the two complex numbers	
}

//Convert a real part to a complex part: 
complex realpartTOcomplexpart(float realpart) //Function to convert the real part to complex part
{
	complex convert; //Create a complex variable to store the convertion of realpart and complex part
	convert.realpart = realpart; //convert real part to real part
	convert.imaginarypart = 0.0000; //convert imaginary part to 0.0000
	return convert; //Return the result, which is the convertion of real part to complex part
}

//Print a complex number 
void printComplex(complex z) 
{
	if(z.realpart == 0)
	{
		printf("%4.4fi", z.imaginarypart); //print out the imaginary part if the real part doesn't exist
	}
	else if(z.imaginarypart == 0)
	{
		printf("%4.4f", z.realpart); //print out the real part if the imaginary part doesn't exist
	}
	else
	{
		printf("%4.4f", z.realpart); //print out the real part
		if(z.imaginarypart > 0) //while the imaginary part is positive
		{
			printf("+%4.4fi", z.imaginarypart); //print out the positive sign and the imaginary part
		}
		else //while the imaginary part is negative
		{
			printf("%4.4fi", z.imaginarypart); //print out the negative sign and the imaginary part
		}
	}
}

