#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	// You may declare additional variables as needed.
  	int a,b,c;
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		a=x+y*z;
		b=y+z*x;
		c=z+x*y;
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d\n",a,b,c);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ");
		if(a>=b&&a>=c){
			if(b>=c)
			printf("%d %d %d\n",c,b,a);
			else
			printf("%d %d %d\n",b,c,a);
		}
		else if(b>=c&&b>=a){
			if(c>=a)
			printf("%d %d %d\n",a,c,b);
			else
			printf("%d %d %d\n",c,a,b);
		}
		else{
			if(a>=b)
			printf("%d %d %d\n",b,a,c);
			else
			printf("%d %d %d\n",a,b,c);
		}
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ");
		if(a>=b&&a>=c){
			if(b>=c)
			printf("%d %d %d\n",a,b,c);
			else
			printf("%d %d %d\n",a,c,b);
		}
		else if(b>=c&&b>=a){
			if(c>=a)
			printf("%d %d %d\n",b,c,a);
			else
			printf("%d %d %d\n",b,a,c);
		}
		else{
			if(a>=b)
			printf("%d %d %d\n",c,a,b);
			else
			printf("%d %d %d\n",c,b,a);
		}
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		printf("\n-----------------------------------------------\n");
	} while (x!=0||y!=0||z!=0); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
