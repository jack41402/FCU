
//The code includes necessary header files for standard input/output (stdio.h) and mathematical functions (math.h).
#include <stdio.h>
#include <math.h>

int main()
{
// Declare variables for coefficients and solutions
	int a,b,c;//It declares integer variables a, b, and c to store the coefficients of a quadratic equation.
	
//It displays a message indicating that it's solving the roots of an equation in the form a*X^2 + b*X + c.	
	printf("Solving roots of equation a*X^2+b*X+c \n");
// Input coefficients from the user	
	printf("Please enter three integer coefficients a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);//It prompts the user to enter three integer coefficients a, b, and c using scanf.
//The code checks if the discriminant (b * b - 4 * a * c) is equal to 0. If it is, it means there's a multiple real root.   
    if( b*b-4*a*c == 0)
	{
    	printf("The multiple real root of equation ");
    
    	if(a==1){
    		printf("X**2");
		}//If the coefficient a is equal to 1, it prints "X**2"
    	else if(a==-1){
    		printf("-X**2");
		}// If a is equal to -1, it prints "-X**2"
		
		else if(a!=0) {
			printf("%dX**2",a);
		}//If a is not equal to 0 and not equal to 1 or -1, it prints the value of a followed by "X**2"
		if(b==1){
			if(a==0){
				printf("X");
			}	
			else{
				printf("+X");
			}
		}//If the coefficient b is equal to 1, it checks the value of a. If a is 0, it prints "X". If a is not 0, it prints "+X".
		else if(b==-1){
    		printf("-X");
		} //If b is equal to -1, it prints "-X".
		else if(b>0){
			if(a==0){
				printf("%dX",b);
			}
			else{
				printf("+%dX",b);
			}
			
		}// If b is greater than 0, it checks the value of a. If a is 0, it prints the value of b followed by "X". If a is not 0, it prints the value of b preceded by "+" and followed by "X".
		else if(b!=0){
			printf("%dX",b);
		}// If b is not equal to 0 and not equal to 1 or -1, it prints the value of b followed by "X".
		
		if(c>0){
			if(a==0&&b==0){
				printf("%d",c);
			}
			else{ 
			    printf("+%d",c); 
			}
		} // If the coefficient c is greater than 0, it checks the values of a and b. If both a and b are 0, it prints the value of c. Otherwise, it prints "+" followed by the value of c.
		else if(c<0) {
			printf("%d",c);
		}// If c is less than 0, it prints the value of c. 
		printf("=0");
		printf(" is ");
		printf("%1.4lf.",(float)-b/(2*a)+1e-8);
	}
	//This condition checks if the discriminant is greater than zero, which indicates that there are real roots. 
	else if(b*b-4*a*c > 0 ){
		    	printf("The real roots of equation ");//It prints a message indicating that there are real roots of the equation. 
    	if(a==1){
    		printf("X**2");
		}//If the coefficient a is equal to 1, it prints "X**2".
    	else if(a==-1){
    		printf("-X**2");
		}//If a is equal to -1, it prints "-X**2".
		
		else if(a!=0) {
			printf("%dX**2",a);
		}// If a is not equal to 0, 1, or -1, it prints the value of a followed by "X**2".
		if(b==1){
			if(a==0){
				printf("X");
			}	
			else{
				printf("+X");
			}
		}//If b is equal to 1, it checks the value of a. If a is 0, it prints "X". If a is not 0, it prints "+X".
		else if(b==-1){
    		printf("-X");
		}//If b is equal to -1, it prints "-X".
		else if(b>0){
			if(a==0){
				printf("%dX",b);
			}
			else{
				printf("+%dX",b);
			}
			
		}// If b is greater than 0, it checks the value of a. If a is 0, it prints the value of b followed by "X". If a is not 0, it prints the value of b preceded by "+" and followed by "X".
		else if(b!=0){
			printf("%dX",b);
		}//If b is not equal to 0, 1, or -1, it prints the value of b followed by "X".
		
		if(c>0){
			if(a==0&&b==0){
				printf("%d",c);
			}
			else{ 
			    printf("+%d",c); 
			}
		} // If the constant c is greater than 0, it checks the values of a and b. If both a and b are 0, it prints the value of c. Otherwise, it prints "+" followed by the value of c.
		else if(c<0) {
			printf("%d",c);
		}//If c is less than 0, it prints the value of c.
		

		printf("=0");
		printf(" are");	
		printf(" %1.4lf and %1.4lf.",((-b)+ sqrt((b*b)-(4*a*c)))/(2*a)+1e-8,((-b)- sqrt((b*b)-(4*a*c)))/(2*a)+1e-8);
	}
	else{

		printf("The complex roots of equation ");
    	if(a==1){
    		printf("X**2");
		}//If the coefficient a is equal to 1, it prints "X**2".
    	else if(a==-1){
    		printf("-X**2");
		}//If a is equal to -1, it prints "-X**2".
		
		else if(a!=0) {
			printf("%dX**2",a);
		}// If a is not equal to 0, 1, or -1, it prints the value of a followed by "X**2".
		if(b==1){
			if(a==0){
				printf("X");
			}	
			else{
				printf("+X");
			}
		}// If b is equal to 1, it checks the value of a. If a is 0, it prints "X." If a is not 0, it prints "+X".
		else if(b==-1){
    		printf("-X");
		}// If b is equal to -1, it prints "-X".
		else if(b>0){
			if(a==0){
				printf("%dX",b);
			}
			else{
				printf("+%dX",b);
			}
			
		}// If b is greater than 0, it checks the value of a. If a is 0, it prints the value of b followed by "X". If a is not 0, it prints the value of b preceded by "+" and followed by "X".
		else if(b!=0){
			printf("%dX",b);
		}//If b is not equal to 0, 1, or -1, it prints the value of b followed by "X".
		
		if(c>0){
			if(a==0&&b==0){
				printf("%d",c);
			}
			else{ 
			    printf("+%d",c); 
			}
		} // If the constant c is greater than 0, it checks the values of a and b. If both a and b are 0, it prints the value of c. Otherwise, it prints "+" followed by the value of c.
		else if(c<0) {
			printf("%d",c);
		}// If c is less than 0, it prints the value of c.
		printf("=0");
		printf(" are");
		if (b==0){
			 // If the coefficient 'b' is zero, it means a purely imaginary solution.
			printf(" %1.4lfi and -%1.4lfi.",sqrt(-b*b-(-4*a*c))/(2*a),sqrt(-b*b-(-4*a*c))/(2*a));
		}
		else{
		// If 'b' is not zero, both a real and imaginary part in the solutions.
			printf(" %1.4lf+%1.4lfi and %1.4lf-%1.4lfi.", (float)((-b))/(2*a),sqrt(-b*b-(-4*a*c))/(2*a),(float)((-b))/(2*a),sqrt(-b*b-(-4*a*c))/(2*a));
		}
		
		
		
	}	
		return 0;
	
}
