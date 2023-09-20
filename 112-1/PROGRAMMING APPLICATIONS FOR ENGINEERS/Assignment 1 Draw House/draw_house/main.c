#include <stdio.h>

int main ()
{
    int roof_top , roof_side , roof_bottom , house_width , house_height , door_width , door_height ;
    int window_width=9 , window_height=13 ;
    // Input information
    do
    {
        printf(">>> Enter the width of the roof top (10 to 20): ") ;
        scanf("%d" , &roof_top) ;
    }
    while (roof_top<10 || roof_top>20) ;
    do
    {
        printf(">>> Enter the isosceles side of the roof (10 to 25): ") ;
        scanf("%d" , &roof_side) ;
    }
    while (roof_side<10 || roof_side>25) ;
    roof_bottom = roof_top + 2*roof_side ;
    printf(">>> The width of the roof bottom r_bottom is r_top+2*r_side %d.\n" , roof_bottom) ;
    do
    {
        printf(">>> Enter the width of the house (<44 and (r_bottom, h_width) both even or odd): ") ;
        scanf("%d" , &house_width) ;
    }
    while (house_width<0 || house_width>44 || (house_width&1)!=(roof_bottom&1) || house_width>=roof_bottom-4) ;
    do
    {
        printf(">>> Enter the height of the house (<42): ") ;
        scanf("%d" , &house_height) ;
    }
    while (house_height<0 || house_height>42 || house_height>house_width) ;

    printf("\n\n") ;
    printf("***** Design parameters of the house:\n") ;
    printf("   <<< The top of the roof: %d" , roof_top) ;
    printf("   <<< The side of the roof: %d" , roof_side) ;
    printf("   <<< The bottom of the roof: %d" , roof_bottom) ;
    printf("   <<< The width of the house: %d" , house_width) ;
    printf("   <<< The height of the house: %d" , house_height) ;
    printf("   <<< The width of the window: %d" , window_width) ;
    printf("   <<< The height of the window: %d" , window_height) ;
    printf("   <<< The width of the door: %d" , roof_top) ;
    printf("   <<< The height of the door: %d" , roof_top) ;
    printf("   <<< The space from the window/door to the ceiling: %d" , roof_top) ;
    printf("   <<< The space from the window to the wall: %d" , roof_top) ;
    printf("   <<< The space between the window and the door: %d" , roof_top) ;
    printf("   <<< The space between the floor and the door: %d" , roof_top) ;
    printf("\n\n") ;

    for (int i=0 ; i<roof_top ; ++i)
    {
        printf("@") ;
    }
    printf("\n") ;
    for (int i=1 ; i<=roof_side ; ++i)
    {
        for (int j=roof_side ; j>=i ; --i)
        {
            printf(" ") ;
        }
        printf("@") ;
        for (int j=0 ; j<roof_top+2*roof_side ; ++j)
        {
            printf("*") ;
        }
        printf("@\n") ;
    }
    for (int i=0 ; i<roof_bottom ; ++i)
    {
        printf("@") ;
    }
    printf("\n") ;
    return 0;
}
