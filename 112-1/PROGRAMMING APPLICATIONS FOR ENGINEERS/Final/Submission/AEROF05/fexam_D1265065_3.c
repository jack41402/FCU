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

double f1(double x) {
	return (-b/a)*x+b;
};

double f2(double x) {
	return (-c/b)*x+c;
}; 

double f3(double x) {
	return (-d/c)*x+d;
};

double f4(double x) {
	return (-d/a)*x+d;
};

// b. Define and implement function 
//      double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) 
//    to compute the area covered by two functional parameters f and g between interval (r, s) 
//    along the X axis.

double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) {
	double interval; // Size of the partitioned interval.
	double point; // The left-end point of each individual interval.
	double area; // Area of the covered region, left Riemann sum of the current iteration.
	double last; // Left Riemann sum of the previous iteration.
	int i; // Loop variable.
	
   T = 1;
   last = -1;
   area = -2;
   while (fabs(last-area)>epsilon){
	interval = fabs(r-s) / T;
	point = r + interval / 2;
	last = area;
	area = 0;
	for(i = 0; i < T; i++)
	{
		area += fabs(f(point)-g(point)) * interval;
		point += interval;
	}
	printf("Number of intervals: %d, interval size: %8.6lf, area: %.6lf\n", T, interval, area);
	T = T*2;
	} 
	return area;
}

int main(void) {
	double areaBCD, areaBAD; // Area of triangle BCD and triangle BAD.
	double area; // Area of the quadrilateral.
    
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
	printf("**** Compute area the area of triangle BCD.\n");
	areaBCD = right_Riemann_sum(c,0,f2,f3);
	printf("The number of intervals: %d\n\n", T/2);
  	printf("**** Compute area the area of triangle BAD.\n");
	areaBAD = right_Riemann_sum(0,a,f1,f4);
	printf("The number of intervals: %d\n\n", T/2);
	area = areaBCD + areaBAD;
	// e. Print the area of triangle BCD, the area of triangle BAD, and the area of quadrilateral ABCD.
	printf(">>>> Area of triangle BCD: %.6lf\n", areaBCD);
	printf(">>>> Area of triangle BAD: %.6lf\n", areaBAD);
	printf(">>>> Area of quadrilateral ABCD: %.6lf\n", area);
	printf(">>>> The result of 1/2|(a-c)(b-d)| is: %.6lf\n", 1.0/2.0*(fabs(a-c)*(b-d)));
	printf(">>>> The error is: %.6f\n",fabs(area-(1.0/2.0*(fabs(a-c)*(b-d)))));
  
	// f. Verify the result with the area formula 1/2|(a-c)(b-d)|.
  
	return 0;
}
