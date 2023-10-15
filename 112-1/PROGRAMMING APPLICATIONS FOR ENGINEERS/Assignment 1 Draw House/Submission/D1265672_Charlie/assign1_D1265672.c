#include <stdio.h>
void printHouse(int i, char a){
    int j;
    for (j=0; j<i; j++){
        printf("%c", a);// print char
    }
}
void windowd(int width_w, int i){
    int e, g;
    if (i%6==0){
        printHouse(width_w, '=');// print window frame
    }
    else{
        for (g=0; g<width_w; g++) {
            if (g == 0 || g == width_w-1) {
                printf("="); // print window left and right using '='
            }
            else if (g%5 == 0){
                printf("+"); // print the frame
            }
            else{
                printf(" "); // print the glass
            }
        }
    }
}
int main(void) {
    // Data
    int width_r = 40, side_r = 16, bottom_r = 72, width_h = 68, height_h = 44, width_d = 20, height_d = 28;
    int width_w = 16, height_w = 25, space_wdc = 10, space_ww = 2, space_wd = 4, space_fd = 2, thickness = 2, space = 3;
    int i;
       
    // Output
    printf("***** Design parameters of the house:\n");
    printf("   <<< The top of the roof: %d\n", width_r);
    printf("   <<< The side of the roof: %d\n", side_r);
    bottom_r = width_r + 2 * side_r;
    printf("   <<< The bottom of the roof: %d\n", bottom_r);
    printf("   <<< The width of the door: %d\n", width_d);
    printf("   <<< The height of the door: %d\n", height_d);
    printf("   <<< The width of the window: %d\n", width_w);
    printf("   <<< The height of the window: %d\n", height_w);
    printf("   <<< The width of a window glass: 4\n");
    printf("   <<< The height of a window glass: 5\n");
    printf("   <<< The thickness of wall/ceiling/floor: %d\n", thickness);
    printf("   <<< The space from the window/door to ceiling: %d\n", space_wdc);
    printf("   <<< The space between the floor and the door: %d\n", space_fd);
    printf("   <<< The space between the floor and the window: 5\n");
    printf("   <<< The space from the window to the wall: %d\n", space_ww);
    printf("   <<< The space between the window and the door: %d\n", space_wd);
    printf("\n");
    
    // Calculate
    int total_width = bottom_r; // roof bottom width must be larger than house width so total width equal to roof bottom
    int total_height = side_r + 2 + thickness*2 +space_wdc + height_d + space_fd; // calculate the total height of house
    int exterior_width = (thickness + space_ww + width_w + space_wd)*2 + width_d; // calculate the exterior_width
    int exterior_height = total_height - side_r - 2; // calculate the exterior_heigh
    int interior_width = exterior_width - thickness*2; // calculate the interior_width
    int interior_height = exterior_height - thickness*2; // calculate the interior_heigh
    
    // verify the house is valid or not
    if (bottom_r <= exterior_width || bottom_r%2 != exterior_width%2){
        printf("***** The house design is invalid.\n"); // print invalid
    }
    else{
        printf("***** The house design is valid.\n"); // print valid
    }
    
    // Output
    printf("   >>> The total width of the house: %d\n", total_width);
    printf("   >>> The total height of the house: %d\n", total_height);
    printf("   >>> The exterior width of the house: %d\n", exterior_width);
    printf("   >>> The exterior height of the house: %d\n", exterior_height);
    printf("   >>> The interior width of the house: %d\n", interior_width);
    printf("   >>> The interior height of the house: %d\n", interior_height);
    printf("\n\n\n");
    
    // Draw Roof
    printHouse(side_r+space, ' '); // draw space
    printHouse(width_r, '#'); // draw the top layer of roof
    printf("\n");
    
    int k = 1; // a variable use to count the space every time plus one
    int roof_a = width_r; // the width of roof = roof_a
    for (i=0; i<side_r; i++) {
        printHouse(side_r-k+space, ' '); // print the space
        k += 1;
        printf("#"); // print the frame of roof
        printHouse(roof_a, '*'); // print the middle of the roof
        printf("#\n"); // print the frame of roof
        roof_a += 2;
    }
    printHouse(space, ' '); // print space
    printHouse(bottom_r, '#'); // print the bottom layer of roof
    printf("\n");
    
    // Draw House
    // Top of the House
    for (i=0; i<thickness; i++) {
        printHouse((bottom_r-width_h)/2+space, ' '); // print space
        printHouse(width_h, '@'); // print the ceiling
        printf("\n");
    }
    
    for (i=0; i<space_wdc; i++) {
        printHouse((bottom_r-width_h)/2+space, ' '); // print space
        printf("@@"); // print wall
        printHouse(width_h-4, ' '); // print the middle of house
        printf("@@\n"); // print wall
}
    
    // Draw window and door
    for (i=0; i<height_w; i++) {
        printHouse((bottom_r-width_h)/2+space, ' '); // print space
        printf("@@"); // print wall
        printHouse(space_ww, ' '); // print the space between wall and window
        windowd(width_w, i); // print window
        printHouse(space_wd, ' '); // print the space between window and door
        printHouse(width_d, '&'); // print door
        printHouse(space_wd, ' '); // print the space between window and door
        windowd(width_w, i); // print window
        printHouse(space_ww, ' '); // print the space between wall and window
        printf("@@\n"); // print wall
    }
    
    // Draw door
    int interval = height_h-4-space_wdc-height_w-space_fd; // calculate the rest of the door that should be print
    for (i=0; i<interval; i++) {
        printHouse((bottom_r-width_h)/2+space, ' '); // print space
        printf("@@"); // print wall
        printHouse((width_h-4-width_d)/2, ' '); //print space
        printHouse(width_d, '&'); // print door
        printHouse((width_h-4-width_d)/2, ' '); // print space
        printf("@@\n"); // print wall
    }
    
    // Draw rest of the house
    for (i=0; i<space_fd; i++) {
        printHouse((bottom_r-width_h)/2+space, ' '); // print space
        printf("@@"); // print wall
        printHouse(width_h-4, ' '); // print space
        printf("@@\n"); // print wall
    }
    for (i=0; i<thickness; i++) {
        printHouse((bottom_r-width_h)/2+space, ' '); // print space
        printHouse(width_h, '@'); // print floor
        printf("\n");
    }
    
    return 0;
}

