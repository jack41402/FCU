#include <stdio.h>
#include <stdlib.h>

// Print n times of character c.
void printChar(int n, char c) {
	int i; // Loop vairable.

	for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}

int main(void) {
	const int leading = 4; // Number of leading blanks before the house.
	// Parameters defining the Christmas tree.
	// r_top, r_side, r_bottom: top, side , and bottom of the roof.
	// h_width, h_height: width and height of the house.
	// d_width, d_height: width and height of the door.
	int r_top, r_side, r_bottom, h_width, h_height, d_width, d_height;
	int h_grid, v_grid; // The horizontal and vertical grid counter of the window.
	const int w_width = 9; // Width of the winddow. 
	const int w_height = 13; // Height of the winddow. 
	const int space_from_ceiling = 6; // The space from the window/door to the ceiling.
	const int space_from_wall = 2; // The space from the window to the wall.
	const int door_to_floor = 6; // The space between the floor and the door.
	const int window_door = 2; // The space between the window and the door.
	int i, j; // Loop variables.
  
	// Input the width of the roof top, between 10 and 20.
	do {
		printf(">>> Enter the width of the roof top (10 to 20): ");
		scanf("%d", &r_top);
	} while ((r_top<10) || (r_top>20));
  
	// Input the isosceles side of the roof, between 10 and 25.
	do {
		printf(">>> Enter the isosceles side of the roof (10 to 25): ");
		scanf("%d", &r_side);
	} while ((r_side<10) || (r_side>25));
	
	// The width of the roof bottom r_bottom is r_top+2*r_side.
	r_bottom = r_top + 2 * r_side; 
	printf(">>> The width of the roof bottom r_bottom is r_top+2*r_side %d.\n", r_bottom);
  
	// Input the width of the house, must be less than r_bottom-4.
	// The values of r_bottom and h_width must be both even or both odd.
	do {
		printf(">>> Enter the width of the house (<%d and (r_bottom,h_width) both even or odd): ", r_bottom-4);
		scanf("%d", &h_width);
	} while ((h_width>r_bottom-4) || ((r_bottom-h_width)%2!=0));
  
	// Input the height of the house, must be less than h_width.
	do {
		printf(">>> Enter the height of the house (<%d): ", h_width);
		scanf("%d", &h_height);
	} while (h_height>=h_width);
	
	// Calculate the width and height of the door.
	d_width = h_width - (space_from_wall + window_door + w_width) * 2;
	d_height = h_height - space_from_wall - door_to_floor;
	
	// Output the house design.
	printf("\n***** Design parameters of the house:\n");
	printf("   <<< The top of the roof: %d\n", r_top);
	printf("   <<< The side of the roof: %d\n", r_side);
	printf("   <<< The bottom of the roof: %d\n", r_bottom);
	printf("   <<< The width of the house: %d\n", h_width);
	printf("   >>> The height of the house: %d\n", h_height);
	printf("   <<< The width of the window: %d\n", w_width);
	printf("   <<< The height of the window: %d\n", w_height);
	printf("   <<< The width of the door: %d\n", d_width);
	printf("   <<< The height of the door: %d\n", d_height);
	printf("   <<< The space from the window/door to the ceiling: %d\n", space_from_ceiling);
	printf("   <<< The space from the window to the wall: %d\n", space_from_wall);
	printf("   <<< The space between the window and the door: %d\n", window_door);
	printf("   <<< The space between the floor and the door: %d\n", door_to_floor);
	
  	if (d_width<10 || d_height<12)
  		printf("***** The house design is invalid.\n\n");
  	else {
  		printf("\n");
  		// Print the roof top. Use '@' for the boundary of the roof.
  		printChar(leading + r_side, ' ');
  		printChar(r_top, '@');
  		printf("\n");
  		
  		// Print the roof extended by the side. 
		// Use '@' for the boundary of the roof and '*' for the interior points of the roof.
		for (i=0; i<r_side; i++) {
  			printChar(leading + r_side-i-1, ' ');
  			printChar(1, '@');
  			printChar(2 * i + r_top, '*');
  			printChar(1, '@');
  			printf("\n");			
		}
		
  		// Print the roof bottom. Use '@' for the boundary of the roof.
  		printChar(leading, ' ');
  		printChar(r_bottom, '@');
  		printf("\n");	
  		
  		// Print the two side walls. Use '%' for the wall.
  		for (i=0; i<space_from_ceiling; i++) {
  			printChar(leading  + (r_bottom - h_width) / 2, ' ');
  			printChar(2, '%');
  			printChar(h_width - 4, ' ');
  			printChar(2, '%');
  			printf("\n");
		}
  		 
		// Use '%' for the wall of the house.
		// Use '=' for the frame points, '+' for the grid lines, '@' for door.
		// of the two windows and the door.
		for (i=0; i<3; i++) {
			for (j=0; j<=3; j++) {
				printChar(leading  + (r_bottom - h_width) / 2, ' ');
				printChar(2, '%');
				printChar(space_from_wall, ' ');
				if (j==0) printChar(9, '=');
				else {
					printChar(1, '=');
					printChar(3, ' ');
					printChar(1, '+');
					printChar(3, ' ');
					printChar(1, '=');
				}
				printChar(window_door, ' ');
				printChar(d_width-4, '@');
				printChar(window_door, ' ');
				if (j==0) printChar(9, '=');
				else {
					printChar(1, '=');
					printChar(3, ' ');
					printChar(1, '+');
					printChar(3, ' ');
					printChar(1, '=');
				}
				printChar(space_from_wall, ' ');
				printChar(2, '%');
				printf("\n"); 
			}
		}
		printChar(leading  + (r_bottom - h_width) / 2, ' ');
		printChar(2, '%');
		printChar(space_from_wall, ' ');		
		printChar(9, '=');
		printChar(window_door, ' ');
		printChar(d_width-4, '@');
		printChar(window_door, ' ');
		printChar(9, '=');
		printChar(space_from_wall, ' ');
		printChar(2, '%');
		printf("\n");
		
		for (i=0; i<d_height-w_height; i++) {
			printChar(leading  + (r_bottom - h_width) / 2, ' ');
			printChar(2, '%');
			printChar(space_from_wall+window_door+9, ' ');	
			printChar(d_width-4, '@');
			printChar(window_door, ' ');
			printChar(space_from_wall+window_door+7, ' ');	
			printChar(2, '%');
			printf("\n");
		} 
  		
  		// Print the two side walls. Use '%' for the wall.
  		for (i=0; i<door_to_floor; i++) {
  			printChar(leading  + (r_bottom - h_width) / 2, ' ');
  			printChar(2, '%');
  			printChar(h_width - 4, ' ');
  			printChar(2, '%');
  			printf("\n");
		}
		
		
  		// Print the floor. Use '%' for the boundary of the roof.
  		printChar(leading  + (r_bottom - h_width) / 2, ' ');
  		printChar(h_width, '%');
  		printf("\n");	
  		printChar(leading  + (r_bottom - h_width) / 2, ' ');
  		printChar(h_width, '%');
  		printf("\n");	
  		
  		printf("\n\n");
		
	}
	return 0;
}
