#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define epsilon 0.000001 // Difference error.

// Declare globe variables.
double a, b, c, d; // Points A(a, 0), B(0, b), C(c,0), and D(0, d).
int T; // Number of the partitioned intervals.

// ***** Complete the implementation of functions in Step a and Step b.  

// a. Define and implement four functions double f1(double x), double f2(double x), 
//    double f3(double x), and double f4(double x) for lines AB, BC, CD, and DA.
double(interval)

double f1(double x) 
{
	for(int i=0; i < c; i--)
	interval = (fabs(a - 0) / T) * fabs(b);
};

double f2(double x) 
{
	interval = (fabs(0 - c) / T) * fabs(b);
}; 

double f3(double x) 
{
	interval = (fabs(0 - c) / T) * fabs(d);
};

double f4(double x) 
{
	interval = (fabs((a - 0) / T) * fabs(d);
};

// b. Define and implement function 
//      double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) 
//    to compute the area covered by two functional parameters f and g between interval (r, s) 
//    along the X axis.

double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) 
{
	double interval; // Size of the partitioned interval.
	double point; // The left-end point of each individual interval.
	double area; // Area of the covered region, left Riemann sum of the current iteration.
	double last; // Left Riemann sum of the previous iteration.
	int i; // Loop variable.

}

int main(void) 
{
	double areaBCD, areaBAD; // Area of triangle BCD and triangle BAD.
	double area; // Area of the quadrilateral.
	int i, j;
	
	fabs(fabs(f) - fabs(g)) < epsilon;
	
	interval = fabs(b - a) / T;
	point = (interval + a) / 2;
	last = area;
	area = 0;
	
	T += T * 2;
    
	// c. Enter four real numbers (double type) a, b, c and d, where c<0<a and d<0<b, to 
	//    represent points A(a, 0), B(0, b), C(c,0), and D(0, d).
	printf("Enter real number a for point A(a, 0), a>0: ");
	scanf("%lf", &a); // Input point A.
	printf("Enter real number b for point B(0, b), b>0: ");
	scanf("%lf", &b); // Input point B.
	printf("Enter real number c for point C(c, 0), c<0: ");
	scanf("%lf", &c); // Input point C.
	printf("Enter real number c for point D(0, d), d<0: ");
	scanf("%lf", &d); // Input point D.  
	printf("\nPoints: A=(%6.4lf, 0), B=(0, %6.4lf), C=(%6.4lf, 0), D=(0, %6.4lf)\n\n", a, b, c, d);
	
	// ***** Complete the program of the following steps.
  
	// d. Compute the area of quadrilateral ABCD using right Riemann sum approach.
  
	// e. Print the area of triangle BCD, the area of triangle BAD, and the area of quadrilateral ABCD.
  
	// f. Verify the result with the area formula 1/2|(a-c)(b-d)|.
	
	
	for(i = 0; i = c; i--)
	{
		double f2(double x);
		double f3(double x);
	}
	
	for(i=0; i<a; i++)
	{
		double f1(double x);
		double f4(double x);
	}
	
	
	printf("****Compute the area triangle BCD.\n");
	for(i = 0; i < b - a; i++)
	{
		printf("Number of intervals: %d, interval size: %6.4lf, area: %6.4lf\n", 2 ^ (b - a), (b - a) / T, areaBCD);
	}
	printf("The number of intervals: %d", 2 ^ (b - a));

	printf("****Compute the area triangle BAD.\n");
	for(i = 0; i <b - a; i++)
	{
		printf("Number of intervals: %d, interval size: %6.4lf, area: %6.4lf\n", 2 ^ (b - a), (b - a) / T, areaBAD); 
	}
	printf("The number of intervals: %d", 2 ^ (b - a));
	printf("\n\n");
	
	printf(">>>> Area of triangle BCD: %6.4lf\n", areaBCD);
	printf(">>>> Area of triangle BAD: %6.flf\n", areaBAD);
	printf(">>>> Area of the quadrilateral ABCD: %6.4lf\n", fags(areaBCD + areaBAD));
	printf(">>>> The result of 1/2|(a-c)(b-d)| is: %6.4lf\n", fags(areaBCD + areaBAD));
	printf("The error is:0.000000");

	
	return 0;
}

//hint: y=f1(x)=-b/a x+b and y=f2(x)=-c/b x+c, y=f3(x)=-d/c x+d, and y=f4(x)=-d/a x+d
