#include<stdio.h>
int main(void)
{
	int i,j,k=40,m;//line 4 to line 29 are going to delimit the constant 
	const int r_top=40;
	const int r_bottom=72;
	const int r_side=16;
	const int h_width=64;
	const int h_height=40;
	const int d_width=20;
	const int d_height=28;
	const int w_width=16;
	const int w_height=25;
	const int wg_width=4;
	const int wg_height=5;
	const int wall_thickness=2;
	const int c_thickness=2;
	const int f_thickness=2;
	const int space_window_ceiling=10;
	const int space_floor_door=2;
	const int space_floor_window=5;
	const int space_window_wall=2;
	const int space_window_door=4;
	const int total_width=72;
	const int total_height=62;
	const int exterior_width=68;
	const int exterior_height=44;
	const int interior_width=64;
	const int interior_height=40; 
	printf("*** Design parameters of the house:\n");//To print out the constant of each part of the house
 	printf("   <<< The top of the roof: %d\n",r_top);
 	printf("   <<< The side of the roof: %d\n",r_side);
 	printf("   <<< The bottom of the roof: %d\n",r_bottom);
 	printf("   <<< The width of the door: %d\n",d_width);
 	printf("   <<< The height of the door: %d\n",d_height);
 	printf("   <<< The width of the window: %d\n",w_width);
 	printf("   <<< The height of the window: %d\n",w_height);
 	printf("   <<< The width of the window glass: %d\n",wg_width);
 	printf("   <<< The height of the window glass: %d\n",wg_height);
 	printf("   <<< The thickness of the wall/ceiling/floor: %d\n",wall_thickness);
 	printf("   <<< The space from the window/door to the ceiling: %d\n",space_window_ceiling);
 	printf("   <<< The space between the floor and the door: %d\n",space_floor_door);
 	printf("   <<< The space between the floor and the window: %d\n",space_floor_window);
 	printf("   <<< The space from the window to the wall: %d\n",space_window_wall);
 	printf("   <<< The space between the window and the door: %d\n",space_window_door);
 	printf("\n");
 	if (total_width==d_width+w_width*2+wall_thickness*2+space_window_wall*2+space_window_door*2+(r_bottom-h_width-wall_thickness*2)&&
	 total_height==r_side+2+c_thickness+space_window_ceiling+w_height+(d_height-w_height)+space_floor_door+f_thickness&&
	 exterior_width==wall_thickness*2+space_window_wall*2+w_width*2+space_window_door*2+d_width&&
	 exterior_height==c_thickness+space_window_ceiling+w_height+(d_height-w_height)+space_floor_door+f_thickness&&
	 interior_width==space_window_wall*2+w_width*2+space_window_door*2+d_width&&
	 interior_height==space_window_ceiling+w_height+(d_height-w_height)+space_floor_door)//To verify the data are right or not
	{
 	printf("*** The house design is valid.\n");
	printf("   >>> The total width of the house: %d\n",total_width);//print out the total, exterior and interior height and width
 	printf("   >>> The total height of the house: %d\n",total_height);
 	printf("   >>> The exterior width of the house: %d\n",exterior_width);
 	printf("   >>> The exterior height of the house: %d\n",exterior_height);
 	printf("   >>> The interior width of the house: %d\n",interior_width);
 	printf("   >>> The interior height of the house: %d\n",interior_height);
 	printf("\n");
 	printf("\n");
	for (j=1;j<=r_top+r_side;++j)//print the first line
	{
		if (j<=r_side)//print out the blanks which are located on the right of the first line
			{
				printf(" ");
			}
		else  //print the rest of the first line with the sign of #
			{
				printf("#");
			}
	} 
	printf("\n");//to change to the next line
	for (i=1;i<=r_side;++i)//calculate the lines of the ceiling 
	{
		for (j=1;j<=r_side+1;++j)
		{
			if (i+j<=r_side)
			{
				printf(" ");//print out the blanks located on the right of the ceiling
			}
		}
		printf("#");//print out the # sign that on the left of the ceiling
		for(j=1;j<=k;j++)//To calculate the amount of the * sign in the middle of the ceiling 
		{
			printf("*");
		}
		printf("#");
		k=k+2;//k plus two after for loop has done each of the time
	printf("\n");
	}
	for (j=1;j<=r_bottom;++j)//calculate the amount of # sign in the last line of the ceiling
	{
		printf("#");
	}
	printf("\n");//change to the next line
	for (i=1;i<=2;++i)//calculate the amount of lines of the roof
	{
		for(j=1;j<=r_bottom;++j)//calculate the amount of j
		{
			if (3<=j&&j<=70) //print @ sign if 3<=j<=70
			{
				printf("@");	
			}
			else //print the other place of the roof with blanks
			{
				printf(" ");
			} 
		}
		printf("\n");//change to the next line
	}
	for (i=1;i<=10;++i)//select the first 10 lines of the wall
	{	
		for (j=1;j<=r_bottom;++j)//count the amount of j
		{
			if (i<=10)
			{
				if (j==3||j==4||j==69||j==70)//when j=3 or 4 or 69 or 70, print @
				{
					printf("@");
				}
				else //print the other places with blanks
				{
					printf(" ");
				}
			} 		
		}
		printf("\n");//change to the next line	
	}
	for (m=1;m<=4;++m)//print the combination of wall, window, glasses and door for four times
	{
		for (i=1;i<=6;++i)//the combination of wall, glasses and door are combin in six lines
		{
			for (j=1;j<=r_bottom;++j)//count the amount of j
			{
				if(i<=6)
				{
					if (j==3||j==4||j==69||j==70)//when j=3 or 4 or 69 or 70, print @ 
					{
						printf("@");
					}
					else if (j==7||j==22||j==51||j==66)//when j=7 or 22 or 51 or 66, print =
					{
						printf("=");
					}
					else if (27<=j&&j<=46)//when27<=j<=46,print &
					{
						printf("&");
					}
					else if (2<=i&&i<=6&&j==12)//print the frame of the left window
					{
						printf("+");
					}
					else if (2<=i&&i<=6&&j==17)//print the frame of the left window
					{
						printf("+");
					}
					else if (2<=i&&i<=6&&j==56)//print the frame of the right window
					{
						printf("+");
					}
					else if (2<=i&&i<=6&&j==61)//print the frame of the right window
					{
						printf("+");
					}
					else if (8<=j&&j<=21&&i==1)//print the top of the left window
					{
						printf("=");
					}
					else if (52<=j&&j<=65&&i==1)//pirnt the top of the right window
					{
						printf("=");
					}
					else 
					{
						printf(" ");//fill in the other places with blanks
					}
				}
			}
		printf("\n");//change to the next line
		}		
	} 
	for (j=1;j<=r_bottom;++j)//print the last line of the window
	{
		if (j==3||j==4||j==69||j==70)
		{
			printf("@");
		}
		else if (7<=j&&j<=22)//print the last line of the left window
		{
		 	printf("="); 
		}
		else if (51<=j&&j<=66)//print the last line of the right window
		{
			printf("=");
		}
		else if (27<=j&&j<=46)//print the lines of the door
		{
			printf("&");
		}
		else 
		{
			printf(" ");//fill in the other places with blanks
		}	
	}
	printf("\n");//change to the next line
	for (i=1;i<=3;++i)//print the combination of wall and door for three lines
	{
		for (j=1;j<=r_bottom;++j)//count the amount of j
		{
			if (j==3||j==4||j==69||j==70)//print the three lines of the wall
			{
				printf("@");
			}
			else if (27<=j&&j<=46)//print the last three lies of the door
			{
				printf("&");
			}
			else 
			{
				printf(" ");//fill in the other places with blanks
			}
		}
	printf("\n");//change to the next line
	}
	for (i=1;i<=2;++i)//print the last two lines of the wall
	{
		for (j=1;j<=r_bottom;++j)//count the amount of j
		{
			if (j==3||j==4||j==69||j==70)//print the last two lines of the wall
			{
				printf("@");
			}
			else 
			{
				printf(" ");//fill in the other places with blanks
			}
		}
	printf("\n");
	}
	for (i=1;i<=2;++i)//print the two lines of the floor
	{
		for (j=1;j<=r_bottom;++j)//count the amount of j
		{
			if (3<=j&&j<=70)
			{
				printf("@");//print the two lines of the wall
			}
			else 
			{
				printf(" ");//fill in the other place with blanks
			}
		}
	printf("\n");//change to the next line
	}
	return 0;
	}
	else
	{
		return 0;
	}
}
