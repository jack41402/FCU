#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	int expr1, expr2, expr3; // Three expressions.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		expr1 = x + y * z;
		expr2 = y + z * x;
		expr3 = z + x * y;
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d\n", expr1, expr2, expr3);
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ");
		if (expr1<=expr2 && expr2<=expr3) printf("%d %d %d\n", expr1, expr2, expr3);
		else if (expr1<=expr3 && expr3<=expr2) printf("%d %d %d\n", expr1, expr3, expr2);
		else if (expr2<=expr1 && expr1<=expr3) printf("%d %d %d\n", expr2, expr1, expr3);
		else if (expr2<=expr3 && expr3<=expr1) printf("%d %d %d\n", expr2, expr3, expr1);
		else if (expr3<=expr1 && expr1<=expr2) printf("%d %d %d\n", expr3, expr1, expr2);
		else if (expr3<=expr2 && expr2<=expr1) printf("%d %d %d\n", expr3, expr2, expr1);
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ");
		if (expr1>=expr2 && expr2>=expr3) printf("%d %d %d\n", expr1, expr2, expr3);
		else if (expr1>=expr3 && expr3>=expr2) printf("%d %d %d\n", expr1, expr3, expr2);
		else if (expr2>=expr1 && expr1>=expr3) printf("%d %d %d\n", expr2, expr1, expr3);
		else if (expr2>=expr3 && expr3>=expr1) printf("%d %d %d\n", expr2, expr3, expr1);
		else if (expr3>=expr1 && expr1>=expr2) printf("%d %d %d\n", expr3, expr1, expr2);
		else if (expr3>=expr2 && expr2>=expr1) printf("%d %d %d\n", expr3, expr2, expr1);
		printf("\n-----------------------------------------------\n");
	} while (x!=0 || y!=0 || z!=0);
	printf("End of program execution.\n");
	
	return 0;
}
