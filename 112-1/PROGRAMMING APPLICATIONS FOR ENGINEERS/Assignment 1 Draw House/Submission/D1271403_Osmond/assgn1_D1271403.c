#include <stdio.h>
int main(){
	int i, k, t;
	int r_bottom=72;
	int house_width = 64 + 4;
	int house_height = 44;
	int r_roof=40;
	int r_side=16;
	printf("***** Design parameters of the house:\n");
 printf("   <<< The top of the roof: %d\n", r_roof);
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


 if (r_bottom==72||((house_height+4)+(r_side+2))==62||house_width+4==68||house_height+4==44||house_width==64||house_height==40){
  printf("***** The house design is valid.\n");
 }
 else {
  printf("***** The house design is not valid.\n");
 }
 
 printf("   >>>Total width of the house: %d\n", r_bottom);
 printf("   >>>Total height of the house: %d\n", (house_height+4)+(r_side+2));
 printf("   >>>The exterior width of the house: %d\n", house_width+4);
 printf("   >>>The exterior height of the house: %d\n", house_height+4);
 printf("   >>>The interior width of the house: %d\n", house_width);
 printf("   >>>The interior height of the house: %d\n", house_height);
 printf("\n\n");
										//the left side part of the roof, filled with blank space 						
		for(i=0; i<r_side; i++) {
           	printf(" ");				
		   }
		   for(i=0; i<r_roof; i++) {	//the first line of the roof
		   	printf("#");
		   }
		   printf("\n" );
		   									//the middle part of the trapezoid
		   for(i=0; i<r_side; i++) {
		   	
		   	 for(k=0; i+k<r_side-1; k++) {
		   	 	printf(" ");
				}
			for (k=0; k<r_roof+2; k++){
			if(k==0|| k==r_roof+1){
				printf("#");
			}
			else {
				printf("*");
			}
		}
			r_roof=r_roof+2;
			 
				printf("\n");
		   }
										//the last line of the roof	   								
	for (k=0; k<r_bottom; k++){
		printf("#");
	}	   
	printf("\n");
									//first part of the house
	for(i=0; i<house_height; i++){
		for (k=0; k<2; k++){
		printf(" ");
	}
	if(i==0||i==1||i==house_height-2||i==house_height-1){		//prints out the top and bottom of the house
		for(t=0; t<house_width; t++){
			printf("@");
		}
	}
																	//middle part of the house
	else{
		for(t=0; t<house_width; t++){
		
		if(t==0||t==1||t==house_width-1||t==house_width-2){			//prints out the left and right wall of the house 
			printf("@");	
		}
																	//windows + the door of the house
		else if(i>=12&&i<house_height-4){
			if(t<(house_width/2)-10||t>(house_width/2)+9){
					if(i==12||i==18||i==24||i==30||i==36){
						if(t>3&&t<20){
								printf("=");
						}
				
					else if(t>47&&t<64){
						printf("=");
				}
				else{
						printf(" ");
				}
				}
				
				else if(i>12&&i<36){
				
					if(t==4||t==19||t==48||t==63)
					{
						
						printf("=");
					}
					else if(t==9||t==14||t==53||t==58){
						printf("+");
					}
					else{
						printf(" ");
					}
				}
				else{
					printf(" ");
				}
				
				}
			else{
				printf("&");
			}
			}
																//the blank space of the last two line of the house								
			else{
					printf(" ");
		}
		
	}
	}
	printf("\n");
}
}

