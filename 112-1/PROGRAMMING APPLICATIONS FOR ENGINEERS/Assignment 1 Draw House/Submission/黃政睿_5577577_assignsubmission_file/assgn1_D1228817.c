#include <stdio.h>

int main()
{
	int r_top=40, r_side=16, h_width=64, h_height=40;
	int r_bottom = r_top+2*r_side;
	
	int A;//The value input of A by the user enables the program to run correctly on dev c++
	printf("enter anything to run the program correctly: ");
	scanf("%d", &A);
	printf("\n\n");
	
	printf("***** Design parameters of the house:\n");
	printf("   <<< The top of the roof: %d\n", r_top);
	printf("   <<< The side of the roof: %d\n", r_side);
	printf("   <<< The bottom of the roof: %d\n", r_bottom);
	printf("   <<< The width of the door: 20\n");
	printf("   <<< The height of the door: 28\n");
	printf("   <<< The width of the window: 16\n");
	printf("   <<< The height of the window: 25\n");
	printf("   <<< The width of a window glass: 4\n");
	printf("   <<< The height of a window glass: 5\n");
	printf("   <<< The thickness of wall/ceiling/floor: 2\n");
	printf("   <<< The space from the window/door to the ceiling: 10\n");
	printf("   <<< The space between the floor and the door: 5\n");
	printf("   <<< The space between the floor and the window: 10\n");
	printf("   <<< The space from the window to the wall: 2\n");
	printf("   <<< The space between the window and the door: 4\n\n\n");

	//Varifying the validity of the house design.
	if (r_bottom==72||((h_height+4)+(r_side+2))==62||h_width+4==68||h_height+4==44||h_width==64||h_height==40){
		printf("***** The house design is valid.\n");
	}
	else {
		printf("***** The house design is not valid.\n");
	}
	//When calculating the exterior width/height of the house, the number of h_width and h_height need to increase bt 4 in order to account for the thickness of the walls.  
	//When calculating the layers of the roof, r_side needs to be increased by 2 as the topmost and bottommost layer of the roof are not included in the 16 layers of the isosceles side.
	
	printf("   >>>Total width of the house: %d\n", r_bottom);
	printf("   >>>Total height of the house: %d\n", (h_height+4)+(r_side+2));
	printf("   >>>The exterior width of the house: %d\n", h_width+4);
	printf("   >>>The exterior height of the house: %d\n", h_height+4);
	printf("   >>>The interior width of the house: %d\n", h_width);
	printf("   >>>The interior height of the house: %d\n", h_height);
	printf("\n\n");
	
	int j, t, i;//t controls the spaces on the left hand side of each layer. j controls the change of layers. i prints out characters. 
	
	//topmost layer of roof
	for (t = 0; t < r_side; ++t) {
			printf(" ");
		}
		for (i = 0; i < r_top; i++) {
			printf("#");
		}
			printf("\n");
	//isosceles side of roof			
	for (j = 0; j < r_side; ++j) {
		for (t = 0; t + j < r_side-1; ++t) {
			printf(" ");
		}
		for (i = 0; i < r_top+2; i++) {			//The variable r_top is the number of interior points contained in the second layer of the roof. 
			if (i==0){
					printf("#");
			}
			else if(i==r_top+1){
				printf("#");
			}
			else{
			printf("*");
		}
		}
		printf("\n");
		r_top+=2;
	}
	//bottommost layer of roof
	for(i=0;i<r_bottom;i++)
	{
		printf("#");
	}
	printf("\n");
	//main house
	int a,b,c,d,e;//a controls the change of layers. b controls the spaces outside of the house(left). c prints out characters. 
	      	      //d controls the width of the door. e controls when to print the grid line and the glass of the window. 
	for (a = 0; a < h_height+4; ++a) {
		for (b = 0; b<(r_bottom-(h_width+4))/2; ++b) {
			printf(" ");
		}
		printf("@@");
		if (a<2){
			for(c=0; c < h_width; c++){
					printf("@");
			}
		}
		else if (a<12){
			for (c = 0; c < h_width; c++){
				printf(" ");
			}
		}
			else if (a==12||a==18||a==24||a==30){
				for(c=0;c<4;c++){
					printf(" ");
				}
					for(c=0;c<16;c++){
					printf("=");
				}
					for(c=0;c<2;c++){
					printf(" ");
				}
					for(d=0;d<h_width-44;d++)
					{printf("&");
				}
					for(c=0;c<2;c++){
					printf(" ");
				}
				for(c=0;c<16;c++){
					printf("=");
				}
				for(c=0;c<4;c++){
					printf(" ");
				}
			}
			else if(a>12&&a<30){
				for(c=0;c<4;c++){
					printf(" ");
				}
				printf("=");
				for(e=0; e<3; e++){
					for(c=0; c<4; c++){
						printf(" ");
					}
					if(e<2){
						printf("+");
					}
				}
				printf("=");
				for(c=0;c<2;c++){
					printf(" ");
			}
				for(d=0;d<h_width-44;d++)
					{printf("&");
				}
					for(c=0;c<2;c++){
					printf(" ");
				}
				printf("=");
				for(e=0; e<3; e++){
					for(c=0; c<4; c++){
						printf(" ");
					}
					if(e<2){
						printf("+");
					}
				}
				printf("=");
				for(c=0;c<4;c++){
					printf(" ");
				}
			}
			else if(a<h_height){
				d=h_width-44;
			for (c=0; c < (h_width-d)/2; c++) {
			printf(" ");
		}
			for(d=0;d<h_width-44;d++){
					printf("&");
				}
				for (c=0; c < (h_width-d)/2; c++) {
			printf(" ");
		}
	}
		else if (a>h_height+1){
			for(c=0; c < h_width; c++){
					printf("@");
		}
	}
		else
		{
			for (c = 0; c < h_width; c++){
				printf(" ");
			}
	}
	
		printf("@@");
		printf("\n");
		
	}
return 0;
}

