#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		int i=x+y*z, j=y+z*x, k=z+x*y;
		printf("The value of expression x+y*z, y+z*x, and z+x*y: %d, %d, %d\n",i ,j ,k);
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		printf("Expression x+y*z, y+z*x, and z+x*y in the ascend order: ");
		if(i<=j<=k)
		{
			printf("%d, %d, %d\n",i ,j ,k);
		}
		else if(j<=i<=k)
			{
			printf("%d, %d, %d\n",j ,i ,k);
		}
			else if(k<=i<=j)
			{
			printf("%d, %d, %d\n",k ,i ,j);
		}
			else if(i<=k<=j)
			{
			printf("%d, %d, %d\n",i ,k ,j);
		}
			else if(j<=k<=i)
			{
			printf("%d, %d, %d\n",j ,k ,i);
		}
			else if(k<=j<=i)
			{
			printf("%d, %d, %d\n",k ,j ,i);
		}
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		printf("\n-----------------------------------------------\n");
	} while ((x==0)&&(y==0)&&(z==0)); // Fill in the loop condition here.
	{
		printf("End of program execution.\n");
	}
	return 0;
}
