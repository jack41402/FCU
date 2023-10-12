#include<stdio.h>
int main(){//Declaring the variables
int i, j, h, v;//Declaring the variables i, j, h, v
	const int r_top=40;//Declaring the top of the roof 
	const int r_side=16;//Declaring the side of the roof
	const int r_bottom=r_top+2*r_side;//Declaring the bottom of the roof
	const int d_width=20;//Declaring the width of the door
	const int d_height=28;//Declaring the height of the height
	const int w_width=16;//Declaring the width of the window
	const int w_height=25;//Declaring the height of the window
	const int g_width=4;//Declaring the width of the window glass
	const int g_height=5;//Declaring the height of the window glass
	const int wcf_thickness=2;//Declaring the thickness of the wall, ceiling and floor.
	const int wdtoc_space=10;//Declaring the space from the window, door to the ceiling
	const int fd_space=2;//Declaring the space from the floor to the door
	const int fw_space=5;//Declaring the space from the floor to the window
	const int ww_space=2;//Declaring the space from the window to the wall
	const int wd_space=4;//Declaring the space from the window to the door
	const int h_width=72;//Declaring the whole width of the house
	const int h_height=62;//Declaring the whole height of the house
	const int h_exwidth=68;//Declaring the exterior width of the house
	const int h_exheight=44;//Declaring the exterior height of the house
	const int h_inwidth=64;//Declaring the interior width of the house
	const int h_inheight=40;//Declaring the interior height of the house
	const int blank=4;//Declare the blank space before the house 
	const int rt_height=1;//Declare the rooftop's height
	const int rb_height=1;//Declare the roof bottom's height
	const int rbtow_dis=2;//Declare the roof bottom to the wall's distance under vertical translation 
	const int wg_num=4;//Declare the number of the window glass
	const int wgp_width=1;//Declare the number of the width of each piece window glass
	const int wb_height=1;//Declare the height of the window bottom
	const int bd_dis=3;//Declare the door to the window's distance under vertical translation 
//printing the variables declared above
printf("   <<<The top of the roof:%d\n", r_top);
printf("   <<<The side of the roof:%d\n", r_side);
printf("   <<<The bottom of the roof:%d\n", r_bottom);
printf("   <<<The width of the door:%d\n", d_width);
printf("   <<<The height of the door:%d\n", d_height);
printf("   <<<The width of the window:%d\n", w_width);
printf("   <<<The height of the window:%d\n", w_height);
printf("   <<<The width of the window glass:%d\n",g_width);
printf("   <<<The height of the window glass:%d\n", g_height);
printf("   <<<The width of the door:%d\n", d_width);
printf("   <<<The thickness of wall/ceiling/floor:%d\n", wcf_thickness);
printf("   <<<The space from the window/door to the ceiling:%d\n", wdtoc_space);
printf("   <<<The space between the floor and the door:%d\n", fd_space);
printf("   <<<The space between the floor and the window:%d\n", fw_space);
printf("   <<<The space from the window to the wall:%d\n", ww_space);
printf("   <<<The space between the window and the door:%d\n", wd_space);
printf("\n");//Change to next line
if(w_width*2+d_width+ww_space*2+wd_space*2+wcf_thickness*2+rbtow_dis*2==h_width&&
 r_side+rt_height+rb_height+wcf_thickness*2+wdtoc_space+d_height+fd_space==h_height&&
 w_width*2+d_width+ww_space*2+wd_space*2+wcf_thickness*2==h_exwidth&&
 wcf_thickness*2+wdtoc_space+d_height+fd_space==h_exheight&&
 w_width*2+d_width+ww_space*2+wd_space*2==h_inwidth&&
 wdtoc_space+d_height+fd_space==h_inheight){//To verify if the house is valid by seeing whether the whole, interior and exterior height and the width add up, if it does print the variables below and print the house
 	
printf("***** The house design is valid\n");
printf("   <<<The total width of the house:%d\n", h_width);
printf("   <<<The total height of the house:%d\n", h_height);
printf("   <<<The exterior width of the house:%d\n", h_exwidth);
printf("   <<<The exterior height of the house:%d\n", h_exheight);
printf("   <<<The interior width of the house:%d\n", h_inwidth);
printf("   <<<The interior height of the house:%d\n", h_inheight);
printf("\n");//Change to next line
printf("\n");//Change to next line
printf("\n");//Change to next line
    
 
    for(i=0; i<r_side+blank; ++i){//Repeat the execution of printing space until r_side+blank(the first row)
    	printf(" ");//Print space  
	}
	for(i=0; i<r_top; ++i){//Repeat the execution of printing # until r_top(the first row)
		printf("#");//Print #
		

}
printf("\n");//Change to next line


	for (i=0; i<r_side; ++i) {//Repeat the execution of printing until r_side(the roof)
		for(j=0; j<r_side-i+blank-1; ++j){//Repeat the execution of printing space until r_side-i=blank-1
    printf(" ");}//Print space
    printf("#");//Print #
    for(j=0; j<2*i+r_top; ++j){//Repeat the execution of printing * until 2*i+r_top
    	printf("*");//Print *
	}
	printf("#");//Print #
	printf("\n");//Change to next line
}
    for(i=0; i<blank; ++i){//Repeat the execution of printing until blank(the roof bottom row)
    	printf(" ");}//Print space
    	for(i=0; i<r_bottom; ++i){//Repeat the execution of printing # until r_bottom
		printf("#");// Print #
}
		printf("\n");//Change to next line
    for(i=0; i<wcf_thickness; ++i)	{//Repeat the execution of printing until wcf_thickness(the top wall)
	
	for(j=0; j<blank+rbtow_dis; ++j){//Repeat the execution of printing space until blank+rbtow_dis
		printf(" ");}//Print space
		for(j=0; j<r_bottom-rbtow_dis*2; ++j){//Repeat the execution of printing @ until r_bottom-rbtow_dis*2
		
		printf("@");//Print @
	}

		printf("\n");//Change to next line
	}
	for(i=0; i<wdtoc_space; ++i){//Repeat the execution of printing until wdtoc_space(the top wall to the row with window)
		for(j=0; j<blank+rbtow_dis; ++j){//Repeat the execution of printing space until blank+rbtow_dis
		printf(" ");}//Print space
		for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
			printf("@");//Print @
		}
		for(j=0; j<h_inwidth; ++j){//Repeat the execution of printing space until h_inwidth
			printf(" ");//Print space
		}
		for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
			printf("@");//Print @
		}
		printf("\n");//Change to next line
	}
	for(i=0; i<wg_num; ++i){//Repeat the execution of printing until wg_num(the rows incuding window)
		for(j=0; j<blank+rbtow_dis; ++j){//Repeat the execution of printing space until blank+rbtow_dis
			printf(" ");//Print space
		}
		for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
			printf("@");//Print @
		}
		for(j=0; j<ww_space; ++j){//Repeat the execution of printing space until ww_space
			printf(" ");//Print space
		}
		for(j=0; j<w_width; ++j){//Repeat the execution of printing = until w_width
			printf("=");//Print =
		}
		for(j=0; j<wd_space; ++j){//Repeat the execution of printing space until wd_space
			printf(" ");//Print space
		}
		for(j=0; j<d_width; ++j){//Repeat the execution of printing & until d_width
			printf("&");//Print &
		}
		for(j=0; j<wd_space; ++j){//Repeat the execution of printing space until wd_space
			printf(" ");//Print space
		}
		for(j=0; j<w_width; ++j){//Repeat the execution of printing = until w_width
			printf("=");//Print =
		}
		for(j=0; j<ww_space; ++j){//Repeat the execution of printing space until ww_space
			printf(" ");//Print space
		}
		for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
			printf("@");//Print @ 
		}
		printf("\n");//Change to next line
		for(h=0; h<fw_space; ++h ){//Repeat the execution of printing until fw_space(window glass) 
			for(v=0; v<blank+rbtow_dis; ++v){//Repeat the execution of printing space until blank+rbtow_dis
				printf(" ");//Print space
			}
			for(v=0; v<wcf_thickness; ++v){//Repeat the execution of printing @ until wcf_thickness
				printf("@");//Print @
			}
			for(v=0; v<ww_space; ++v){//Repeat the execution of printing space until ww_space
				printf(" ");//Print space
			}
			for(v=0; v<wgp_width; ++v){//Repeat the execution of printing = until wgp_width
				printf("=");//Print =
			}
			for(v=0; v<wd_space;++v){//Repeat the execution of printing space until wd_space
				printf(" ");//Print space
			}
			for(v=0; v<wgp_width; ++v){//Repeat the execution of printing + until wgp_width
				printf("+");//Print +
			}
			for(v=0; v<wd_space; ++v){//Repeat the execution of printing space until wd_space
				printf(" ");//Print space
			}
			for(v=0; v<wgp_width; ++v){//Repeat the execution of printing + until wgp_width
				printf("+");//Print +
			}
			for(v=0; v<wd_space; ++v){//Repeat the execution of printing space until wd_space
				printf(" ");//Print space
			}
			for(v=0; v<wgp_width; ++v){//Repeat the execution of printing = until wgp_width
				printf("=");//Print =
			}
			for(v=0; v<wd_space; ++v){//Repeat the execution of printing space until wd_space
				printf(" ");//Print space
			}
			for(v=0; v<d_width; ++v){//Repeat the execution of printing & until d_width
				printf("&");//Print &
			}
			for(v=0; v<wd_space; ++v){//Repeat the execution of printing space until wd_space
				printf(" ");//Print space
			}
			for(v=0; v<wgp_width; ++v){//Repeat the execution of printing = until wgp_width
				printf("=");//Print
			}
			for(v=0; v<wd_space;++v){//Repeat the execution of printing space until wd_space
				printf(" ");//Print space
			}
			for(v=0; v<wgp_width; ++v){//Repeat the execution of printing + until wgp_width
				printf("+");//Print +
			}
			for(v=0; v<wd_space; ++v){//Repeat the execution of printing space until wd_space
				printf(" ");//Print space
			}
			for(v=0; v<wgp_width; ++v){//Repeat the execution of printing + until wgp_width
				printf("+");//Print +
			}
			for(v=0; v<wd_space; ++v){//Repeat the execution of printing space until wd_space
				printf(" ");//Print space
			}
			for(v=0; v<wgp_width; ++v){//Repeat the execution of printing = until wgp_width
				printf("=");//Print =
			}
			for(v=0; v<ww_space; ++v){//Repeat the execution of printing space until ww_space
				printf(" ");//Print space
			}
			for(v=0; v<wcf_thickness; ++v){//Repeat the execution of printing @ until wcf_thickness
				printf("@");//Print @
			}
		printf("\n");//Change to next line
		}
		
		
	}
	for(i=0; i<wb_height; ++i){//Repeat the execution of printing until wb_height(the bottom of the window)
		for(j=0; j<blank+rbtow_dis; ++j){//Repeat the execution of printing space until blank+rbtow_dis
			printf(" ");//Print space
		}
		for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
			printf("@");//Print @
		}
		for(j=0; j<ww_space; ++j){//Repeat the execution of printing @ until ww_space
			printf(" ");//Print space
		}
		for(j=0; j<w_width; ++j){//Repeat the execution of printing = until w_width
			printf("=");//Print =
		}
		for(j=0; j<wd_space; ++j){//Repeat the execution of printing space until wd_space
			printf(" ");//Print space
		}
		for(j=0; j<d_width; ++j){//Repeat the execution of printing & until d_width
			printf("&");//Print &
		}
		for(j=0; j<wd_space; ++j){//Repeat the execution of printing space until wd_space
			printf(" ");//Print space
		}
		for(j=0; j<w_width; ++j){//Repeat the execution of printing = until w_width
			printf("=");//Print =
		}
		for(j=0; j<ww_space; ++j){//Repeat the execution of printing space until ww_space
			printf(" ");//Print space
		}
		for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
			printf("@");//Print @
		}
		
}
printf("\n");//Change to next line
      for(i=0; i<bd_dis; ++i){//Repeat the execution of printing until bd_dis(the row including the window but not the door)
      for(j=0; j<blank+rbtow_dis; ++j){//Repeat the execution of printing space until blank+rbtow_dis
      	printf(" ");//Print space
	  }
	  for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
	  	printf("@");//Print @
	  }
	  for(j=0; j<w_width+2+wd_space; ++j){//Repeat the execution of printing space until w_width+2+wd_space
	  	printf(" ");//Print space
	  }
	  for(j=0; j<d_width; ++j){//Repeat the execution of printing & until d_width
	  printf("&");//Print &
      }
      for(j=0; j<w_width+2+wd_space; ++j){//Repeat the execution of printing space until w_width+2+wd_space
      	printf(" ");//Print space
	  }
	  for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
	  	printf("@");//Print @
	  }
	  printf("\n");//Change to next line
}
    for(i=0; i<fd_space; ++i){//Repeat the execution of printing until fd_space(the floor to the door)
    	for(j=0; j<blank+rbtow_dis; ++j){//Repeat the execution of printint space until blank+rbtow_dis
    		printf(" ");//Print space
		}
		for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
    	printf("@");//Print @
    }
        for(j=0; j<h_inwidth; ++j){//Repeat the execution of printing space until h_width
        	printf(" ");//Print space
		}
		for(j=0; j<wcf_thickness; ++j){//Repeat the execution of printing @ until wcf_thickness
			printf("@");//Print @
		}
		printf("\n");//Change to next line
	}
	for(i=0; i<2; ++i){//Repeat the execution of printing(the house bottom)
		for(j=0; j<blank+rbtow_dis;++j){//Repeat the execution of printing blank until blank+rbtow_dis
			printf(" ");//Print space
		}
		for(j=0; j<h_exwidth; ++j){//Repeat the execution of printing @ until h_exwidth
			printf("@");//Print @
		}
		printf("\n");//Change to next line
	}
}
 else{//If the whole, interior and exterior height and the width don't add up, print This house is not valid
 
 printf("This house is not valid");}//Print This house is not valid
	return 0;
}
