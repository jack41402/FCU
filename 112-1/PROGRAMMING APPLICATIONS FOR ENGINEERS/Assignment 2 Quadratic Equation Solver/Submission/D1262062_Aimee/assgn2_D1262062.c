#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Solving roots of equation a*X^2+b*X+c = 0.\n");
	double a, b, c, D, r1, r2, r3, r4;
	printf("Please enter three interger coefficients a, b, and c:");
	scanf("%lf %lf %lf", &a, &b, &c);
	D = b*b-4*a*c;// This is the discriminant of the equation. 
	r1 = -b/(2*a);// The value of the roots when D=0 and it's also the real number part of the complex roots.
	r2 = (-b+sqrt(D))/(2*a);// The value of the first root when D>0.
	r3 = (-b-sqrt(D))/(2*a);// The value of the second root when D>0.
	r4 = sqrt(-D)/(2*a);// The value of the imaginary number of an comlex root.
	if(D==0)printf("The multiple real root of equation ");// Determine the value of D, if D=0, print out "The multiple real root of equation".
	else if(D>0)printf("The real roots of equation ");// If D>0, print out "The real roots of equation".
	else printf("The complex roots of equation ");//If D<0, print out The complex roots of equation".
	if(a==0)printf("Error");// First, determine the coefficient of X^2, if it's zero the equation is error.  
	else if(a==1)printf("X**2");// If a=1 don't print out the value 1.
	else if(a==-1)printf("-X**2");// If a=-1 don't print out the value -1 and only the negative sign.
	else printf("%.0lfX**2", a);// Else print out the coefficient a.
	if(b==0)printf("");// Next, etermine the coefficient of X, if it's zero nothing will be printed out.
	else if(b==1)printf("+X");// If b=1 don't print out the value 1 and only the positive sign.
	else if(b==-1)printf("-X");// If b=-1 don't print out the value -1 and only the negative sign.
	else if(b>1) printf("+%.0lfX", b);// If b>1 print out the value and the positive sign.
	else printf("%.0lfX", b);//Else print out the coefficient c.
	if(c==0)printf(" ");// Then, determine the coefficient of constant term, if it's zero, only print out a blank.
	else if(c>0)printf("+%.0lf=0 ", c);// If c>0 print out the value and the positive sign.
	else printf("%.0lf=0 ", c);// Else print out the coefficient c.
	if(D==0)// Last, determine the value of D and print out the correct roots.
	{
		if(r1==0)printf("is 0.0000.");// If D=0 and the roots equal to 0, print out 0.0000.
		else printf("is %6.4lf.", r1);// Else print out the value of the root.
	}
	else if(D>0)
	{
		if(r2==0)printf("are 0.0000 and %6.4lf.", r3);// If D>0 and the roots equal to 0 and another number, print out 0.0000 and the value of another root.
		else if(r3==0)printf("are %6.4lf and 0.0000.", r2);// If the roots equal to one number and 0, print out the value of first root and 0.0000.
		else printf("are %6.4lf and %6.4lf.", r2, r3);// Else print out the values of both roots.
	}
	else
	{
		if(r1==0)printf("are %6.4lfi and -%6.4lfi.", r4, r4);// If D>0 and the real number of the roots equal to 0 , print out only the value of imaginary numbers part.
		else printf("are %6.4lf+%6.4lfi and %6.4lf-%6.4lfi.", r1, r4, r1, r4);// Else print out the values of both real part and imaginary part.
	}
	return 0;
}
