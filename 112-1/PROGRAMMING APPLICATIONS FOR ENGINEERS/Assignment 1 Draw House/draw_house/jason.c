#include <stdio.h>

int main(void){
    int a,b,c,i,k,r_top,r_side,r_bottom,h_width,h_heigth,test;
    do{
        printf("Enter the width of the roof top (10 to 20):");
        scanf("%d",&r_top);
        if(r_top>=10&&r_top<=20){
            test=0;
        }
        else{
            test=1;
            printf("Your data is wrong, please re-enter it!\n");
        }
    }while(test==1);
    do{
        printf("Enter the isosceles side of the roof (10 to 25):");
        scanf("%d",&r_side);
        if(r_side>=10&&r_side<=25){
            test=0;
        }
        else{
            test=1;
            printf("Your data is wrong, please re-enter it!\n");
        }
    }while(test==1);
    printf("The width of the roof bottom r_bottom is r_top+2*r_side %d.\n",r_top+2*r_side);
    do{
        printf("Enter the width of the house (<%d and (r_botton,h_width) both even or odd): ",r_top+2*r_side-4);
        scanf("%d",&h_width);
        if(h_width<r_top+2*r_side-4&&h_width%2==(r_top+2*r_side)%2){
            if(h_width>=38){
                test=0;
            }
            else{
                printf("h_width is too small to make a door. Please re-enter it!\n");
                test=1;
            }
        }
        else{
            printf("Your data is wrong, please re-enter it!\n");
            test=1;
        }
    }while(test==1);
    do{
        printf("Enter the heigth of the house (<%d): ",h_width);
        scanf("%d",&h_heigth);
        if(h_heigth<h_width){
            if(h_heigth>=28){
                test=0;
            }
            else{
                printf("h_heigth is too small to make a door. Please re-enter it!\n");
                test=1;
            }
        }
        else{
            printf("Your data is wrong, please re-enter it!\n");
            test=1;
        }
    }while(test==1);
    r_bottom=r_top+2*r_side;

    for(i=0;i<r_side;i++){
        printf(" ");
    }
    for(i=0;i<r_top;i++){
        printf("@");
    }
    printf("\n");
    int j=r_top;
    for(i=r_side;i>0;i--){
        for(k=i-1;k>0;k--){
            printf(" ");
        }
        printf("@");
        for(k=1;k<=j;k++){
            printf("*");
        }
        printf("@");
        j=j+2;
        printf("\n");
    }
    for(i=0;i<r_top+2*r_side;i++){
        printf("@");
    }
    printf("\n");
    for(i=1;i<=h_heigth;i++){
        if(i<=6||i>=h_heigth-5&&i<=h_heigth){
            for(k=1;k<=(r_bottom-h_width-4)/2;k++){
                printf(" ");
            }
            printf("%%%%");
            for(k=0;k<h_width;k++){
                printf(" ");
            }
            printf("%%%%");
        }
        else if(i==7||i==11||i==15||i==19){
            for(k=1;k<=(r_bottom-h_width-4)/2;k++){
                printf(" ");
            }
            printf("%%%%");
            for(k=1;k<=h_width;k++){
                if(k==1||k==2||k==12||k==13||k==h_width-12||k==h_width-11||k==h_width-1||k==h_width){
                    printf(" ");
                }
                else if(k>=3&&k<=11||k>=h_width-10&&k<=h_width-2){
                    printf("=");
                }
                else{
                    printf("@");
                }
            }
            printf("%%%%");
        }
        else if(i>=8&&i<=10||i>=12&&i<=14||i>=16&&i<=18){
            for(k=1;k<=(r_bottom-h_width-4)/2;k++){
                printf(" ");
            }
            printf("%%%%");
            for(k=1;k<=h_width;k++){
                if(k==1||k==2||k==12||k==13||k==h_width-12||k==h_width-11||k==h_width-1||k==h_width){
                    printf(" ");
                }
                else if(k>=4&&k<=6||k>=8&&k<=10||k>=h_width-9&&k<=h_width-7||k>=h_width-5&&k<=h_width-3){
                    printf(" ");
                }
                else if(k==3||k==11||k==h_width-10||k==h_width-2){
                    printf("=");
                }
                else if(k==7||k==h_width-6){
                    printf("+");
                }
                else{
                    printf("@");
                }
            }
            printf("%%%%");
        }
        else if(i>=20&&i<=h_heigth-6){
            for(k=1;k<=(r_bottom-h_width-4)/2;k++){
                printf(" ");
            }
            printf("%%%%");
            for(k=1;k<=h_width;k++){
                if(k>=14&&k<=h_width-13){
                    printf("@");
                }
                else{
                    printf(" ");
                }
            }
            printf("%%%%");
        }

        printf("\n");
    }

    for(i=1;i<=2;i++){
        for(k=1;k<=(r_bottom-h_width-4)/2;k++){
            printf(" ");
        }
        for(k=1;k<=h_width+4;k++){
            printf("%%");
        }
        printf("\n");
    }


    return 0;
}
