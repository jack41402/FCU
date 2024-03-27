#include <stdio.h>
#include "complex_D1265686.h"
#include <math.h>


int main()
{
    float a ,b ,c;
    
    float t ,t2;
    printf("Enter coefficients a, b, and c for quadratic equation a x**2 + b x + c = 0: "); //Enter coefficient 
    scanf("%f %f %f",&a ,&b ,&c);  
    
    printf("The quadratic equation is: "); 
    
    if(a==1) //Output according to the required format
    {
        printf("X**2 ");
    }
    else
    {
        printf("%.4f X**2 ",a);
    }
    
    if(b>0)
    {
        printf("+ %.4f X ",b);
    }
    else if(b<0)
    {
        t=fabs(b);
        printf("- %.4f X ",t);
    }
    
    if(c>0)
    {
        printf("+ %.4f = 0.",c);
    }
    else if(c<0)
    {
        t2 = fabs(c);
        printf("- %.4f = 0",t2);
    }
    else
    {
        printf("= 0");
    }
    
    printf("\n\n");
    
    complex root1 ,root2; 
    
    if( (b*b - 4*a*c ) > 0) //Compute root
    {
        root1 = r2c((-b + sqrt(b*b-4*a*c))/ (2*a) ); 
        root2= r2c((-b - sqrt(b*b-4*a*c))/ (2*a) );
     
        printf("The two roots of the quadratic equation are: ");
        printComplex(root1); 
        printf(" and ");
        printComplex(root2);
        
    }
    
    else if( (b*b - 4*a*c ) < 0)
    {
        root1.re = -b/(2*a) ;
        root1.im = sqrt(4*a*c-b*b)/ (2*a) ;
        
        root2.re = -b/(2*a) ;
        root2.im = -sqrt(4*a*c-b*b) /(2*a);
        
        printf("The two roots of the quadratic equation are: ");
        printComplex(root1); //Use functions to print out complex numbers
        printf(" and ");
        printComplex(root2); //Use functions to print out complex numbers
    }
    
    else
    {
        root1 = r2c(-b/(2*a)) ; //Convert real numbers to imaginary numbers using r2c
        root2 = r2c(-b/(2*a)) ; //Convert real numbers to imaginary numbers using r2c
        printf("The two roots of the quadratic equation are: ");
        printComplex(root1);
        printf(" and ");
        printComplex(root2);
    }
    
    printf("\n\n");
    
    
    //Bring the roots back into the equation to verify the result
    complex result1;
    complex result2;
    
    //Perform verification
    
    result1 = add(add(ttime(ttime(root1,root1),r2c(a)),ttime(r2c(b), root1)),r2c(c));
    result2 = add(add(ttime(ttime(root2,root2),r2c(a)),ttime(r2c(b), root2)),r2c(c));
    
    //Determine whether the verification result is within the error value
    if(absComplex(result1)<0.000001 && absComplex(result2)<0.000001)
    {
        printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.");
    }
    
    
    return 0;
}

