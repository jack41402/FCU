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
  
	// Input tilt of the side, 0: left, 1: right.
	do {
		printf("Enter 0 for left-tilt or 1 for right-tilt of the side: ");
		scanf("%d", &tilt);
	} while ((tilt != 0) && (tilt != 1));
	
	if (tilt==0) { // Tilting to the left.
		printf("\n"); 		
		printChar(leading+side+1, ' '); // Leading blanks with side and bottom of the left-hand-side.
		printChar(top, '#'); // Print the top.
		printf("\n");
		
		// Print the figure between top and bottom.
		for (i=0; i<side; i++) {
			printChar(leading+side-i, ' '); // One blank less than the line above.
			printChar(1, '#'); // Left side.
			printChar(top-2, '@'); // Interiors.
			printChar(1, '#'); // Right side.
			printf("\n");		
		}
		
		printChar(leading, ' '); // Leading blanks.
		printChar(top, '#'); // Print the bottom.
		printf("\n\n");
	} 
	else { // Tilting to the right.
		printf("\n");
		printChar(leading, ' '); // Leading blanks.
		printChar(top, '#'); // Print the top.
		printf("\n");
		
		// Print the figure between top and bottom.
		for (i=0; i<side; i++) {
			printChar(leading+i+1, ' '); // One blank more than the line above.
			printChar(1, '#'); // Left side.
			printChar(top-2, '@'); // Interiors.
			printChar(1, '#'); // Right side.
			printf("\n");		
		}
		
		printChar(leading+side+1, ' '); // Leading blanks with the top and side of the left-hand-side.
		printChar(top, '#'); // Print the bottom.
		printf("\n\n");
	}
	
	// Compute and print the number of characters on the perimeter£¬in the interior, 
	// and the parallelogram¡£ 
	printf("The number of characters on the perimeter:     %d.\n", 2*(top+side));
	printf("The number of characters in the interior:      %d.\n", (top-2)*side);
	printf("The number of characters of the parallelogram: %d.\n", top*(side+2));
	return 0;
}
