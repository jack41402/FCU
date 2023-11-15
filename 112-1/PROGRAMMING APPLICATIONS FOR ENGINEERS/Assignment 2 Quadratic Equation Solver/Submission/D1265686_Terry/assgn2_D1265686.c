#include<stdio.h>
#include<math.h> 
int main()
{
	long long int a,b,c; //use long long to increase the number of storage digits for variables  
	printf("Solving roots of equation a*X^2+b*X+c=0.\n"); 
	printf("Please enter three integer coefficients a, b, and c:");
	scanf("%lld %lld %lld",&a, &b, &c);
	
	if(a==0) //to make sure that "a" is not 0
	{
		printf("a must not be 0\n enter a again:");
		scanf("%lld",&a);
	}
	double m,p;
	m=b*b-4*a*c;
	
	//Use the discriminant to confirm how many roots there are
	if(m>0)
	{
		printf("The real roots of ");
	}
	
	else if(m==0)
	{
		printf("multiple root of ");
	}
	
	else if(m<0)
	{
		printf("Two complex roots of ");
	}
	
	//to check the value of "a" and print out suitable mathematical symbols
	if (a==1)
	{
		printf("x**2");
	}
	else if(a==-1)
	{
		printf("-x**2");
	}
	else
	{
		printf("%lldx**2",a);
	}
	
	//to check the value of "b" and print out suitable mathematical symbols
	if (b==1)
	{
		printf("x");
	}
	
	else if(b==-1)
	{
		printf("-x");
	}
	else if(b!=0)
	{
		printf("%+lldx",b);
	}
	
	//to make sure that "c" is not 0 and then print out the value of "c"
	if(c!=0)
	{
		printf("%+lld",c);
	}
	printf("=0 ");
	
	
	//to confirm how many roots there are
	if(m>0) 
	{
		double d,e;
		d=(-b+sqrt(m))/(2*a)+0; //"+0" is to confirm the result of the value would not print out "-0.0000"
		e=(-b-sqrt(m))/(2*a)+0;
		printf("are %.4lf and %.4lf",d ,e);
	}
	
	else if(m==0)
	{
		double f;
		f=(-b+sqrt(m))/(2*a)+0;
		printf("is %.4lf",f);
	}
	
	else if(m<0)
	{
		double g,h;
		p=m*-1; //the value of "m" is negative number, so we change the value to positive first
		g=sqrt(p)/(2*a)+0;
		h=-b/(2.*a)+0; //use "2." is because if the value of the result is not integer, it can not correct to print the value out
		
		//to confirm whether the result have real numbers or not
		if(h==0)
		{
			printf("are %.4lfi and -%.4lfi",g,g);
		}
		else
		{
			printf("are %.4lf + %.4lfi and %.4lf - %.4lfi",h,g,h,g);
		}
	}
}
