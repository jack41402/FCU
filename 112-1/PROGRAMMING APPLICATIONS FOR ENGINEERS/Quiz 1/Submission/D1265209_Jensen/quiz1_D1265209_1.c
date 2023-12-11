#include <stdio.h>

// Print n copies of character c.
void printChar(int n, char c) 
{
	int i;
	for (i = 0; i < n; i++) 
	{
		printf("%c", c);	
	}
}

int main(void) {
	const int leading=10; // 10 leading blanks on the left side of the figure.
	int top; // Length of the top, 3<=top<=29, of the parallelogram.
	int side; // Length of the side, 2<=side<=20 between the top and the bottom of the parallelogram
	int tilt; // 0 for left-tilt or 1 for right-tilt of the side of the parallelogram.
	int i; // Loop variable.
	int j;
  
	// Input Length of the top, 3<=top<=29.
	do {
		printf("Enter top, an integer between 3 and 29 (including): ");
		scanf("%d", &top);
	} while ((top < 3) || (top > 29));
  
	// Input Length of the side, 2<=side<=20.
	do {
		printf("Enter side, an integer between 2 and 20 (including): ");
		scanf("%d", &side);
	} while ((side < 2) || (side > 20));
  
	// Input tilt of the side, 2<=side<=20.
	do {
		printf("Enter 0 for left-tilt or 1 for right-tilt of the side: ");
		scanf("%d", &tilt);
	} while ((tilt != 0) && (tilt != 1));
	{
		printf("\n");
		if(tilt==0)
		{
			for(i=0;i<side+2;++i)
			{
				printChar(leading+side-i-1,' ');
				printf("#");
				if(i==0||i==side+1)
				{
					printChar(top-1,'#');
				}
				else
				{
					printChar(top-2,'@');
					printf("#");
				}
				printf("\n");
			}
		}
		if(tilt==1)
		{
			for(i=0;i<side+2;++i)
			{
				printChar(leading+i,' ');
				printf("#");
				if(i==0||i==side+1)
				{
					printChar(top-1,'#');
				}
				else
				{
					printChar(top-2,'@');
					printf("#");
				}
				printf("\n");
			}
		}
		printf("\n");
		int a=top*2+2*side,b=(top-2)*side,c=top*(side+2);
		printf("The number of characters on the perimeter: %d\n",a);
		printf("The number of characters in the interior: %d\n",b);
		printf("The number of characters of the parallelogram: %d\n",c);
	}
	
	// ***** Complete the rest of the program.
	
	// Draw the parallelogram. Consider left-tilt and right-tilt cases.	
	
	// Compute and print the number of characters on the perimeter£¬in the interior, 
	// and the parallelogram¡£ 
	
	return 0;
}
