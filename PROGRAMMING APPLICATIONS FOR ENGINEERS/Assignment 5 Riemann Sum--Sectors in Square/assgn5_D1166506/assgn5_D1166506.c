#include <stdio.h>
#include <math.h>
#define pi acos(-1)

int main ()
{
    while (1)
    {
        // Initialize the variable will be used later.
        double a ;
        double interval=1 , interval_size , area=-1 , last=-2 , left , right , point ;
        double R1 , R2 , R3 ;
        // Print the sentence and input the side of the square a.
        printf ("Enter the side of square a: ") , fflush (stdout) ;
        scanf ("%lf" , &a) ;
        // If a is not equal to 0, then break the loop.
        if (!a) break ;
        // Initialize the upper and lower limits.
        left = a/2 , right =sqrt (3)*a/2 ;
        // While loop until the difference is lower than 1e-6 which is epsilon equivalently.
        while (fabs(area-last)>1e-6)
        {
            // Compute the variables.
            interval_size = (right-left)/interval ;
            point = left + interval_size/2.0 ;
            last = area ;
            area = 0 ;
            // Calculate the area.
            for (int i=0 ; i<interval ; ++i)
            {
                area += (sqrt (a*a-point*point) - a/2.0) * interval_size ;
                point += interval_size ;
            }
            interval *= 2 ;
        }
        // Calculate and print R1, R2, and R3 as required.
        R1 = area * 4 , R2 = a*a*(pi-2) - 2*R1 , R3 = a*a - R1 - R2 ;
        printf ("Area R1: %.4lf, Area R2: %.4lf, Area R3: %.4lf\n" , R1 , R2 , R3) , fflush (stdout) ;
        printf ("\n--------------------------------------------------------------\n\n") , fflush (stdout) ;
    }
    return 0;
}

