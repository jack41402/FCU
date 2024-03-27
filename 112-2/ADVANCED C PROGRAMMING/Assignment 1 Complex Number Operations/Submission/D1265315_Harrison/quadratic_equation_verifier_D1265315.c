#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex_D1265315.h"

int main(){
    float a, b, c;
    float real, real1, real2, img, check;
    complex root1, root2, coefa, coefb, coefc;
    complex ver1, ver2;

    //input and ensure that a not equal 0
    do{
        printf(" Enter coefficients a, b and c for quadratic equation a x**2 + b x + c = 0: ");
        scanf("%f %f %f", &a, &b, &c);
    }while(a == 0);

    //output the equation
    printf("\nThe quadratic equation is: ");
    if (a != 0){
        if (a == 1){
            printf("X**2 ");
        }
        else if (a == -1){
            printf("-X**2 ");
        }
        else printf("%6.4f X**2 ", a);
    }
    if (b != 0){
        if (b == 1){
            printf("+ X ");
        }
        else if (b == -1){
            printf("- X ");
        }
        else if (b > 0){
            printf("+ %6.4f X ", b);
        }
        else if (b < 0){
            printf("- %6.4f X", -b);
        }
    }
    if (c != 0){
        if (c > 0){
            printf("+ %6.4f = 0.\n", c);
        }
        else if (c < 0){
            printf("- %6.4f = 0.\n", -c);
        }
    }

    //convert to complex
    check = pow(b,2) - 4*a*c;
    if (check >= 0){
        real1 = (-b + sqrt(pow(b,2) - 4*a*c))/ (2*a);
        real2 = (-b - sqrt(pow(b,2) - 4*a*c))/ (2*a);
        root1 = r2c(real1, 0);
        root2 = r2c(real2, 0);
    }
    else{
        real = -b / (2*a);
        img = sqrt(4*a*c -pow(b,2))/ (2*a);
        root1 = r2c(real, img);
        root2 = r2c(real, -img);
    }

    //print roots
    printf("\nThe two roots of quadratic equation are: ");
    printComplex(root1);
    printf(" and ");
    printComplex(root2);
    printf("\n");

    //verify
    coefa = r2c(a,0);
    coefb = r2c(b,0);
    coefc = r2c(c,0);
    ver1 = add(add(multiplie(coefa, multiplie(root1, root1)), multiplie(coefb, root1)), coefc);
    ver2 = add(add(multiplie(coefa, multiplie(root2, root2)), multiplie(coefb, root2)), coefc);
    if (absComplex(ver1)< 0.000001 && absComplex(ver2)<0.000001){
        printf("\nQuadratic solutions is a pair of valid roots. Verifications succeeds.");
    }

    return 0;
}


