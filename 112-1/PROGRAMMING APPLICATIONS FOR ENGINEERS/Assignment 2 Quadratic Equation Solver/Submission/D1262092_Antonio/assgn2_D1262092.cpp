#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    float a, b, c;
    
    printf("Solving roots of equation a*X^2+b*X+c = 0\n\n");
    printf("Please enter three integer coefficients a, b, and c (a¡Ú0):");
    scanf("%f %f %f", &a, &b, &c);
    if(a == 0){// if a equal to 0 then shut down the program
    	printf("\na can not be equal to 0");
    	exit(1);
	}
    printf("\n");
    
    float discriminant = b * b - 4.0 * a * c;//create a float formula of discriminant(b^2-4ac) to use later
    char equation[50];//create a character array to store the data of equation to use later
    
	//store the equation data after pretty printing format into the cahracter array "equation"
    if (a != 0) {//a can not be equal to 0
        if (a != 1 && a != -1)
            sprintf(equation + strlen(equation), "%.0fX^2", a);
        
		else if (a == -1)//when a = -1, print the "-1X^2" without "-1"
            sprintf(equation + strlen(equation), "-X^2");
        
		else//when a = 1, print the "1X^2" without "1"
            sprintf(equation + strlen(equation), "X^2");
    }
    if (b != 0) {//when b = 0, print nothing 
        
		if (b > 0)
            sprintf(equation + strlen(equation), "+%.0fX", b);
        
		else if (b < 0)
            sprintf(equation + strlen(equation), "-%.0fX", -b);//don't print "+" when b < 0
    }
    if (c != 0) {//when c = 0, print nothing
        
		if (c > 0)
            sprintf(equation + strlen(equation), "+%.0f", c);
        
		else if (c < 0)
            sprintf(equation + strlen(equation), "-%.0f", -c);//don't print "+" when c < 0
    }
    sprintf(equation + strlen(equation), "=0");
    
	//discriminant > 0, 2 real roots
	if (discriminant > 0) { 
	    if(a > 0) 
         printf("The real roots of the equation  %s are %.4f and %.4f.\n", equation, (-b + sqrt(discriminant)) / (2.0 * a), (-b - sqrt(discriminant)) / (2.0 * a));
        
		else if (a < 0)
         printf("The real roots of the equation  %s are %.4f and %.4f.\n", equation, (b - sqrt(discriminant)) / -(2.0 * a), (b + sqrt(discriminant)) / -(2.0 * a));
    } 
	//discriminant = 0, 1 multuple root
	else if (discriminant == 0) { 
	    if(a > 0)
            printf("The multiple real root of the equation  %s is %.4f.\n", equation, (-b + sqrt(discriminant))/ (2.0*a));
        
		else if(a < 0)
            printf("The multiple real root of the equation  %s is %.4f.\n", equation, (b - sqrt(discriminant))/ -(2.0*a));
    } 
	//discriminant < 0, 2 complex roots composed by the real number part and the imaginary number part
	else {      
		float RealPart = -b / (2.0 * a);
        float ImaginaryPart = sqrt(-discriminant) / (2.0 * a);
        
        if(RealPart == 0)//To print the roots in pretty printing format, when Real munber part = 0, don't print the RealPart but just the imaginary number part
        	printf("The complex roots of the equation  %s are %.4fi and -%.4fi.\n", equation, ImaginaryPart, ImaginaryPart);
        
		else
		    printf("The complex roots of the equation  %s are %.4f+%.4fi and %.4f-%.4fi.\n", equation, RealPart, ImaginaryPart, RealPart, ImaginaryPart);
    }
    
    return 0;
}
