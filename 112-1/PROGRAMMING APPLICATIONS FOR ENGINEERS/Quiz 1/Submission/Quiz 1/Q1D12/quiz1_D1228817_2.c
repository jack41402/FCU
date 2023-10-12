#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	// You may declare additional variables as needed.
  int a, b, c,i;
  
 
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		 a=x+(y*z);
 		 b=y+(x*z);
  		 c=z+(x*y);
		printf("\n");
		printf("The values of expressions x+(y*z), y+(x*z), and z+(x*y): %d, %d, %d\n", a, b, c);
		
		int max, min, medium;
		max=a;
		for(i=0; i<1; i++){
			if(max<b){
			max=b;
		}
		}
		for(i=0; i<1; i++){
			if(max<c){
				max=c;
			}
		}
		min=a;
		for(i=0; i<1; i++){
			if(min>b){
				min=b;
			}
		}
		for(i=0; i<1; i++){
			if(min>c){
				min=c;
			}
		}
		
		if(a!=max&&a!=min){
			medium=a;
		}
			else if(b!=max&&b!=min){
			medium=b;
		}
			else{
			medium=c;
		}
		
		printf("Expressions x+(y*z), y+(x*z), and z+(x*y) in the ascending order: %d, %d, %d\n", min, medium, max);
		printf("Expressions x+(y*z), y+(x*z), and z+(x*y) in the descending order: %d, %d, %d\n", max, medium, min);
		
		
	
		
		printf("\n-----------------------------------------------\n");
	} while (x!=0||y!=0||z!=0); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
