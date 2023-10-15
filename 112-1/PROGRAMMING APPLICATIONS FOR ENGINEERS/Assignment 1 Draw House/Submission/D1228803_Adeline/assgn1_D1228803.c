#include <stdio.h>
#include <stdlib.h> 

int main()
{
system("pause");

printf ("\n");
printf ("*****Design parameters of the house:\n");
printf ("   <<<The top of the roof: 40\n");
printf ("   <<<The side of the roof: 16\n");
printf ("   <<<The bottom of the roof: 72\n");
printf ("   <<<The width of the door: 20\n");
printf ("   <<<The height of the door: 28\n");
printf ("   <<<The width of the window: 16\n");
printf ("   <<<The height of the window: 25\n");
printf ("   <<<The width of a window glass: 4\n");
printf ("   <<<The height of a window glass: 5\n");
printf ("   <<<The thickness of wall/ceiling/floor: 2\n");
printf ("   <<<The space from the window/door to the celing: 10\n");
printf ("   <<<The space between the floor and the door: 2\n");
printf ("   <<<The space between the floor and the window: 5\n");
printf ("   <<<The space from the window to the wall: 2\n");
printf ("   <<<The space between the window and the door: 4\n");
printf ("\n\n");
printf ("*****The house design is valid.\n");
printf ("   >>>The total width of the house: 72\n");
printf ("   >>>The total height of the house 62\n");
printf ("   >>>The exterior width of the house: 68\n");
printf ("   >>>The exterior height of the house: 44\n");
printf ("   >>>The interior width of the house: 64\n");
printf ("   >>>The interior height of the house: 40\n");
printf ("\n\n");

int r_top = 40;//set the top of the roof as 40
int r_side = 16;//set the side of the roof as 16
int r_bottom = r_top + 2 * r_side; //set the bottom of the roof as (r_top + 2 * r_side) equals to 72
int h_width = r_bottom; //set the width of the house as r_bottom equals to 72
int h_height = 44;//set the height of the house as 44
int d_width = 20;//set the width of the door as 20
int d_height = 28;//set the height of the door as 28
int w_width = 16;//set the width of the window as 16
int w_height = 25;//set the height of the window as 25
int g_width = 4;//set the width of the glass as 4
int g_height = 5;//set height of the glass as 5
int t_wallceilingfloor = 2;//set the thickness of the wall, the ceiling , the floor is 2
int w_singleglass = 4;//set the width of single glass of the window is 4
int h_singleglass = 5;//set the height of single glass of the window is 5
int s_ceiling = 10;//set the space to the ceiling is 10
int s_floordoor = 2;//set the space from the floor to the door is 2
int s_floorwindow = 5;//set the space of the floor to the window is 5
int s_windowdoor = 4;//set the space from the window to the soor is 4
int s_windowwall = 2;//set the space from the window to the door is 2
int s_housestart = 1;//set the space from the house to the starting line is 1
int w_column = 3;//set the number of the column of the window
int w_row = 4;//set the number of row of the window

int a = 0, b = 36;
int i, j, k, m; //declare i, j, k, m 

//Roof
for(i = 1; i < 2; ++i)//set the upper part of the roof will only last one line
{
	for(j = 0; j <= r_side; ++j)//print space until the begining of the trapezoid roof
	{
		printf(" ");//roof with trapezoid must comes with space
	} 
	for(j = 0; j < r_top; ++j)//the top of the roof comes
	{
		printf("#");//the top of the roof comes in "#"
	}
	printf("\n");//prints a newline character to the standard output
}

for(i = 20; i < b; ++i)
//the first line contained one star, the second line contained three stars, the third line contained five stars
//if expected upper base as 3, then int a = 1; if expected upper base as 5, then int a = 3
//triangle can be known as the trapezoid which its upper base is 0, so int a=0
//the 'a' in "int a" stands for the number of line
{
		
	for(j = 0; j < (b - i); ++j)//print space until the begining of the trapezoid roof
	{
		printf(" ");//roof with trapezoid must comes with space
	}
		printf("#");//every layers of the trapezoid comes begin with a '#'
		
	for(j = 1; j <= ( i * 2 ); ++j)//print the '*'until the lower base 
	{
		printf("*");//the trapezoid are made up from '*'
	}
		printf("#");//every layers of the trapezoid end with a '#'
			
	
	printf("\n");//prints a newline character to the standard output
}

for(i = 1; i <= 2; ++i)//print space until the begining of the trapezoid roof
	{
		printf(" ");//roof with trapezoid must comes with space
		
		for(j = 0; j < r_bottom; ++j)//the last layers of the roof
		{
			printf("#");//the last layers of the roof comes in '#'
		}
		printf("\n");//prints a newline character to the standard output
	}
//House
//The upper part of the house 
for(i = 1; i <= t_wallceilingfloor; ++i)//the thickness of the top part of the house is 2
	{
		for(j = 0; j < s_housestart + t_wallceilingfloor; ++j)//the main body of the house located at the middle of the house, which need spaces
		{
			printf(" ");//space is neccessary to keep the main body of the house stay at the middle  
		} 
		for(j = 0; j < r_bottom - 4; ++j)//print '@' from two space from to the roof to two space before the roof
		{
			printf("@");//print '@' as the upper boundary part of the house
		}
		printf("\n");//prints a newline character to the standard output
	}
	
//The house which is above the door and windows	
for(i = 1; i <= s_ceiling; ++i)//Print from the ceiling to the door and window
{
	for(j = 0; j < s_housestart + t_wallceilingfloor; ++j)//print space from the left roof to the startof the wall
	{
		printf(" ");//print space
	}
	for(j = 0; j < t_wallceilingfloor; ++j)//print the thickness of the wall as request 2 '@' on left
	{
		printf("@");//print 2 '@' as the wall
	}
	for(j = 0; j < s_windowwall + w_width + s_windowdoor + d_width + s_windowdoor + w_width + s_windowwall; ++j)//print space from the left side wall to the right side wall
	{
		printf(" ");//print space
	}
	for(j = 0; j < t_wallceilingfloor; ++j)//print the thickness of the wall as request 2 '@' on right
	{
		printf("@");//print 2 '@' as the wall
	}
	printf("\n");//prints a newline character to the standard output
}


//Window and Door
for(i = 1; i <= w_row; ++i)//print the rows of the window
{
	for(j = 1; j < 2; ++j)//print the first line of the window (upper frame)
	{
		for(k = 0; k < s_housestart + t_wallceilingfloor; ++k)//print the space from the lefth of the roof 
		{
			printf(" ");//print space
		}
		for(k = 0; k < t_wallceilingfloor; ++k)//print the wall beside the window
		{
			printf("@");//print '@' as the wall
		}
		for(k = 0; k < s_windowwall; ++k)//print space from the wall to the left side of the window
		{
			printf(" ");//print space
		}
		for(k = 0; k < w_width; ++k)//print the left window upper frame as the width of 10
		{
			printf("=");//the frame of the window is made up by '='
		}
		for(k = 0; k < s_windowdoor; ++k)//print the space from the left window to the door
		{
			printf(" ");//print space
		}
		for(k = 0; k < d_width; ++k)//print the first line of the door as the width request for 20
		{
			printf("&");//the door is made up by '&'
		}
		for(k = 0; k < s_windowdoor; ++k)//print the space from the door to the right window
		{
			printf(" ");//print space
		}
		for(k = 0; k < w_width; ++k)//print the right window upper frame as the width of 10
		{
			printf("=");//the frame of the window is made up by '='
		}
		for(k = 0; k < s_windowwall; ++k)//print the space from the right window to the wall
		{
			printf(" ");//print space
		}
		for(k = 0; k < t_wallceilingfloor; ++k)//print the wall as the thickness of 2 '@'
		{
			printf("@");//print '@' as the wall
		}
		printf("\n");//prints a newline character to the standard output
	}

	for(j = 1; j < h_singleglass; ++j)//print the single glass of the window, which would be repeat by row and column
		{
			for(k = 0; k < s_housestart + t_wallceilingfloor; ++k)//print the space from the lefth of the roof 
			{
				printf(" ");//print space
			}
			for(k = 0; k < t_wallceilingfloor; ++k)//print the left side of the wall as the thickness of 2 '@'
			{
				printf("@");//print '@' as the wall
			}
			for(k = 0; k < s_windowwall; ++k)//print the space from the wall to the left window
			
			{
				printf(" ");//print space
			}
				printf("=");//print the left frame of the window 
			
			for(k = 1; k < w_column; ++k)//decide the width of the column of the window
			{
				for(m = 0; m < w_singleglass; ++m)//print the space from the frame of the window to the grid line
				{
					printf(" ");//print space
				}
				printf("+");//print '+' as the vertical grid line
			}
			for(k = 0; k < w_singleglass; ++k)//print the space from the right side of the window(the last vertical grid line) to the right frame
			{
				printf(" ");//print space 
			}
			printf("=");//print '=' as the right frame of the window
			for(k = 0; k < s_windowdoor; ++k)//print the space from the left window to the door
			{
				printf(" ");//print space
			}
			for(k = 0; k < d_width; ++k)//print the door as the width request for 20
			{
				printf("&");//the door is made up by '&'
			}
			for(k = 0; k < s_windowdoor; ++k)//print the space from the soor to the right window
			{
				printf(" ");//print space
			}
			printf("=");//print the left frame of the window 
			for(k = 1; k < w_column; ++k)//decide the width of the column of the window
			{
				for(m = 0; m < w_singleglass; ++m)//print the space from the frame of the window to the grid line
				{
					printf(" ");//print space
				}
				printf("+");//print '+' as the vertical grid line
			}
			for(k = 0; k < w_singleglass; ++k)//print the space from the right side of the window(the last vertical grid line) to the right frame
			{
				printf(" ");//print frame
			}
			printf("=");//print '=' as the right frame of the window
			
			for(k = 0; k < s_windowwall; ++k)//print the space from the right window to the wall
			{
				printf(" ");//print space
			}
			for(k = 0; k < t_wallceilingfloor; ++k)//print the right side of the wall as the thickness of 2 '@'
			{
				printf("@");//print '@' as the wall
			}
			printf("\n");//prints a newline character to the standard output
		}
} 
//lower window frame 
for(i = 1; i < 2; ++i)//print the last line of the window (lower frame)
{
	for(j = 0; j < s_housestart + t_wallceilingfloor; ++j)//print the space from the lefth of the roof 
	{
		printf(" ");//print space
	}
	for(j = 0; j < t_wallceilingfloor; ++j)//print the wall beside the window
	{
		printf("@");//print '@' as the wall
	}
	for(j = 0; j < s_windowwall; ++j)//print space from the wall to the left side of the window
	{
		printf(" ");//print space
	}
	for(j = 0; j < w_width; ++j)//print the left window lower frame as the width of 10
	{
		printf("=");//the frame of the window is made up by '='
	}
	for(j = 0; j < s_windowdoor; ++j)//print the space from the left window to the door
	{
		printf(" ");//print space
	}
	for(j = 0; j < d_width; ++j)//print the first line of the door as the width request for 20
	{
		printf("&");//the door is made up by '&'
	}
	for(j = 0; j < s_windowdoor; ++j)//print the space from the door to the right window
	{
		printf(" ");//print space
	}
	for(j = 0; j < w_width; ++j)//print the right window upper frame as the width of 10
	{
		printf("=");//the frame of the window is made up by '='
	}
	for(j = 0; j < s_windowwall; ++j)//print the space from the right window to the wall
	{
		printf(" ");//print space
	}
	for(j = 0; j < t_wallceilingfloor; ++j)//print the wall as the thickness of 2 '@'
	{
		printf("@");//print '@' as the wall
	}
	printf("\n");//prints a newline character to the standard output
}
//The lower part of the house(with door) 
for(i = 1; i <= s_floorwindow - s_floordoor; ++i)//print the lower part of the house with door
{
	for(j = 0; j < s_housestart + t_wallceilingfloor; ++j)//print the space from the left of the roof 
	{
		printf(" ");//print space
	}
	for(j = 0; j < t_wallceilingfloor; ++j)//print the wall as the thickness of 2 '@'
	{
		printf("@");//print '@' as the wall
	}
	for(j = 0; j < s_windowwall + w_width + s_windowdoor; ++j)//print the space from the left side of wall to the door
	{
		printf(" ");//print space
	}
	for(j = 0; j < d_width; ++j)//print the first line of the door as the width request for 20
	{
		printf("&");//the door is made up by '&'
	}
	for(j = 0; j < s_windowdoor + w_width + s_windowwall; ++j)//print the space from the door to the right side of the wall
	{
		printf(" ");//print space
	}
	for(j = 0; j < t_wallceilingfloor; ++j)//print the wall as the thickness of 2 '@'
	{
		printf("@");//print '@' as the wall
	}
	printf("\n");//prints a newline character to the standard output
	
}
//The low part of the door
for(i = 1; i <= s_floordoor; ++i)//print from the lower part of the door to the floor
{
	for(j = 0; j < s_housestart + t_wallceilingfloor; ++j)//the main body of the house located at the middle of the house, which need spaces
	{
		printf(" "); //print space
	}
	for(j = 0; j < t_wallceilingfloor; ++j)//print the thickness of the wall as request 2 '@' on left
	{
		printf("@");//print 2 '@' as the wall
	}
	for(j = 0; j < s_windowwall + w_width + s_windowdoor + d_width + s_windowdoor + w_width + s_windowwall; ++j)//print space from the left side wall to the right side wall
	{
		printf(" ");//print space
	}
	for(j = 0; j < t_wallceilingfloor; ++j)//print the thickness of the wall as request 2 '@' on right
	{
		printf("@");//print 2 '@' as the wall
	}
	printf("\n");//prints a newline character to the standard output
}
//Floor
for(i = 1; i <=2; ++i)//the thickness of the floor is 2
{
	for(j = 0; j < s_housestart + t_wallceilingfloor; ++j)//the main body of the house located at the middle of the house, which need spaces
	{
		printf(" ");//space is neccessary to keep the main body of the house stay at the middle  
	}
	for(j = 0; j < h_width - 4; ++j)//print '@' from two space from to the roof to two space before the roof
	{
		printf("@");//print '@' as the lower boundary part(floor) of the house
	}
	printf("\n");//prints a newline character to the standard output
}

	return 0;//to indicate the successful execution of a program
} 
