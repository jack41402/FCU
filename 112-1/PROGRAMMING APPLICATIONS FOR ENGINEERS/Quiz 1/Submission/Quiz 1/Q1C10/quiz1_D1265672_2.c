#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	int ans1, ans2, ans3, tmp;
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		// ***** Complete the rest of the program.
		ans1 = x+y*z;
		ans2 = y+z*x;
		ans3 = z+x*y;
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d\n", ans1, ans2, ans3);
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order.
		if (ans1 < ans2){
			tmp = ans1;
			ans1 = ans2;
			ans2 = tmp;
		}
		if (ans2 < ans3){
			tmp = ans2;
			ans2 = ans3;
			ans3 = tmp;
		}
		if (ans1 < ans2){
			tmp = ans1;
			ans1 = ans2;
			ans2 = tmp;
		}
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", ans3, ans2, ans1);
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", ans1, ans2, ans3);
		printf("\n-----------------------------------------------\n");
	} while (!(x==0 && y==0 && z==0)); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
