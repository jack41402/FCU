#include <stdio.h>

void printChar(int n, char c) {
	int i;
 
	for (i = 0; i < n; i++) printf("%c", c);
}

int main(){
	const int leading=10; // 10 leading blanks on the left side of the figure.
	int top; // Length of the top, 3<=top<=29, of the parallelogram.
	int side; // Length of the side, 2<=side<=20 between the top and the bottom of the parallelogram
	int tilt; // 0 for left-tilt or 1 for right-tilt of the side of the parallelogram.
	int i; // Loop variable.
  
	do {
		printf("Enter top, an integer between 3 and 29 (including): ");
		scanf("%d", &top);
	} while ((top < 3) || (top > 29));
  
	do {
		printf("Enter side, an integer between 2 and 20 (including): ");
		scanf("%d", &side);
	} while ((side < 2) || (side > 20));
  
	do {
		printf("Enter 0 for left-tilt or 1 for right-tilt of the side: ");
		scanf("%d", &tilt);
	} while ((tilt != 0) && (tilt != 1));
	printf("\n\n");
	
	if(tilt==0){
		printChar(leading,' ');
		printChar(top,'#');
		printf("\n");
		for(i=0;i<side;i++){
			printChar(leading-i-1,' ');
			printChar(1,'#');
			printChar(top-2,'@');
			printChar(1,'#');
			printf("\n");
	}
	printChar(leading - side - 1,' ');
	printChar(top,'#');
	printf("\n\n");
	printf("The number of characters on the perimeter: %d",top * 2 + side * 2);
	printf("\n");
	printf("The number of characters in the interior: %d",top * side);
	printf("\n");
	printf("The number of the characters of the parallelogram: %d",top * 2 + side * 2 + top * side);
	
	}else{
	printChar(leading,' ');
		printChar(top,'#');
		printf("\n");
		for(i=0;i<side;i++){
			printChar(leading+i+1,' ');
			printChar(1,'#');
			printChar(top-2,'@');
			printChar(1,'#');
			printf("\n");
	}
	printChar(leading + side + 1,' ');
	printChar(top,'#');
	printf("\n\n");
	printf("The number of characters on the perimeter: %d",top * 2 + side * 2);
	printf("\n");
	printf("The number of characters in the interior: %d",top * side);
	printf("\n");
	printf("The number of the characters of the parallelogram: %d",top * 2 + side * 2 + top * side);
	
	
}
	
	return 0;
}
