#include <stdio.h>
int main()
{
int top,side,space,tilt,a,b,c,perimeter,interior,parallelogram;
printf("Enter top, an integer between 3 and 29 (including):");
scanf("%d",&top);
printf("Enter side, an integer between 2 and 10 (including):");
scanf("%d",&side);
printf("Enter 0 for left-tilt or 1 for right-tilt of the side:");
scanf("%d",&tilt);
printf("\n\n");
    side = side+2;
	if(tilt==0){
	space = side+5;
	for(a=1;a<=side;a++){
		for(b=1;b<=space;b++){
			printf(" ");
		}
		for(b=space;b<=space+top;b++){
			if(a==1 || a==side || b==space || b==space+top){
				printf("#");
			}
			else{
			printf("@");
	    }
		}
		printf("\n");
		space--;
	}
}
    if(tilt==1){
    	space = 5;
	for(a=1;a<=side;a++){
		for(b=1;b<=space;b++){
			printf(" ");
		}
		for(b=space;b<=space+top;b++){
			if(a==1 || a==side || b==space || b==space+top){
				printf("#");
			}
			else{
			printf("@");
	    }
		}
		printf("\n");
		space++;
	}	
	}
    perimeter = top*2+(side-2)*2;
    interior = side*top-perimeter;
    parallelogram = side*top;
	printf("\n\n");
	printf("The number of characters on the perimeter:%d",perimeter);
	printf("\n");
	printf("The number of characters in the interior:%d",interior);
    printf("\n");
    printf("The number of characters of the parallelogram:%d",parallelogram);
	return 0;
}
