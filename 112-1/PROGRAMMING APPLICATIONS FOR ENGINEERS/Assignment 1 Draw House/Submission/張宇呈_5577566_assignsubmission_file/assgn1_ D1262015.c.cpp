#include <stdio.h>

int main() {
    int width = 68;
    int height = 12;
    int upBase = 40;
    int sideBase = 16;
    int downBase = upBase + 2 * sideBase;
    int j, space,i;
    int househight = 43 ;
    printf("***** Design parameters of the house :\n");
    printf(">>>the upBase of the roof is : %d\n", upBase);
    printf(">>>the side of the roof is : %d\n",sideBase);
    printf(">>>the downBase of the roof is¡G%d\n", upBase + 2*sideBase);
    printf(">>>the waith of the houuse is : 68 \n");
    printf(">>>The width of the door: 20 \n");
    printf(">>>The height of the door: 28 \n");
    printf(">>>The width of the window: 16 \n");
    printf(">>>The height of the window: 25 \n");
    printf(">>>The width of a window glass: 4 \n");
    printf(">>>The height of a window glass: 5 \n");
    printf(">>>The thickness of wall/ceiling/floor: 2 \n");
    printf(">>>The space from the window/door to the ceiling: 10 \n");
    printf(">>>The space between the floor and the door: 2 \n");
    printf(">>>The space from the window to the wall: 2 \n");
    printf(">>>The space between the floor and the window: 5 \n");
    printf(" \n");
    printf("***** The house design is valid \n");
    printf(">>>The total width of the house: 72 \n");
    printf(">>>The total height of the house: 62 \n");
    printf(">>>The exterior width of the house: 68 \n");
    printf(">>>The exterior height of the house: 44 \n");
    printf(">>>The interior width of the house: 64 \n");
    printf(">>>The interior height of the house: 40 \n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    // height of the roof
    for (i = 1; i <= (downBase - upBase)/2 + 1; i++) {
        // to control hoe many spaces should be printed
        for (space = 1; space <= (upBase/2-i); space++) {
            printf(" ");
        }
        
        for (j = 1; j <= upBase + 2 * (i - 1); j++) {
            if (i == 1 || j == 1 || j == upBase + 2 * (i - 1)) {
                printf("#");
            } else {
                printf("*");
            }
        }
        
        printf("\n");
    }
    //print the down base of the roof
    for (j=1; j < (upBase/2 - sideBase) ; j++){
    	printf(" ");
    }
    
    for (j=1; j <= downBase ; j++){
    	printf("#");
    }
    printf("\n");
    
    
    for (int i = 0; i <=househight; i++) {
        for (int k = 0; k <=4; k++) {
            printf(" ");
        }
        //print the structure of the house
	  for (int j = 0; j < width; j++) {
            if ( j == 0 ||j == 1 ||j == width - 2 || j == width - 1|| i== househight || i== househight-1||i==1||i==0) {
                printf("@");
            }
		//print door
            else if (i>=12&&i<=39&&j>=24&&j<=43) {
            	printf("&");
		}
		//print left window
		else if (j>=4&&j<=19&&(i==height||i==18||i==24||i==30||i==36)){
			printf("=");
		}
		//print right window
		else if (j>=48&&j<=63&&(i==height||i==18||i==24||i==30||i==36)){
			printf("=");
		}
		//print "=" inside the windows 
		else if ((j==4||j==19||j==48||j==63)&&((i>=13&&i<=17)||(i>=19&&i<=23)||(i>=25&&i<=29)||(i>=31&&i<=35))){
			printf("=");
		}
		//print "+" inside the windows
		else if ((j==9||j==14||j==53||j==58)&&((i>=13&&i<=17)||(i>=19&&i<=23)||(i>=25&&i<=29)||(i>=31&&i<=35))){
			printf("+");
		}
		else {
                printf(" ");
            }
        }
      
        printf("\n");
    }
    
        
	    
	    
	    
      
    	
    	
    
    return 0;
}
        
    
        	




