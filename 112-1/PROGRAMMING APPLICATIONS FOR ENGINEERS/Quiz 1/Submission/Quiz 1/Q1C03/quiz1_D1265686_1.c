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
	int i; // Loop variable.
  
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
		int a;
		for(a=1;a<=side;++a)
		{
			int h;
			for(h=1;h<=10;++h)
			{
				printf(" ");
			}
			int b;
			for(b=1;b<=side-a;++b)
			{
				printf(" "); 
			}
			int c;
			
			if(a==1||a==side)
			{
				for(c=1;c<=top;++c)
				{
					printf("#");
				}
				printf("\n");
			}
			else
			{
				printf("#");
				int d;
				for(d=1;d<=top-2;++d)
				{
				printf("@");
				}
				printf("#");
				printf("\n");
			}	
			
			
		}
	}
	else
	{
		int e;
		for(e=1;e<=side;++e)
		{
			int y;
			for(y=1;y<=10;++y)
			{
				printf(" ");
			}
			int f;
			for(f=1;f<=e;++f)
			{
				printf(" ");
			}
			if(e==1||e==side)
			{
				int g;
				for(g=1;g<=top;++g)
				{
					printf("#");
				}
				printf("\n");
			}
			else
			{
				printf("#");
				int r;
				for(r=1;r<=top-2;++r)
				{
					printf("@");
				}
				printf("#");
				printf("\n");
			}
		}
	}
	
	int k;
	k=top*2+side*2-4;
	int s;
	s=(top-2)*(side-2);
	int p;
	p=top*side;
	
	printf("The number of the characters on the perimeter: %d \n",k);
	printf("The number of the characters in the interior: %d \n",s);
	printf("The number of the characters of the parallelogram: %d \n",p);
	
	// ***** Complete the rest of the program.
	
	// Draw the parallelogram. Consider left-tilt and right-tilt cases.	
	
	// Compute and print the number of characters on the perimeter£¬in the interior, 
	// and the parallelogram¡£ 
	
	return 0;
}
