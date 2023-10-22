#include <stdio.h>

int main(void) {
	int x, y, z,suma,sumb,sumc,mass,middle,min;; // Input data.
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
			suma=x+y*z;
	sumb=y+z*x;
	sumc=z+x*y;
	printf("The values of expressions: x+y*z, y+z*x, and z+x*y:%d, %d, %d", suma, sumb ,sumc);
	printf("\n");
	if(suma>sumb&&suma>sumc)mass=suma;
	else if(sumb>sumc)mass=sumb;
	else mass=sumc;
	if((suma<sumb&&suma>sumc)||(suma>sumb&&suma<sumc))middle=suma;
	else if((sumb<sumc&&sumb>suma)||(sumb>sumc&&sumb<suma))middle=sumb;
	else middle=sumc;
	if(suma<sumb&&suma<sumc)min=suma;
	else if(sumb<sumc)min=sumb;
	else min=sumc;
	printf("Expressions x+y*z,y+z*x, and z+x*y in the acsending order: %d, %d, %d", min,middle,mass);
	printf("\n");
	printf("Expressions x+y*z,y+z*x, and z+x*y in the decsending order: %d, %d, %d", mass, middle,min);
	printf("\n");
	
		
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		
		printf("\n-----------------------------------------------\n");
		
	} while (x!=0&&y!=0&&z!=0); // Fill in the loop condition here.
	

	printf("End of program execution.\n");
	
	return 0;

}
