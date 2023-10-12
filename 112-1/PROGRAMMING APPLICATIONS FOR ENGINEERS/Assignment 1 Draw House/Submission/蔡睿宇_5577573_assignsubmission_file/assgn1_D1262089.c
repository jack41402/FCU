#include<stdio.h>

int main(){
    int a,b,m,n;
	int d,e;
	const int roof_t=40,roof_s=16,roof_b=72,door_w=20,door_h=28;
	const int window_w=16,window_h=25,window_glass_w=4,window_glass_h=5;
	const int wallceilingfloor_th=2,ceiling_floorwindow=10,floor_door=2,floor_window=5;
	const int window_wall=2,window_door=4;
	int total_w_house=roof_b;
	int total_h_house=roof_s+2+wallceilingfloor_th*2+ceiling_floorwindow+window_h+floor_window;
	int exterior_w_house=wallceilingfloor_th*2+window_wall*2+window_w*2+window_door*2+door_w;
	int exterior_h_house=total_h_house-2-roof_s;
	int interior_w_house=exterior_w_house-wallceilingfloor_th*2;
	int interior_h_house=exterior_h_house-wallceilingfloor_th*2;
	m=(total_w_house-exterior_w_house)/2;
	
	
	printf("***** Design parameters of the house:\n");
	printf("   <<< The top of the roof:%d\n",roof_t);
	printf("   <<< The side of the roof:%d\n",roof_s);
	printf("   <<< The bottom of the roof:%d\n",roof_b);
	printf("   <<< The width of the door:%d\n",door_w);
	printf("   <<< The height of the door:%d\n",door_h);
	printf("   <<< The width of the window:%d\n",window_w);
	printf("   <<< The height of the window:%d\n",window_h);
	printf("   <<< The width of a window glass:%d\n",window_glass_w);
	printf("   <<< The height of a window glass:%d\n",window_glass_h);
	printf("   <<< The thickness of wall/ceiling/floor:%d\n",wallceilingfloor_th);
	printf("   <<< The space from the window/door to the ceiling:%d\n",ceiling_floorwindow);
	printf("   <<< The space between the floor and the door:%d\n",floor_door);
	printf("   <<< The space between the floor and the window:%d\n",floor_window);
	printf("   <<< The space from the window to the wall:%d\n",window_wall);
	printf("   <<< The space between the window and the door:%d\n\n",window_door);
	printf("***** The house design is valid.\n");
	printf("   <<< The total width of the house:%d\n",total_w_house);
	printf("   <<< The total height of the house:%d\n",total_h_house);
	printf("   <<< The exterior width of the house:%d\n",exterior_w_house);
	printf("   <<< The exterior height of the house:%d\n",exterior_h_house);
	printf("   <<< The interior width of the house:%d\n",interior_w_house);
	printf("   <<< The interior height of the house:%d\n\n\n",interior_h_house);

    
	for(a=0;a<=roof_s+1;a++){//build the roof
		for(b=0;b<=roof_b-1;b++){//(b,a)=(x,y)
			if(a+b==roof_s||b-a==roof_b-roof_s-1||a==0&&b>=roof_s&&b<=roof_b-roof_s-1||a==roof_s+1){
				printf("#");
			}else if(a+b>roof_s&&b-a<roof_b-roof_s-1){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	for(d=0;d<=exterior_h_house-1;d++){
		for(n=1;n<=m;n++){
		printf(" ");
		}//define where is (0,0) 
		for(e=0;e<=exterior_w_house-1;e++){//(e,d)=(x,y) 
			if(e<=wallceilingfloor_th-1||e>=wallceilingfloor_th+interior_w_house||d<=wallceilingfloor_th-1||d>=wallceilingfloor_th+interior_h_house){//build the wall
				printf("@");	
			}else if(d>=ceiling_floorwindow+wallceilingfloor_th&&d<=ceiling_floorwindow+wallceilingfloor_th+door_h-1&&e>=wallceilingfloor_th+window_wall+window_w+window_door&&e<=wallceilingfloor_th+window_wall+window_w+window_door+door_w-1){//build the door
				printf("&");
			}else if(e>=wallceilingfloor_th+window_wall&&e<=wallceilingfloor_th+window_wall+window_w-1&&(d ==ceiling_floorwindow+wallceilingfloor_th||d==ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*1||d==ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*2||d==ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*3||d==ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*4)){//build the left window
					printf("=");
			}else if(e>=exterior_w_house-wallceilingfloor_th-window_wall-window_w&&e<=exterior_w_house-1-wallceilingfloor_th-window_wall&&(d==ceiling_floorwindow+wallceilingfloor_th||d==ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*1||d==ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*2||d==ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*3||d==ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*4)){//build the right window
				    printf("=");
            }else if((e==wallceilingfloor_th+window_wall||e==wallceilingfloor_th+window_wall+window_w-1||e==exterior_w_house-wallceilingfloor_th-window_wall-window_w||e==exterior_w_house-1-wallceilingfloor_th-window_wall)&&( (d>=ceiling_floorwindow+wallceilingfloor_th+1&&d<=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*1-1)|| (d>=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*1+1&&d<=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*2-1)|| (d>=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*2+1&&d<=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*3-1)|| (d>=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*3+1&&d<=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*4-1))){//build the windows    
					printf("=");
            }else if((e==wallceilingfloor_th+window_wall+(window_glass_w+1)*1||e==wallceilingfloor_th+window_wall+(window_glass_w+1)*2||e==exterior_w_house-1-wallceilingfloor_th-window_wall-(window_glass_w+1)*2||e==exterior_w_house-1-wallceilingfloor_th-window_wall-window_glass_w*1)&&( (d>=ceiling_floorwindow+wallceilingfloor_th+1&&d<=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*1-1)|| (d>=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*1+1&&d<=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*2-1)|| (d>=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*2+1&&d<=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*3-1)|| (d>=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*3+1&&d<=ceiling_floorwindow+wallceilingfloor_th+(window_glass_h+1)*4-1))){//windows' detail
					printf("+");

			}else{
				printf(" ");
			}
		}
		printf("\n");
	} 
	return 0;
}
