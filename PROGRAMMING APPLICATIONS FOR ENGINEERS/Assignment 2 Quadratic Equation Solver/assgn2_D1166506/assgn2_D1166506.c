#include <stdio.h>
#include <math.h>

int main()
{
    //Declare the required integer variables a, b, and c, and flag to record the status.
    int a , b , c , flag ;
    //Print as required.
    printf ("Solving roots of equation a*X^2+b*X+c = 0.\n\n") ;
    //Use do-while to prevent the user from mistyping the non-integer variables.
    do
    {
        //Print the prompt text.
        printf ("Please enter three integer coefficients a, b, and c: ") , fflush(stdout) ;
        //Clear the buffer in order to avoid the scanf function getting the previous false input.
        fflush(stdin) ;
        //Get the variables a, b, and c, and use a variable flag to record the number of inputs correctly.
        flag = scanf ("%d %d %d" , &a , &b , &c) ;
    }
    //If the number of inputs correctly isn't equal to 3 or a is equal to 0, input the variables a, b, and c again.
    while (flag!=3 || a==0);
    //Declare and initialize the value of the variable D, a discriminant of the quadratic equation.
    double D=(b*b-4*a*c) ;
    //Use conditional expressions to determine and print the equation.
    if (D==0) printf ("\nThe multiple real root of equation ") ;
    else if (D>0) printf ("\nThe real roots of equation ") ;
    else printf ("\nThe complex roots of equation ") ;
    if (a==1) printf ("X**2") ;
    else if (a==-1) printf ("-X**2") ;
    else if (a!=0) printf ("%dX**2" , a) ;
    if (b==1) printf ("+X") ;
    else if (b==-1) printf ("-X") ;
    else if (b!=0) printf ("%+dX" , b) ;
    if (c) printf ("%+d" , c) ;
    printf ("=0 ") ;
    //Separate the root into two parts, and combine them in different ways according to the value of variable D.
    double x1 = -b/(2*(double)a) , x2 = sqrt(fabs(D))/(2*(double)a) ;
    //Use conditional expressions to determine and print the equation.
    if (D==0) printf ("is %.4lf.\n" , x1+x2) ;
    else if (D>0) printf ("are %.4lf and %.4lf.\n" , x1+x2 , x1-x2) ;
    else if (x1!=0) printf ("are %.4lf+%.4lfi and %.4lf-%.4lfi.\n" , x1 , x2 , x1 , x2) ;
    else printf ("are %.4lfi and -%.4lfi.\n" , x2 , x2) ;
    return 0;
}
