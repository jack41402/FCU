#include <stdio.h>
#include <math.h>
#include "complex_D1265273.h"

complex add (complex x, complex y)//The add function
{
	complex sum;//define sum
	sum.re= x.re + y.re;//the real part of sum
	sum.im= x.im + y.im;//the imaginary part of sum
	return sum;
}
complex minus(complex x, complex y)//The minus function
{
	complex diff;//define diff
	diff.re= x.re + y.re;//The real part of diff
	diff.im= x.im - y.im;//The imaginary part of diff
	return diff;
}
complex multi(complex x, complex y)//The multi function
{
	complex prod;//define prod
	prod.re= (x.re * y.re) - (x.im * y.im);//The real part of prod
	prod.im= (x.re * y.im )+ (x.im * y.re);//The imaginary part of prod
	return prod;
}
complex divide(complex x, complex y)//The divide function
{
	complex quot;//define quot
	quot.re= (x.re * y.re + x.im * y.im) / ((y.re)*(y.re)+(y.im)*(y.im));//the real part of quot
	quot.im= (((-1)*(x.re)* y.im)+ y.im * y.re) / ((y.re)*(y.re)+(y.im)*(y.im));//the imaginary part of quot
	return quot;
}
float absComplex(complex x)//The absComplex function
{
	float s;//define float
	s= sqrt((x.re)*(x.re)+(x.im)*(x.im));//the value of s
	return s;	
}
complex r2c(float n)//The r2c function
{
	complex c;//define c
	c.re= n;//the real part of c
	c.im= 0;//the imaginary of c is 0
	return c;
}
void printcomplex(complex c)//The printcomplex function
{
	if (c.re< 0)//When the real part of c<0
	{
		if (c.im<0)//when the imaginary part of c < 0
		{
			printf("%1.4f%1.4fi",	c.re, c.im);
		}
		else if (c.im>0)//when the imaginary part of c > 0
		{
			printf("%1.4f+%1.4fi", c.re, c.im);
		}
		else//when the imaginary part of c = 0
		{
			printf("%1.4f", c.re);
		}
	}
	else if(c.re==0)//When the real part of c = 0
	{
		if (c.im>0)//when the imaginary part of c > 0
		{
			printf("%1.4fi", c.im);
		}
		else//when the imaginary part of c < 0
		{
			printf("%1.4fi", c.im);
		}
	}
	else//When the real part of c>0
	{
		if (c.im>0)//when the imaginary part of c > 0
		{
			printf("%1.4f+%1.4fi", c.re, c.im);
		}
		else if(c.im<0)//when the imaginary part of c < 0
		{
			printf("%1.4f%1.4fi", c.re, c.im);
		}
		else//when the imaginary part of c = 0
		{
			printf("%1.4f+%1.4fi", c.re, c.im);
		}
	}	
}

