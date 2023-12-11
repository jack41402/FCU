#include<stdio.h>
#include<math.h>
int main(void)
{
	float a,b,c,k,root_1,root_2;//definite the six different variable 
	printf("solving root of equation a*x**2+b*x+c=0\n");//print the sentence of solving root of equation a*x**2+b*x+c=0 and then chcange to the next line
	printf("please enter three integer coefficients a, b and c:\n");//print the sentence of please enter three integer coefficients a, b and c: and then change to the next line
	scanf("%f %f %f",&a,&b,&c);//scan the three integer into a,b and c
	if (a!=0)//to check if the equation is quadratic equation
	{
		if (b*b-4*a*c>0)//use discriminant to determine the value of root_1 and root_2
		{
			root_1=(-1*b+sqrt(b*b-4*a*c))/(2*a);//caculate the value of root_1 and root_2
			root_2=(-1*b-sqrt(b*b-4*a*c))/(2*a);
			printf("The real root of the equation:");//use discriminant to determine the sentence we are going to print
		}
		else if (b*b-4*a*c==0)
		{
			root_1=(-1*b+sqrt(b*b-4*a*c))/(2*a);
			root_2=(-1*b-sqrt(b*b-4*a*c))/(2*a);
			printf("The multiple real root of the equation:");//use discriminant to determine the sentence we are going to print
		}
		else //when the value of discriminant is smaller than 0
		{
			if (b==0)//because the different format of the roots, so use b equal 0 or not to determine the different format	
			{
				root_1=sqrt(-1*(b*b-4*a*c))/(2*a);
				root_2=(-1*sqrt(-1*(b*b-4*a*c)))/(2*a);
			}
			else 
			{
				k=(-1*b)/(2*a);//to definte k with the part of the real number
				root_1=(sqrt(-1*(b*b-4*a*c)))/(2*a);
				root_2=((-1)*sqrt(-1*(b*b-4*a*c)))/(2*a);
			}
			printf("The complex roots of the equation:");//use discriminant to determine the sentence we are going to print
		}
		if (a==1)//if the coefficient of quadratic term is 1, don't print 1
		{
			printf("X**2");
		}
		else if (a==-1)//if the coefficient of quadratic term is -1, print - before X*2
		{
			printf("-X**2");
		}
		else //if the coefficient of quadratic term isn;t 1 or -1, print the coefficient a
		{
			printf("%1.0fx**2",a);
		}
		if (b==1)//if the coefficient of linear term is 1, don't print 1 but print + sign
		{
			printf("+X");
		}
		else if (b==-1)//if the coefficient of linear term is -1, print - sign before X 
		{
			printf("-X");
		}
		else if (b<0)//if the coefficient of linear term isn't 1 or -1 and it is negative, print coefficient -b
		{
			printf("-%1.0fX",-b);
		}
		else if (b>0)//if the coefficient of linear term isn't 1 or -1 and it is positive, print coefficient +b
		{
			printf("+%1.0fX",b);
		}
		if (c<0)//if the constant is negative, print coefficient c 
		{
			printf("%1.0f",c);
		}
		else if (c>0)//if the constant is positive , print coefficient +c
		{
			printf("+%1.0f",c);
		}
		if (b*b-4*a*c>0)//print the roots part
		{
			if (root_1==-0.0000)//if one if the root is -0.0000, print 0.0000
			{
				printf("are %1.4f and %1.4f",0.0000,root_2);
			}
			else
			{
				printf(" are %1.4f and %1.4f.",root_1,root_2);
			}
		}
		else if (b*b-4*a*c==0)//print the root when discriminant equal 0
		{
			printf(" is %1.4f",root_1);
		}
		else //print the root when discriminant is negative
		{
			if (b==0)//print the i sign after when roots include -1**0.5
			{
				printf(" are %1.4fi and %1.4fi",root_1,root_2);
			}
			else 
			{
				printf(" are %1.4f + %1.4fi and %1.4f %1.4fi",k,root_1,k,root_2);
			}
			
		}
	}
	else
	{
		printf("error");
	}
} 
