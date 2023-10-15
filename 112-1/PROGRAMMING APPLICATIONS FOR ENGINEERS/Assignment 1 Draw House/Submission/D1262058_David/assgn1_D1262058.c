#include <stdio.h>
int main(void) {
	int rt=40,rs=16,rb,hw=64,hh=40,i,a,b,c,k,e;//rt is r_top, rs is r_side, hw is h_width, hh is h_height
	rb=rt+2*rs;//rb is r_bottom
printf("*** Design parameters of the house:\n");
	printf("   <<< The top of the roof: %d\n",rt);
	printf("   <<< The side of the roof: %d\n",rs);
	printf("   <<< The bottom of the roof: %d\n",rb);
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
	int th = rs+hh+6;//th is total_height
    int tw = rb;//tw is total_width 
    int ew = hw+4;//ew is exterior_width
    int eh = hh+4;//eh is exterior_height
    int iw = hw;//iw is interior_width
    int ih = hh;//ih is interior_height

	if(th == 62 && tw == 72 && ew == 68 && eh == 44 && iw == 64 && ih == 40){
     printf("* The house design is valid.\n");
	}
    else{
     printf("* The house design is invalid.\n");
	}
	printf("   >>> The total width of the house: %d\n",tw);
	printf("   >>> The total height of the house: %d\n",th);
	printf("   >>> The exterior width of the house: %d\n",ew);
	printf("   >>> The exterior height of the house: %d\n",eh);
	printf("   >>> The interior width of the house: %d\n",iw);
	printf("   >>> The interior height of the house: %d\n",ih);
	printf("\n");
	printf("\n");//print out information
//roof
	for(a=1;a<=rs;a++){
		printf(" ");
	}
	for(b=1;b<=rt;b++){
		printf("#");
	}
	printf("\n");//roof top
	for(i=rs;i>=1;i--){
		for(a=i-2;a>=0;a--){
		printf(" ");
		}
		printf("#");
		for(b=rt;b>=1;b--){
			printf("*");
		}
		rt+=2;
		printf("#");
		printf(" \n");//roof body
	}
	for(b=1;b<=rb;b++){
		printf("#");
	}
	printf("\n");//roof bottom
//upper house body
	for(i=1;i<=2;i++){
	printf("  @@");
	for(a=1;a<=hw+2;a++){
		printf("@");
	}
	printf("\n");
    }
	for(i=1;i<=10;i++){
		printf("  @@");
		for(k=1;k<=hw;k++){
			printf(" ");
		}
		printf("@@\n");
	}
//windows 
for(c=1;c<=4;c++){//print four windows
	for(i=1;i<=6;i++){
		if(i==1){ //windows frame
			printf("  @@");
			for(a=1;a<=hw;a++){
				if(a>=3&&a<=18||a>=47&&a<=62){
					printf("=");			
				}
				else if(a>=23&&a<=42){
					printf("&");
				}
				else{
					printf(" ");
				}
			}
			printf("@@\n");
		}
		if(i>=2&&i<=6){//windows glass
			printf("  @@");
			for(a=1;a<=hw;a++){
				if(a==3||a==18||a==47||a==62){
					printf("=");					
				}
				else if(a==8||a==13||a==52||a==57){
					printf("+");
				}
				else if(a>=23&&a<=42){
					printf("&");
				}
				else{
					printf(" ");
				}
			}
			printf("@@\n");
		}
	
	}
}
//lower part of the house
	for(i=1;i<=6;i++){
		if(i==1){
			printf("  @@");
			for(a=1;a<=hw;a++){
				if(a>=3&&a<=18||a>=47&&a<=62){
					printf("=");
				}
				else if(a>=23&&a<=42){
					printf("&");
				}
				else{
					printf(" ");
				
				}
			}
			printf("@@");
		}
		if(i>=2&&i<=4){
			printf("  @@");
			for(a=1;a<=hw;a++){
				if(a>=23&&a<=42){
					printf("&");
				}
				else{
					printf(" ");
				}
			}
			printf("@@");
 		}
		if(i==5||i==6){
			printf("  @@");
			for(a=1;a<=hw;a++){
				printf(" ");
			}
			printf("@@");
		}
		printf("\n");
	}
	for(i=1;i<=2;i++){
	printf("  @@");
	for(a=1;a<=hw+2;a++){
		printf("@");
	}
	printf("\n");
	}
	return 0;	
}
