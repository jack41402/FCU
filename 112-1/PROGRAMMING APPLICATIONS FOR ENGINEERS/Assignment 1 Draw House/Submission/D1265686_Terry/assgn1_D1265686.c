#include<stdio.h>
int main()
{
	//set variables
	int r_top=40; 
	int r_side=16;
	int h_width=64;
	int h_height=40;
	int r_bottom=72;
	int windows_width=25; 
	int windows_height=16;
	int door_width=20;
	int door_height=28;
	int window_space_wall=2;
	int window_space_door=4;
	int door_space_floor=2;
	int door_space_ceiling=10;
	
	//print out all the value of the house
	
	printf("Design parameters of the house :\n");
	printf("top of the roof : %d\n", r_top);
	printf("side of the roof : %d\n",r_side);
	printf("bottom of the roof : %d\n",r_bottom);
	printf("width of the house :  %d\n",h_width);
	printf("height of the house :  %d\n",h_height);
	printf("width of the window :  %d\n",windows_width);
	printf("height of the window :  %d\n",windows_height);
	door_width=h_width-window_space_wall*2-window_space_door*2;
	printf("width of the door  :  %d\n",door_width);
	door_height=h_height-door_space_ceiling-door_space_floor;
	printf("height of the door :  %d\n",door_height);
	printf("space from the window / door to the ceiling :  %d\n",door_space_ceiling);
	printf("space from the window to the wall :  %d\n",window_space_wall);
	printf("space between the window and the door:  %d\n",window_space_door);
	printf("space between the floor and the door  :  %d\n",door_space_floor);
	
	
	int space=(r_bottom-r_top)/2; //calculate the value of the space that we need to print out in the first line of the roof
	int d;
	for(d=0;d<space;++d)
	{
		printf(" ");
	}
	int c;
	for(c=1;c<=r_top;++c) //print out the top of the roof
	{
		printf("#");
	}
	printf("\n");
	int a;
	for(a=1;a<=r_side;++a) //calculate the line where we are
 	{
 		int b;
 		for(b=0;b<=r_side-a-1;++b) //print out the space before the roof and minus one space that we meed to print when it comes to next line 
 		{
 			printf(" ");
		}
		printf("#"); //print out the first first letter when it comes to a new line
		int c;
		for(c=0;c<=2*a+r_top-3;++c) //print out the middle of the roof
		{
			printf("*");
		}
		printf("#"); //when it comes to the end of the line print this leter again
	printf("\n");
	}
	int e;
	for(e=1;e<=r_bottom;++e) // this is the end row of the roof
	{
		printf("#");
	}
	printf("\n");
	printf("  "); 
	int f;
	for(f=1;f<=h_width+4;++f) //this is the first line of the main body of the house
	{
		printf("@");
	}
	printf("\n");
	printf("  ");
	int z;
	for(z=1;z<=h_width+4;++z) //this is the second line of the main body of the house
	{
		printf("@");
	}
	printf("\n");
	int g;
	for(g=1;g<=door_space_ceiling;++g) //print out the line from the third line of the house to the window/door
	{
		printf("  @@");
		int h;
		for(h=1;h<=h_width;++h) //this is the space between the wall to the wall
		{
			printf(" ");
		}
		printf("@@");
		printf("\n");
		
	}
	int i, j,k,w;
	for(i=0;i<h_height-door_space_ceiling-5;++i) //calculate the line from the  top of window/door to the bottom of window
	{
		if(i==0||i==6||i==12||i==18||i==24) //judge whether the line have "=" or not
		{
			printf("  @@  ");
			for(j=1;j<=16;++j)
			{
				printf("=");
			}
			for(k=1;k<=4;++k)
			{
				printf(" ");
			}
			for(w=1;w<=20;++w)
			{
				printf("&");
			}
			for(k=1;k<=4;++k)
			{
				printf(" ");
			}
			for(j=1;j<=16;++j)
			{
				printf("=");
			}
			printf("  @@");
			printf("\n");
		}
		else 
		{
			printf("  @@  ");
			printf("=    +    +    =    ");
			for(w=1;w<=20;++w)
			{
				printf("&");
			}
			printf("    =    +    +    = ");
			printf(" @@");
			printf("\n");
		}	
	}
	int q;
	for(q=0;q<3;++q) //calculate the rows
	{
			printf("  @@"); //print out the wall
		int y;
		for(y=1;y<=22;++y) //print out the space between the wall to the door
		{
			printf(" ");
		}
		for(w=1;w<=20;++w) //print out the door
		{
			printf("&");
		}
		for(y=1;y<=22;++y) //print out the space between the door to the wall
		{
			printf(" ");
		}	
		printf("@@"); //print out the wall
		printf("\n");
	}
	int u;
	for(u=0;u<2;++u)
	{
		printf("  @@"); //print out the wall
		int p;
		for(p=1;p<=64;++p) //print out the space between the wall to wall
		{
			printf(" ");
		}
		printf("@@"); //print out the wall
		printf("\n");
	}
	printf("  ");
	int t;
	for(t=1;t<=h_width+4;++t) //print out the floor
	{
		printf("@");
	}
	printf("\n");
	printf("  ");
	for(t=1;t<=h_width+4;++t) 
	{
		printf("@");
	}
}
