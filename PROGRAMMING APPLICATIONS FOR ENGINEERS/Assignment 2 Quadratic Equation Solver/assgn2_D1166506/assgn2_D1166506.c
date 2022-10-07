#include <stdio.h>
#include <math.h>

int main()
{
    int a , b , c , flag ;
    printf ("Solving roots of equation a*X^2+b*X+c = 0.\n\n") ;
    do
    {
        printf ("Please enter three integer coefficients a, b, and c: ") , fflush(stdout) ;
        fflush(stdin) ;
        flag = scanf ("%d %d %d" , &a , &b , &c) ;
    }
    while (flag!=3 || a==0);
    double D=(b*b-4*a*c) , x1 , x2 ;
    if (D==0) printf ("\nThe multiple real root of equation ") ;
    else if (D>0) printf ("\nThe real roots of equation ") ;
    else printf ("\nThe complex roots of equation ") ;

    if (a==1) printf ("X**2") ;
    else if (a==-1) printf ("-X**2") ;
    else if (a!=0) printf ("%dX**2" , a) ;
    if (b==1) printf ("+X") ;
    else if (b==-1) printf ("-X") ;
    else if (b!=0) printf ("%+dX" , a) ;
    if (c) printf ("%+d" , c) ;
    printf ("=0 ") ;
    x1 = -b/(2*(double)a) , x2 = sqrt(fabs(D))/(2*(double)a) ;
    if (D==0) printf ("is %.4lf.\n" , x1+x2) ;
    else if (D>0) printf ("are %.4lf and %.4lf.\n" , x1+x2 , x1-x2) ;
    else
    {
        if (b!=0) printf ("are %.4lf+%.4lfi and %.4lf-%.4lfi.\n" , x1 , x2 , x1 , x2) ;
        else printf ("are %.4lfi and -%.4lfi.\n" , x2 , x2) ;
    }
    return 0;
}
