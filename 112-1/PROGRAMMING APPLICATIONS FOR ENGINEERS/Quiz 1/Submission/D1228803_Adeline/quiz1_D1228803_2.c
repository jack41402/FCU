#include <stdio.h>

int main(void) 
{
	int x, y, z, temp; // Input data.
	// You may declare additional variables as needed.
  
	
	do 
	{ // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		printf("The value of expression x+y*z, y+z*x and z+x*y: \n" ,x+y*z, y+z*x, z+x*y);
	
		
		
		if(x+y*z > y+z*x && y+z*x > z+x*y)//1
		{
			printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order: ", x+y*z, y+z*x, z+x*y);
		}
		else if(x+y*z > z+x*y && z+x*y > y+z*x)//2
		{
			printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order: ", x+y*z, z+x*y, y+z*x);
		}
		else if(y+z*x > x+y*z && x+y*z > z+x*y)//3
		{
			printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order: ", y+z*x, x+y*z, z+x*y);
		}
		else if(y+z*x > z+x*y && z+x*y > x+y*z)//4
		{
			printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order: ", y+z*x, z+x*y, x+y*z);
		}
		else if(z+x*y > x+y*z && x+y*z > y+z*x)//5
		{
			printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order: ", z+x*y, x+y*z, y+z*x);
		}
		else if(z+x*y > y+z*x && y+z*x > x+y*z)
		{
			printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order: ", z+x*y, y+z*x, x+y*z);
		}
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		printf("\n-----------------------------------------------\n");
	} while (x+y+z); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	
	return 0;
}
