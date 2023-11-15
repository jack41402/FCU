#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Please enter the coefficients of the quadratic equation:\n");
    printf("Please enter a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("The equation is %lf x^2 + %lf x + %lf\n", a, b, c);

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The equation has two real roots:\n");
        if (root1 == 0) root1 = 0;  // Check for zero and set it to zero
        if (root2 == 0) root2 = 0;
        printf("root 1 = %.4lf\n", root1);
        printf("root 2 = %.4lf\n", root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("The equation has a real root:\n");
        if (root == 0) root = 0;  // Check for zero and set it to zero
        printf("root = %.4lf\n", root);
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("The equation has two complex roots:\n");
        if (realPart == 0) realPart = 0;  // Check for zero and set it to zero
        if (imaginaryPart == 0) imaginaryPart = 0;
        if (imaginaryPart < 0) {
            imaginaryPart = -imaginaryPart;
            printf("root 1 = %.4lf - %.4lfi\n", realPart, imaginaryPart);
            printf("root 2 = %.4lf + %.4lfi\n", realPart, imaginaryPart);
        }else{
            printf("root 1 = %.4lf + %.4lfi\n", realPart, imaginaryPart);
            printf("root 2 = %.4lf - %.4lfi\n", realPart, imaginaryPart);
        }
    }

    return 0;
}
