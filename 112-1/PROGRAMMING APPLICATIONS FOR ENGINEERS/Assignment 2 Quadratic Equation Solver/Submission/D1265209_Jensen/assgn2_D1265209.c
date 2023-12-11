#include <stdio.h>
#include <math.h>
#include <complex.h>

int main()
{
    long long int a, b, c, discriminant;//declare variables
    double root1, root2,real,imag;
    do
    {
        printf("Solving roots of equation a*X^2+b*X+c = 0.\n\n");
        printf("Please enter three integer coefficients a, b, and c: ");
        scanf("%lld%lld%lld", &a, &b, &c);//let user enter the number and scan it
    } while (a==0);//make sure a doesn't equal 0, and the program can continue
    {
        printf("\n");
        //use the discriminant first
        discriminant=b*b-4*a*c;//declare discriminant
        if(discriminant==0)
        {
            root1=-b/(2*a);//the root
            printf("The multiple real root of equation ");//print after root
        }
        else if(discriminant>0)
        {
            root1=(-b+sqrt(discriminant))/(2*a);//the root 
            root2=(-b-sqrt(discriminant))/(2*a);//the root
            printf("The real roots of equation ");//print after root
        }
        else//if discriminant smaller than 0
        {
            real=-b/(2*a);//the real root
            imag=sqrt(-discriminant)/(2*a);//the virtual root
            printf("The complex roots of equation ");//print after root
        }
        //print the equation
        if(a==1)
        {
            printf("X**2");
        }
        else if(a==-1)
        {
            printf("-X**2");
        }
        else
        {
            printf("%lldX**2",a);
        }
        if(b>0)
        {
            printf("+");
        }
        if(b!=0)
        {
            printf("%lldX",b);
        }
        if(c>0)
        {
            printf("+");
        }
        if(c!=0)
        {
            printf("%lld",c);
        }
        //print the answer of the root
        if(discriminant==0)
        {
            printf(" is %.4lf\n",root1);
        }
        else if(discriminant>0)
        {
            printf(" are %.4lf and %.4lf\n",root1,root2);
        }
        else
        {
            if(real!=0)
            {
                printf(" are %.4lf+%.4lfi and %.4lf-%.4lfi\n",real,imag,real,imag);
            }
            else//if real equal 0, dont have to print it
            {
                printf(" are %.4lfi and -%.4lfi\n",imag,imag);
            }
        }
    }
}
