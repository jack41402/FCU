#include <stdio.h>
#include <math.h>

int main()
{
    //Declare the required integer variables a, b, and c, and flag to record the status.
    double a , b , c ;
    //Print as required.
    printf ("Solving roots of equation a*X^2+b*X+c = 0.\n\n") ;
    //Use do-while to prevent the user from mistyping the non-integer variables.
    do
    {
        //Print the prompt text.
        printf ("Please enter three integer coefficients a, b, and c: ") , fflush(stdout) ;
        //Clear the buffer in order to avoid the scanf function getting the previous false input.
        fflush(stdin) ;
        //Get the variables a, b, and c.
        scanf ("%lf %lf %lf" , &a , &b , &c) ;
    }
    //If variable a, b, or c is not an integer value or variable a is equal to 0, input the variables a, b, and c again.
    while (a!=(int)a || b!=(int)b || c!=(int)c || a==0);
    //Declare and initialize the value of the variable D, a discriminant of the quadratic equation.
    double D=(b*b-4*a*c) ;
    //Use conditional expressions to determine and print the equation.
    if (D==0) printf ("\nThe multiple real root of equation ") ;
    else if (D>0) printf ("\nThe real roots of equation ") ;
    else printf ("\nThe complex roots of equation ") ;
    if (a==1) printf ("X**2") ;
    else if (a==-1) printf ("-X**2") ;
    else if (a!=0) printf ("%.0lfX**2" , a) ;
    if (b==1) printf ("+X") ;
    else if (b==-1) printf ("-X") ;
    else if (b!=0) printf ("%+.0lfX" , b) ;
    if (c) printf ("%+.0lf" , c) ;
    printf ("=0 ") ;
    //Separate the root into two parts, and combine them in different ways according to the value of variable D.
    double x1 = -b/(2*a) , x2 = sqrt(fabs(D))/(2*a) ;
    //Use conditional expressions to determine and print the equation.
    if (D==0) printf ("is %.4lf.\n" , x1+x2) ;
    else if (D>0) printf ("are %.4lf and %.4lf.\n" , x1+x2 , x1-x2) ;
    else if (x1!=0  && x2!=1) printf ("are %.4lf+%.4lfi and %.4lf-%.4lfi.\n" , x1 , x2 , x1 , x2) ;
    else if (x1!=0) printf ("are %.4lf+i and %.4lf-i.\n" , x1 , x1) ;
    else if (x2!=1) printf ("are %.4lfi and -%.4lfi.\n" , x2 , x2) ;
    else printf ("are i and -i.\n") ;
    return 0;
}
