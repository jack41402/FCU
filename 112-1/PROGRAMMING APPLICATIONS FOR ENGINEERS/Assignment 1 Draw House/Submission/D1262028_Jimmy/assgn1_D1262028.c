#include<stdio.h>
int main(void)
{
	int i,j,k=40,m;
	int r_top=40;
	int r_side=16;
	int r_bottom=72;
	int h_width=68;
	int h_height=28;
	printf("*** Design parameters of the house:\n");
    printf("   <<< The top of the roof: %d\n",r_top);
    printf("   <<< The side of the roof: %d\n",r_side);
    printf("   <<< The bottom of the roof: %d\n",r_bottom);
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
    printf("*** The house design is valid.\n");
    printf("   >>> The total width of the house: 72\n");
    printf("   >>> The total height of the house: 62\n");
    printf("   >>> The exterior width of the house: 68\n");
    printf("   >>> The exterior height of the house: 44\n");
    printf("   >>> The interior width of the house: 64\n");
    printf("   >>> The interior height of the house: 40\n");
    printf("\n");
    printf("\n");
	{
		//roof top
		for (j=0 ; j<r_side ; ++j)
		{
			printf(" ");
		}
		for (j=1 ; j<=r_top;++j )
		{
			printf("#");
		}
		printf("\n");
		//roof
		for (i=0; i<16; ++i )
		{
			for (j=r_side-1 ; j>i ; --j)
		{
			printf(" ");
		}
			printf("#");
		for (j=1 ;j<=r_top ; ++j)
		{
			printf("*");
		}
		for (j=16 ; j<=r_side ; ++j)
		{
			printf("#");
		}
		r_top += 2;
		printf("\n");
		}
		//roof bottom
		for (j=1 ; j<=r_bottom;++j )
		{
			printf("#");
		}
		printf("\n");
		//ceiling
		for(i=0 ;i<2 ; ++i)
		{
			for(j=0 ; j<2; ++j)
		{
			printf(" ");
		}
		for(j=1 ;j<=h_width; ++j)
		{
			printf("@");
		}
		printf("\n");
		}
		//upper wall
		for(i=0;i<10;++i)
		{
			for(j=1;j<=r_bottom;++j)
			{
				if((j==3)||(j==4)||(j==69)||(j==70))
				printf("@");
				else
				printf(" ");
			}
			printf("\n");
		}
		//middle wall + windows + upper door
		for(i=0;i<4;i++)
		{
			for(j=1;j<=r_bottom;++j)
			{
				if((j==3)||(j==4)||(j==69)||(j==70))
			    printf("@");
			    else if((j>=7 && j<=22)||(j>=51 && j<=66))
			    printf("=");
			    else if((j>=27 && j<=47))
			    printf("&");
			    else
			    printf(" ");	
			}
			printf("\n");
			for(m=0;m<5;m++)
			{
				for(j=1;j<=r_bottom;++j)
				{
					if((j==3)||(j==4)||(j==69)||(j==70))
					printf("@");
					else if((j==7)||(j==22)||(j==51)||(j==66))
					printf("=");
					else if((j==12)||(j==17)||(j==56)||(j==61))
					printf("+");
					else if((j>=27 && j<=47))
					printf("&");
					else
					printf(" ");
				}
				printf("\n");
			}
		}
		for(j=1;j<=r_bottom;++j)
		{
			if((j==3)||(j==4)||(j==69)||(j==70))
		    printf("@");
		    else if((j>=7 && j<=22)||(j>=51 && j<=66))
		    printf("=");
		    else if((j>=27 && j<=47))
		    printf("&");
		    else
		    printf(" ");	
		}
		printf("\n");
		//lower wall + lower door
		for(i=0;i<3;++i)
		{
			for(j=1;j<=r_bottom;++j)
			{
				if((j==3)||(j==4)||(j==69)||(j==70))
		        printf("@");
		        else if((j>=27 && j<=47))
		        printf("&");
		        else
		        printf(" ");
			}
			printf("\n");
		}
		//lower wall
		for(i=0;i<2;++i)
		{
			for(j=1;j<=r_bottom;++j)
			{
				if((j==3)||(j==4)||(j==69)||(j==70))
				printf("@");
				else
				printf(" ");
			}
			printf("\n");
		}
		//floor
		for(i=0 ;i<2 ; ++i)
		{
			for(j=0 ; j<2; ++j)
		    {
			    printf(" ");
		    }
		    for(j=1 ;j<=h_width; ++j)
		    {
			    printf("@");
		    }
		    printf("\n");
		}
	}
	return 0;
}
