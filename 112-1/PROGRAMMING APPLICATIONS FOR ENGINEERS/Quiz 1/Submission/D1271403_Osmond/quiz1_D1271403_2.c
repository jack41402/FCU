#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		printf("\n");
		if(x+y*z > y+z*x && y+z*x > z+x*y){
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
	}
		if(y+z*x > x+y*z && x+y*z > z+x*y){
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
	}
		if(z+x*y > x+y*z && x+y*z > y+z*x){
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ", &x+y*z, &y+z*x, &z+x*y);
		printf("\n");
	}
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		printf("\n-----------------------------------------------\n");
	} while (x==0 && y==0 && z==0); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
