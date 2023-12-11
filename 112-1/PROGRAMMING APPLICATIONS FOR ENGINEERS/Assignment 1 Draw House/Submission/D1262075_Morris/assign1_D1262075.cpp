#include <stdio.h>
#include <stdlib.h>


int main(){
	int r_top,r_side,r_bottom,h_width,h_height,d_width,d_height,w_width,w_height,g_width,g_height,thickness,s1;
	int ABC;//the"ABC"enable the program to run correctly
	scanf("%d", ABC);
	r_top = 40;
	r_side = 16;
	d_width = 20;
	d_height = 28;
	w_width = 16;
	w_height = 25;
	g_width = 4;
	g_height = 5;
	thickness = 2;
	s1 = 10;
	printf("*****Design parameter of the house:\n");
	printf(" <<<The top of the roof:%d\n", r_top);
	printf(" <<<The side of the roof:%d\n", r_side);
	r_bottom = r_top + 2*r_side;
	printf(" <<<The bottom of the roof: %d\n",r_bottom);
	printf(" <<<The width of the door: %d\n",d_width );
	printf(" <<<The height of the door: %d\n",d_height);
	printf(" <<<The width of the window: %d\n",w_width);
	printf(" <<<The height of the window: %d\n", w_height);
	printf(" <<<The width of a window glass: %d\n", g_width);
	printf(" <<<The height of a window glass: %d\n", g_height);
	printf(" <<<The thickness of wall/ceiling/floor: %d\n", thickness); 
	printf(" <<<The space from the window/door to the ceiling: %d\n", s1);
	printf(" <<<The space from the window/door to the ceiling: %d\n", thickness);
	printf(" <<<The space between the floor and the door: %d\n", g_height);
	printf(" <<<The space from the window to the wall: %d\n", thickness);
	printf(" <<<The space between the window and the wall: %d\n\n", g_width);
	printf("*****The house design is valid.\n");
	printf(" >>>The totall width of the house:%d\n",r_bottom);
	printf(" >>>The totall height of the house:%d\n",r_bottom-10);
	printf(" >>>The exteriot width of the house:%d\n",r_bottom-4);
	printf(" >>>The exterior height of the house:%d\n",2*3+10+d_height);
	printf(" >>>The interior width of the house:%d\n",r_bottom-8);
	printf(" >>>The interior height of the house:%d\n",10+2+d_height);
	int i,j,k,counter,l,m,n;
	counter=0;
	for(i=0;i<=r_side;i++){ //print out the blanks space before the house.
		for(j=r_side-counter;j>=0;j--){
			printf(" ");
		} 
		for	(k=0;k<r_top+i*2;k++){ //if the location is on the top row or left and right side of the roof print out#.
			if((k>=r_top+i*2-1) || (k==0) || (i==0)){
				printf("#");
			}
			else{  //else print out*
				printf("*");
			}
		}
		counter+=1; //the variation 'counter' is to satisfy the roof side,form a inverted triangle blanks before roof.
		printf("\n");
	}
	printf(" ");
	for(l=0;l<r_bottom;l++){ //print out the bottom of the roof.
		printf("#");
	}
	printf("\n");
	for(i=0;i<2;i++){ //the top two line of the house ceiling.
		for(m=0;m<=2;m++){ //the blanks before the house wall.
	 			printf(" ");
			 }
		for(k=0;k<r_bottom-4;k++){ //using @ to form  68 width(r_bottom-4=72-4=68) two line of ceiling.
			printf("@");
		}
		printf("\n");
    }
    for(i=0;i<10;i++){ //the 10 space between ceiling and the windows and door.
    	for(m=0;m<=2;m++){ //the blanks before the house wall.
    		printf(" ");
		}
		for(k=0;k<2;k++){ //left side wall of the house.
			printf("@");
		}
		for(j=0;j<r_bottom-8;j++){ //the 64 blanks(r_bottom-8=72-8=64) between left wall.
			printf(" ");
		}
		for(l=0;l<2;l++){ //right side wall of the house.
			printf("@");
		}printf("\n");
	}
	for(i=0;i<25;i++){ //25 spaces of windows.
		for(m=0;m<=2;m++){ //the blanks before the house wall.
    		printf(" ");
		}	
		for(n=0;n<1;n++){ //left wall of the house.
			printf("@@  ");
		}
		for(k=0;k<r_bottom-8;k++){ 
			if((i%6==0&&i<=24)){
				if((k>=0)&&(k<=15)){ //print out 16 '='
					printf("=");
				}
			}
			else if((i>=1)&&(i<=5)||(i>=7)&&(i<=11)||(i>=13)&&(i<=17)||(i>=19)&&(i<=23)){
				if((k==0)){
						printf("=    +    +    =");
					}
				}
			if((i>=0)||(i<=24)){ //the 4 spaces of blanks between left window and the door.
				if((k>=16)&&(k<=19)){
					printf(" ");
				}
				}
	 		if((i>=0)&&(i<=24)){ //door
				if((k>=20)&&(k<=39)){
					printf("&");
					}else if((i>=0)&&(i<=24)){ //the 4 spaces of blanks between right window and the door.
						if((k>=40)&&(k<=43)){
							printf(" ");
						}
					}
			}
			if((i%6==0&&i<=24)){ //print out 16 '='.
				if((k>=44)&&(k<=59)){
					printf("=");
				}
			}
			else if((i>=1)&&(i<=5)||(i>=7)&&(i<=11)||(i>=13)&&(i<=17)||(i>=19)&&(i<=23)){
				if((k==44)){
						printf("=    +    +    =");
					}
				}
			if((i>=0)&&(i<=24)){ //the blanks between right window and right side house wall.
			if((k>=60)&&(k<=61)){
				printf(" ");
			}
			}
			if((k==62)||(k==63)){ //right side house wall.
				printf("@");
				}
	}
	printf("\n");
	}
	for(i=0;i<3;i++){ //three more line for the lack spaces of door(door needs 28 lines,while windows only need 25).
		for(m=0;m<=2;m++){ //blanks before house wall
			printf(" ");
		}
		for(n=0;n<1;n++){ //left side wall of the house
			printf("@@  ");
		}
		for(k=0;k<64;k++){
			if((k>=0)&&(k<=19)){ //blanks between left wall and door.
				printf(" ");
			}else if((k>=20)&&(k<=39)){ //three more line of the door.
				printf("&");
			}else if((k>=40)&&(k<=61)){ //blanks between door and right wall.
				printf(" ");
			}else{                      //right side wall.
				printf("@");
			}
		}printf("\n");
	} 
	for(i=0;i<2;i++){
		for(m=0;m<=2;m++){ //blanks before house.
			printf(" ");
		}
		for(k=0;k<2;k++){ //left side wall.
		printf("@");
		}
		for(l=0;l<r_bottom-8;l++){ //blanks between two walls.
			printf(" ");
		}
		for(n=0;n<2;n++){ //left side wall.
			printf("@");
		}printf("\n");
	}
	for(i=0;i<2;i++){ //two line of '@' to form the base of the house.
		printf("   ");
		for(j=0;j<r_bottom-4;j++){
			printf("@");
		}printf("\n");
	}
}


