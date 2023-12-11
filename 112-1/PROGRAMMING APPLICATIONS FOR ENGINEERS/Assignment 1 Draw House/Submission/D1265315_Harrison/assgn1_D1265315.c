#include <stdio.h>
#include <stdlib.h>

void roof(int,int);
void house(int,int);
int announce(int,int,int);
int a,b,top,layer,bottom,c,d,r_side;

int main()
{
    top = 40;
    layer = 18;
    r_side = 16;
    bottom=top+r_side*2;
    announce(top,r_side,bottom);
    roof(top,layer);
    house(layer,bottom);
    return 0;
}


void roof(int top,int layer){
    int side = top;
    int space = layer;
    
    for(b=1;b<=layer;b++){ //layer of the roof
    for(a=1;a<space-1;a++){ //space in front of the roof
        printf(" ");
    }
    for(a=space;a<space+side;a++){ //roof
        if(b==1 || a==space || a==space+side-1 || b==layer){
            printf("#");
        }
        else{
        printf("*");
        }
    }
    printf("\n");
    space--; //space in front of the roof decrease as the layer goes down
    if(b<=16){
        side = side + 2; //rows of the roof increases as the layer goes down
    }
    }
}

void house(int layer,int bottom)
{
    int height=44;
    for(d=layer+1;d<=layer+height;d++){
    for(c=1;c<=bottom-2;c++){ //rows of the house
        
        //ceiling
        if((d==layer+1 || d==layer+2 || d==layer+height || d==layer+height-1) && (c>=3 && c<=bottom-2)){
            printf("@");
        }
        
        //wall
        else if(c==3 || c==4 || c==bottom-3 || c==bottom-2 && (d>layer+2 && d<layer+height-1)){
            printf("@");
        }
        
        //door
        else if(d>=layer+12 && d<=layer+height-4 && c>(bottom-20)/2 && c<=(bottom-20)/2+20){
            printf("&");
        }
        
         //window
        else if((d==layer+12 || d==layer+18 || d==layer+24 || d==layer+30 || d==layer+36) && ((c>=7 && c<=22) || (c>=bottom-21 && c<=bottom-6))){
            printf("=");
        }
        
        else if(d>layer+12 && d<layer+36 && (c==7 || c==22 || c==bottom-21 || c==bottom-6)){
            printf("=");
        }
        
        else if(d>layer+12 && d<layer+36 && (c==12 || c==17 || c==bottom-16 || c==bottom-11)){
            printf("+");
        }
        else{
            printf(" ");
        }
    }

        printf("\n");
    }


}

int announce(int top, int r_side, int bottom)
{
    printf("***Design parameters of the house:\n");
    printf("   <<<The top of the roof: %d \n",top);
    printf("   <<<The side of the roof: %d \n",r_side);
    printf("   <<<The bottom of the roof: %d \n",bottom);
    printf("   <<<The width of the door: 20 \n");
    printf("   <<<The height of the door: 28 \n");
    printf("   <<<The width of the window: 16 \n");
    printf("   <<<The height of the window: 25 \n");
    printf("   <<<The width of a window glass: 4 \n");
    printf("   <<<The height of a window glass: 5 \n");
    printf("   <<<The thickness of wall/ceiling/floor: 2 \n");
    printf("   <<<The space from the window/door to the ceiling: 10 \n");
    printf("   <<<The space between the floor and the door: 2 \n");
    printf("   <<<The space between the floor and the window: 5 \n");
    printf("   <<<The space from the window to the wall: 2 \n");
    printf("   <<<The space between the window and the door:4 \n\n");
    printf("***The house design is valid.\n");
    printf("   <<<The total width of the house: 72 \n");
    printf("   <<<The total height of the house: 62 \n");
    printf("   <<<The exterior width of the house: 68 \n");
    printf("   <<<The exterior height of the house: 44 \n");
    printf("   <<<The interior width of the house: 64 \n");
    printf("   <<<The interior height of the house: 40 \n\n");
    return 0;
}

