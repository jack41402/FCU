#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	int a = 0;
	int b = 0;
	int c = 0;
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		// ***** Complete the rest of the program.
		a = x + y * z;
		b = y + z * x;
		c = z + x * y;
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		printf("The value of expressions x + y * z, y + z * x; z + x * y: %d %d %d\n", a, b, c);
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		if(a < b && b < c) printf("Expressions x + y * z, y + z * x; z + x * y in the ascending order: %d %d %d\n", a, b, c);
		if(a < c && c < b) printf("Expressions x + y * z, y + z * x; z + x * y in the ascending order: %d %d %d\n", a, c, b);
		if(b < a && a < c) printf("Expressions x + y * z, y + z * x; z + x * y in the ascending order: %d %d %d\n", b, a, c);
		if(b < c && c < a) printf("Expressions x + y * z, y + z * x; z + x * y in the ascending order: %d %d %d\n", b, c, a);
		if(c < b && b < a) printf("Expressions x + y * z, y + z * x; z + x * y in the ascending order: %d %d %d\n", c, b, a);
		if(c < a && a < b) printf("Expressions x + y * z, y + z * x; z + x * y in the ascending order: %d %d %d\n", c, a, b);
		if(c == 0 && b == 0 && a == 0) printf("Expressions x + y * z, y + z * x; z + x * y in the ascending order: 0 0 0\n");
		//printf("Expressions x + y * z, y + z * x; z + x * y in the ascending order: ");
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		if(a > b && b > c) printf("Expressions x + y * z, y + z * x; z + x * y in the descending order: %d %d %d\n", a, b, c);
		if(a > c && c > b) printf("Expressions x + y * z, y + z * x; z + x * y in the descending order: %d %d %d\n", a, c, b);
		if(b > a && a > c) printf("Expressions x + y * z, y + z * x; z + x * y in the descending order: %d %d %d\n", b, a, c);
		if(b > c && c > a) printf("Expressions x + y * z, y + z * x; z + x * y in the descending order: %d %d %d\n", b, c, a);
		if(c > b && b > a) printf("Expressions x + y * z, y + z * x; z + x * y in the descending order: %d %d %d\n", c, b, a);
		if(c > a && a > b) printf("Expressions x + y * z, y + z * x; z + x * y in the descending order: %d %d %d\n", c, a, b);
		if(c == 0 && b == 0 && a == 0) printf("Expressions x + y * z, y + z * x; z + x * y in the descending order: 0 0 0\n");
		//printf("Expressions x + y * z, y + z * x; z + x * y in the descending order: ");
		printf("\n-----------------------------------------------\n");
	} while (x != 0|| y != 0|| z != 0 ); // Fill in the loop condition here.

	printf("End of program execution.\n");
	
	return 0;
}
