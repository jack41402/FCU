#include <stdio.h>
#include <stdlib.h>

// Print n times of character c.
void printChar(int n, char c) {
	int i; // Loop vairable.

	for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}

int main(void) {
	const int leading = 4; // Number of leading blanks at the beginning of each line.
	
	const int r_top = 40; // The width of the roof top, 20.
	const int r_side = 16; // The isosceles side of the roof, 16.
	const int r_bottom = r_top + 2 * r_side; // The width of the roof bottom, 52.
	const int c_w_f_thick = 2; // Thickness of ceiling, wall, and floor.
	const int d_width = 20; // The width of the door, 20.
	const int d_height = 28; // The height of the door, 28.
	const int w_width = 16; // Width of the window, 16. 
	const int w_height = 25; // Height of the window, 25.
	const int g_width = 4; // Width of a window glass, 4.
	const int g_height = 5; // Height of a window glass, 5.
	const int t_wall_ceiling_floor = 2; // The thickness of wall/ceiling/floor, 2.
	const int s_ceiling_window_door = 10; // The space from the ceiling to the window/door, 10. 
	const int floor_door = 2; // The space from the floor to the door, 2.
	const int floor_window = 5; // The space from the floor to the windows, 5.
	const int wall_window = 2; // The space from the wall to left/right window, 2.
	const int window_door = 4; // The space between the window and the door, 4.
	
	int t_width, t_height; // Total width and height, including the roof, of the house.	
	int e_width, e_height; // Exterior width and height of the house.
	int i_width, i_height; // Interior width and height of the house.
	int i, j; // Loop variables.
	
	// Output the house design.
	printf("\n***** Design parameters of the house:\n");
	printf("   <<< The top of the roof: %d\n", r_top);
	printf("   <<< The side of the roof: %d\n", r_side);
	printf("   <<< The bottom of the roof: %d\n", r_bottom);
	printf("   <<< The width of the door: %d\n", d_width);
	printf("   <<< The height of the door: %d\n", d_height);
	printf("   <<< The width of the window: %d\n", w_width);
	printf("   <<< The height of the window: %d\n", w_height);
	printf("   <<< The width of a window glass: %d\n", g_width);
	printf("   <<< The height of a window glass: %d\n", g_height);
	printf("   <<< The thickness of wall/ceiling/floor: %d\n", t_wall_ceiling_floor);
	printf("   <<< The space from the window/door to the ceiling: %d\n", s_ceiling_window_door);
	printf("   <<< The space between the floor and the door: %d\n", floor_door);
	printf("   <<< The space between the floor and the window: %d\n", floor_window);
	printf("   <<< The space from the window to the wall: %d\n", wall_window);
	printf("   <<< The space between the window and the door: %d\n", window_door);
	
	// Total width of the house, 72.
	// Total height of the house, 62.
	t_width = 4+t_wall_ceiling_floor*2+w_width*2+d_width+wall_window*2+window_door*2; 
	t_height = 2+t_wall_ceiling_floor*2+r_side+d_height+s_ceiling_window_door+floor_door; 
	
	// Exterior width of the house, 68.
	// Exterior height of the house, 44.
	e_width = t_wall_ceiling_floor*2+w_width*2+d_width+wall_window*2+window_door*2; 
	e_height =t_wall_ceiling_floor*2+d_height+s_ceiling_window_door+floor_door; 

	// Interior width of the house, 64.
	// Interior height of the house, 40.
	i_width = w_width*2+d_width+wall_window*2+window_door*2; 
	i_height = d_height+s_ceiling_window_door+floor_door; 
	
  	if ((t_width==72 && t_height==62) && (e_width==68 && e_height==44) && 
	    (i_width==64 && i_height==40)) {
  		printf("\n***** The house design is valid.\n");
	
		printf("   >>> The total width of the house: %d\n", t_width);
		printf("   >>> The total height of the house: %d\n", t_height);
		printf("   >>> The exterior width of the house: %d\n", e_width);
		printf("   >>> The exterior height of the house: %d\n", e_height);
		printf("   >>> The interior width of the house: %d\n", i_width);
		printf("   >>> The interior height of the house: %d\n", i_height);
	}
  	else {
  		printf("\n***** The house design is invalid.\n");
	
		printf("   >>> The total width of the house: %d\n", t_width);
		printf("   >>> The total height of the house: %d\n", t_height);
		printf("   >>> The exterior width of the house: %d\n", e_width);
		printf("   >>> The exterior height of the house: %d\n", e_height);
		printf("   >>> The interior width of the house: %d\n", i_width);
		printf("   >>> The interior height of the house: %d\n", i_height);
  		return 0;
	}

	// Print the roof top.	
	// Use '#' for the boundary of the roof and '*' for the interior points of the roof.
  	printf("\n\n");		
	printChar(leading+r_side, ' ');
	printChar(r_top, '#');
  	printf("\n");		
	
  	// Print the roof extended by the side. 
	for (i=0; i<r_side; i++) {
  		printChar(leading + r_side-i-1, ' ');
  		printChar(1, '#');
  		printChar(2 * i + r_top, '*');
  		printChar(1, '#');
  		printf("\n");			
	}
	
	// Print the roof bottom.	
	printChar(leading, ' ');
	printChar(r_bottom, '#');
  	printf("\n");
	  
	// Print the ceiling of the house. Use '@' for the wall. 
	for (i=0; i<t_wall_ceiling_floor; i++) {
		printChar(leading+2, ' ');
		printChar(e_width, '@');
  		printf("\n");
	}	
  	
  	// Print the two side walls for the house interior above the windows and the door. 
	// Use '#' for the wall.
  	for (i=0; i<s_ceiling_window_door; i++) {
  		printChar(leading+(r_bottom-e_width)/2, ' ');
  		printChar(t_wall_ceiling_floor, '@');
  		printChar(i_width, ' ');
  		printChar(t_wall_ceiling_floor, '@');
  		printf("\n");
	}
	
	// Print the windows and the door.	
	// Use '#' for the wall, '=' for window frame and horizontal grid line, 
	// '+' for vertical grid lines, ' ' for window glasses and '&' for the door.
	for (i=0; i<d_height; i++) {
  		printChar(leading+(r_bottom-e_width)/2, ' ');
  		printChar(t_wall_ceiling_floor, '@');
  		printChar(wall_window, ' ');
  		
  		// Print the left window.
  		if (i<w_height) {
  			if (i%6==0) printChar(w_width, '=');
  			else {
  				printChar(1, '=');
  				for (j=1; j<w_width-1; j++)
  					if (j%(g_width+1)==0) printChar(1, '+');
  					else  printChar(1, ' ');
  				printChar(1, '=');
			}
		}
		else printChar(w_width, ' '); 
		
		printChar(window_door, ' ');
		printChar(d_width, '&');
		printChar(window_door, ' ');
		
		// Print the right window.
  		if (i<w_height) {
  			if (i%6==0) printChar(w_width, '=');
  			else {
  				printChar(1, '=');
  				for (j=1; j<w_width-1; j++)
  					if (j%(g_width+1)==0) printChar(1, '+');
  					else  printChar(1, ' ');
  				printChar(1, '=');
			}
		}
		else printChar(w_width, ' '); 
		
  		printChar(wall_window, ' ');
  		printChar(t_wall_ceiling_floor, '@');
  		printf("\n");
	} 
  	
  	// Print the two side walls for the house interior below the door. 
	// Use '#' for the wall.
  	for (i=0; i<floor_door; i++) {
  		printChar(leading+(r_bottom-e_width)/2, ' ');
  		printChar(t_wall_ceiling_floor, '@');
  		printChar(i_width, ' ');
  		printChar(t_wall_ceiling_floor, '@');
  		printf("\n");
	}
	  
	// Print the floor of the house. Use '@' for the wall. 
	for (i=0; i<t_wall_ceiling_floor; i++) {
		printChar(leading+2, ' ');
		printChar(e_width, '@');
  		printf("\n");
	}	
  	printf("\n\n");
  	
	return 0;
}
