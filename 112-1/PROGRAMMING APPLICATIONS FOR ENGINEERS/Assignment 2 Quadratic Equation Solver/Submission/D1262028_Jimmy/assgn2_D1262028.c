#include <stdio.h>
#include <math.h>
int main (void)
{
	float a, b, c;//define a, b, and c.
	printf("Solving root of equation a*X^2+b*X+c = 0.\n");
    printf("Please enter three integer coefficient a, b, and c: ");
    scanf("%f %f %f",&a,&b,&c);
	if(a==0)//if a=0, it won't be a quadratic function.
	{
		printf("Error!");
	}
	else//run the program if a is not equal to 0.
	{
	    //Consider the solution cases.
        if(pow(b,2)-4*a*c==0)//multiple real root.
        {
        	printf("The multiple real root of equation ");
    	}
    	else if(pow(b,2)-4*a*c > 0)//two real roots.
    	{
    		printf("The real roots of equation ");
    	}
    	else//two complex roots.
    	{
    		printf("The complex roots of equation ");
    	}
    	if((a>1)||(a<-1))//print the coefficient of X**2 if a>1 or a<-1.
    	{
    		printf("%.0fX**2",a);
		}
		else if(a==1)//print only X**2 if a=1.
		{
			printf("X**2");
		}
		else//print -X**2 if a=-1.
		{
			printf("-X**2");
		}
		if(b>1)//print +bX if b>1.
		{
			printf("+%.0fX",b);
		}
		else if(b<-1)//print bX if b<-1.
		{
			printf("%.0fX",b);
		}
		else if(b==1)//print X if b=1.
		{
			printf("+X");
		}
		else if(b==-1)//print -X if b=-1.
		{
			printf("-X");
		}
		if(c>0)//print +c if c>0.
		{
			printf("+%.0f",c);
		}
		else if(c<0)//print c if c<0.
		{
			printf("%.0f",c);
		}
		printf("=0 ");
		if(pow(b,2)-4*a*c==0)//multiple real root.
		{
			float r1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
			printf("is %0.4f.",r1);
		}
		else if(pow(b,2)-4*a*c>0)//two real roots.
		{
			float r1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
			float r2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
			if(r1==-0.0000)
			{
				printf("are 0.0000 and %0.4f.",r2 );
			}
			else if(r2==-0.0000)
			{
				printf("are %0.4f and 0.0000.",r1 );
			}
			else
			{
				printf("are %0.4f and %0.4f.",r1 ,r2 );
			}
		}
		else if((pow(b,2)-4*a*c<0) && (b!=0))//two complex roots and b is not = 0.
		{
			float r1=(sqrt(-1*(pow(b,2)-4*a*c)))/(2*a);
			float r2=(-sqrt(-1*(pow(b,2)-4*a*c)))/(2*a);//*-1 to make the value inside the square root become positive.
			printf("are %0.4f+%0.4fi and %0.4f%0.4fi.",-b/(2*a ),r1 ,-b/(2*a ),r2 );//then print i behind the value. 
		}
		else if((pow(b,2)-4*a*c<0) && (b==0))////two complex roots and b=0.
		{
			float r1=(sqrt(-1*(4*a*c))/(2*a));
			float r2=(-sqrt(-1*(4*a*c))/(2*a));
			printf("are %0.4fi and %0.4fi.",r1  ,r2 );
		}
    }
	return 0;
}
