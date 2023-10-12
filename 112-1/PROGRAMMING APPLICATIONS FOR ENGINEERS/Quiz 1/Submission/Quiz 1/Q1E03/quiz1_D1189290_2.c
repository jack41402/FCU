#include <stdio.h>


int main(void) {
	int x, y, z, a, b ,c ; // Input data.
	// You may declare additional variables as needed.
  	a = x + y * z;
  	b = y + z * x;
  	c = z + x * y;
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d",x+y*z,y+z*x,z+x*y);
		printf("\n");
			if(a<b<c){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d, %d, %d",x+y*z,y+z*x,z+x*y);
			}else if(a<c<b){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d, %d, %d",x+y*z,z+x*y,y+z*x);
			}else if(b<a<c){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d, %d, %d",y+z*x,x+y*z,z+x*y);
			}else if(b<c<a){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d, %d, %d",y+z*x,z+x*y,x+y*z);
			}else if(c<a<b){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d, %d, %d",z+x*y,x+y*z,y+z*x);
			}else if(c<b<a){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d, %d, %d",z+x*y,y+z*x,x+y*z);
			}
			printf("\n"); 
			if(a>b>c){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d, %d, %d",x+y*z,y+z*x,z+x*y);
			}else if(a>c>b){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d, %d, %d",x+y*z,z+x*y,y+z*x);
			}else if(b>a>c){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d, %d, %d",y+z*x,x+y*z,z+x*y);
			}else if(b>c>a){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d, %d, %d",y+z*x,z+x*y,x+y*z);
			}else if(c>a>b){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d, %d, %d",z+x*y,x+y*z,y+z*x);
			}else if(c>b>a){
				printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d, %d, %d",z+x*y,y+z*x,x+y*z);
			}
			printf("\n");
			
		
		printf("\n");
		printf("\n-----------------------------------------------\n");
	} while (x!=0 && y!=0 && z!=0); 
		
	printf("End of program execution.\n");
	
	return 0;
}
