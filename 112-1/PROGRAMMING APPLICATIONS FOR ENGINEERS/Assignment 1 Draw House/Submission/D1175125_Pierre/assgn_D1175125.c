//
//  main.c
//  assgn1_D1175125.c
//
//  Created by pierre huang on 2023/9/19.
//

#include <stdio.h>

int main(){
    int r_top, r_side, r_bottom, h_width, h_height, h_space, w_space, d_width;
    printf("Enter the width of the roof top (10 to 20): ");
    scanf("%d", &r_top);
    printf("Enter the isosceles side of the roof (10 to 25): ");
    scanf("%d", &r_side);
    r_bottom = r_top + r_side*2;
    printf("The width of the roof bottom r_bottom is r_top+r_side*2 %d\n", r_bottom);
    printf("Enter the width of the house (<=%d and(r_bottom, h_width) both even or odd): ", r_bottom-4);
    scanf("%d", &h_width);
    printf("Enter the height of the house (<=%d): ", h_width);
    scanf("%d", &h_height);
    printf("\n");
    h_space = h_height-23;
    w_space = (h_width/2)-18;
    if(r_bottom%2==1){
        d_width = 13;
    }else{
        d_width = 12;
    }
    printf("***** Design parameters of the house:");
    printf("The top of the roof: %d\n", r_top);
    printf("The side of the roof: %d\n", r_side);
    printf("The bottom of the roof: %d\n", r_bottom);
    printf("The width of the house: %d\n", h_width);
    printf("The height of the house: %d\n", h_height);
    printf("The width of the window: 9\n");
    printf("The height of the window: 13\n");
    printf("The width of the door: %d\n", d_width);
    printf("The height of the door: 17\n");
    printf("The space from the window/door to the ceiling: 4\n");
    printf("The space from the window to the wall: 1\n");
    printf("The space between the window and the door: %d\n", w_space);
    printf("The space between the floor and the door: %d\n", h_space);
    printf("\n");
    if(r_bottom%2==1){
        for(int i = 0; i<r_top+r_side; i++){
            if(i<r_side){
                printf(" ");
            }else{
                printf("@");
            }
        }
        printf("\n");
        for(int i = 0; i<r_side; i++){
            for(int j = 0; j<r_side+r_top+i+1;j++){
                if(j<r_side-1-i){
                    printf(" ");
                }else if(j==r_side-i-1||j==r_side+r_top+i){
                    printf("@");
                }else{
                    printf("*");
                }
            }
            printf("\n");
        }
        for(int i = 0; i<r_bottom; i++){
            printf("@");
        }printf("\n");
        for(int i = 0; i<h_height; i++){
            for(int l = 0;l<(r_bottom-h_width)/2; l++){
                printf(" ");
            }
            for(int j = 0; j<h_width; j++){
               if(i<4){
                    if(j<2||j>h_width-3){
                        printf("%%");
                    }else{
                        printf(" ");
                    }
                }else if(i>=4&&i<17){
                    if(i==4||i==8||i==12||i==16){
                        if(j==0||j==1||j==h_width-1||j==h_width-2){
                            printf("%%");
                        }else if(j>((h_width/2)-7)&&j<((h_width/2)+7)){
                            printf("@");
                        }else if(j>2&&j<12){
                            printf("=");
                        }else if(j>h_width-13&&j<h_width-3){
                            printf("=");
                        }else{
                            printf(" ");
                        }
                    }else{
                        if(j==0||j==1||j==h_width-1||j==h_width-2){
                            printf("%%");
                        }else if(j==3||j==11||j==h_width-12||j==h_width-4){
                            printf("=");
                        }else if(j==7||j==h_width-8){
                            printf("+");
                        }else if(j>((h_width/2)-7)&&j<((h_width/2)+7)){
                            printf("@");
                        }else{
                            printf(" ");
                        }
                    }
                }else if(i>=17&&i<21){
                    if(j==0||j==1||j==h_width-1||j==h_width-2){
                        printf("%%");
                    }else if(j>((h_width/2)-7)&&j<((h_width/2)+7)){
                        printf("@");
                    }else{
                        printf(" ");
                    }
                }else if(i>=21&&i<h_height-2){
                    if(j<2||j>h_width-3){
                        printf("%%");
                    }else{
                        printf(" ");
                    }
                }else if(i==h_height-1||i==h_height-2){
                    printf("%%");
                }
            }printf("\n");
        }
    }else{
        for(int i = 0; i<r_top+r_side; i++){
            if(i<r_side){
                printf(" ");
            }else{
                printf("@");
            }
        }
        printf("\n");
        for(int i = 0; i<r_side; i++){
            for(int j = 0; j<r_side+r_top+i+1;j++){
                if(j<r_side-1-i){
                    printf(" ");
                }else if(j==r_side-i-1||j==r_side+r_top+i){
                    printf("@");
                }else{
                    printf("*");
                }
            }
            printf("\n");
        }
        for(int i = 0; i<r_bottom; i++){
            printf("@");
        }printf("\n");
        for(int i = 0; i<h_height; i++){
            for(int l = 0;l<(r_bottom-h_width)/2; l++){
                printf(" ");
            }
            for(int j = 0; j<h_width; j++){
               if(i<4){
                    if(j<2||j>h_width-3){
                        printf("%%");
                    }else{
                        printf(" ");
                    }
                }else if(i>=4&&i<17){
                    if(i==4||i==8||i==12||i==16){
                        if(j==0||j==1||j==h_width-1||j==h_width-2){
                            printf("%%");
                        }else if(j>((h_width/2)-7)&&j<((h_width/2)+6)){
                            printf("@");
                        }else if(j>2&&j<12){
                            printf("=");
                        }else if(j>h_width-13&&j<h_width-3){
                            printf("=");
                        }else{
                            printf(" ");
                        }
                    }else{
                        if(j==0||j==1||j==h_width-1||j==h_width-2){
                            printf("%%");
                        }else if(j==3||j==11||j==h_width-12||j==h_width-4){
                            printf("=");
                        }else if(j==7||j==h_width-8){
                            printf("+");
                        }else if(j>((h_width/2)-7)&&j<((h_width/2)+6)){
                            printf("@");
                        }else{
                            printf(" ");
                        }
                    }
                }else if(i>=17&&i<21){
                    if(j==0||j==1||j==h_width-1||j==h_width-2){
                        printf("%%");
                    }else if(j>((h_width/2)-7)&&j<((h_width/2)+6)){
                        printf("@");
                    }else{
                        printf(" ");
                    }
                }else if(i>=21&&i<h_height-2){
                    if(j<2||j>h_width-3){
                        printf("%%");
                    }else{
                        printf(" ");
                    }
                }else if(i==h_height-1||i==h_height-2){
                    printf("%%");
                }
            }printf("\n");
        }
    }
}
