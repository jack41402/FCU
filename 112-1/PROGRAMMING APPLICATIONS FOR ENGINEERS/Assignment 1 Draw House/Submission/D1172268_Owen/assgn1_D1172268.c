#include<stdio.h>

int main(){
	int top_roof = 40;
	int side_roof = 16;
	int wid_house = 64;
	int hei_house = 40;
	int wid_door = 20;
	int hei_door = 28;
	int wid_window = 16;
	int hei_window = 25;
	int wid_window_glass = 4;
	int hei_window_glass = 5; 
	int house_gap = 2;
	int wall_width = 2;
	int win_to_ceil = 10;
	int floor_to_door = 2;
	int floor_to_win = 5;
	int win_to_wall = 2;
	int win_to_door = 4;
	
	int i = 0;
	int j = 0;
	int k = 0;
	int bot_roof = top_roof + side_roof*2;
	
	
	printf("***** Design parameters of the house:\n");
	printf("   <<< The top of the roof: %d\n", top_roof);
	printf("   <<< The bottom of the roof: %d\n", bot_roof);
	printf("   <<< The width of the door: %d\n", wid_door);
	printf("   <<< The height of the door: %d\n", hei_door);
	printf("   <<< The width of the window: %d\n", wid_window);
	printf("   <<< The height of the window: %d\n", hei_window);
	printf("   <<< The width of a window glass: %d\n", wid_window_glass);
	printf("   <<< The height of a window glass: %d\n", hei_window_glass);
	printf("   <<< The thickness of a wall/ceiling/floor: %d\n", wall_width);
	printf("   <<< The space from the window/door to the ceiling: %d\n", win_to_ceil);
	printf("   <<< The space between the floor and the door: %d\n", floor_to_door);
	printf("   <<< The space between the floor and the window: %d\n", floor_to_win);
	printf("   <<< The space from the window to the wall: %d\n", win_to_wall);
	printf("   <<< The space between the window and the door: %d\n\n", win_to_door);
	printf("***** The house design is valid.\n");
	printf("   >>> The total width of the house: %d\n", (house_gap + wall_width + win_to_wall + wid_window + win_to_door) * 2 + wid_door);
	printf("   >>> The total height of the house: %d\n", 1 + side_roof + 1 + wall_width + win_to_ceil + hei_door + floor_to_door + wall_width);
	printf("   >>> The exterior width of the house: %d\n", (wall_width + win_to_wall + wid_window + win_to_door) * 2 + wid_door);
	printf("   >>> The exterior height of the house: %d\n", wall_width + win_to_ceil + hei_door + floor_to_door + wall_width);
	printf("   >>> The interior width of the house: %d\n", (win_to_wall + wid_window + win_to_door) * 2 + wid_door);
	printf("   >>> The interior height of the house: %d\n", win_to_ceil + hei_door + floor_to_door);
	printf("\n\n\n");
	
	//roof top
	for(i = 0; i <side_roof; i++){
		printf(" ");
	}
	for(j = 0; j < top_roof; j++){
		printf("#");	
	}
	printf("\n");
	
	//roof body
	for(i = 0; i < side_roof; i++){
		for(j = 0; j < side_roof - i - 1; j++){
			printf(" ");
		}
		printf("#");
		for(j = 0; j < top_roof + i*2; j++){
			printf("*");
		}
		printf("#\n");
	}
	
	//roof bottom
	for(i = 0; i < bot_roof; i++){
		printf("#");
	}
	printf("\n");
	
	//top wall
	
	for( i = 0; i < wall_width; i++ ){
		for(j =0; j < house_gap; j++){
			printf(" ");
		}
		for(j = 0; j < wid_house + wall_width * 2; j++){
			printf("@");
		}
		printf("\n");
	} 
	
	//house before window
	for(i = 0; i < win_to_ceil; i++){
		for(j = 0; j < house_gap; j++){
			printf(" ");
		}
		printf("@@");
		for(j = 0; j < wid_house; j++){
			printf(" ");
		}
		printf("@@\n");
	}
	
	//window
	int window_width = 16;
	for(i = 0; i < 4; i++){ //divide window as four part 
		for(j = 0; j < house_gap; j++){
			printf(" ");
		}
		printf("@@  ");
		for(j = 0; j < wid_window; j++){
			printf("=");
		}	
		for(j = 0; j < win_to_door; j++){
			printf(" ");
		}
		for(j = 0; j < wid_door; j++){
			printf("&"); 
		}
		for(j = 0; j < win_to_door; j++){
			printf(" ");
		}
		for(j = 0; j < wid_window; j++){
			printf("=");
		}
		printf("  @@\n");
		for(j = 0; j < hei_window_glass; j++){//after divide into four parts, divide into another five parts
			printf("  @@  ");
			printf("=");
			for(k = 0; k < wid_window_glass; k++){
				printf(" ");
			}
			printf("+");
			for(k = 0; k < wid_window_glass; k++){
				printf(" ");
			}
			printf("+");
			for(k = 0; k < wid_window_glass; k++){
				printf(" ");
			}
			printf("=");
			for(k = 0; k < wid_window_glass; k++){
				printf(" ");
			}
			for(k = 0; k < wid_door; k++){
				printf("&"); 
			}
			printf("    ");
			printf("=");
			for(k = 0; k < wid_window_glass; k++){
				printf(" ");
			}
			printf("+");
			for(k = 0; k < wid_window_glass; k++){
				printf(" ");
			}
			printf("+");
			for(k = 0; k < wid_window_glass; k++){
				printf(" ");
			}
			printf("=");
			printf("  @@\n");
		}
	}
	
	//final part of window
	for(j = 0; j < house_gap; j++){
		printf(" ");
	}
	printf("@@  ");
	for(j = 0; j < wid_window; j++){
		printf("=");
	}
	printf("    ");
	for(j = 0; j < wid_door; j++){
		printf("&"); 
	}
	printf("    ");
	for(j = 0; j < wid_window; j++){
		printf("=");
	}
	printf("  @@\n");
	
	//house after window finishing door
	for(i = 0; i < hei_door - hei_window; i++){
		printf("  @@");
		for(j = 0; j < 22; j++){
			printf(" ");
		}
		for(j = 0; j < wid_door; j++){
			printf("&");
		}
		for(j = 0; j < 22; j++){
			printf(" ");
		}
		printf("@@\n");
	}
	//house after door and before bottom
	for(i = 0; i < floor_to_door; i++){
		printf("  @@");
		for(j = 0; j < 64; j++){
			printf(" ");
		}
		printf("@@\n");
	}
	
	//house bottome
	for( i = 0; i < wall_width; i++ ){
		for(j =0; j < house_gap; j++){
			printf(" ");
		}
		for(j = 0; j < wid_house + wall_width * 2; j++){
			printf("@");
		}
		printf("\n");
	} 
}
