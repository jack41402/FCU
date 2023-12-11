#include <stdio.h>

int main(void){
	
	int r_top=40,r_side=16,ex_h_height=44,in_h_width=64,ex_h_width=68,i,k,r_bottom,t_w,t_h,ew_h,eh_h,iw_h,ih_h;
	int d_w=20,d_h=28,w_w=16,w_h=25,wd_w=4,wd_h=5,tn_c=2,s_w_c=10,s_f_d=2,s_f_w=5,s_w_w=2,s_w_d=4;
	//calculate the data of the house
	r_bottom=r_top+2*r_side;
	t_w=r_bottom;
	t_h=1+r_side+1+tn_c+s_w_c+d_h+s_f_d+tn_c;
	ew_h=tn_c+s_w_w+w_w+s_w_d+d_w+s_w_d+w_w+s_w_w+tn_c;
	eh_h=tn_c+s_w_c+d_h+s_f_d+tn_c;
	iw_h=s_w_w+w_w+s_w_d+d_w+s_w_d+w_w+s_w_w;
	ih_h=s_w_c+d_h+s_f_d;
	//print parametely
	printf("***** Design parameters of the house:\n");
	printf("   <<< The top of the roof: %d\n",r_top);
	printf("   <<< The side of the roof: %d\n",r_side);
	printf("   <<< The bottom of the roof: %d\n",r_bottom);
	printf("   <<< The width of the door: %d\n",d_w);
	printf("   <<< The height of the door: %d\n",d_h);
	printf("   <<< The width of the window: %d\n",w_w);
	printf("   <<< The height of the window: %d\n",w_h);
	printf("   <<< The width of the window glass: %d\n",wd_w);
	printf("   <<< The height of the window glass: %d\n",wd_h);
	printf("   <<< The thickness of the wall/ceiling/floor: %d\n",tn_c);
	printf("   <<< The space from the window/door to the ceiling: %d\n",s_w_c);
	printf("   <<< The space between the floor and the door: %d\n",s_f_d);
	printf("   <<< The space between the floor and the window: %d\n",s_f_w);
	printf("   <<< The space from the window to the wall: %d\n",s_w_w);
	printf("   <<< The space between the window and the door: %d\n",s_w_d);
	printf("\n");
	//verify if the data got wrong or not
	if(t_w==72&&t_h==62&&ew_h==68&&eh_h==44&&iw_h==64&&ih_h==40){
	printf("***** The house design is valid.\n");
	printf("   >>> The total width of the house: %d\n",t_w);
	printf("   >>> The total height of the house: %d\n",t_h);
	printf("   >>> The exterior width of the house: %d\n",ew_h);
	printf("   >>> The exterior height of the house: %d\n",eh_h);
	printf("   >>> The interior width of the house: %d\n",iw_h);
	printf("   >>> The interior height of the house: %d\n",ih_h);
	printf("\n");
	printf("\n");
	for(i=0;i<r_side;i++)//roof top
		printf(" ");
	for(i=0;i<r_top;i++)//roof top
		printf("#");
	printf("\n");
	for(i=r_side;i>0;i--){//roof middle
		for(k=i-1;k>0;k--)
			printf(" ");
		printf("#");
		for(k=1;k<=r_top;k++)
			printf("*");
		printf("#");
		r_top+=2;
		printf("\n");
	}
	for(i=0;i<r_bottom;i++)//roof bottom
		printf("#");
	printf("\n");
	for(i=1;i<=ex_h_height;i++){// house body
		if(i>=3&&i<=12||i>=41&&i<=42){//space between roof bottom and the window, door bottom and house bottom
			printf("  ");
			printf("@@");
			for(k=0;k<in_h_width;k++)
				printf(" ");
			printf("@@");
		}
		else if(i==13||i==19||i==25||i==31||i==37){//window frame and some part of the door
			printf("  ");
			printf("@@");
			for(k=1;k<=in_h_width;k++){
				if(k==1||k==2||k>=19&&k<=22||k>=43&&k<=46||k==63||k==64)
					printf(" ");
				else if(k>=23&&k<=42)
					printf("&");
				else
					printf("=");
			}
			printf("@@");
		}
		else if(i>=14&&i<=18||i>=20&&i<=24||i>=26&&i<=30||i>=32&&i<=36){//window and some part of the door
			printf("  ");
			printf("@@");
			for(k=1;k<=in_h_width;k++){
				if(k==1||k==2||k>=19&&k<=22||k>=43&&k<=46||k==63||k==64)
					printf(" ");
				else if(k>=4&&k<=7||k>=9&&k<=12||k>=14&&k<=17||k>=58&&k<=61||k>=53&&k<=56||k>=48&&k<=51)
					printf(" ");
				else if(k==3||k==18||k==62||k==47)
					printf("=");
				else if(k==8||k==13||k==57||k==52)
					printf("+");
				else
					printf("&");
			}
			printf("@@");
		}
		else if(i>=38&&i<=40){//the bottom 3 layer of the door
			printf("  @@");
			for(k=1;k<=in_h_width;k++){
				if(k>=23&&k<=42)
					printf("&");
				else
					printf(" ");
			}
			printf("@@");
		}
		else{
			printf("  ");
			for(k=1;k<=ex_h_width;k++)
				printf("@");
		}
		printf("\n");
	}
}
else{	//verify if the data got wrong or not
	printf("error");
}
	return 0;
}

