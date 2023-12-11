#include <stdio.h>

// Print n copies of character c.
void printChar(int n, char c) {
	int i;
 
	for (i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
	const int leading=10; // 10 leading blanks on the left side of the figure.
	int top; // Length of the top, 3<=top<=29, of the parallelogram.
	int side; // Length of the side, 2<=side<=20 between the top and the bottom of the parallelogram
	int tilt; // 0 for left-tilt or 1 for right-tilt of the side of the parallelogram.
	int i;
	int m;
	int p=1;
	int q=0; // Loop variable.
  	int w=0;
  	int a,b,c;
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
	if(tilt==0)
	{
		for(i=1;i<=10+side+1+top;++i)
		{
			if(i<=10+side+1)
			{
				printf(" ");
			}
			else 
			{
				printf("#");
			}	
		}printf("\n");
		for(m=1;m<=side;++m)
		{
			for(i=1;i<=10+side+top+q;++i)
			{
				if(i<=10+side+q)
				{
					printf(" ");
				}
				else if (i==10+side+1+q||i==10+side+top+q)
				{
					printf("#");
				}
				else
				{
					printf("@");
				}
			}q-=1;
			printf("\n");
		}
		for(i=1;i<=10+top;++i)
		{
			if(i<=10)
			{
				printf(" ");
			}
			else
			{
				printf("#");
			}
		}
	}
	if(tilt==1)
	{
		for(i=1;i<=10+top;++i)
		{
			if(i<=10)
			{
				printf(" ");
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
		for(m=1;m<=side;++m)
		{
			for(i=1;i<=10+p+top+w;++i)
			{
				if(i<=10+p+w)
				{
					printf(" ");
				}
				else if (i==10+p+w+1||i==10+p+top+w)
				{
					printf("#");
				}
				else
				{
					printf("@");
				}
			}w+=1;
			printf("\n");
		}
		for(i=1;i<=10+side+1+top;++i)
		{
			if(i<=10+side+1)
			{
				printf(" ");
			}
			else 
			{
				printf("#");
			}	
		}
	return 0;
	}
		a=top*2+side*2;
		b=(top-2)*side;
		c=(top*2+side*2)+((top-2)*side);
		printf("The number of characters on the perimeter:%d",a);
		printf("The number of characters in the interior:%d",b);
		printf("The number of characters of the parallelogram:%d",c);
	
	
	// ***** Complete the rest of the program.
	
	// Draw the parallelogram. Consider left-tilt and right-tilt cases.	
	
	// Compute and print the number of characters on the perimeter£¬in the interior, 
	// and the parallelogram¡£ 
	
	return 0;
}
