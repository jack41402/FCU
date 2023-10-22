#include <stdio.h>

int main(void) {
	int x, y, z; // Input data.
	// You may declare additional variables as needed.
  	int a, b, c;
	int big, mid, small;
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		// ***** Complete the rest of the program.
		
		// (b) Evaluate and print the results of expressions x+y*z, y+z*x, and z+x*y.
		int a= x+y*z;
		int b= y+z*x;
		int c= z+x*y;
		printf("The value of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d\n",a ,b ,c); 
		
		// (c) Print x+y*z, y+z*x, and z+x*y in the ascending order. 
		if(a>b && a>c){
			if(b>c){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order:%d, %d, %d\n",c, b, a);
			}
			else if(c>b){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order:%d, %d, %d\n",b, c, a);

			}
	}
		if(b>a && b>c){
			if(a>c){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order:%d, %d, %d\n",c, a, b);
			}
			else if(c>a){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order:%d, %d, %d\n",a, c, b);

			}
		}
		if(c>a && c>b){
			if(a>b){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order:%d, %d, %d\n",b, a, c);
			}
			else if(b>a)
			    printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order:%d, %d, %d\n",a, b, c);
		}
		// (d) Print x+y*z, y+z*x, and z+x*y in the descending order. 
		if(a>b && a>c){
			if(b>c){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the descending order:%d, %d, %d\n",a, b, c);
			}
			else if(c>b){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the descending order:%d, %d, %d\n",a, c, b);

			}
	}
		if(b>a && b>c){
			if(a>c){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the descending order:%d, %d, %d\n",b, a, c);
			}
			else if(c>a){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the descending order:%d, %d, %d\n",b, c, a);

			}
		}
		if(c>a && c>b){
			if(a>b){
			    printf("Expression x+y*z, y+z*x, and z+x*y in the descending order:%d, %d %d\n",c, a, b);
			}
			else if(b>a)
			    printf("Expression x+y*z, y+z*x, and z+x*y in the descending order:%d, %d %d\n",c, b, a);
		}
		if(x==0 && y==0 && z==0){
		printf("Expression x+y*z, y+z*x, and z+x*y in the ascending order: 0, 0, 0\n");
		printf("Expression x+y*z, y+z*x, and z+x*y in the descending order: 0, 0, 0\n");
		} 
		printf("\n-----------------------------------------------\n");
		
	} while (x!=0 && y!=0 && z!=0); // Fill in the loop condition here.

	printf("End of program execution.\n");
	
	return 0;
}


