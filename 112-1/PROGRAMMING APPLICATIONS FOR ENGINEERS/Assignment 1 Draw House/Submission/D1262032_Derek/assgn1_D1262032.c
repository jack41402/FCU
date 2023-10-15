#include <stdio.h>
int main(void)
{
    int r_top=40,r_side=16,r_bottom=r_top+2*r_side,d_width=20,d_height=28,h_width=r_bottom, h_house=r_side+46, exw_house=h_width-4, exh_house=h_house-r_side-2;
    printf("***** Design parameters of the house:\n");
    printf("   <<< The top of the roof: %d\n", r_top);
    printf("   <<< The side of the roof: %d\n", r_side);
    printf("   <<< The bottom of the roof: %d\n", r_bottom);
    printf("   <<< The width of the door: %d\n", d_width);
    printf("   <<< The height of the door: %d\n", d_height);
    printf("   <<< The width of the window: 16\n");
    printf("   <<< The height of the window: 25\n");
    printf("   <<< The width of a window glass: 4\n");
    printf("   <<< The height of a window glass: 5\n" );
    printf("   <<< The thickness of wall/ceiling/floor: 2\n");
    printf("   <<< The space from the window/door to the ceiling: 10\n");
    printf("   <<< The space between the floor and the door: 2\n");
    printf("   <<< The space between the floor and the window: 5\n");
    printf("   <<< The space from the window to the wall: 2\n");
    printf("   <<< The space between the window and the door: 4\n\n");
    printf("***** The house design is valid.\n");
    printf("   >>> The total width of the house: %d\n", h_width);
    printf("   >>> The total height of the house: %d\n", h_house);
    printf("   >>> The exterior width of the house: %d\n", exw_house);
    printf("   >>> The exterior height of the house: %d\n", exh_house);
    printf("   >>> The interior width of the house: %d\n", h_width-4-4);
    printf("   >>> The interior height of the house: %d\n\n", h_house-r_side-2-4);
    int i,j,k;//k=離左邊的距離
    k=(r_bottom-r_top)/2;
    for(i=1;i<=r_side+2;i++)//屋頂
    {
        for(j=1;j<=k+1-i;j++)//屋頂底部貼邊狀況下要打的空格數
        {
            printf(" ");
        }
        printf("   #");//讓整個房子離左邊3格
        if(i==1)//r_top
        {
            for(j=1;j<=r_top-1;j++)
            {
                printf("#");
            }
            printf("\n");
        }
        if(i==r_side+2)//r_bottom
        {
            for(j=1;j<=r_bottom-1;j++)
            {
                printf("#");
            }
            printf("\n");
        }
        if(i!=1&&i!=r_side+2)//屋頂中間16層
        {
            for(j=1;j<=2*i+r_top-4;j++)
            {
                printf("*");
            }
            printf("#\n");
        }
    }
    int s=(r_bottom-exw_house)/2+3;//設s為屋體離左邊的距離
    for(i=1;i<=12;i++)//屋體最上面12層
    {
        for(j=1;j<=s;j++)
        {
            printf(" ");
        }
            printf("@@");//牆壁
        if(i<=2)//天花板
        {
            for(j=1;j<=r_bottom-6;j++)
            {
                printf("@");
            }
            printf("\n");
        }
        else//屋體的3-10層
        {
            for(j=1;j<=r_bottom-8;j++)
            {
                printf(" ");
            }
            printf("@@\n");
        }
    }
    int x;
    for(x=1;x<=4;x++)//蓋前24層窗戶，每6層為一組，蓋4次
    {
        for(i=1;i<=6;i++)//6層為一組
      {
        if(i==1)//一組中的第1層
        {
            for(j=1;j<=s;j++)
            {
                printf(" ");
            }
            printf("@@  ");
            for(j=1;j<=16;j++)//窗戶框
            {
                printf("=");
            }
            printf("    ");
            for(j=1;j<=r_bottom-52;j++)//門
            {
                printf("&");
            }
            printf("    ");
            for(j=1;j<=16;j++)//窗戶框
            {
                printf("=");
            }
            printf("  @@\n");
        }
        else//一組中的第2-5層
        {
            for(j=1;j<=s;j++)
            {
                printf(" ");
            }
            printf("@@  =    +    +    =    ");
            for(j=1;j<=r_bottom-52;j++)
            {
                printf("&");
            }
            printf("    =    +    +    =  @@\n");
        }
      }
    }
    for(i=1;i<=1;i++)//第25層(最後一層窗戶)
    {
        for(j=1;j<=s;j++)
        {
            printf(" ");
        }
        printf("@@  ");
        for(j=1;j<=16;j++)//窗戶框
        {
            printf("=");
        }
        printf("    ");
        for(j=1;j<=r_bottom-52;j++)//門
        {
            printf("&");
        }
        printf("    ");
        for(j=1;j<=16;j++)//窗戶框
        {
            printf("=");
        }
        printf("  @@\n");
   }
    for(i=1;i<=exh_house-41;i++)//最後3層門
    {
        for(j=1;j<=s;j++)
        {
            printf(" ");
        }
            printf("@@");//門柱
        for(j=1;j<=22;j++)
        {
            printf(" ");
        }
        for(j=1;j<=r_bottom-52;j++)//門
        {
            printf("&");
        }
        for(j=1;j<=22;j++)
        {
            printf(" ");
        }
            printf("@@\n");//門柱
    }
    for(i=1;i<=2;i++)//門離地板間的2層
    {
        for(j=1;j<=s;j++)
        {
            printf(" ");
        }
            printf("@@");
        for(j=1;j<=h_width-8;j++)
        {
            printf(" ");
        }
            printf("@@\n");
    }
    for(i=1;i<=2;i++)//2層地板
    {
        for(j=1;j<=s;j++)
        {
            printf(" ");
        }
        for(j=1;j<=h_width-4;j++)
        {
            printf("@");
        }
        printf("\n");
    }
 }
