#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		
		
		
		
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: ");
		printf("%d, %d, %d",x+y*z,y+z*x,z+x*y);
		printf("\n");
		// ***** Complete the rest of the program.
		
		
		
		
		
		if(x+y*z> y+z*x&& x+y*z>z+x*y && y+z*x>z+x*y){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ");
			printf("%d %d %d",z+x*y,y+z*x,x+y*z);
			printf("\n");
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ");
			printf("%d %d %d",x+y*z,y+z*x,z+x*y);
			
		}
		else if(x+y*z> y+z*x&& x+y*z>z+x*y && z+x*y>y+z*x){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ");
			printf("%d %d %d",y+z*x,z+x*y,x+y*z);
			printf("\n");
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ");
			printf("%d %d %d",x+y*z,z+x*y,y+z*x);
		}
		else if( y+z*x>x+y*z&& y+z*x>z+x*y && x+y*z>z+x*y){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ");
			printf("%d %d %d",z+x*y,x+y*z,y+z*x);
			printf("\n");
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ");
			printf("%d %d %d",y+z*x,x+y*z,z+x*y);
		}
		else if( y+z*x>x+y*z&& y+z*x>z+x*y && x+y*z<z+x*y){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ");
			printf("%d %d %d",x+y*z,z+x*y,y+z*x);
			printf("\n");
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ");
			printf("%d %d %d",y+z*x,z+x*y,x+y*z);
		}
		else if(z+x*y> x+y*z && z+x*y>y+z*x&& x+y*z>y+z*x){
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ");
			printf("%d %d %d",y+z*x,x+y*z,z+x*y);
			printf("\n");
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ");
			printf("%d %d %d",z+x*y,x+y*z,y+z*x);
		}
		else{
			printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: ");
			printf("%d %d %d",x+y*z,y+z*x,z+x*y);
			printf("\n");
			printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: ");
			printf("%d %d %d",z+x*y,y+z*x,x+y*z);
		}
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		printf("\n-----------------------------------------------\n");
	} 
       while ((x+y*z> y+z*x) || (x+y*z> z+x*y));
//	
//	
//	
//	
//	
//	
//	
//	
//	); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
