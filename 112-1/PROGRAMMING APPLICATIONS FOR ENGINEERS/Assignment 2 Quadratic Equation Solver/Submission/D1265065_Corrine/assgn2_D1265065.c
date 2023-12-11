#include<stdio.h>
#include<math.h>
int main(void){
	int a, b, c;// declared three floating coefficients parameters
	printf("Solving roots of equation a*X^2+b*X+c = 0\n\n");// Print out the title of assignments
	// Use the Do-While loop to make the coefficient of X^2 not to be 0.
	do{
	printf("Please enter three integer coefficients a, b, and c : ");// Print out the text to ask the performer to enter three integers.
	scanf("%d%d%d", &a, &b, &c);// to scan what number does the performer enter
	printf("\n");// print a newline
	}while(a==0);// when a==0 computer will keep asking to enter the integers.
	// Divide the last line of text into multiple parts to determine which kind of root.
	// First, use "if" to determine the discriminant whether greater than zero or not.
	if(b*b-4*a*c == 0){//when discriminant equals to zero,
		printf("The multiple real root of equation ");//print out the text meaning the root is multiple real root.
	}else if(b*b-4*a*c > 0){//when discriminant greater than zero,
		printf("The real roots of equation ");//print out the text meaning the root is real root.
	}else{//when discriminant smaller than zero,
		printf("The complex roots of equation ");//print out the text meaning the root is complex root.
	}
	//To fit the pretty printing format we have to determine each coefficients.
	//Second, use "if" to determine if "a" equals one.
	if(a == 1){
		printf("X**2");
	}else{
		printf("%.0fX**2", a);
	}
	//Third, use "if" to determine if "b" equals one or greater than zero.
	if(b == 1){
		printf("X");
	}else if(b < 0){
		printf("%.0fX", b);
	}else if(b > 0){
		printf("+%.0fX", b);
	}
	//Forth, use "if" to determine if "c" equals one or greater than zero.
	if(c < 0){
		printf("%.0f", c);
	}else if(c > 0){
		printf("+%.0f", c);
	}
	printf("=0");
	//To determine which kinds of root print out.
	if(b*b-4*a*c == 0){
		float r1 = -b/(2*a);// Declare the floating number root.
		//To determine if the root is zero or not, or else it will print out "-0.0000".
		if(r1 == 0){
			printf(" is 0.0000.");
		}else{
			printf(" is %.4f.", r1);
		}
	}else if(b*b-4*a*c > 0){
		float r1 = ((-b)+sqrt(b*b-4*a*c))/(2*a);// Declare the floating number root.
		float r2 = ((-b)-sqrt(b*b-4*a*c))/(2*a);// Declare the floating number root.
		//To determine if the root is zero or not, or else it will print out "-0.0000".
		if(r1 == 0){
			printf(" are 0.0000 and %.4f.", r2);
		}else if(r2 == 0){
			printf(" are %.4f and 0.0000.", r1);
		}else{
			printf(" are %.4f and %.4f.", r1,r2);
		}
	}else{
		float r1 = -b/(2*a);// Declare the floating number root.
		float r2 = sqrt((b*b-4*a*c)*(-1))/(2*a);// Declare the floating number root.
		//To determine if the root is real nuber.
		if(r1 == 0){
			printf(" are %.4fi and -%.4fi.", r2,r2);//print out pure imaginary number.
		}else{
			printf(" are %.4f+%.4fi and %.4f-%.4fi.",r1,r2,r1,r2);//print out real number and imaginary number.
		}
	}
	return 0;
}
