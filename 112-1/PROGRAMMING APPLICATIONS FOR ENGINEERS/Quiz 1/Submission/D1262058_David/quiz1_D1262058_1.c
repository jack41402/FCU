#include <stdio.h>

// Print n copies of character c.
int a,b=0,c,d=1,e;
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
	if(tilt==1){
		for(a=1;a<=side;a++){
			printChar(10, ' ');
			for(e=1;e<=side-1+b;e++){
				printf(" ");
				} 
			printf("#");
			
				if(a==1||a==side){
						printChar(10, '#');
					}
				else{
						printChar(10, '@');
					}					
			
		printf("#\n");
		b-=1;				
		}

	}
	if(tilt==0){
		for(a=1;a<=side;a++){
			printChar(10, ' ');
			for(e=1;e<d;e++){
				printf(" ");
				} 
			printf("#");
			for(c=1;c<=top;c++){
				if(a==1||a==side){
					printf("#");
					}
				else{
					printf("@");
					}					
			}
		printf("#\n");
		d+=1;				
		}

	}

	
	return 0;
}
