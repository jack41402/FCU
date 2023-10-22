#include <stdio.h>

int main(void)
{
	int top, side, left_right;
	do{
		printf("Enter top, an integer between 3 and 29 (including): ");
		scanf("%d", &top);} while (top<3||top>29);
	do{
		printf("Enter side, an integer between 2 and 20 (including): ");
		scanf("%d", &side);} while (top<2||top>20);
	printf("Enter 0 for left-tilt or 1 for right-tilt of the side: ");
	scanf("%d", &left_right);
	
	int i, j, k;
	if(left_right)
	{
		printf("\n");
		for(i=side; i>-1; --i)
		{
			for(j=0; j<side-1-i+10; ++j) printf(" ");
			printf("#");
			if(i==0||i==side)
			{
				for(k=0; k<top-2; ++k) printf("#");
			}
			else
			{
				for(k=0; k<top-2; ++k) printf("@");
			}
			printf("#\n");
		}
	}
	else
	{
		printf("\n");
		for(i=0; i<side; ++i)
		{	
			for(j=0; j<side-1-i+10; ++j) printf(" ");
			printf("#");
			if(i==0||i==side-1)
			{
				for(k=0; k<top-2; ++k) printf("#");
			}
			else
			{
				for(k=0; k<top-2; ++k) printf("@");
			}
			printf("#\n");
		}
	}
	return 0;
}
