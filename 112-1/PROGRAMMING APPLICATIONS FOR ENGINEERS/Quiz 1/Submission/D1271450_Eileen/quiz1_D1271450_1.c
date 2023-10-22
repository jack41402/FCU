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
	int j;
  
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
	
	// ***** Complete the rest of the program.
	
	// Draw the parallelogram. Consider left-tilt and right-tilt cases.	
	
	// Compute and print the number of characters on the perimeter£¬in the interior, 
	// and the parallelogram¡£ 
	if(tilt==0){
	
	for(i=0;i<1;++i){
		for(j=0;j<side+11;++j){
			printf(" ");
		}
		for(j=0;j<top;++j){
			printf("#");
		}
		printf("\n");
	}
	for(i=0;i<side;++i){
		for(j=0;j<side-i+10;++j){
			printf(" ");
		}
		printf("#");
		for(j=0;j<top-2;++j){
			printf("@");
		}
		printf("#");
		printf("\n");
	}
	for(i=0;i<1;++i){
		for(j=0;j<10;++j){
			printf(" ");
		}
		for(j=0;j<top;++j){
			printf("#");
		}
		printf("\n");
	}
}
	else{
	
	for(i=0;i<1;++i){
		for(j=0;j<10;++j){
			printf(" ");
		}
		for(j=0;j<top;++j){
			printf("#");
		}
		printf("\n");
	}
	for(i=0;i<side;++i){
		for(j=0;j<11+i;++j){
			printf(" ");
		}
		printf("#");
		for(j=0;j<top-2;++j){
			printf("@");
		}
		printf("#");
		printf("\n");
	}
	for(i=0;i<1;++i){
		for(j=0;j<11+side;++j){
			printf(" ");
		}
		for(j=0;j<top;++j){
			printf("#");
		}
		printf("\n");
	}
}
	
	return 0;
}
