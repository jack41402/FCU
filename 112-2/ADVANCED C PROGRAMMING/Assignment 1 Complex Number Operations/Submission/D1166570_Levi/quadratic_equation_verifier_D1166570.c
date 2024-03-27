#define _CRT_SECURE_NO_WARNINGS

#include "complex_D1166570.h"

void printchar(float a, float b, float c) {
	if (a == 1) {
		printf("X**2");
	}
	else if (a == -1) {
		printf("-X**2");
	}
	else {
		printf("%.4f X**2", a);
	}
	if (b == 1) {
		printf(" + X");
	}
	else if (b == -1) {
		printf(" - X");
	}
	else if (b != 0) {
		if (b > 0)
		{
			printf(" + %.4f X", b);
		}
		else
		{
			printf(" - %.4f X", -b);
		}
	}
	if (c == 1) {
		printf(" + 1 = 0");
	}
	else if (c == -1) {
		printf(" - 1 = 0");
	}
	else if (c == 0) {
		printf(" ");
	}
	else {
		if(c > 0)
			printf(" + %.4f = 0 ", c);
		else
			printf(" - %.4f = 0 ", -c);
	}
}

int main() {
	float a, b, c, x1, x2, d;
	complex delta;
	do {
		printf("Enter coefficients a, b, and c for quadratic equation a*X^2 + b*X + c = 0: ");
		scanf("%f %f %f", &a, &b, &c);
	} while (a == 0);
	printf("The quadratic equation is: ");
	printchar(a, b, c);
	printf("\n");
	d = b * b - 4 * a * c;
	if (d < 0)
	{
		delta.re = 0;
		delta.im = sqrt(-d);
	}
	else
	{
		delta.re = sqrt(d);
		delta.im = 0;
	}
	complex r1 = divide(add(r2c(-b), delta), r2c(2 * a));
	complex r2 = divide(minus(r2c(-b), delta), r2c(2 * a));
	printf("\n");
	printf("The two roots of the quadratic equation are: ");
	printComplex(r1);
	printf(" and ");
	printComplex(r2);
	printf("\n");
	printf("\n");
	int valid = 1;
	if (absComplex(add(add(time(time(r2c(a), r1), r1), time(r2c(b), r1)), r2c(c))) > 0.000001)
	{
		valid = 0;
	}
	if (absComplex(add(add(time(time(r2c(a), r2), r2), time(r2c(b), r2)), r2c(c))) > 0.000001)
	{
		valid = 0;
	}
	if (valid)
	{
		printf("Quadratic equation solution is a pair of valid roots. Verification succeeds.\n");
	}
	else
	{
		printf("Quadratic equation solution is not a pair of valid roots. Verification fails.\n");
	}
	return 0;
}

