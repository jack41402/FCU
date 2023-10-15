#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
	
	int r_top = 40,r_side = 16,h_width = 68,h_height = 44;
    int r_bottom = r_top + r_side * 2;
    int d_width = 20;
	int d_height = 28;
	
	
	//info of the house
	printf("* Design parameters of the house:\n");
	
	printf("   <<< The top of the roof: %d\n", r_top);
	
	printf("   <<< The side of the roof: %d\n", r_side);
	
	printf("   <<< The bottom of the roof: %d\n", r_bottom);
	
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
	
	
	//verify 
	int total_height = r_side + h_height + 2;
	int total_width = r_bottom;
	int exterior_width = h_width;
	int exterior_height = h_height;
	int interior_width = h_width - 4;
	int interior_height = h_height - 4;
	
	

	printf("   >>> The total width of the house: %d\n", total_width);
	
	printf("   >>> The total height of the house: %d\n", total_height);
	
	printf("   >>> The exterior width of the house: %d\n", exterior_width);
	
	printf("   >>> The exterior height of the house: %d\n", exterior_height);
	
	printf("   >>> The interior width of the house: %d\n", interior_width);
	
	printf("   >>> The interior height of the house: %d\n", interior_height);
	
	printf("\n");
	
	printf("\n");
	
	if(total_height == 62 && total_width == 72 && exterior_width == 68 && exterior_height == 44 && interior_width == 64 && interior_height == 40){
	 printf("* The house design is valid.\n");//if the design is valid then go on
}
	else{
	 printf("* The house design is invalid.\n");//if the design is not valid then shut down the program
	 exit(1);
}
  //roof top
for(int i = 0; i < r_side; ++i){//the roof top's "#" starts after the same number of " " as variable r_side 
    printf(" ");
  
  }
for(int i = r_side; i >= r_side && i < (r_side + r_top); ++i){//print the same number of "#" as r_top 
  	printf("#");
  
  }
  printf("\n");
  
  
  //roof 
for(int i = 0; i < r_side; ++i){//the height of roof without roof top and roof bottom is r_side
  	
	for(int j = 1; j <= (r_side - i); ++j){//this for loop is to print the " " and "#" of the boundry of the roof before the body of roof 
	
	 if( j == (r_side - i) )
	   printf("#");
     else
	   printf(" ");
  
	}
	for(int j = 0; j <= (r_top + i * 2); ++j){//this for loop is to print the "*" and the last "#" on the boundry of the roof
	
	 if( j == (r_top + i * 2) )
	   printf("#");
     else
	   printf("*");
	
    }
  printf("\n");
  } 
  
  //roof bottom
for(int i = 0; i < (r_bottom); ++i){//print the same number of "#" as the length of roof bottom
  	printf("#");
  }
  printf("\n");
  
  //ceiling
for(int j = 1; j <= 2; ++j){ //the thickness of the ceiling is 2 characters 
  
  for(int i = 1; i <= r_bottom; ++i){//operate until the length reach the length of roof bottom 

    if(i >= 3 && i <= r_bottom - 2 )//the 3rd character till the 2nd character before roof bottom of both line is "@"
      printf("@");
    else
      printf(" ");//print " " under every other condition 
 }
 printf("\n");
} 
  //upper wall
for(int i = 1; i <= 10; ++i){//the height of upper wall is 10 characters
  	
  	for(int j = 1; j <= r_bottom; ++j){
	  
  	 if( (j >= 3 && j <= 4) || (j >= 69 && j <= 70) )//print "@" when it's 3rd and 4th character and 69th 70th character
  	  printf("@");
  	  
     else
      printf(" ");//print " " under every other condition

  }
  printf("\n");
}
 //mid wall + window + upper door
for(int i = 1; i <= 25; ++i){//the height of the mid part of the house is 25 characters
  	
	if(i == 1|| i == 7|| i == 13|| i == 19|| i == 25){ 
	
	 for(int j = 1; j <= 19; ++j){//calculate the characters and make "@@" and "================" to 1 unit and print them at once
	
	  if(j == 3 || j == 19 ){
  	    printf("@@");
      } 
	  else if(j == 6 || j == 16){
  	    printf("================");
      }
      else if(j == 11){
	  	for(int k = 1; k <= d_width; ++k)//print the same number of "&" as d_width
	  	  printf("&");
	  }
	  else{
        printf(" "); 	
      }  
	 } 
    } 
	else {//for the rest of the part of the mid house body,are composed with " ","@@","=    +     +    =","&" so i use "else" here 
	 
	 for(int j = 1; j <= 19; ++j){
	
	  if(j == 3 || j == 19 ){
  	    printf("@@");
      }  	 
	  else if(j == 6 || j == 16){
  	    printf("=    +    +    =");
      }
      else if(j == 11){
	  	for(int k = 1; k <= d_width; ++k)
	  	  printf("&");
      }
	  else{
       printf(" "); 	
      }  
	 } 
	}
	 printf("\n");
	
}
//lower wall + lower door
for(int i = 1; i <= 3; ++i){//this part of code is for the lines of lower part of the wall which contains lower part of the door 

  	for(int j = 1; j <= r_bottom; ++j){
	  
  	 if((j >= 3 && j <= 4) || (j >= 69 && j <= 70)){//this prints the wall
  	   printf("@");
     }
  	 else if(j >= 27 && j <= 46){//print "&" when 27th till 46th character (22 characters of " " between the wall and door(4+22+1=27,27+16=46))
	     printf("&");
     }
	else
      printf(" ");

  }
  printf("\n");
  }
//lower wall  
for(int i = 1; i <= 2; ++i){//the height of the lowest part of the wall is 2 characters 
  	
  	for(int j = 1; j <= r_bottom ; ++j){
	  
  	 if((j >= 3 && j <= 4 )||(j >= 69 && j <= 70))
  	  printf("@");
  	  
     else
      printf(" ");

  }
  printf("\n");
}
//floor
for(int i = 1; i <= 2; ++i){//the thickness of the floor is 2 characters 
  
  for(int j = 1; j <= r_bottom ; ++j){
    if (j >= 3 && j <= 70)    
	 printf("@");
	else 
	 printf(" ");
  }  
  printf("\n");
}
return 0 ;
}
