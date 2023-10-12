#include <stdio.h>
#include <stdlib.h> 
int main(void)
{
const int r_top = 40;// Declare the top of the roof
const int r_side = 16;// Declare the side of the roof
const int r_bottom = 72;// Declare the bottom of the roof
const int d_width = 20;// Declare the width of the door
const int d_height = 28;// Declare the height of the door
const int w_width = 16;// Declare the width of the window
const int w_height = 25;// Declare the height of the window
const int wg_width = 4;// Declare the width of the window glass
const int wg_height = 5;// Declare the height of the window glass
const int wcf_thickness = 2;// Declare the thickness of wall/ceiling/floor
const int wdc_space = 10;// Declare the space from the window/door to the ceiling
const int fd_space = 2;// Declare the space between the floor and the door
const int fw_space = 5;// Declare the space between the floor and the window
const int ww_space = 2;// Declare the space from the window to the wall 
const int wd_space = 4;// Declare the space between the window and the door
const int h_total_width = 72;// Declare the total width of the house 
const int h_total_height = 62;// Declare the total height of the house
const int h_exterior_width = 68;//Declare the exterior width of the house
const int h_exterior_height = 44;//Declare the exterior height of the house
const int h_interior_width = 64;//Declare the interior width of the house
const int h_interior_height = 40;//Declare the interior height of the house
const int HOUSE_LEFT_MARGIN = 4;//Declare the house left margin

system("pause");

//print the prelude message
	printf("***** Design parameters of house:\n");
    printf("   <<< The top of the roof: %d\n", r_top);
    printf("   <<< The side of the roof: %d\n", r_side);
    printf("   <<< The bottom of the roof: %d\n", r_top + 2 * r_side);
    printf("   <<< The width of the door: %d\n", d_width);
    printf("   <<< The height of the door: %d\n", d_height);
    printf("   <<< The width of the window: %d\n", w_width);
    printf("   <<< The height of the window: %d\n", w_height);
    printf("   <<< The width of the window glass: %d\n", wg_width);
    printf("   <<< The height of the window glass: %d\n", wg_height);
    printf("   <<< The thickness of wall/ceiling/floor: %d\n", wcf_thickness);
    printf("   <<< The space from the window/door to the ceiling: %d\n", wdc_space);
    printf("   <<< The space between the floor and the door: %d\n", fd_space);
    printf("   <<< The space between the floor and the window: %d\n", fw_space);
    printf("   <<< The space from the window to the wall: %d\n", ww_space);
    printf("   <<< The space between the window and the door: %d\n", wd_space);
    printf("\n");
	printf("***** The house design is valid:\n");
    printf("   >>> The total width of the house: %d\n", h_total_width);
    printf("   >>> The total height of the house: %d\n", h_total_height);
    printf("   >>> The exterior width of the house: %d\n", h_exterior_width);
    printf("   >>> The exterior height of the house: %d\n", h_exterior_height);
    printf("   >>> The interior width of the house: %d\n", h_interior_width);
    printf("   >>> The interior height of the house: %d\n", h_interior_height);


// The top of the roof

    int i,j,k,l ; //Variables i,j,k, and l
    for(i=0; i< r_side+HOUSE_LEFT_MARGIN; ++i){
        printf(" ");// Print the left top of the roof margin
    }
    for(i=0; i< r_top; ++i){
        printf("#");// Print the top of the roof
    }
	printf("\n");// Print the newline.
// roof
	for(i=0; i< r_side; ++i){  //It suggests that the code will execute r_side times for different values of i.
		for(j=0; j< r_side+HOUSE_LEFT_MARGIN-1-i+(h_total_width-r_bottom)/2; ++j){
			printf(" ");//statement is used to print a single space character.
		}
		printf("#");
		for(j=0; j< r_top+2*i; ++j){
			printf("*");
		}
		printf("\n");// Print the newline.

	}

//The top of the roof
    for(i=0; i< HOUSE_LEFT_MARGIN+(h_total_width-r_bottom)/2; ++i){
        printf(" ");// To print spaces before printing the roof of the house. 
    }
    for(i=0; i< r_bottom; ++i){
        printf("#");// To print the roof of the house.
    }
	printf("\n");// Print the newline.

	for(i=0; i<wcf_thickness; ++i){ //It suggests that the code will execute wcf_thickness times for different values of i.
        for(j=0; j<HOUSE_LEFT_MARGIN+(h_total_width-h_exterior_width )/2;++j){
            printf(" ");
        }

        for(j=0; j<h_exterior_width; ++j){
            printf("@");
        }
    printf("\n");// Print the newline.
	}
//wall
    for(i=0; i<wdc_space; ++i){ //It suggests that the code will execute wdc_space times for different values of i.
        for(j=0; j<HOUSE_LEFT_MARGIN+(h_total_width-h_exterior_width )/2;++j){
            printf(" "); 
        }
        for(j=0; j<wcf_thickness;++j){ 
            printf("@"); // To print an at symbol ('@').
        }

        for(j=0; j<h_interior_width; ++j){
            printf(" ");
        }
        for(j=0; j<wcf_thickness;++j){
            printf("@"); // To print an at symbol ('@').
        }
        printf("\n");// Print the newline.

    }
//the glass of window
    for(i=0;i<(w_height-1)/(wg_height+1);++i){
        //window frame
        for(j=0; j<HOUSE_LEFT_MARGIN+(h_total_width-h_exterior_width )/2;++j){
            printf(" ");

        }
        for(j=0; j<wcf_thickness;++j){
            printf("@"); // To determine the thickness of the window frame and prints '@' characters.
        }
        for(j=0; j<ww_space; ++j){
            printf(" "); //To create space between the window frame and the window content.
        }
        for(j=0;j<w_width;++j){
             printf("="); // To print '=' characters.
        }
        for(j=0; j<wd_space; ++j){
             printf(" "); //To create space between the window frame and the door content.
        }
        for(j=0; j<d_width; ++j){
             printf("&"); //To print the window content, which consists of '&' characters. It iterates d_width times.
        }
        for(j=0;j<wd_space; ++j){
             printf(" "); //To create space between the window frame and the door content.
        }
        for(j=0;j<w_width;++j){
             printf("="); // To print '=' characters.
        }
        for(j=0; j<ww_space; ++j){
             printf(" "); //To create space between the window frame and the window content.
        }
        for(j=0; j<wcf_thickness;++j){
             printf("@"); // To print an at symbol ('@').
        }
        printf("\n");// Print the newline.
        // Window
        for(l=0; l<wg_height;++l){
            for(j=0; j<HOUSE_LEFT_MARGIN+(h_total_width-h_exterior_width )/2;++j){
                printf(" ");

            }
             for(j=0; j<wcf_thickness;++j){
                printf("@"); // To print an at symbol ('@').
            } 
            for(j=0; j<ww_space; ++j){ //To create space between the window frame and the window content.
                printf(" ");
            }
            printf("=");
            for(j=0; j<(w_width-1)/(wg_width+1)-1;++j){ //This loop determines how many times the horizontal divisions should be repeated based on the width of the window w_width and the width of the grid cells wg_width.
                for(k=0; k<wg_width; ++k){ //To create the appearance of empty grid cells within the window content.
                    printf(" ");
                }
                printf("+");

            }
            for(j=0; j<wg_width; ++j){
                printf(" "); // To create space between the window glass.
            }
            printf("="); // To print an at symbol ('=').
            for(j=0;j<wd_space; ++j){
                printf(" ");
            }
            for(j=0; j<d_width; ++j){
                 printf("&");
            }
            for(j=0;j<wd_space; ++j){
                printf(" ");
            }

            printf("=");
            for(j=0; j<(w_width-1)/(wg_width+1)-1;++j){
                for(k=0; k<wg_width; ++k){
                    printf(" ");
                }
                printf("+");

            }
            for(j=0; j<wg_width; ++j){
                printf(" ");
            }
            printf("=");
            for(j=0; j<ww_space; ++j){
                printf(" ");
            }
            for(j=0; j<wcf_thickness;++j){
                printf("@"); // To print an at symbol ('@').
            }
            printf("\n");// Print the newline.
        }
    }
    for(j=0; j<HOUSE_LEFT_MARGIN+(h_total_width-h_exterior_width )/2;++j){
        printf(" ");

    }
    for(j=0; j<wcf_thickness;++j){
        printf("@");
    }
    for(j=0; j<ww_space; ++j){
        printf(" ");
    }
    for(j=0;j<w_width;++j){
         printf("=");
    }
    for(j=0; j<wd_space; ++j){
         printf(" ");
    }
    for(j=0; j<d_width; ++j){
         printf("&");
    }
    for(j=0;j<wd_space; ++j){
         printf(" ");
    }
    for(j=0;j<w_width;++j){
         printf("=");
    }
    for(j=0; j<ww_space; ++j){
         printf(" ");
    }
    for(j=0; j<wcf_thickness;++j){
         printf("@");
    }
    printf("\n");// Print the newline.

    for(k=0; k<d_height-w_height;++k){
        for(j=0; j<HOUSE_LEFT_MARGIN+(h_total_width-h_exterior_width )/2;++j){
                printf(" ");

        }
        for(j=0; j<wcf_thickness;++j){
            printf("@");
        }
        for(j=0; j<ww_space+w_width+wd_space; ++j){
            printf(" ");
        }
        for(j=0; j<d_width; ++j){
            printf("&");
        }
        for(j=0; j<ww_space+w_width+wd_space; ++j){
            printf(" ");
        }
        for(j=0; j<wcf_thickness;++j){
            printf("@");
        }

        printf("\n");// Print the newline.
    }
    for(i=0;i<fd_space;++i){
        for(j=0; j<HOUSE_LEFT_MARGIN+(h_total_width-h_exterior_width )/2;++j){
                printf(" ");

        }
        for(j=0; j<wcf_thickness;++j){
            printf("@");
        }
        for(j=0;j<h_interior_width;++j){
            printf(" ");
        }
        for(j=0; j<wcf_thickness;++j){
            printf("@");
        }
        printf("\n");// Print the newline.
    }
    for(i=0;i<wcf_thickness;++i){
        for(j=0; j<HOUSE_LEFT_MARGIN+(h_total_width-h_exterior_width )/2;++j){
                printf(" ");

        }
        for(j=0;j<h_exterior_width;++j){
            printf("@");
        }
        printf("\n");// Print the newline.
    }
    return 0;
    if (h_total_width == h_total_width && h_total_height == h_total_height) {
        printf("\n***** The house design is valid:\n");
        printf("   >>> The total width of the house: %d\n", h_total_width);
        printf("   >>> The total height of the house: %d\n", h_total_height);
        // verify other dimensions
    } else {
        // Invalid design
        printf("\n***** The house design is not valid. Dimensions do not match expected values.\n");
    }

}








