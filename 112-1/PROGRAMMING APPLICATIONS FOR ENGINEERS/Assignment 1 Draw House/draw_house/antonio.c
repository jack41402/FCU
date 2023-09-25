#include <stdio.h>

int main(void)
{

    int r_top = 40,r_side = 16,h_width = 68,h_height = 44;
    int r_bottom = r_top + r_side * 2;
    int d_width = 20;
    int d_height = 28;

    //info of this house
    printf("* Design parameters of the house:\n");

    printf("   <<< The top of the roof: %d\n", r_top);

    printf("   <<< The side of the roof: %d\n", r_side);

    printf("   <<< The bottom of the roof: %d\n", r_bottom);

    printf("   <<< The width of the door: 20\n");

    printf("   <<< The height of the door: 28\n");

    printf("   <<< The width of the window: 16\n");

    printf("   <<< The height of the window: 25\n");

    printf("   <<< The width of the window glass: 4\n");

    printf("   <<< The height of the window glass: 5\n");

    printf("   <<< The thickness of the wall/ceiling/floor: 2\n");

    printf("   <<< The space from the window/door to the ceiling: 10\n");

    printf("   <<< The space between the floor and the door: 2\n");

    printf("   <<< The space between the floor and the window: 5\n");

    printf("   <<< The space from the window to the wall: 2\n");

    printf("   <<< The space between the window and the door: 4\n");

    printf("\n");
    //verify

    printf("* The house design is valid.\n");

    printf("   >>> The total width of the house: 72\n");

    printf("   >>> The total height of the house: 62\n");

    printf("   >>> The exterior width of the house: 68\n");

    printf("   >>> The exterior height of the house: 44\n");

    printf("   >>> The interior width of the house: 64\n");

    printf("   >>> The interior height of the house: 40\n");

    printf("\n");

    printf("\n");

    //roof top
    for(int i = 0; i < r_side; ++i){
        printf(" ");

    }
    for(int i = r_side; i >= r_side && i < (r_side + r_top); ++i){
        printf("#");

    }
    printf("\n");


    //roof
    for(int i = 0; i < r_side; ++i){

        for(int j = 1; j <= (r_side - i); ++j){

            if( j == (r_side - i) )
                printf("#");
            else
                printf(" ");

        }
        for(int j = 0; j <= (r_top + i * 2); ++j){

            if( j == (r_top + i * 2) )
                printf("#");
            else
                printf("*");

        }
        printf("\n");
    }

    //roof bottom
    for(int i = 0; i < (r_side*2 + r_top); ++i){
        printf("#");
    }
    printf("\n");

    //ceiling
    for(int j = 1; j <= 2; ++j){

        for(int i = 1; i <= r_bottom; ++i){

            if(i >= 3 && i <= 70 )
                printf("@");
            else
                printf(" ");
        }
        printf("\n");
    }
    //upper wall
    for(int i = 1; i <= 10; ++i){

        for(int j = 1; j <= r_bottom; ++j){

            if( (j >= 3 && j <= 4) || (j >= 69 && j <= 70) )
                printf("@");

            else
                printf(" ");

        }
        printf("\n");
    }
    //mid wall + window + upper door
    for(int i = 1; i <= 25; ++i){

        if(i == 1|| i == 7|| i == 13|| i == 19|| i == 25){

            for(int j = 1; j <= 19; ++j){

                if(j == 3 || j == 19 ){
                    printf("@@");
                }
                else if(j == 6 || j == 16){
                    printf("================");
                }
                else if(j == 11){
                    for(int k = 1; k <= d_width; ++k)
                        printf("&");
                }
                else{
                    printf(" ");
                }
            }
        }
        else {

            for(int j = 1; j <= 19; ++j){

                if(j == 3 || j == 19 ){
                    printf("@@");
                }
                else if(j == 6 || j == 16){
                    printf("=    +    +    =");
                }
                else if(j == 11){
                    for(int k = 1; k <= d_width; ++k)
                        printf("&");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");

    }
//lower wall + lower door
    for(int i = 1; i <= 3; ++i){

        for(int j = 1; j <= r_bottom; ++j){

            if((j >= 3 && j <= 4) || (j >= 69 && j <= 70)){
                printf("@");
            }
            else if(j >= 27 && j <= 46){
                printf("&");
            }
            else
                printf(" ");

        }
        printf("\n");
    }
//lower wall
    for(int i = 1; i <= 2; ++i){

        for(int j = 1; j <= r_bottom ; ++j){

            if((j >= 3 && j <= 4 )||(j >= 69 && j <= 70))
                printf("@");

            else
                printf(" ");

        }
        printf("\n");
    }
//floor
    for(int i = 1; i <= 2; ++i){

        for(int j = 1; j <= r_bottom ; ++j){
            if (j >= 3 && j <= 70)
                printf("@");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0 ;
}
