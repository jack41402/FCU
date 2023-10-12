#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long x, y, z;
	printf("Input three integers x, y, and z: ");
	scanf("%lld %lld %lld", &x, &y, &z);
	if (x==0, y==0, z==0)
	{
		printf("\nThe values of expressions x+y*z, y+z*x, and z+x*y: %lld, %lld, %lld", x+y*z, y+z*x, z+x*y);	
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: 0 0 0");
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: 0 0 0");
	}
	else
	{
	while (x!=0||y!=0||z!=0){
	printf("\nThe values of expressions x+y*z, y+z*x, and z+x*y: %lld, %lld, %lld", x+y*z, y+z*x, z+x*y);
	long long a, b, c, max, min, middle;
	a = x+y*z;
	b = y+z*x;
	c = z+x*y;
	if(a>0&&b>0&&c>0)
	{
		if(a>b&&a>c) 
		{
			max = a;
			if(b>c)
			{
				middle = b;
				min = c;
			}
			else
			{
				middle = c;
				min = b;
			}
		}
		else if(b>c)
		{
			max = b;
			if(a>c)
			{
				middle = a;
				min = c;
			}
			else
			{
				middle = c;
				min = a;
			}
		}
		else
		{
			 max = c;
			 if(a>b)
			{
				middle = a;
				min = b;
			}
			else
			{
				middle = b;
				min = a;
			}
		}
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: %lld %lld %lld", min, middle, max);
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: %lld %lld %lld", max, middle, min);
	}
	else if(a<0&&b>0&&c>0)
	{
		min = a;
		if(b>c)
		{
			middle = b;
			min = c;
		}
		else
		{
			middle = c;
			min = b;
		}
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: %lld %lld %lld", min, middle, max);
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: %lld %lld %lld", max, middle, min);
	}
	else if(a>0&&b<0&&c>0)
	{
		min = b;
		if(a>c)
		{
			middle = a;
			min = c;
		}
		else
		{
			middle = c;
			min = a;
		}
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: %lld %lld %lld", min, middle, max);
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: %lld %lld %lld", max, middle, min);
	}
	else if(a<0&&b>0&&c<0)
	{
		min = c;
		if(b>a)
		{
			middle = b;
			min = a;
		}
		else
		{
			middle = a;
			min = b;
		}
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: %lld %lld %lld", min, middle, max);
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: %lld %lld %lld", max, middle, min);
	}
	else if(a>0&&b<0&&c<0)
	{
		max = a;
		b = -b;
		c = -c;
		if(b>c)
		{
			middle = -c;
			min = -b;
		}
		else
		{
			middle = -b;
			min = -c;
		}
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: %lld %lld %lld", min, middle, max);
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: %lld %lld %lld", max, middle, min);
		
	}
	else if(a<0&&b>0&&c<0)
	{
		max == b;
		if((0-a)>(0-c))
		{
			middle = c;
			min = a;
		}
		else
		{
			middle = a;
			min = c;
		}
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: %lld %lld %lld", min, middle, max);
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: %lld %lld %lld", max, middle, min);
		
	}
	else if(a<0&&b<0&&c>0)
	{
		max = c;
		b = -b;
		a = -a;
		if(b>a)
		{
			middle = -a;
			min = -b;
		}
		else
		{
			middle = -b;
			min = -a;
		}
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: %lld %lld %lld", min, middle, max);
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: %lld %lld %lld", max, middle, min);
	}
	else
	{
		a = -a;
		b = -b;
		c = -c;
		if(a>b&&a>c) 
		{
			max = -a;
			if(b>c)
			{
				middle = -b;
				min = -c;
			}
			else
			{
				middle = -c;
				min = -b;
			}
		}
		else if(b>c)
		{
			max = -b;
			if(a>c)
			{
				middle = -a;
				min = -c;
			}
			else
			{
				middle = -c;
				min = -a;
			}
		} 
		else
		{
			 max = -c;
			 if(a>b)
			{
				middle = -a;
				min = -b;
			}
			else
			{
				middle = -b;
				min = -a;
			}
		}
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the ascending order: %lld %lld %lld", max, middle, min);
		printf("\nExpressions x+y*z, y+z*x, and z+x*y in the descending order: %lld %lld %lld", min, middle, max);
	}
	printf("\n--------------------------------------------------------------------------");
	printf("\nInput three integers x, y, and z: ");
	scanf("%lld %lld %lld", &x, &y, &z);
	}
	}	
	return 0;
}
