#include <stdio.h>
#include <math.h>

int main() {
    long long int a, b, c;
    double discriminant, root1, root2;
    
    printf("Sloving roots of equation a*X^2+b*X+c =0\n");
    printf("Please enter three integer coefficients a, b and c: ");
    scanf("%lld %lld %lld", &a, &b, &c);

    while(a == 0){
        printf("a cannot be 0\nPlease enter a again\n");
        scanf("%lld", &a);
    }
    
    discriminant = b * b - 4 * a * c;
        
        if(discriminant > 0){
            printf("The real roots of ");
        }
        if(discriminant == 0){
            printf("Multiple root of ");
        }
        if(discriminant < 0){
            printf("Two complex roots of ");
        }
        
        if (a == 1){
            printf("x^2 ");
        }
        else if (a == -1){
            printf("-x^2 ");
        }
        else{
            printf("%lldx^2 ", a);
    }

    if (b != 0){
        if (b == 1)
            printf("+ x ");
        else if (b == -1)
            printf("- x ");
        else if (b > 0)
            printf("+ %lldx ", b);
        else
            printf("- %lldx ", -b);
    }

    if (c != 0){
        if (c > 0)
            printf("+ %lld ", c);
        else
            printf("- %lld ", -c);
    }

    printf("= 0");

    if (discriminant > 0){
        root1 = (-b + sqrt(discriminant)) / (2.0 * a);
        root2 = (-b - sqrt(discriminant)) / (2.0 * a);
        if(root1 == -0){
            root1 = 0;
        }
        if(root2 == -0){
            root2 = 0;
        }
        printf(" are %.4lf, %.4lf\n", root1, root2);
    } else if (discriminant == 0){
        root1 = -b / (2.0 * a);
        printf(" is %.4lf\n", root1);
    } else{
        float realPart = -b / (2.0 * a);
        float imaginaryPart = sqrt(-discriminant) / (2.0 * a);
        printf(" are %.4lf + %.4lfi, %.4lf - %.4lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}