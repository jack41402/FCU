#include <stdio.h>

int main(void)
{
	int i,j,k,m; 
	int r_top , r_side , h_width , h_hieght ;
	int r_bottom ;
	do
	{
		printf("roof_top(10<=roof_top<=20):");
		scanf("%d", &r_top);
	}while(r_top>20 || r_top<10);
	do
	{
		printf("roof_side(10<=roof_side<=25):");
		scanf("%d", &r_side);
	}while(r_side>25 || r_side<10);

	r_bottom = r_top+2*r_side;
	for(i = 0 ; i <= r_side ; i++)
	{
		if(i == 0)
		{
			for(j = 0 ; j <= r_side ; j++)
			{
				printf(" ");
			}
			for(j = 0 ; j < r_top ; j++)
			{
				printf("#");
			}
		}
		else
		{
			for(j = r_side-i ; j >= 0 ; j--)
			{
				printf(" ");
			}
			printf("#");
			
			for(k = 0 ; k < r_top+i*2-2 ; k++)
			{
				printf("*");
			}
			printf("#");
		}
		
	printf("\n");
			
	}
	printf(" ");
	for(j = 0 ; j < r_bottom ; j++)
	{
	printf("#");
	}
	
}
