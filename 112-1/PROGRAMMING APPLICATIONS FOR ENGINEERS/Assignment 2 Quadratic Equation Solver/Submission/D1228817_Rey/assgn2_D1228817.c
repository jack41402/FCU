#include <stdio.h>
#include<math.h>

int main(){
	printf("Solving roots of equation a*X^2+b*X+c=0\n\n");
	float a, b, c;//"a", "b" and "c" are the three coefficients of the equation. 
	printf("Please enter three integer coefficients a, b, and c: ");
	scanf("%f %f %f", &a, &b, &c);
	if(a==0){//Checking if "a" is 0.
		printf("a cannot be 0, please try again.");
		exit(0);
	}
	printf("\n");
	int A, B, C;//"A", "B" and "C" are the values of "a", "b" and "C" without numbers after the decimal points.
	A=a;
	B=b;
	C=c;
	if(a-A!=0||b-B!=0||c-C!=0){//Checking if all coefficients are integers.
		printf("The coefficients have to be integers! Please try again.");
		exit(0);
	}
	int j=0;//"j" is used to identify which kind of roots the equation has.
	float d;
		
	if(((b*b)-4*a*c)<0){//The condition for complex roots.
		d=sqrt(-(b*b)+4*a*c);
		j++;//"j" becomes 1 if the equation has complex roots.
	}
	else{//The condition for real roots.
		d= sqrt((b*b)-4*a*c);
	}


	float root_one;
	if(-b+d==0){
		root_one=0;//This line of code prevents the output of the root to be -0 when the root is 0.
	}
	else{
		root_one=(-b+d)/(2*a);
	}

	float root_two;
	if(-b-d==0){
		root_two=0;//This line of code prevents the output of the root to be -0 when the root is 0.
	}
	else{
		root_two=(-b-d)/(2*a);
	}

	if (root_one==root_two&&j==0){
		printf("The multiple real root of equation ");
	}
	else if(root_one!=root_two&&j==0){
		printf("The real roots of equation ");
	}
	else {
		printf("The complex roots of equation ");
	}
	

	if (a==1){
		printf("X**2");//If "a" equals 1, X**2 will be printed out instead of 1X**2.
	}
	else if(a==-1){
		printf("-X**2");//If "a" equals -1, -X**2 will be printed out instead of -1X**2.
	}
	else {
		printf("%.0fX**2", a);
	}


	if(b==1){
		printf("+X");
	}
	else if(b==-1){
		printf("-X");
	}
	else if (b>0){
		printf("+%.0fX", b);//"+" must be added before the X term if "b" is greater than 0, for the X^2 term will not be 0. 
	}
	else if (b!=0){
		printf("%.0fX", b);
	}
	else{
		printf("");
	}


	if(c>0){
		printf("+%.0f", c);//"+" must be added before the constant if "c" is greater than 0, for the X^2 term will not be 0. 
	}
	else if(c!=0){
		printf("%.0f", c);
	}
	else{
		printf("");
	}


printf("=0");

if (root_one==root_two&&j==0){//The equation has a multiple real root.
	printf(" is ");
	printf("%.4f.", root_one);
}
else if(root_one!=root_two&&j==0){//The equation has real roots.
	printf(" are ");
	printf("%.4f and %.4f.", root_one, root_two);
}
else if(b!=0&&j!=0){//The equation has complex roots(b!=0).
	printf(" are ");
	printf("%.4f+%.4fi and %.4f-%.4fi.", -b/(2*a), d/(2*a), -b/(2*a), d/(2*a));
}
else {//The equation has complex roots(b=0).
	printf(" are ");
	printf("%.4fi and -%.4fi.", d/(2*a), d/(2*a));
}

return 0;
}
