#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"complex_D1265273.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	float a, b, c, s, s_2; //define float variable
	complex root_1, root_2, c_1, c_2, c_3, sum_1, sum_2, x_2, x, y, y_2;//define conplex variable
	//enter the coefficient
	do{
		printf("Enter coefficients a, b and c for quadratic equation a x**2 + b x + c=0: ");
		scanf("%f %f %f", &a, &b, &c);
	}while(a==0);
	
	if(b*b-4*a*c>0)//when Discriminant>0, the are two real roots
	{
		root_1.re= (-1*b+ sqrt(b*b-4*a*c))/ (2*a);
		root_2.re= (-1*b- sqrt(b*b-4*a*c))/ (2*a);
	}
	else if (b*b-4*a*c==0)//when Discriminant=0, there are tow same roots
	{
		root_1.re=(-1*b+sqrt(b*b-4*a*c))/(2*a);
		root_2.re=(-1*b+sqrt(b*b-4*a*c))/(2*a);
	}
	else//whem Discriminant<0, there are complex roots
	{
		if (b==0)//when b=0, the real part is 0
		{
			root_1.re= 0;
			root_2.re= 0;
			root_1.im= sqrt(-1*(b*b-4*a*c))/(2*a);
			root_2.im= (-1)*(sqrt(-1*(b*b-4*a*c)))/(2*a);
		}
		else//when b!=0, the roots will contain real part and imaginary part
		{
			root_1.re= (-1*b)/(2*a);
			root_2.re= (-1*b)/(2*a);
			root_1.im= (sqrt(-1*(b*b-4*a*c)))/(2*a);
			root_2.im= ((-1)*sqrt(-1*(b*b-4*a*c)))/(2*a);
		}
	}
	//print out the equation
	if (a==1)//not printing the 1 sign
	{
		printf("The quadratic equation is: x**2");
	}
	else if(a==-1)
	{
		printf("The quadratic equation is: -x**2");
	}
	else
	{
		printf("The quadratic equation is: %1.4fx**2", a);
	}
	if (b>0)
	{
		printf("+%1.4fx", b);
	}
	else if (b==-1)
	{
		printf("-x");
	}
	else if(b<0)
	{
		printf("%1.4fx", b);
	}
	if (c>0)
	{
		printf("+%1.4f", c);
	}
	else if (c<0)
	{
		printf("%1.4f", c);
	}
	
	printf("\n\nThe two roots of the quadratic equationi are:");
	//print out all the roots
	if (b*b-4*a*c>0)//when Discriminant>0, print two real roots
	{
		printcomplex(root_1);
		printf(" and ");
		printcomplex(root_2);
	}
	else if (b*b-4*a*c==0)//when Discriminant=0, print two roots that are the same
	{
		printcomplex(root_1);
		printf(" and ");
		printcomplex(root_2);
	}
	else //when Discriminant<0, print out two complex roots
	{
		printcomplex(root_1);
		printf(" and ");
		printcomplex(root_2);
	}
	//change the coefficient to complex number
	c_1= r2c(a); 
	c_2= r2c(b);
	c_3= r2c(c);
	//calculate the value when plug in the first root into the equation
	x_2= multi(c_1, multi(root_1,root_1));
	x= multi(c_2, root_1);
	sum_1= add(add(x_2, x), c_3);
	s= absComplex(sum_1);
	//calculate the value when plug in the second root into the equation
	y_2= multi(c_1, multi(root_2,root_2));
	y= multi(c_2, root_2);
	sum_2= add(add(y_2, y), c_3);
	s_2= absComplex(sum_2);
	
	if (s-0<0.000001 && s_2-0<0.000001)//verify the both roots value
	{
		printf("\n\nQuadratic equation solution is a pair of valid roots. Verification succeeds.");
	}
	else
	{
		printf("\n\nQuadratic equation solution is a pair of valid roots. Verification unsucceeds.");
	}
	return 0;
}
