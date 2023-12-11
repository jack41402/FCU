#include <stdio.h>
#include <stdlib.h>
//print n times of character c
void printChar(int n, char c){
    int i; //Loop variable
    for(i=0 ; i<n ; i++) printf("%c",c); // Each iteration print one character c.
}
int main(){
    int r_top, r_side, r_bottom, h_width, h_height;
    int i, j;
    do{
        printf("Enter the width of the roof top (10 to 20): ");
        scanf("%d", &r_top);
    }while((r_top < 10 || r_top > 20));

    do{
        printf("Enter the isosceles side of the roof (10 to 25): ");
        scanf("%d", &r_side);
    }while((r_side < 10 || r_side > 25));

    r_bottom = r_top + 2 * r_side;
    printf("The width of the roof bottom r_bottom is r_top+2*r_side %d.\n",r_bottom);

    do{
        printf("Enter the width of the house (<%d and (r_bottom,h_width) both even or odd): ",r_bottom-4);
        scanf("%d", &h_width);
    }while((h_width >= r_bottom-4));
    do{
        printf("Enter the height of the house (<%d): ",h_width);
        scanf("%d", &h_height);
    }while((h_height >= h_width));
    printf("\n");
    printf("***** Design parameters of the house:\n");
    printf("   <<< The top of the roof: %d\n", r_top);
    printf("   <<< The side of the roof: %d\n", r_side);
    printf("   <<< The botoom of the roof: %d\n", r_bottom);
    printf("   <<< The width of the house: %d\n", h_width);
    printf("   <<< The heigt of the house: %d\n", h_height);
    printf("   <<< The width of the window: 9\n");
    printf("   <<< The height of the window: 13\n");
    printf("   <<< The width of the door: %d\n",h_width-30);
    printf("   <<< The height of the door: %d\n",h_height-8);
    printf("   <<< The space from the window/door to the ceiling: 4\n");
    printf("   <<< The space from the window to the wall: 2\n");
    printf("   <<< The space between the window and the door: 2\n");
    printf("   <<< The space between the floor and the door: 2\n");
    printf("\n");
    printChar(r_side,' ');
    printChar(r_top, '@');
    printf("\n");
    for(i=0 ; i < r_side ; i++){
        printChar(r_side - i - 1, ' ');
        printChar(1, '@');
        printChar(2 * i + r_top, '*');
        printChar(1, '@');
        printf("\n");
    }
    printChar(r_bottom,'@');
    printf("\n");
    for(i=0 ; i < 4 ; i++){
        printChar((r_bottom-h_width)/2, ' ');
        printChar(2, '%');
        printChar(h_width-4,' ');
        printChar(2,'%');
        printf("\n");
    }
    for(i=0;i<3;i++){
        printChar((r_bottom-h_width)/2, ' ');
        printChar(2,'%');
        printChar(2,' ');
        printChar(9,'=');
        printChar(2,' ');
        printChar(h_width-30,'@');
        printChar(2,' ');
        printChar(9,'=');
        printChar(2,' ');
        printChar(2,'%');
        printf("\n");
        for(j=0;j<3;j++){
            printChar((r_bottom-h_width)/2, ' ');
            printChar(2,'%');
            printChar(2,' ');
            printChar(1,'=');
            printChar(3,' ');
            printChar(1,'+');
            printChar(3,' ');
            printChar(1,'=');
            printChar(2,' ');
            printChar(h_width-30,'@');
            printChar(2,' ');
            printChar(1,'=');
            printChar(3,' ');
            printChar(1,'+');
            printChar(3,' ');
            printChar(1,'=');
            printChar(2,' ');
            printChar(2,'%');
            printf("\n");
        }
    }
    printChar((r_bottom-h_width)/2, ' ');
    printChar(2,'%');
    printChar(2,' ');
    printChar(9,'=');
    printChar(2,' ');
    printChar(h_width-30,'@');
    printChar(2,' ');
    printChar(9,'=');
    printChar(2,' ');
    printChar(2,'%');
    printf("\n");
    for(i=0 ; i < h_height-21 ; i++){
        printChar((r_bottom-h_width)/2, ' ');
        printChar(2,'%');
        printChar(13,' ');
        printChar(h_width-30,'@');
        printChar(13,' ');
        printChar(2,'%');
        printf("\n");
    }
    for(i=0 ; i < 2 ; i++){
        printChar((r_bottom-h_width)/2, ' ');
        printChar(2,'%');
        printChar(h_width-4,' ');
        printChar(2,'%');
        printf("\n");
    }
    for(i = 0 ; i < 2 ; i++){
        printChar((r_bottom-h_width)/2, ' ');
        printChar(h_width,'%');
        printf("\n");
    }
}

