#include <stdio.h>
// Print n times of character c.
void printChar(int n, char c){
	int i;// loop viriable
	
	for (i=0; i<n; i++) printf("%c", c);// Each iteraion print one character c.
}
int main(void)
{	// To declare the number of the house that we design.
	const int r_top=40;// roof top
	const int r_side=16;// roof side
	const int r_bottom=r_top+2*r_side;// roof bottom
	const int d_width=20;// door width
	const int d_height=28;// door height
	const int w_width=16;// window width
	const int w_height=25;// window height
	const int g_width=4;// glass of the window width
	const int g_height=5;// glass of the window height
	const int thickness=2;// the thickness of the wall
	const int window_to_ceiling=10;// space between window and ceiling
	const int space_floor_to_door=2;// space between floor and window
	const int space_floor_to_window=5;// space between floor and window
	const int space_window_to_wall=2;// space between window and wall
	const int space_window_to_door=4;// space between window and door
	const int h_total_width=r_bottom;// the total width of the house
	const int h_total_height=2+r_side+thickness+window_to_ceiling+d_height+space_floor_to_door+thickness;// the tatol height of the the house
	const int h_interior_width=(space_window_to_wall+w_width+space_window_to_door)*2+d_width;// the interior width of the house
	const int h_interior_height=window_to_ceiling+d_height+space_floor_to_door;// the interior height of the house
	const int h_exterior_width=(thickness+space_window_to_wall+w_width+space_window_to_door)*2+d_width;//the exterior width of the house
	const int h_exterior_height=thickness+window_to_ceiling+d_height+space_floor_to_door+thickness;// the exterior height of the house
	int i, j, k;//To declare the loop variable.
	
	printf("***** Design the parameter of the house:\n");//Print out the number of the house segment that you design.
	printf("   <<< The top of the roof: %d\n", r_top);
	printf("   <<< The side of the roof: %d\n", r_side);
	printf("   <<< The bottom of the roof: %d\n", r_bottom);
	printf("   <<< The width of the door: %d\n", d_width);
	printf("   <<< The height of the door: %d\n", d_height);
	printf("   <<< The width of the window: %d\n", w_width);
	printf("   <<< The height of the window: %d\n", w_height);
	printf("   <<< The width of a window glass: %d\n", g_width);
	printf("   <<< The height of a window glass: %d\n", g_height);
	printf("   <<< The thickness of wall/ceiling/floor: %d\n", thickness);
	printf("   <<< The space from the window/door to the ceiling: %d\n", window_to_ceiling);
	printf("   <<< The space between the floor and the door: %d\n", space_floor_to_door);
	printf("   <<< The space between the floor and the window: %d\n", space_floor_to_window);
	printf("   <<< The space from the window to the wall: %d\n", space_window_to_wall);
	printf("   <<< The space between the window and the door: %d\n\n", space_window_to_door);
if (h_total_width==72&&h_total_height==62&&h_exterior_width==68&&h_exterior_height==44&&h_interior_width==64&&h_interior_height==40)
/*
To verify a valid house. If the house is a valid design, it will print out the house. 
But if the house is invalid,it will print out 'Error', because the house design isn't valid.
*/
{	
	printf("***** The house design is valid.\n");
	printf("   >>> The total width of the house: %d\n", h_total_width);
	printf("   >>> The total height of the house: %d\n", h_total_height);
	printf("   >>> The exterior width of the house: %d\n", h_exterior_width);
	printf("   >>> The exterior height of the house: %d\n", h_exterior_height);
	printf("   >>> The interior width of the house: %d\n", h_interior_width);
	printf("   >>> The interior height of the house: %d\n\n",  h_interior_height);

	for(i = 0 ; i < r_side+1 ; i++)//To create a loop of the house roof.
	{
		if(i == 0)//To decide which row are going to print, the row which is all '#' or the row which combined with '#' and '*'.
		{
			for(j = r_side-i+4 ; j > 0 ; j--)//Create a loop to draw the blank before the roof.
			{
				printf(" ");//Print out a blank
			}
			for(j = 0 ; j < r_top ; j++)//Create a loop to draw the top of the house roof.
			{
				printf("#");//Print out the first line of the roof.
			}
		}
		else
		{
			for(j = r_side-i+4 ; j > 0 ; j--)//Create a loop to draw the main part of the roof.
			{
				printf(" ");//Print out the blanks in front of the roof
			}
			printf("#");//Print out the frame of the roof
			
			for(k = 0 ; k <= r_top+i*2-3 ; k++)//Create a loop to print the main part of the roof.
			{
				printf("*");//Print out the main body of the roof
			}
			printf("#");//Print out the frame of the roof
		}
		printf("\n");//Print the newline
	}
	for(j = r_side-i+5 ; j > 0 ; j--)//Create a loop to draw the blank before the roof.
	{
		printf(" ");
	}
	for(j = 0 ; j < r_bottom ; j++)//Create a loop to draw the boottom of the roof.
	{
		printf("#");
	}
	printf("\n");//Print the newline
	for(i = thickness ; i > 0 ; i--)//Create a loop to make evry row of the house newline.
	{	
		for(j = 0 ; j < 6 ; j++)//Create a loop to have three blanks before the house print out.
		{
			printf(" ");
		}
		for(j = 0 ; j < r_bottom-4 ; j++)//Create a loop to draw the thickness of interior house.
		{
			printf("@");
		}
		printf("\n");//Print the newline
	}
	for(i = 0 ; i < h_interior_height+1 ; i++)//Create a loop to draw the remain part (under the roof) of the house.
	{
		if(i <= 10 || i == 39 || i == 40)//Verify which row to print the segment, such as window, door, blank.
		{
			for(j = 0 ; j < 6 ; j++)//Create a loop to print the space in front of the house
			{
				printf(" ");
			}
			printChar(thickness, '@');//Print out two @ for the house thickness
			for(j = 0 ; j < h_interior_width ; j++)//Create a loop to print the space in the middle of the house
			{
				printf(" ");
			}
		printChar(thickness, '@');//Print out two @ for the house thickness
		printf("\n");//Print the newline
		} else if(i % 6 == 5 && i != 5 )//Use remainder to control which line have to print out the frame of the window.
		{ 	for(j = 0 ; j < 6 ; j++)//The blanks in front of the house.
			{
				printf(" ");
			}
			printChar(thickness, '@');//To print out the frame of the window and door.
			printChar(space_window_to_wall, ' ');//Print out 2 blanks for the space between window and the wall.
			printChar(w_width, '=');//Print out 16 = for the window width.
			printChar(space_window_to_door, ' ');//Print out 4 blanks for the space between window and the door.
			printChar(d_width, '&');//Print out 20 & for the door width.
			printChar(space_window_to_door, ' ');//Print out 4 blanks for the space between window and the door.
			printChar(w_width, '=');//Print out 16 = for the window width.
			printChar(space_window_to_wall, ' ');//Print out 2 blanks for the space between window and the wall.
			printChar(thickness, '@');//To print out the frame of the window and door.
			printf("\n");//Print the newline
		}else if(i % 6 == 0 && i != 0 && i != 6 && i != 36 )//To print out the window and door.
		{
			for(k = g_height ; k > 0 ; k--)//Create a loop to print the door and the window.
			{		
				for(j = 0 ; j < 6 ; j++)//
				{
					printf(" ");
				}
				printChar(thickness, '@');//print out 2 @ for the wall
				printChar(space_window_to_wall, ' ');//Print out 2 blanks for the space between window and the wall.
				printf("=");
				printChar(g_width, ' ');//Print out 4 blanks for the glass width 
				printf("+");
				printChar(g_width, ' ');//Print out 4 blanks for the glass width 
				printf("+");
				printChar(g_width, ' ');//Print out 4 blanks for the glass width 
				printf("=");
				printChar(space_window_to_door, ' ');//print out 4 blanks for the space from window to the wall
				printChar(d_width, '&');//print out 20 & for the door width
				printChar(space_window_to_door, ' ');//print out 4 blanks for the space from window to the wall
				printf("=");
				printChar(g_width, ' ');//Print out 4 blanks for the glass width 
				printf("+");
				printChar(g_width, ' ');//Print out 4 blanks for the glass width 
				printf("+");
				printChar(g_width, ' ');//Print out 4 blanks for the glass width 
				printf("=");
				printChar(space_window_to_wall, ' ');//Print out 2 blanks for the space between window and the wall.
				printChar(thickness, '@');//print out 2 @ for the wall
				printf("\n");//Print the newline
			}
		}else if (i == 36 || i == 37 || i == 38)//To print out the door.
		{
			for(j = 0 ; j < 6 ; j++)//Ccreate a for loop to print out the space.
			{
				printf(" ");
			}
			printChar(thickness, '@');//print out 2 @ for the wall
			printChar(space_window_to_wall+w_width+space_window_to_door, ' ');//print out 2 blanks for space from window to the wall
			printChar(d_width, '&');
			printChar(space_window_to_wall+w_width+space_window_to_door, ' ');//print out 2 blanks for space from window to the wall
			printChar(thickness, '@');//print out 2 @ for the wall
			printf("\n");//Print the newline
		}
	}
	for(i = thickness ; i > 0 ; i--)//To print out the floor.
	{	
		for(j = 0 ; j < 6 ; j++)//Create a for loop to print blanks in front of the floor 
		{
			printf(" ");
		}
		for(j = 0 ; j < r_bottom-4 ; j++)//Caeat a for loop to print the floor
		{
			printf("@");
		}
		printf("\n");//Print the newline
	}
}
else
{
	printf("Error, because the house design isn't valid.\n");//print out error
}
	return 0;
}
