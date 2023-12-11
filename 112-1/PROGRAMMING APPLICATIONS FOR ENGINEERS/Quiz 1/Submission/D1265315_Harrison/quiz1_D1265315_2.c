#include <stdio.h>

int main() {
	int x,y,z,one,two,three;
	printf("Input three integers x, y, and z:");
	scanf("%d %d %d",&x,&y,&z);
	while(x!=0 || y!=0 || z!=0){
	one = x+y*z;
	two = y+z*x;
	three = z+x*y;
	printf("\nThe values of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d\n",one,two,three);
	if(x==0 && y==0 && z==0){
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order:%d %d %d\n",three,two,one);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order:%d %d %d\n",one,two,three);
	printf("\n----------------------------------------\n");
	printf("End of program execution");
	break;
	}
	if(one>=two && two>=three){
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order:%d %d %d\n",three,two,one);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order:%d %d %d\n",one,two,three);
	printf("\n----------------------------------------\n");
	printf("Input three integers x, y, and z:");
	scanf("%d %d %d",&x,&y,&z);
}
	else if (one>=two && one>=three && three>=two){
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order:%d %d %d\n",two,three,one);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order:%d %d %d\n",one,three,two);
	printf("\n----------------------------------------\n");
	printf("Input three integers x, y, and z:");
	scanf("%d %d %d",&x,&y,&z);
}
	else if (two>=one && one>=three){
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order:%d %d %d\n",three,one,two);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order:%d %d %d\n",two,one,three);
	printf("\n----------------------------------------\n");
	printf("Input three integers x, y, and z:");
	scanf("%d %d %d",&x,&y,&z);
	}
	else if (two>=one && three>=one && two>=three){
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order:%d %d %d\n",one,three,two);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order:%d %d %d\n",two,three,one);
		printf("\n----------------------------------------\n");
	printf("Input three integers x, y, and z:");
	scanf("%d %d %d",&x,&y,&z);
	}
	else if (three>=one && one>=two){
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order:%d %d %d\n",two,one,three);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order:%d %d %d\n",three,one,two);
	printf("\n----------------------------------------\n");
	printf("Input three integers x, y, and z:");
	scanf("%d %d %d",&x,&y,&z);
	}
	else if (three>=one && two>=one && three>=two){
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order:%d %d %d\n",one,two,three);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order:%d %d %d\n",three,two,one);
		printf("\n----------------------------------------\n");
	printf("Input three integers x, y, and z:");
	scanf("%d %d %d",&x,&y,&z);
	}
	
}
	if(x==0 && y==0 && z==0){
	one = x+y*z;
	two = y+z*x;
	three = z+x*y;
		printf("\nThe values of expressions x+y*z, y+z*x, and z+x*y: %d, %d, %d\n",one,two,three);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the ascending order:%d %d %d\n",three,two,one);
		printf("Expressions x+y*z, y+z*x, and z+x*y in the descending order:%d %d %d\n",one,two,three);
	printf("\n----------------------------------------\n");
	printf("End of program execution");
	}
	return 0;
}
