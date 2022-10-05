#include <stdio.h>
#include <math.h>

int main()
{
    double a , b , c ;
    printf ("Solving roots of equation a*X^2+b*X+c = 0.\n\n") ;
    printf ("Please enter three integer coefficients a, b, and c: ") , fflush(stdout) ;
    
    scanf ("%lf %lf %lf" , &a , &b , &c) ;
    double D=(b*b-4*a*c) , root1 , root2 ;
    if (D==0) printf ("\nThe multiple real root of equation ") ;
    else if (D>0) printf ("\nThe real roots of equation ") ;
    else printf ("\nThe complex roots of equation ") ;

    if (a==1) printf ("X**2") ;
    else if (a==-1) printf ("-X**2") ;
    else if (a!=0) printf ("%.0lfX**2" , a) ;
    if (b>0)
    {
        if (b==1) printf ("+X") ;
        else printf ("+%.0lfX" , b) ;
    }
    else if (b<0)
    {
        if (b==-1) printf ("-X") ;
        else printf ("%.0lfX" , b) ;
    }
    if (c>0) printf ("+%.0lf" , c) ;
    else if (c<0) printf ("%.0lf" , c) ;
    printf ("=0 ") ;

    root1 = (-b+sqrt(D))/(2*(double)a) ;
    root2 = (-b-sqrt(D))/(2*(double)a) ;
    if (D==0) printf ("is %.4f.\n" , root1) ;
    //PROBLEM!!!!!!!!!!!!!!!!!!!! -5 2 0
    else if (D>0) printf ("are %.4f and %.4f.\n" , root1 , root2) ;
    else
    {
        double real = -(double)b/(2*(double)a) ;
        double complex=sqrt(-D)/(2*a) ;
        if (b!=0) printf ("are %.4f+%.4fi and %.4f-%.4fi.\n" , real , complex , real , complex) ;
        else printf ("are %.4fi and -%.4fi.\n" , complex , complex) ;
    }
    return 0;
}
