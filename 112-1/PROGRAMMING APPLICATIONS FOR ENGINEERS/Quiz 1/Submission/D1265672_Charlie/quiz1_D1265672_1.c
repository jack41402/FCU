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
	
	// ***** Complete the rest of the program.
	printf("\n");
	// Draw the parallelogram. Consider left-tilt and right-tilt cases.	
	if (tilt == 0){
		printChar(side+leading+1, ' ');
		printChar(top, '#');
		printf("\n");
		for(i = 0; i < side; i++){
			printChar(side+leading-i, ' ');
			printf("#");
			printChar(top-2, '@');
			printf("#");
			printf("\n");
		}
		printChar(leading, ' ');
		printChar(top, '#');
	}
	else{
		printChar(leading, ' ');
		printChar(top, '#');
		printf("\n");
		for(i = 0; i < side; i++){
			printChar(leading+i+1, ' ');
			printf("#");
			printChar(top-2, '@');
			printf("#");
			printf("\n");
		}
		printChar(side+leading+1, ' ');
		printChar(top, '#');
	}
	printf("\n\n");
	// Compute and print the number of characters on the perimeter in the interior, 
	// and the parallelogram°£ 
	printf("The number of characters on the perimeter:     %d\n", (top*2)+(side*2));
	printf("The number of characters in the interior:      %d\n", (top-2)*side);
	printf("The number of characters of the parallelogram: %d\n", (side+2)*top);
	
	return 0;
}
