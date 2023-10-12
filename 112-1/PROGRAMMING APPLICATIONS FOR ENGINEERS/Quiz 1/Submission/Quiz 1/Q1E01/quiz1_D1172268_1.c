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
  	int blank = 0;
  	char a = ' ';
  	
  	int peri = 0;
  	int inter= 0;
  	int parallel = 0;
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
	

	
//	if(tilt == 0) blank = -1;
	//if(tilt == 1) blank = 1;
	
	if(tilt == 0){
		printChar(leading + side , a);
		
		printChar(top, '#');
		printf("\n");
	for(i = 0; i < side; i++){
		printChar(leading + side+ -1 *(i + 1), a);
		printf("#");
		printChar(top-2, '@');
		printf("#\n");
	}
	
	printChar(leading +side + -1*(side +1), a);
	printChar(top, '#');
	printf("\n");
	}	
	
	if(tilt == 1){
		printChar(leading, a);
		
		printChar(top, '#');
		printf("\n");
		for(i = 0; i < side; i++){
			printChar(leading+ 1 *(i + 1), a);
			printf("#");
			printChar(top-2, '@');
			printf("#\n");
		}
		
		printChar(leading+ 1*(side +1), a);
		printChar(top, '#');
		printf("\n");
		}	
		
	
	// Compute and print the number of characters on the perimeter£¬in the interior, 
	// and the parallelogram¡£ 
	
	peri = top * 2 + side *2;
	inter = (top -2) * side;
	parallel = top * (side +2);
	printf("The number of character on the perimeter: %d\n", peri);
	printf("The number of character in the interior: %d\n", inter);
	printf("The number of character of the parallelogram: %d\n", parallel);
return 0;
}
