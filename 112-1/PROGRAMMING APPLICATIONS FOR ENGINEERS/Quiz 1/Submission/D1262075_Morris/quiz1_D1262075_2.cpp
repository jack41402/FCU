#include <stdio.h>

int main(void) {
	int x, y, z,a,b,c; // Input data.
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		a = x+y*z;
		b = y+z*x;
		c = z+x*y;
		printf("The value of expressions x+y*z, y+z*x, z+x*y: %d,%d,%d\n",a,b,c);
		printf("Expressions x+y*z, y+z*x and z+x*y ascending order:");
	if((c>=a)&&(a>=b)){
		printf("%d %d %d",b,a,c);
	}else if((c>=b)&&(b>=a)){
		printf("%d %d %d",a,b,c);
	}else if((b>=a)&&(a>=c)){
		printf("%d %d %d",c,a,b);
	}else if((b>=c)&&(c>=a)){
		printf("%d %d %d",a,c,b);
	}else if((a>=b)&&(b>=c)){
		printf("%d %d %d",c,b,a);
	}else{
		printf("%d %d %d",b,c,a);
	}
	printf("\n");
		printf("Expressions x+y*z, y+z*x and z+x*y descending order:");
	if((c>a)&&(a>b)){
		printf("%d %d %d",c,a,b);
	}else if((c>b)&&(b>a)){
		printf("%d %d %d",c,b,a);
	}else if((b>a)&&(a>c)){
		printf("%d %d %d",b,a,c);
	}else if((b>c)&&(c>a)){
		printf("%d %d %d",b,c,a);
	}else if((a>b)&&(b>c)){
		printf("%d %d %d",a,b,c);
	}else {
		printf("%d %d %d",a,c,b);
	}
	
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		printf("\n-----------------------------------------------\n");
	} while ((x+y*z!=0)&&(y+z*x!=0)&&(z+x*y!=0)); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
