#include <stdio.h>

int main(void) {
	int x, y, z,a,b,c; // Input data.
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		a=x+y*z,b=y+z*x,c=z+x*y;
		if(a!=0&&b!=0&&c!=0)
		{
			if(a>=b>=c)
			{
				printf("The value expressions x+y*z, y+z*x and z+x*y: %d, %d, %d\n",a,b,c);
				printf("Expressions x+y*z, y+z*x and z+x*y in the ascending order: %d, %d, %d\n",c,b,a);
				printf("Expressions x+y*z, y+z*x and z+x*y in the descending order: %d, %d, %d\n",a,b,c);
			}
			else if(a>=c>=b)
			{
				printf("The value expressions x+y*z, y+z*x and z+x*y: %d, %d, %d\n",a,b,c);
				printf("Expressions x+y*z, y+z*x and z+x*y in the ascending order: %d, %d, %d\n",b,c,a);
				printf("Expressions x+y*z, y+z*x and z+x*y in the descending order: %d, %d, %d\n",a,c,b);
			}
			else if(b>=a>=c)
			{
				printf("The value expressions x+y*z, y+z*x and z+x*y: %d, %d, %d\n",a,b,c);
				printf("Expressions x+y*z, y+z*x and z+x*y in the ascending order: %d, %d, %d\n",c,a,b);
				printf("Expressions x+y*z, y+z*x and z+x*y in the descending order: %d, %d, %d\n",b,a,c);
			}
			else if(b>=c>=a)
			{
				printf("The value expressions x+y*z, y+z*x and z+x*y: %d, %d, %d\n",a,b,c);
				printf("Expressions x+y*z, y+z*x and z+x*y in the ascending order: %d, %d, %d\n",a,c,b);
				printf("Expressions x+y*z, y+z*x and z+x*y in the descending order: %d, %d, %d\n",b,c,a);
			}
			else if (c>=a>=b)
			{
				printf("The value expressions x+y*z, y+z*x and z+x*y: %d, %d, %d\n",a,b,c);
				printf("Expressions x+y*z, y+z*x and z+x*y in the ascending order: %d, %d, %d\n",b,a,c);
				printf("Expressions x+y*z, y+z*x and z+x*y in the descending order: %d, %d, %d\n",c,a,b);
			}
			else
			{
				printf("The value expressions x+y*z, y+z*x and z+x*y: %d, %d, %d\n",a,b,c);
				printf("Expressions x+y*z, y+z*x and z+x*y in the ascending order: %d, %d, %d\n",a,b,c);
				printf("Expressions x+y*z, y+z*x and z+x*y in the descending order: %d, %d, %d\n",c,b,a);
			}	
		}
		else
		{
			printf("The value expressions x+y*z, y+z*x and z+x*y: %d, %d, %d\n",a,b,c);
			printf("Expressions x+y*z, y+z*x and z+x*y in the ascending order: %d, %d, %d\n",a,b,c);
			printf("Expressions x+y*z, y+z*x and z+x*y in the descending order: %d, %d, %d\n",c,b,a);
		}
		
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		printf("\n-----------------------------------------------\n");
	} while (x!=0&&y!=0&&z!=0); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
