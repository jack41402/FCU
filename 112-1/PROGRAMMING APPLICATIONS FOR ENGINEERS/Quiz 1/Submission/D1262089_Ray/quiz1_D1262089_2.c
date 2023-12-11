#include <stdio.h>
int f(int,int,int);
int g(int,int,int);
int h(int,int,int);

int main(void) {
	int x, y, z; // Input data.
	// You may declare additional variables as needed.
  
	do { // (e) Repeat steps (a) to (d) until the input values of x, y, and z are all zero's.
		// (a) Input three integers x, y, and z.
		printf("Input three integers x, y, and z: "); // Request to input three integers.
		scanf("%d %d %d", &x, &y, &z); // Input three integers.
		printf("\n");
		
		printf("The values of expressions x+y*z, y+z*x, and z+x*y: %d %d %d\n", x+y*z, y+z*x, z+x*y);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order: %d %d %d\n", g(x+y*z,y+z*x,z+x*y) , h(x+y*z,y+z*x,z+x*y), f(x+y*z,y+z*x,z+x*y));
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order: %d %d %d\n",f(x+y*z,y+z*x,z+x*y), h(x+y*z,y+z*x,z+x*y), g(x+y*z,y+z*x,z+x*y));

		printf("\n-----------------------------------------------\n");
	} while (x!=0||y!=0||z!=0); // Fill in the loop condition here.
	
	printf("End of program execution.\n");
	
	return 0;
}


int f(int a,int b,int c){
	int max;
    max=a;
    if(b>=a){
    max=b;
}
    if(c>=b){
    max=c;
}
 return max;	
}


int g(int a,int b,int c){
	int min;
    min=a;
    if(b<=a){
    min=b;
}
    if(c<=b){
    min=c;
}
 return min;	
}

int h(int a,int b,int c){
	int mid;
	if(a!=f(a,b,c)&&a!=g(a,b,c)){
		mid=a;
	}else if(b!=f(a,b,c)&&b!=g(a,b,c)){
		mid=b;
	}else{
		mid=c;
	}
	return mid;
}
 







