#include <stdio.h>

// Print n copies of character c.
void printChar(int n, char c) {
	int i;
 
	for (i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
	const int leading=10; // 10 leading blanks on the left side of the figure.
	int top; // Length of the top, 3<=top<=29, of the parallelogram.
	int side; // Length of the side, 2<=side<=20 between the top and the bottom of the parallelogram
	int tilt; // 0 for left-tilt or 1 for right-tilt of the side of the parallelogram.
	int i; // Loop variable.
  
	// Input Length of the top, 3<=top<=29.
	do {
		printf("Enter top, an integer between 3 and 29 (including): ");
		scanf("%d", &top);
	} while ((top < 3) || (top > 29));
  
	// Input Length of the side, 2<=side<=20.
	do {
		printf("Enter side, an integer between 2 and 20 (including): ");
		scanf("%d", &side);
	} while ((side < 2) || (side > 20));
  
	// Input tilt of the side, 2<=side<=20.
	do {
		printf("Enter 0 for left-tilt or 1 for right-tilt of the side: ");
		scanf("%d", &tilt);
	} while ((tilt != 0) && (tilt != 1));
	printf("\n");
	if(tilt=0){
	printChar(leading+10,' ');
	printChar(top,'#');
	printf("\n");
	
	for(i=0;i<side;++i){
	printChar(10+3,' ');
	printChar(side-i-1,' ');
	printChar(1,'#');
	printChar(top-2,'@');
	printChar(1,'#');
	printf("\n");
	}
	printChar(10,' ');
	printChar(top,'#');
	printf("\n");
	}
	if(tilt=1){
	
	printChar(10,' ');
	printChar(top,'#');
	printf("\n");
	
	for(i=0;i<side;++i){
	printChar(10+3,' ');
	printChar(side+i-1,' ');
	printChar(1,'#');
	printChar(top-2,'@');
	printChar(1,'#');
	printf("\n");
	}
	printChar(10+2,' ');
	printChar(top,'#');
	printf("\n");	
		
		
	}
	
    
	
	
	// ***** Complete the rest of the program.
	
	// Draw the parallelogram. Consider left-tilt and right-tilt cases.	
	
	// Compute and print the number of characters on the perimeter£¬in the interior, 
	// and the parallelogram¡£ 
	
	return 0;
}
