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
	int j;
	printf("Enter top, an integer between 3 and 29 (including): \n");
	scanf("%d", &top);
	printf("Enter side, an integer between 2 and 20 (including): \n");
	scanf("%d", &side);
	printf("Enter 0 for left-tilt or 1 for right-tilt of the side: \n");
	scanf("%d", &tilt);
	
	if(tilt==0){
		for(j=1;j<=leading;j++){
			printf(" ");
		}
	for(j=1;j<=top-1;j++){
			printf(" ");
		}
	for(j=1;j<=top;j++){
		printf("#");
	}
	printf("\n");
	for(i=1;i<=side-2;i++){
		for(j=1;j<=leading;j++){
			printf(" ");
		}
		for(j=1;j<=top-i-1;j++){
			printf(" ");
		}
		for(j=1;j<=top;j++){
			if(j==1||j==top){
				printf("#");
			}
			else{
				printf("@");
			}
			
			
		}
		printf("\n"); 
	}
	for(j=1;j<=leading;j++){
			printf(" ");
		}
	for(j=1;j<=top-side;j++){
			printf(" ");
		}
	for(j=1;j<=top;j++){
		printf("#");
	}
	return 0;
}
else if (tilt==1){
	for(j=1;j<=leading;j++){
			printf(" ");
		}
	for(j=1;j<=top-side;j++){
			printf(" ");
		}
	for(j=1;j<=top;j++){
		printf("#");
	}
	printf("\n");
	for(i=1;i<=side-2;i++){
		for(j=1;j<=leading;j++){
			printf(" ");
		}
		for(j=1;j<=top-side+i;j++){
			printf(" ");
		}
		for(j=1;j<=top;j++){
			if(j==1||j==top){
				printf("#");
			}
			else{
				printf("@");
			}
			
			
		}
		printf("\n"); 
	}
	for(j=1;j<=leading;j++){
			printf(" ");
		}
	for(j=1;j<=top-1;j++){
			printf(" ");
		}
	for(j=1;j<=top;j++){
		printf("#");
	}
	return 0;
}
else {
	printf("tlit must be 0 or 1");
	return 0;
}
}


	
