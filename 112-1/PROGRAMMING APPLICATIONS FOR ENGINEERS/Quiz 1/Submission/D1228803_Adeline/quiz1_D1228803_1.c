#include <stdio.h>

// Print n copies of character c.


int main(void) 
{
	int i, j;// Loop variable.
	int side;// Length of the side, 2<=side<=20 between the top and the bottom of the parallelogram
	int  top;// Length of the top, 3<=top<=29, of the parallelogram.
	int tilt;// 0 for left-tilt or 1 for right-tilt of the side of the parallelogram.

	// Input Length of the top, 3<=top<=29.
	// Input Length of the side, 2<=side<=20.	
	// Input tilt of the side, 2<=side<=20.
	
	printf("Enter top, an integer between 3 and 29 (including): ");
	scanf("%d", &top);
	printf("Enter side, an integer between 2 and 20 (including): ");
	scanf("%d", &side);
	printf("Enter 0 for left-tilt or 1 for right-tilt of the side: ");
	scanf("%d", &tilt);


// ***** Complete the rest of the program.
	
// Draw the parallelogram. Consider left-tilt and right-tilt cases.	
	
// Compute and print the number of characters on the perimeter£¬in the interior, 
// and the parallelogram¡£ 
	
	
if(tilt=0)
{

	//top 
	for(i = 1; i < 2; ++i)
	{
		for(j = 1; j <= 10 + top - 1; ++j)
			{
				printf(" ");
			} 
			for(j = 1; j<= side; ++j)
			{
				printf("#");
			}
			printf("\n");
	}
	//main part
	for(i = 1; i <= side - 2; ++i)
	{
		for(j = 1; j <= 10 + side - i -1; ++j)
		{
			printf(" ");
		}
		printf("#");
		for(j = 1; j <= top - 2; ++j)
		{
			printf("@");
		}
		printf("#");
		
		printf("\n");
	}
	
	//bottom line 
	for(i = 1; i < 2; ++i)
	{
		for(j = 1; j >= 10 + top - 1; ++j)
			{
				printf(" ");
			} 
			for(j = 1; j<= side; ++j)
			{
				printf("#");
			}
			printf("\n");
	}
}

else if(tilt= 1)
{
	//top 
	for(i = 1; i < 2; ++i)
	{
		for(j = 10+top-1; j <= 1; ++j)
			{
				printf(" ");
			} 
			for(j = 1; j<= side; ++j)
			{
				printf("#");
			}
			printf("\n");
	}
	//main part
	for(i = 1; i <= side - 2; ++i)
	{
		for(j = 1; j <= 10+side-i; ++j)
		{
			printf(" ");
		}
		printf("#");
		for(j = 1; j <= top - 2; ++j)
		{
			printf("@");
		}
		printf("#");
		
		printf("\n");
	}
	
	//bottom line 
	for(i = 1; i < 2; ++i)
	{
		for(j = 1; j >= 10 + top - 1; ++j)
			{
				printf(" ");
			} 
			for(j = 1; j<= side; ++j)
			{
				printf("#");
			}
			printf("\n");
	}

} 

	return 0;
}

