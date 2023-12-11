#include <stdio.h>
int main()
{
    printf("***** Design parameters of the house:\n");
    int r_top=40,r_side=16,r_bottom=72;//宣告函數
    printf("   <<< The top of the roof: %d\n",r_top);//print value
    printf("   <<< The side of the roof: %d\n",r_side);
    printf("   <<< The bottom of the roof: %d\n",r_bottom);
    int width_door=20,height_door=28,width_window=16,height_window=25;//declare function
    printf("   <<< The width of the door: %d\n",width_door);//print value
    printf("   <<< The height of the door: %d\n",height_door);
    printf("   <<< The width of the window: %d\n",width_window);
    printf("   <<< The height of the window: %d\n",height_window);
    int width_window_glass=4,height_window_glass=5;//宣告函數
    printf("   <<< The width of a window glass: %d\n",width_window_glass);//print value
    printf("   <<< The height of a window glass: %d\n",height_window_glass);
    int thickness_wall_ceiling_floor=2;//宣告函數
    printf("   <<< The thickness of wall/ceiling/floor: %d\n",thickness_wall_ceiling_floor);//print value
    int space_window_door_ceiling=10;//宣告函數
    printf("   <<< The space form the window/door to the ceiling: %d\n",space_window_door_ceiling);//print value
    int space_floor_door=2,space_floor_window=5,space_window_wall=2,space_window_door=4;//declare function
    printf("   <<< The space between the floor and the door: %d\n",space_floor_door);//print value
    printf("   <<< The space between the floor and the window: %d\n",space_floor_window);
    printf("   <<< The space from the window to the wall: %d\n",space_window_door);
    printf("   <<< The space between the window and the door: %d\n\n",space_window_door);

    int total_width_house=r_bottom, total_height_house=r_side+2+thickness_wall_ceiling_floor*2+space_window_door_ceiling+height_door+space_floor_door;
    int exterior_width_house=thickness_wall_ceiling_floor*2+width_window*2+width_door+space_window_wall*2+space_window_door*2;
    int exterior_height_house=space_window_door_ceiling+height_door+space_floor_door+thickness_wall_ceiling_floor*2;
    int interior_width_house=width_window*2+width_door+space_window_wall*2+space_window_door*2;
    int interior_height_house=space_window_door_ceiling+height_door+space_floor_door;
    if(total_width_house!=72||total_height_house!=62||exterior_width_house!=68||exterior_height_house!=44||interior_width_house!=64||interior_height_house!=40)
    {
        printf("The value error.");
        return 0;
    }
    printf("***** The house design is valid:\n");
    printf("   >>> The total width of the house: %d\n",total_width_house);//print value
    printf("   >>> The total height of the house: %d\n",total_height_house);
    printf("   >>> The exterior width of the house: %d\n",exterior_width_house);//print value
    printf("   >>> The exterior height of the house: %d\n",exterior_height_house);
    printf("   >>> The interior width of the house: %d\n",interior_width_house);//print value
    printf("   >>> The interior height of the house: %d\n\n",interior_height_house);
    int i,j,x;//declare variables
    for(i=0;i<r_side+2;++i)//make the roof with for loop
    {
        for(j=0;j<r_side-i;++j)
        {
            printf(" ");
        }
        if(i==0)//the first level of the roof
        {
            for(j=0;j<r_top-2;++j)
            {
                printf("#");
            }
        }
        printf("#");
        if(i!=0)
        {
            if(i==r_side+1)//the last level of the roof
            {
                for(j=0;j<r_bottom-1;++j)
                {
                    printf("#");
                }
                printf("\n");
                break;
            }
            for(j=0;j<r_top+2*i-2;++j)//inside the roof
            {
                printf("*");
            }
        }
        printf("#\n");
    }
    for(i=0;i<thickness_wall_ceiling_floor;++i)//the thickness of ceiling
    {
        for(j=0;j<2;++j)
        {
            printf(" ");
        }
        for(j=0;j<total_width_house-4;++j)
        {
            printf("@");
        }
        printf("\n");
    }
    for(i=0;i<space_window_door_ceiling;++i)//the space between ceiling and window
    {
        for(j=0;j<2;++j)
        {
            printf(" ");
        }
        printf("@@");
        for(j=0;j<total_width_house-thickness_wall_ceiling_floor*2-4;++j)//the space inside the house
        {
            {
                printf(" ");
            }
        }
        printf("@@\n");
    }
    for(i=0;i<height_window;++i)//the window and the door
    {
        for(j=0;j<2;++j)
        {
            printf(" ");
        }
        printf("@@");
        for(j=0;j<space_window_wall;++j)
        {
            printf("  ");
            if(i%6==0)//the part of window with =======
            {
                for(x=0;x<=width_window-1;++x)
                {
                    printf("=");
                }
                for(x=0;x<space_window_door;++x)
                {
                    printf(" ");
                }
                for(x=0;x<width_door;++x)//door
                {
                    printf("&");
                }
                for(x=0;x<space_window_door;++x)
                {
                    printf(" ");
                }
                for(x=0;x<width_window;++x)
                {
                    printf("=");
                }
                printf("  ");
                printf("@@");
                printf("\n");
            }
            else
            {
                printf("=    +    +    =");//the part of window with =    +    +    =
                for(x=0;x<space_window_door;++x)
                {
                    printf(" ");
                }
                for(x=0;x<width_door;++x)//the door
                {
                    printf("&");
                }
                for(x=0;x<space_window_door;++x)
                {
                    printf(" ");
                }
                printf("=    +    +    =");
                printf("  ");
                printf("@@");
                printf("\n");
            }
            break;
        }
    }
    for(i=0;i<height_door-height_window;++i)//the door which part is over window
    {
        for(j=0;j<2;++j)
        {
            printf(" ");
        }
        printf("@@");
        for(j=0;j<2+width_window+space_window_door;++j)//the space between the wall and the door
        {
            {
                printf(" ");
            }
        }
        for(j=0;j<width_door;++j)
        {
            printf("&");
        }
        for(j=0;j<2+width_window+space_window_door;++j)
        {
            {
                printf(" ");
            }
        }
        printf("@@\n");
    }
    for(i=0;i<space_floor_door;++i)//the space between the door and the floor
    {
        for(j=0;j<2;++j)
        {
            printf(" ");
        }
        printf("@@");
        for(j=0;j<total_width_house-thickness_wall_ceiling_floor*2-4;++j)//space
        {
            {
                printf(" ");
            }
        }
        printf("@@\n");
    }
    for(i=0;i<thickness_wall_ceiling_floor;++i)//the thickness of floor
    {
        for(j=0;j<2;++j)
        {
            printf(" ");
        }
        for(j=0;j<total_width_house-4;++j)
        {
            printf("@");
        }
        printf("\n");
    }
}