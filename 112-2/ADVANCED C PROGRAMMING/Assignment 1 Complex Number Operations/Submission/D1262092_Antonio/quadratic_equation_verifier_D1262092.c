#include <stdio.h>
#include <math.h>
#include "complex_D1262092.h"

void solveQuadratic(float a, float b, float c) {
    complex discriminant = r2c(b * b - 4 * a * c);
    complex root1, root2, coefa, coefb, coefc;
    complex vrfy1, vrfy2;


    if (discriminant.re >= 0) {
        root1 = divide(add(r2c(-b), discriminant), r2c(2 * a));
        root2 = divide(minus(r2c(-b), discriminant), r2c(2 * a));

       	printf("The two roots of quadratic equation are: ");
        printComplex(root1);
        printf(" and ");
        printComplex(root2);
    } else {
        // Complex roots
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant.re) / (2 * a);
		printf("\nThe two roots of quadratic equation are: ");
		
		if (realPart == 0){
			printf("%.4fi and ", imaginaryPart);
        	printf("- %.4fi\n", imaginaryPart);
        }
		else{
			printf("%.4f + %.4fi and ", realPart, imaginaryPart);
        	printf("%.4f - %.4fi\n", realPart, imaginaryPart);
        }
        
    }
    //Verify Roots
    coefa = r2c(a);
	coefb = r2c(b);
	coefc = r2c(c);
	vrfy1 = add(add(time(coefa, time(root1, root1)), time(coefb, root1)), coefc);
	vrfy2 = add(add(time(coefa, time(root2, root2)), time(coefb, root2)), coefc);
	if (absComplex(vrfy1)< 0.000001 && absComplex(vrfy2)<0.000001){
		printf("\nQuadratic solutions is a pair of valid roots. Verifications succeeds.");
	}
	else{
		printf("\nVerification failed.");
	}

}

int main() {
    float a, b, c;
    
    do{
		printf("Enter coefficients a, b and c for quadratic equation a x**2 + b x + c = 0: ");
		scanf("%f %f %f", &a, &b, &c);		
	}while(a == 0);

    printf("\nThe quadratic equation is : ");
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
    solveQuadratic(a, b, c);
    
    return 0;
}

