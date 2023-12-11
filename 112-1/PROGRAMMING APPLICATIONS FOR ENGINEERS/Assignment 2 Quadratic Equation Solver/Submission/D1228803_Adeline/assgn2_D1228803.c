#include<stdio.h>
#include<math.h> //header file provides various mathematical functions that can be used 

int main()//function where the execution of the program begins 
{
	int a, b, c;//declare a, b and c
	float D;//declare D
	float root1, root2, root;//declare root1, root2
	float realpart, imaginarypart;//declare realpart, imaginarypart
	
    
	printf("Solving roots of equation a*X^2+b*X+c=0\n");//print the equation
	printf("Please enter three integer coefficients a, b and c: ");//print the integer the user input
	scanf("%d %d %d", &a, &b, &c);//Use scanf statements to input the integer coefficients a, b, and c of the quadratic equation from the user.
	
	D = b * b - 4 * a * c;//defined D as the discrimination
	
	
	if ( D > 0 )//If D > 0, there are two real roots.
	{
		root1 = (-b + sqrt(D)) / (2.0 * a);//set root1 as the possitive of discrimination
		root2 = (-b - sqrt(D)) / (2.0 * a);//set root2 as the negative of discrimination
		printf("The multiple real root of equation ");//print the root
		if(a > 1 || a < -1)//pretty printing format as determine the time to print out the coefficient
		{
			printf("%dX^2 ", a);//print the X^2
		}
		else if(a == 1)//pretty printing format as determine the time to print without the coefficient
		{
			printf("X^2 ");//print the X^2
		}
		else if(a == -1)//pretty printing format as determine the time to print out the coefficient with minus
		{
			printf("-X^2 ");//print the X^2
		}
		else if(a == 0)//pretty printing format as determine the time when mention error
		{
			printf("Error");//print error
		}
	
		
		if( b > 1 )//pretty printing format as determine the time to print out the possitive coefficient
		{
			printf("+%dX ", b);//print the X
		}
		else if(b < -1)//pretty printing format as determine the time to print out the negative coefficient
		{
			printf("%dX", b);//print the X
		}
		else if(b == 1)//pretty printing format as determine the time to print without the coefficient
		{
			printf("+X ");//print the X
		}
		else if(b == -1)//pretty printing format as determine the time to print out the coefficient with minus
		{
			printf("-X ");//print the X
		}
		
		if(c >= 1)//pretty printing format as determine the time to print out the possitive constant
		{
			printf("+%d ", c);//print constant
		}
		else if(c < 0)//pretty printing format as determine the time to print out the negative constant
		{
			printf("%d", c);//print constant
		}
		
		printf("= 0 are %1.4f and %1.4f. \n", root1, root2);//print out the equation and the roots
			
	}
	
	else if( D == 0 )//If D == 0, there are two equal real roots.
	{
		root = (-b) / (2.0 * a);//set root
		printf("The equal real root of equation ");//print the root
		if(a > 1 || a < -1)//pretty printing format as determine the time to print out the coefficient
		{
			printf("%dX^2 ", a);//print the X^2
		}
		else if(a == 1)//pretty printing format as determine the time to print without the coefficient
		{
			printf("X^2 ");//print the X^2
		}
		else if(a == -1)//pretty printing format as determine the time to print out the coefficient with minus
		{
			printf("-X^2 ");//print the X^2
		}
		else if(a == 0)//pretty printing format as determine the time when mention error
		{
			printf("Error");//print error
		}
	
		
		if(b > 1)//pretty printing format as determine the time to print out the possitive coefficient
		{
			printf("+%dX ", b);//print the X
		}
		else if(b < -1)//pretty printing format as determine the time to print out the negative coefficient
		{
			printf("%dX", b);//print the X
		} 
		else if(b == 1)//pretty printing format as determine the time to print without the coefficient
		{
			printf("+X ");//print the X
		}
		else if(b == -1)//pretty printing format as determine the time to print out the coefficient with minus
		{
			printf("-X ");//print the X
		}

	
		if(c >= 1)//pretty printing format as determine the time to print out the possitive constant
		{
			printf("+%d ", c);//print constant
		}
		else if(c < 0)//pretty printing format as determine the time to print out the negative constant
		{
			printf("%d", c);//print constant
		}
		printf("= 0 is %1.4f. \n", root);//print out the equation and the root
		
	}
	
	else if ( D < 0 )//If D < 0, there are two complex roots
	{
		realpart = (-b) / (2.0 * a);//set realpart
		imaginarypart = sqrt(-D) / (2.0 * a);//set imaginarypart
		printf("The complex roots of equation ");//print the root
		
		if(a > 1 || a < -1)//pretty printing format as determine the time to print out the coefficient
		{
			printf("%dX^2 ", a);//print the X^2
		}
		else if(a == 1)//pretty printing format as determine the time to print without the coefficient
		{
			printf("X^2 ");//print the X^2
		}
		else if(a == -1)//pretty printing format as determine the time to print out the coefficient with minus
		{
			printf("-X^2 ");//print the X^2
		}
		else if(a == 0)//pretty printing format as determine the time when mention error
		{
			printf("Error");//print error
		}
	
		
		if(b > 1)//pretty printing format as determine the time to print out the possitive coefficient
		{
			printf("+%dX ", b);//print the X
		}
		else if(b < -1)//pretty printing format as determine the time to print out the negative coefficient
		{
			printf("%dX", b);//print the X
		}
		else if(b == 1)//pretty printing format as determine the time to print without the coefficient
		{
			printf("+X ");//print the X
		}
		else if(b == -1)//pretty printing format as determine the time to print out the coefficient with minus
		{
			printf("-X ");//print the X
		}

		
		if(c >= 1)//pretty printing format as determine the time to print out the possitive constant
		{
			printf("+%d", c);//print constant
		}
		else if(c < 0)//pretty printing format as determine the time to print out the negative constant
		{
			printf("%d ", c);//print constant
		}
		
		printf("= 0 are: %1.4f + %1.4fi and %1.4f - %1.4fi\n", realpart, imaginarypart, realpart, imaginarypart);//print out the equation and the roots
	}

	return 0;//to indicate the successful execution of a program
}
