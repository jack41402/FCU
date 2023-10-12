#include <stdio.h>

int main(void)
 {
	int x, y, z, a, b, c; 
  
	do { 
		printf("Input three integers x, y, and z: "); 
		scanf("%d %d %d", &x, &y, &z); 
		printf("\n\n");
		a=x+y*z;
		b=y+z*x;
		c=z+x*y;
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d\n", a,b,c);
		if(a>=b&&b>=c)
		{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", c,b,a);
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", a,b,c);
		}
		else if(a>=c&&c>=b)
		{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", b,c,a);
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", a,c,b);
		}
		else if(b>=a&&a>=c)
		{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", c,a,b);
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", b,a,c);
		}
		else if(b>=c&&c>=a)
		{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", a,c,b);
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", b,c,a);
		}
		else if(c>=a&&a>=b)
		{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", b,a,c);
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", c,a,b);
		}
		else 
		{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", a,b,c);
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", c,b,a);
		}
		printf("\n-----------------------------------------------\n");
	} while (x!=0||y!=0||z!=0);
	
	printf("End of program execution.\n");
	
	return 0;
}
