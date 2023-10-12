#include <stdio.h>

int main(void) {
	int x, y, z;
	int a, b, c; // Input data.
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		a = x+y*z;
		b = y+z*x;
		c = z+x*y;
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d\n", a,b,c);
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		if(a<b && a<c && b<c){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", a,b,c);
		}else if(a<b && a<c && b>c){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", a,c,b);
		}else if(b<a && b<c && a<c){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", b,a,c);
		}else if(b<a && b<c && a>c){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", b,c,a);
		}else if(c<a && c<b && a<b){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", c,a,b);
		}else if(c<a && c<b && a>b){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", c,b,a);
		}else{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", a,b,c);
		}
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		if(a>b && a>c && b>c){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", a,b,c);
		}else if(a>b && a>c && b<c){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", a,c,b);
		}else if(b>a && b>c && a>c){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", b,a,c);
		}else if(b>a && b>c && a<c){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", b,c,a);
		}else if(c>a && c>b && a>b){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", c,a,b);
		}else if(c>a && c>b && a<b){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", c,b,a);
		}else{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n", a,b,c);
		}
		printf("\n-----------------------------------------------\n");
	} while (a!=0 || b!=0 || c!=0); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
