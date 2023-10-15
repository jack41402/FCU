#include <stdio.h>
#include <stdlib.h>
// Print n times of character c
void printChar(int n, char c){
	int i; //Loop variable
	for(i=0 ; i<n ; i++) printf("%c",c); // Each iteration print one character c.
}
int main(){
	int r_top = 40, r_side = 16, r_bottom = 72; //Parameters given in the assignment
	int i, j; //Loop variables
	printf("***** Design parameters of the house:\n"); 
	printf("   <<< The top of the roof: 40\n"); 
	printf("   <<< The side of the roof: 16\n"); 
	printf("   <<< The bottom of the roof: 72\n"); 
	printf("   <<< The width of the door: 20\n"); 
	printf("   <<< The height of the door: 28\n"); 	
	printf("   <<< The width of the window: 16\n"); 
	printf("   <<< The height of the window: 25\n");  
	printf("   <<< The width of the window glass: 4\n");
	printf("   <<< The height of the window glass: 5\n");
	printf("   <<< The space from the window/door to the ceiling: 10\n"); // Print the space from the window/door to the ceiling 
	printf("   <<< The space between the floor and the door: 2\n"); // Print the space between the floor and the door 
	printf("   <<< The space between the floor and the window: 5\n");
	printf("   <<< The space from the window to the wall: 2\n"); // Print the space from the window to the wall
	printf("   <<< The space between the window and the door: 4\n"); // Print the space between the window and the door  
	printf("\n"); // Print a newline
	printf("***** The house design is valid.\n");
	printf("   <<< The total width of the house: 72\n");
	printf("   <<< The total height of the house: 62\n");
	printf("   <<< The exterior width of the house: 68\n");
	printf("   <<< The exterior height of the house: 44\n");
	printf("   <<< The interior width of the house: 64\n");
	printf("   <<< The interior height of the house: 40\n");
	printf("\n\n");
	 
	printChar(r_side,' '); // Print the blanks of the first row of the roof
	printChar(r_top, '#'); // Print the first row of the roof
	printf("\n"); //Print a newline
	for(i = 0; i < r_side ; i++){ //Print each row, print side and interior points  
		printChar(r_side - i -1, ' '); // Print blanks
		printChar(1,'#'); //Print the left side 
		printChar(2 * i + r_top, '*'); //Print the interior points
		printChar(1, '#');  //Print the right side 
		printf("\n"); //Print a newline
	}
	printChar(r_bottom, '#'); //Print the bottom of the roof
	printf("\n"); //Print a newline
	//Print the ceiling 
	for(i=0 ; i<2 ; i++){
		printChar(2,' ');
		printChar(68, '@');
		printf("\n");
	}
	//Print the space from the ceiling the to the door 
	for(i=0 ; i<10 ; i++){
		printChar(2,' ');
		printChar(2, '@');
		printChar(64, ' '); 
		printChar(2, '@');
		printf("\n");
	}
	//Print the 1st~6th row of the window for 4 times
	for(i=0 ; i < 4 ; i++){
		printChar(2, ' ');
		printChar(2, '@');
		printChar(2, ' ');
		printChar(16, '=');
		printChar(4, ' ');
		printChar(20, '&');
		printChar(4, ' ');
		printChar(16, '=');
		printChar(2, ' ');
		printChar(2, '@');
		printf("\n");
			//Print the 2nd~6th row of the window using for loop
	 		for(j=0 ; j < 5 ; j++){
				printChar(2, ' ');
				printChar(2, '@');
				printChar(2, ' ');
				printChar(1, '=');
				printChar(4, ' ');
				printChar(1, '+');
				printChar(4, ' ');
				printChar(1, '+');
				printChar(4, ' ');
				printChar(1, '=');
				printChar(4, ' ');
				printChar(20, '&');
				printChar(4, ' ');
				printChar(1, '=');
				printChar(4, ' ');
				printChar(1, '+');
				printChar(4, ' ');
				printChar(1, '+');
				printChar(4, ' ');
				printChar(1, '=');
				printChar(2, ' ');
				printChar(2, '@');
				printf("\n");
	    	}
	}
	//Print the last row of the window 
	printChar(2, ' ');
	printChar(2, '@');
	printChar(2, ' ');
	printChar(16, '=');
	printChar(4, ' ');
	printChar(20, '&');
	printChar(4, ' ');
	printChar(16, '=');
	printChar(2, ' ');
	printChar(2, '@');
	printf("\n");
	//Print the rest of the door  
	for(i = 0 ; i < 3 ; i++){
		printChar(2, ' ');
		printChar(2, '@');
		printChar(22, ' ');
		printChar(20, '&');
		printChar(22, ' ');
		printChar(2, '@');
		printf("\n");
	}
	//Print the space between the floor and the door 
	for(i=0 ; i < 2 ; i++){
		printChar(2,' ');
		printChar(2, '@');
		printChar(64, ' '); 
		printChar(2, '@');
		printf("\n");
	}
	//Print the floor of the house
	for(i = 0 ; i < 2 ; i++){
	printChar(2,' ');
	printChar(68, '@');
	printf("\n");
	}	
}

