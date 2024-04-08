#include <stdio.h>
#include "complex_D1175125.h"
#include <math.h>

int main(){
    float a=1, b, c;
    float pb=0, pc=0;
    complex root1,root2;
    do{
        printf("Enter cofficients a, b, and c for quadratic equation a X**2 + b x + c = 0: ");
        scanf("%f %f %f", &a, &b, &c);
    }while(a==0);
    float discriminant=(b*b-4*a*c);
    if(b<0) pb=-b;
    if(c<0) pc=-c;
    if(a==1){
        if(b==0&&c==0){
            printf("The quadratic equation is: X**2 = 0.\n\n");
        }
        else if (b<0&&c==0){
            printf("The quadratic equation is: X**2 - %.4f X = 0.\n\n", pb);
        }
        else if (c<0&&b==0){
            printf("The quadratic equation is: X**2 - %.4f = 0.\n\n", pc);
        }
        else if(b==0&&c>0){
            printf("The quadratic equation is: X**2 + %.4f = 0.\n\n", c);
        }
        else if(c==0&&b>0){
            printf("The quadratic equation is: X**2 + %.4f X = 0.\n\n", b);
        }
        else if(b<0&&c>0){
            printf("The quadratic equation is: X**2 - %.4f X + %.4f = 0.\n\n", pb, c);
        }
        else if(b>0&&c<0){
            printf("The quadratic equation is: X**2 + %.4f X - %.4f = 0.\n\n", b, pc);
        }
        else if(b<0&&c<0){
            printf("The quadratic equation is: X**2 - %.4f X - %.4f = 0.\n\n", pb, pc);
        }
        else{
            printf("The quadratic equation is: X**2 + %.4f X + %.4f = 0.\n\n", b, c);
        }
    }
    else{
        if(b==0&&c==0){
            printf("The quadratic equation is: %.4fX**2 = 0.\n\n", a);
        }
        else if(b==0&&c>0){
            printf("The quadratic equation is: %.4f X**2 + %.4f = 0.\n\n", a, c);
        }
        else if(b==0&&c<0){
            printf("The quadratic equation is: %.4f X**2 - %.4f = 0.\n\n", a, pc);
        }
        else if(c==0&&b>0){
            printf("The quadratic equation is: %.4f X**2 + %.4f X = 0.\n\n", a, b);
        }
        else if(c==0&&b<0){
            printf("The quadratic equation is: %.4f X**2 - %.4f X = 0.\n\n", a, pb);
        }
        else if(b<0&&c>0){
            printf("The quadratic equation is: %.4f X**2 - %.4f X + %.4f = 0.\n\n", a, pb, c);
        }
        else if(b>0&&c<0){
            printf("The quadratic equation is: %.4f X**2 + %.4f X - %.4f = 0.\n\n", a, b, c);
        }
        else if(b<0&&c<0){
            printf("The quadratic equation is: %.4f X**2 + %.4f X - %.4f = 0.\n\n", a, pb, pc);
        }
        else{
            printf("The quadratic equation is: %.4f X**2 + %.4f X + %.4f = 0.\n\n", a, b, c);
        }
    }
    if (discriminant >= 0) {
          root1.re = (-b + sqrt(discriminant)) / (2 * a);
          root1.im = 0;
          root2.re = (-b - sqrt(discriminant)) / (2 * a);
          root2.im = 0;
      } else {
          root1.re = -b / (2 * a);
          root1.im = sqrt(-discriminant) / (2 * a);
          root2.re = -b / (2 * a);
          root2.im = -sqrt(-discriminant) / (2 * a);
      }
    printf("The two roots of the equation are: ");
    printComplex(root1);
    printf(" and ");
    printComplex(root2);
    printf("\n\n");
    float verification1 = absComplex(add(add(Time(Time(r2c(a), root1), root1), Time(r2c(b), root1)), r2c(c)));
    float verification2 = absComplex(add(add(Time(Time(r2c(a), root2), root2), Time(r2c(b), root2)), r2c(c)));

    if(verification1 < 0.000001 && verification2 < 0.000001) {
        printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.\n");
    } else {
        printf("Quadratic equation solution is a pair of invalid roots. Verification failed.\n");
    }
    complex test1, test2;
    test1.re = 10, test1.im = -5;
    test2.re = 10, test2.im = -5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 10, test2.im = 0;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 0, test2.im = -5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    test2.re = 5, test2.im = 5;
    printf("test1: "), printComplex(test1), printf("\n");
    printf("test2: "), printComplex(test2), printf("\n");
    printComplex(minus(test1, test2));
    printf("\n");
    printComplex(divide(test1, test2));
    printf("\n");
    return 0;
}
