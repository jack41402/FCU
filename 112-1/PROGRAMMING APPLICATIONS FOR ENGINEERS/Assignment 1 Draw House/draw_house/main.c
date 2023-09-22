#include <stdio.h>

int main ()
{
    int roof_top , roof_side , roof_bottom , house_width , house_height , door_width , door_height ;
    int count , outside_space , inside_space ;
    const int window_width=9 , window_height=13 , gap_ceil_door=4 , gap_window_wall=2 , gap_window_door=2 , gap_floor_door=2 ;
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
        printf(">>> Enter the width of the house (<%d and (r_bottom, h_width) both even or odd): " , roof_bottom-4) ;
        scanf("%d" , &house_width) ;
        door_width = house_width - 26 ;
        if (door_width<12) printf("Door is too narrow.\n") ;
    }
    while (house_width<0 || house_width>roof_bottom-4 || (house_width&1)!=(roof_bottom&1) || house_width>=roof_bottom-4 || door_width<12) ;
    do
    {
        printf(">>> Enter the height of the house (<%d): " , house_width) ;
        scanf("%d" , &house_height) ;
        door_height = house_height - gap_ceil_door - gap_floor_door ;
        if (door_height<16) printf("Door is too narrow.\n") ;
    }
    while (house_height<0 || house_height>house_width || door_height<16) ;

    printf("\n\n") ;
    printf("***** Design parameters of the house:\n") ;
    printf("   <<< The top of the roof: %d\n" , roof_top) ;
    printf("   <<< The side of the roof: %d\n" , roof_side) ;
    printf("   <<< The bottom of the roof: %d\n" , roof_bottom) ;
    printf("   <<< The width of the house: %d\n" , house_width) ;
    printf("   <<< The height of the house: %d\n" , house_height) ;
    printf("   <<< The width of the window: %d\n" , window_width) ;
    printf("   <<< The height of the window: %d\n" , window_height) ;
    printf("   <<< The width of the door: %d\n" , door_width) ;
    printf("   <<< The height of the door: %d\n" , door_height) ;
    printf("   <<< The outside_space from the window/door to the ceiling: %d\n" , gap_ceil_door) ;
    printf("   <<< The outside_space from the window to the wall: %d\n" , gap_window_wall) ;
    printf("   <<< The outside_space between the window and the door: %d\n" , gap_window_door) ;
    printf("   <<< The outside_space between the floor and the door: %d\n\n" , gap_floor_door) ;

    // Roof
    for (int i=0 ; i<roof_side+2 ; ++i)
    {
        printf("    ") ;
        for (int j=0 ; j<roof_side-i ; ++j)
        {
            printf(" ") ;
        }
        printf("@") ;
        if (i!=0 && i!=roof_side+1)
        {
            for (int j=0 ; j<roof_side+i*2-2 ; ++j)
            {
                printf("*") ;
            }
        }
        else
        {
            if (i==0) count = roof_top - 2 ;
            else count = roof_bottom - 2 ;
            for (int j=0 ; j<count ; ++j)
            {
                printf("@") ;
            }
        }
        printf("@\n") ;
    }
    // House
    outside_space = (roof_bottom - house_width - 4) / 2 + 4 ;
    for (int i=0 ; i<gap_ceil_door ; ++i)
    {
        for (int j=0 ; j<outside_space ; ++j) printf(" ") ;
        printf("%%%%") ;
        for (int j=0 ; j<house_width ; ++j) printf(" ") ;
        printf("%%%%\n") ;
    }
    for (int i=0 ; i<window_height ; ++i)
    {
        for (int j=0 ; j<outside_space ; ++j) printf(" ") ;
        printf("%%%%") ;
        for (int j=0 ; j<gap_window_wall ; ++j) printf(" ") ;
        if (i==0 || i==4 || i==8 || i==12) printf("=========") ;
        else printf("=   +   =") ;
        for (int j=0 ; j<gap_window_door ; ++j) printf(" ") ;
        for (int j=0 ; j<door_width ; ++j) printf("@") ;
        for (int j=0 ; j<gap_window_door ; ++j) printf(" ") ;
        if (i==0 || i==4 || i==8 || i==12) printf("=========") ;
        else printf("=   +   =") ;
        for (int j=0 ; j<gap_window_wall ; ++j) printf(" ") ;
        printf("%%%%\n") ;
    }
    inside_space = gap_window_wall + window_width + gap_window_door ;
    for (int i=0 ; i<door_height-window_height ; ++i)
    {
        for (int j=0 ; j<outside_space ; ++j) printf(" ") ;
        printf("%%%%") ;
        for (int j=0 ; j<inside_space ; ++j) printf(" ") ;
        for (int j=0 ; j<door_width ; ++j) printf("@") ;
        for (int j=0 ; j<inside_space ; ++j) printf(" ") ;
        printf("%%%%\n") ;
    }
    for (int i=0 ; i<gap_floor_door ; ++i)
    {
        for (int j=0 ; j<outside_space ; ++j) printf(" ") ;
        printf("%%%%") ;
        for (int j=0 ; j<house_width ; ++j) printf(" ") ;
        printf("%%%%\n") ;
    }
    for (int i=0 ; i<2 ; ++i)
    {
        for (int j=0 ; j<outside_space ; ++j) printf(" ") ;
        for (int j=0 ; j<house_width+4 ; ++j) printf("%%") ;
        printf("\n") ;
    }
    return 0;
}
