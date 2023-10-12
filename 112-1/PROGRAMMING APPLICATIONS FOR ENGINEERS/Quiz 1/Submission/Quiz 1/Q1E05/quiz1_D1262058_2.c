#include <stdio.h>

int main(void) {
	int x, y, z,rsl,rsl2,rsl3; // Input data.
	// You may declare additional variables as needed.
  
	do {
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		rsl=x+y*z;
		rsl2=y+z*x;
		rsl3=z+x*y;
		printf("reuslt of x+y*z is ");
		printf("%d\n",rsl);
		printf("reuslt of y+z*x is ");
		printf("%d\n",rsl2);
		printf("reuslt of z+x*y is ");
		printf("%d\n",rsl3);
		printf("the descending order of x+y*z,y+z*x,z+x*y is ");
		if(rsl>rsl2&&rsl2>rsl3){
			printf("%d > %d > %d",rsl,rsl2,rsl3);
		}
		if(rsl>rsl3&&rsl3>rsl2){
			printf("%d > %d > %d",rsl,rsl3,rsl2);
		}
		if(rsl2>rsl&&rsl>rsl3){
			printf("%d > %d > %d",rsl2,rsl,rsl3);
		}
		if(rsl2>rsl3&&rsl3>rsl){
			printf("%d > %d > %d",rsl2,rsl3,rsl);
		}
		if(rsl3>rsl2&&rsl2>rsl){
			printf("%d > %d > %d",rsl3,rsl2,rsl);
		}
		if(rsl3>rsl&&rsl>rsl2){
			printf("%d > %d > %d",rsl3,rsl,rsl2);
		}
				
		printf("the ascending order of x+y*z,y+z*x,z+x*y is ");
		if(rsl<rsl2&&rsl2<rsl3){
			printf("t");
		}
		if(rsl<rsl3&&rsl3<rsl2){
			printf("%d < %d < %d",rsl,rsl3,rsl2);
		}
		if(rsl2<rsl&&rsl<rsl3){
			printf("%d < %d < %d",rsl2,rsl,rsl3);
		}
		if(rsl2<rsl3&&rsl3<rsl){
			printf("%d < %d < %d",rsl2,rsl3,rsl);
		}
		if(rsl3<rsl2&&rsl2<rsl){
			printf("%d < %d < %d",rsl3,rsl2,rsl);
		}
		if(rsl3<rsl&&rsl<rsl2){
			printf("%d < %d < %d",rsl3,rsl,rsl2);
		}
		
		printf("\n-----------------------------------------------\n");
	} while (x!=0&&y!=0&&z!=0); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}
