#include <stdio.h>

// Print n copies of character c.
void printChar(int n, char c) {
	int i;
 
	for (i = 0; i < n; i++) printf("%c", c);
}

int main(void)
 {
	int top; 
	int side; 
	int tilt;
	int i;
	int j;
  
	do {
		printf("Enter top, an integer between 3 and 29 (including): ");
		scanf("%d", &top);
	} while ((top < 3) || (top > 29));
  

	do {
		printf("Enter side, an integer between 2 and 20 (including): ");
		scanf("%d", &side);
	} while ((side < 2) || (side > 20));
  

	do {
		printf("Enter 0 for left-tilt or 1 for right-tilt of the side: ");
		scanf("%d", &tilt);
	} while ((tilt != 0) && (tilt != 1));
	
	if(tilt==0)
	{
		printf("\n");
	for(i=1;i<=11+side;i++)
	{
		printf(" ");
	}
	for(i=1;i<=top;i++)
	{
		printf("#");
	}
	printf("\n");
	for(i=1;i<=side;i++)
	{
		for(j=1;j<=17-i;j++)
		{
		printf(" ");
		}
		printf("#");
		for(j=1;j<=top-2;j++)
		{
		printf("@");
		}
		printf("#\n");
	}
	for(i=1;i<=10;i++)
	{
		printf(" ");
	}
	for(i=1;i<=top;i++)
	{
		printf("#");
	}
	printf("\n\n");
    }
    else
	{
		printf("\n");
	for(i=1;i<=10;i++)
	{
		printf(" ");
	}
	for(i=1;i<=top;i++)
	{
		printf("#");
	}
	printf("\n");
	for(i=1;i<=side;i++)
	{
		for(j=1;j<=i+10;j++)
		{
		printf(" ");
		}
		printf("#");
		for(j=1;j<=top-2;j++)
		{
		printf("@");
		}
		printf("#\n");
	}
	for(i=1;i<=11+side;i++)
	{
		printf(" ");
	}
	for(i=1;i<=top;i++)
	{
		printf("#");
	}
	printf("\n\n");
    }
    printf("The number of characters on the perimeter: %d\n",2*(top+side));
    printf("The number of characters in the interior: %d\n",(top-2)*side);
    printf("The number of characters of the parallelogram: %d\n",top*(side+2));
	return 0;
}
