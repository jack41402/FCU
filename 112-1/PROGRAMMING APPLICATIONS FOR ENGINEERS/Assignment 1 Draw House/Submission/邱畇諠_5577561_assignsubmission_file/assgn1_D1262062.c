#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int r_top = 40, r_side =16, r_bottom = r_top+2*r_side, r_top_thickness = 1, r_bottom_thickness = 1, door_width = 20, door_height = 28, window_width = 16, window_height = 25, glass_width = 4, glass_height = 5;
	int wall_thickness = 2, ceiling_thickness = 2, floor_thickness = 2, space_window_ceiling = 10, space_door_ceiling = 10, space_floor_door = 2, space_floor_window = 5, space_window_wall = 2, space_window_door = 4;
	printf("\n***** Design parameters of the house:\n");
	printf("   <<< The top of the roof: 40\n");
	printf("   <<< The side of the roof: 16\n");
	printf("   <<< The bottom of the roof: 72\n");
	printf("   <<< The width of the door: 20\n");
	printf("   <<< The height of the door: 28\n");
	printf("   <<< The width of the window: 16\n");
	printf("   <<< The height of the window: 25\n");
	printf("   <<< The width of a window glass: 4\n");
	printf("   <<< The height of a window glass: 5\n");
	printf("   <<< The thickness of wall/ceiling/floor: 2\n");
	printf("   <<< The space from the window/door to the ceiling: 10\n");
	printf("   <<< The space between the floor and the door: 2\n");
	printf("   <<< The space between the floor and the window: 5\n");
	printf("   <<< The space from the window to the wall: 2\n");
	printf("   <<< The space between the window and the door: 4\n\n");
	int exterior_width = ((wall_thickness+space_window_wall+space_window_door+window_width)*2+door_width);// Declare and define the variable exterior_width is equal to (wall_thickness+space_window_wall+space_window_door+window_width)*2+door_width.
	int exterior_height = (ceiling_thickness+space_window_ceiling+window_height+space_floor_window+floor_thickness);// Declare and define the variable exterior_height is equal to ceiling_thickness+space_window_ceiling+window_height+space_floor_window+floor_thickness.
	int interior_width = (exterior_width-(wall_thickness)*2);//Declare and define the variable interior_width is equal to exterior_width-(wall_thickness)*2.
	int interior_height = (exterior_height-(ceiling_thickness+floor_thickness));//Declare and define the variable interior_height is equal to exterior_height-(ceiling_thickness+floor_thickness).
	int total_height = (r_top_thickness+r_side+r_bottom_thickness+exterior_height); //Declare and define the variable total_height is equal to r_top_thickness+r_side+r_bottom_thickness+exterior_height.
	int total_width = (r_bottom>exterior_width) ? r_bottom : exterior_width;// Compare the value of r_bottom and exterior_width first, then declare and define the variable total_width is equal to the bigger one.
	if((total_width==72)&&(total_height==62)&&(exterior_width==68)&&(exterior_height==44)&&(interior_width==64)&&(interior_height==40))// Calculate and verify the value of total_width, total_height, exterior_width, exterior_height, interior_width, and interior_height, if the values are all correct then the house design is valid.
	{
		printf("***** The house design is valid.\n");
		printf("   >>> The total width of the house: 72\n");
		printf("   >>> The total height of the house: 62\n");
		printf("   >>> The exterior width of the house: 68\n");
		printf("   >>> The exterior height of the house: 44\n");
		printf("   >>> The interior width of the house: 64\n");
		printf("   >>> The interior height of the house: 40\n");
		printf("\n\n");
		int i, j, k, m, n, o, q, t;
		for(j=0; j<(r_bottom-r_top)/2+10; ++j)// Repeat the execution of printing the space until the total number of all the space characters is equal to (r_bottom-r_top)/2+10, which are all the needed space before the roof top.
		{
			printf(" ");
		}
		for(n=0; n<r_top; ++n)// Repeat the execution of printing "#" until the total number of all the "#" characters is equal to r_top(40).
		{
			printf("#");
		}
		printf("\n");
		for(i=1; i<r_side+1; ++i)// Repeat the execution below until the total number of rows is equal to r_side(16).
		{
			for(j=0; j<r_side-i+10; ++j)// Repeat the execution of printing all the needed spaces. For each line, the needed spaces are r_side(16)-the number of the row+10.
			{ 
				printf(" ");
			}
			printf("#");// Print out the exterior point of the roof with "#".
			for(m=0; m<r_top+2*i-2; ++m)// Repeat the execution of printing out all the interior point of the roof with "*".For each line, the total number of "*" characters is equal to r_top(40)+2*the number of the row-2.
			{
				printf("*");
			}
			printf("#");// Print out the exterior point of the roof with "#".
			printf("\n");// After a row is finished, move to the next line. 
		}
		for(j=0; j<10; ++j)// Repeat the execution of printing the space until the total number of all the space characters is 10, which are all the needed space before the roof bottom.
		{
			printf(" ");
		}
		for(k=1; k<r_bottom+1; ++k)// Repeat the execution of printing "#" until the total number of "#" characters is equal to r_bottom(72). 
		{
			printf("#");
		}
		printf("\n");
		for(o=0; o<exterior_height; ++o)// Repeat the execution below until the total number of rows is equal to exterior_height(44).
		{
			for(q=1; q<(r_bottom-exterior_width)/2+10+1; ++q)// Repeat the execution of printing all the needed spaces. For each line, the needed spaces are (r_bottom-exterior_width)/2+10.
			{
				printf(" ");
			}
			printf("@@");// Print out the left side wall with "@@" for each row.
			if(o<2)// If it's at row number 0 and row number 1, print the ceiling part of the house.
			{
				for(t=0; t<interior_width; ++t)// Repeat the execution of printing "@" until the total number of "@" characters is equal to interior_width(64).
				{
					printf("@"); 
				}
			}
			else if(o>1&&o<12)// If it's at row number 2~11, print the spaces between the ceiling and the window/door of the house.
			{
				for(t=0; t<interior_width; ++t)// Repeat the execution of printing the space until the total number of the space characters is equal to interior_width(64) for each line.
				{
					printf(" "); 
				}
			}
			else if(o>11&&o<37&&o%6==0)// If it's at row number 12&36, print the horizontal surrounding frames of the windows and part of the door; if it's at row number 18,24,30, print the horizontal grid lines of the windows and part of the door, also the spaces for each row.
			{
				for(t=0; t<interior_width; ++t)// For each row, print out a character until the total number of characters is equal to interior_width(64).
				{
					if(t>1&&t<18||t>(interior_width-19)&&t<(interior_width-2))// If it's at the part of the horizontal surrounding frames or the horizontal grid lines, print "=". 
					{
						printf("=");
					}
					else if(t>(interior_width-43)&&t<(interior_width-22))// If it's at the part of the door, print "&"
					{
						printf("&");
					}
					else// If it's at the part of the spaces, print a space character.
					{
						printf(" ");
					}
				}		
			}
			else if (o>12&&o<18||o>18&&o<24||o>24&&o<30||o>30&&o<36)// If it's at row number 13~17, 19~23, 25~29, 31~35, print the vertical surrounding frames of the windows, the window glass, the vertical grid lines of the windows, part of the door, and also the spaces.
			{
				for(t=0; t<interior_width; ++t)// For each row, print out a character until the total number of characters is equal to interior_width(64).
				{
					if(t==2||t==17||t==(interior_width-18)||t==(interior_width-3))// If it's at the part of the vertical surrounding frames, print "=".
					{
						printf("=");
					}
					else if (t==7||t==12||t==51||t==56)// If it's at the part of the vertical grid lines, print "+".
					{
						printf("+");
					}
					else if (t>(interior_width-43)&&t<(interior_width-22))// If it's at the part of the door, print "&".
					{
						printf("&");
					}
					else// If it's at the part of the window glass or the spaces, print a space character.
					{
						printf(" ");
					}
				}
			}
			else if(o>36&&o<exterior_height-4)// If it's at row number 37~39, print the rest part of the the door and the spaces.
			{
				for(t=0; t<interior_width; ++t)// For each row, print out a character until the total number of characters is equal to interior_width(64).
				{
					if (t>(interior_width-43)&&t<(interior_width-22))// If it's at the part of the door, print "&".
					{
						printf("&");
					}
					else// If it's at the part of the spaces, print a space character.
					{
						printf(" ");
					}
				}
			}
			else if(o==exterior_height-4||o==exterior_height-3)// If it's at row number 40&41, print the spaces between the door and the floor of the house.
			{
				for(t=0; t<interior_width; ++t)// Repeat the execution of printing the space until the total number of the space characters is equal to interior_width(64) for each line.
				{
					printf(" "); 
				}
			} 
			else// For the last two rows, print out the floor part of the house.
			{
				for(t=0; t<interior_width; ++t)// Repeat the execution of printing "@" until the total number of "@" characters is equal to interior_width(64).
				{
					printf("@"); 
				}
			}
			printf("@@");// print out the right side wall with "@@" for each row.
			printf("\n");// After a row is finished, move to the next line.
		}
	}
	else//If the values of total_width, total_height, exterior_width, exterior_height, interior_width, and interior_height aren't equal to the right values, then the house design is unvalid.
	{
		printf("The house design is invalid.");
	}
	return 0;
}
	
