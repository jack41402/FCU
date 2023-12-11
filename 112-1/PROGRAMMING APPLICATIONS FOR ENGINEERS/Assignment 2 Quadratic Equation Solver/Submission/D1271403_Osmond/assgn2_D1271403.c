#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    // Display initial message
    printf("Solving roots of equation a*X^2+b*X+c = 0.\n\n");
    printf("Please enter three integer coefficients a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("\n");
    
    // Calculate the discriminant
    int discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        // Two real and distinct roots
        double root1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double root2 = (-b - sqrt(discriminant)) / (2.0 * a);
        printf("The real roots of equation ");
        
        // Pretty print aX^2 term
        if (a) {
            if (a==1) printf("X**2");
            else if (a==-1) printf("-X**2");
            else printf("%dX**2", a);
        }
        
        // Pretty print bX term
        if (b) {
            if (b==1) printf("+X");
            else if (b==-1) printf("-X");
            else if (b<-1) printf("%dX", b);
            else if (b>1) printf("+%dX", b);
        }
        
        // Pretty print c term
        if (c) {
            if (c<0) printf("%d", c);
            else if (c>0) printf("+%d", c);
        }
        if (root1 == 0) root1 = 0;	// Handle zero roots
        printf("=0 are: %.4lf and %.4lf.\n", root1, root2);	// Print roots
    }
    else if (discriminant == 0) {
        // One real root (repeated)
        double root = -b / (2.0 * a);
        printf("The multiple real root of equation ");
        if (a) {
            if (a==1) printf("X**2");
            else if (a==-1) printf("-X**2");
            else printf("%dX**2", a);
        }
        if (b) {
            if (b==1) printf("+X");
            else if (b==-1) printf("-X");
            else if (b<-1) printf("%dX", b);
            else if (b>1) printf("+%dX", b);
        }
        if (c) {
            if (c<0) printf("%d", c);
            else if (c>0) printf("+%d", c);
        }
        printf("=0 is %.4lf.\n", root);	// Print root
    }
    else {
        // Complex roots
        double realPart = -b / (2.0 * a);
        double imaginaryPart = sqrt(-discriminant) / (2.0 * a);
        printf("The complex roots of equation ");
        if (a) {
            if (a==1) printf("X**2");
            else if (a==-1) printf("-X**2");
            else printf("%dX**2", a);
        }
        if (b) {
            if (b==1) printf("+X");
            else if (b==-1) printf("-X");
            else if (b<-1) printf("%dX", b);
            else if (b>1) printf("+%dX", b);
        }
        if (c) {
            if (c<0) printf("%d", c);
            else if (c>0) printf("+%d", c);
        }
        if (realPart) {
           printf("=0 are: %.4lf+%.4lfi and %.4lf-%.4lfi.\n", realPart, imaginaryPart, realPart, imaginaryPart);
         
        } else {
            printf("=0 are: %.4lfi and -%.4lfi.\n", imaginaryPart, imaginaryPart);
        }
    }
}
